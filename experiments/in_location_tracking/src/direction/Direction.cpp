#include "Direction.h"

#define DEBUG 0

void Direction::init()
{
  compass.init();
  /*
   *   call setSmoothing(STEPS, ADVANCED);
   *
   *   STEPS     = int   The number of steps to smooth the results by. Valid 1 to 10.
   *                     Higher steps equals more smoothing but longer process time.
   *
   *   ADVANCED  = bool  Turn advanced smmothing on or off. True will remove
   *                     the max and min values from each step and then process
   *                     as normal.
   *                     Turning this feature on will results in even more
   *                     smoothing but will take longer to process.
   *
   */
  // compass.setSmoothing(10, true);
  // NOTE: manual calibration settings coppied from running calibrate()
  // compass.setCalibrationOffsets(-530.00, -1155.00, 85.00);
  // compass.setCalibrationScales(1.06, 0.72, 1.48);
  compass.setCalibrationOffsets(180.00, 318.00, 1125.00);
  compass.setCalibrationScales(0.89, 0.65, 2.89);
}

void Direction::calibrate(void (*callbackPre)(), void (*callbackStart)(), void (*callbackEnd)())
{
  callbackPre();
  compass.init();
  Serial.println(
      "This will provide calibration settings for your QMC5883L chip. When "
      "prompted, move the magnetometer in all directions until the calibration "
      "is complete.");
  Serial.println("Calibration will begin in 5 seconds.");
  delay(5000);

  Serial.println("CALIBRATING. Keep moving your sensor...");
  callbackStart();
  compass.calibrate();

  Serial.println("DONE. Copy the lines below and paste it into your projects sketch.);");
  Serial.println();
  Serial.print("compass.setCalibrationOffsets(");
  Serial.print(compass.getCalibrationOffset(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(2));
  Serial.println(");");
  Serial.print("compass.setCalibrationScales(");
  Serial.print(compass.getCalibrationScale(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(2));
  Serial.println(");");

  compass.init();
  compass.setCalibrationOffsets(
      compass.getCalibrationOffset(0),
      compass.getCalibrationOffset(1),
      compass.getCalibrationOffset(2));
  compass.setCalibrationScales(
      compass.getCalibrationScale(0),
      compass.getCalibrationScale(1),
      compass.getCalibrationScale(2));
  callbackEnd();
}

int Direction::read()
{
  compass.read();
  int azimuth = compass.getAzimuth();
  azimuth = azimuth < 0 ? 360 + azimuth : azimuth;
  if (DEBUG)
  {
    int x = compass.getX();
    Serial.print(">x:");
    Serial.println(x);
    int y = compass.getY();
    Serial.print(">y:");
    Serial.println(y);
    int z = compass.getZ();
    Serial.print(">z:");
    Serial.println(z);

    Serial.print(">azimuth:");
    Serial.print(azimuth);
    Serial.println();

    char myArray[3];
    compass.getDirection(myArray, azimuth);

    Serial.print(">direction:");
    Serial.print(myArray[0]);
    Serial.print(myArray[1]);
    Serial.print(myArray[2]);
    Serial.println();
    byte bearing = compass.getBearing(azimuth);
    Serial.print(">bearing:");
    Serial.print(bearing);
    Serial.println();
  }
  return azimuth;
}