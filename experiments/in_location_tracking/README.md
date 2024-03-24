# Experiments in location tracking

## Wiring

## ESP32

```
                              ------------------
                             | |--|  |--|  |--| |
                      EN     | |  |--|  |--|  | | GPIO23
                      GPIO36 |  --------------  | GIPO22    I2C_SCL ---- QMC5883L - SCL
                      GPIO39 | |              | | GIPO1
                      GPIO34 | | ESP-WROOM-32 | | GPI03
                      GPIO35 | |              | | GPI021    I2C_SDA ---- QMC5883L - SDA
                      GPIO32 | |              | | GPI019
        TFT - RES --  GPIO33 | |              | | GPI018
                      GPIO25 | |              | | GPI05 --- TFT - CS
        TFT - BLK --- GPIO26 |  --------------  | GPI017
        TFT -  DC --- GPIO27 |                  | GPI016
        TFT - SCL --- GPIO14 |                  | GPI04
                      GPIO12 |                  | GPI02
                      GPIO13 |                  | GPI015 --- TFT - SDA
                      GND    | RST  _____  BOOT | GND
                      VIN    | [ ] / USB \  [ ] | VDD 3V3
                              ------------------
```

## QMC5883L

```
                              ------------
                         VCC |          O |
                         GND |            |
           I2C_SCL       SCL |            |
           I2C_SDA       SDA |            |
                        DRDY |          O |
                              ------------
```

## TFT

TFT - `GC9101`

```
                                --------------------
                              /                      \
                  D26    BLK |                        |
                   D5     CS |                        |
                  D27     DC |                        |
                  D33    RES |                        |
                  D15    SDA |                        |
                  D14    SCL |                        |
                  (3.3V) VCC |                        |
                         GND |                        |
                              \                      /
                                --------------------
```
