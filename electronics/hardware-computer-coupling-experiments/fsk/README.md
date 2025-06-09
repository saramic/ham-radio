# FSK - Frequency Shift Keying

## FSK Overview
Frequency Shift Keying (FSK) is a digital modulation technique where digital
information is transmitted through discrete frequency changes of a carrier wave.
The most common form, binary FSK (BFSK), uses two frequencies: one for binary
'1' and another for binary '0'.

### How FSK Works

- **Basis**: FSK encodes data by shifting the frequency of a carrier signal
  between two (or more) distinct values. For example, 1200 Hz for '1' and 2200
  Hz for '0'.
- **Transmission**: The transmitter alternates the output frequency according to
  the digital data stream.

### FSK with Electronics Hardware

- **Output**: A microcontroller (like Arduino or ESP32) can generate FSK by
  toggling a digital output pin at different frequencies using timers or PWM,
  which can be filtered to produce analog tones.
- **Input**: An analog input (ADC) can sample incoming audio.  Software (or
  dedicated hardware) then detects which frequency is present, decoding the
  digital data.

### FSK in Web Pages (HTML/JS Sound APIs)

- **Output**: The Web Audio API can generate tones of specific frequencies. By
  switching between two frequencies in real time, you can transmit FSK signals
  from a browser.
- **Input**: Using the Web Audio API and getUserMedia, you can capture
  microphone input.  Frequency analysis (e.g., via FFT) allows detection of
  which frequency is present, enabling FSK demodulation in JavaScript.

#### Example (Web Audio API):
- To output: Use an `OscillatorNode` and change its frequency for '1' and '0'.
- To input: Use `AnalyserNode` with FFT to detect the dominant frequency in the
  audio stream.