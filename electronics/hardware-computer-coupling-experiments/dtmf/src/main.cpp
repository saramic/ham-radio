#include <Arduino.h>

// DTMF frequencies
const int dtmfLow[4] = {697, 770, 852, 941};
const int dtmfHigh[4] = {1209, 1336, 1477, 1633};
const char dtmfKeys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

#define DTMF_OUT_PIN 2 // Output pin for DTMF (e.g. piezo or audio out)
#define DTMF_IN_PIN 36 // Example ADC pin for input (ESP32)

const float TONE_DURATION = 0.2; // seconds

// --- DTMF Output ---
void playDTMF(char key) {
  int low = -1, high = -1;
  for (int r=0; r<4; r++) for (int c=0; c<4; c++) if (dtmfKeys[r][c]==key) { low=r; high=c; }
  if (low<0 || high<0) return;
  int freq1 = dtmfLow[low];
  int freq2 = dtmfHigh[high];
  unsigned long t0 = millis();
  while ((millis()-t0) < TONE_DURATION*1000) {
    float t = (millis()-t0)/1000.0;
    float v = sin(2*PI*freq1*t) + sin(2*PI*freq2*t);
    int out = (v > 0) ? HIGH : LOW;
    digitalWrite(DTMF_OUT_PIN, out);
    delayMicroseconds(100); // crude, for demo only
  }
  digitalWrite(DTMF_OUT_PIN, LOW);
}

// --- DTMF Input (very basic, for demo) ---
// In practice, use Goertzel algorithm or a DTMF decoder chip for robust detection
void setup() {
  pinMode(DTMF_OUT_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("DTMF demo ready");
}

void loop() {
  // Demo: play a sequence
  static unsigned long last = 0;
  static int idx = 0;
  const char* seq = "123A456B789C*0#D";
  if (millis() - last > 1500) {
    playDTMF(seq[idx]);
    Serial.print("Sent DTMF: "); Serial.println(seq[idx]);
    idx = (seq[idx+1]) ? idx+1 : 0;
    last = millis();
  }
  // For input: sample analogRead(DTMF_IN_PIN) and run Goertzel or FFT here
  // ...
}
