# Hardware - Computer coupling experiments

There are classic modern ways to connect a computer or phone to some hardware:
  - USB
  - Bluetooth
  - WiFi - directly, on network or via Cloud

There are also cutting edge ways to connect
  - browser based USB and Bluetooth Serial
  - IoT usually via a gateway: LoRA, Zigbee, Matter (formerly CHIP)
  - USB HID or BLE like a crypto smart key
  - phone NFC
  - etc

And all the othe weird ways
  - phone magnetometer
  - phone vibration
  - phone charging circuit
  - phone pressure sensitivity on the screen
  - LED blinking encoded data identified by camera
  - acoustic coupling - _like swipe card readers did via an audio jack_

Below are a number of experiments to do with hardware - computer coupling

## In Progress

### FSK

[fsk](./fsk/)

A modem (modulator-demodulator) is a device that converts digital signals from
devices like computers into analog signals suitable for transmission over
channels such as telephone lines or radio waves, and vice versa. This process
involves different modulation techniques. FSK (Frequency Shift Keying) is one
such technique, but there are several others used in modems.

- **FSK** (Frequency Shift Keying): FSK encodes digital data by changing the
  frequency of a carrier signal, using different frequencies to represent binary
  digits. It is simple to implement and robust against amplitude noise, but less
  bandwidth efficient than other methods and can have frequency discontinuities.
  FSK has been used in early modems and continues in applications such as
  Bluetooth (using GFSK), wireless sensor networks, and caller ID.

- **Other Modulation Formats**: Other techniques include Amplitude Shift Keying
  (ASK), which changes amplitude; Phase Shift Keying (PSK), which changes phase;
  and Quadrature Amplitude Modulation (QAM), which combines ASK and PSK for
  higher data rates. Each has advantages and disadvantages regarding complexity,
  efficiency, and susceptibility to noise.

- **Types of FSK and Variants**: FSK has several forms, including Binary FSK
  (BFSK) which uses two frequencies, Multiple FSK (MFSK) which uses multiple
  frequencies for higher data rates, Continuous-Phase FSK (CPFSK) with smooth
  phase transitions, and Gaussian FSK (GFSK) which uses filtering to improve
  spectral efficiency.

### DTMF

[dtmf](./dtmf/)

**DTMF** (Dual-Tone Multi-Frequency) is a signaling system used in
telecommunication (e.g., telephone keypads) where each key press generates a
combination of two specific audio frequencies—one from a low-frequency group and
one from a high-frequency group. Each digit or symbol is uniquely identified by
its pair of tones.

#### How DTMF Works

Basis: Each button on a DTMF keypad (0-9, *, #, A-D) produces two simultaneous
tones: one from a set of low frequencies (697, 770, 852, 941 Hz) and one from a
set of high frequencies (1209, 1336, 1477, 1633 Hz). Transmission: When a key is
pressed, the two corresponding frequencies are played together, allowing the
receiver to decode which key was pressed by detecting both frequencies.

#### DTMF with Electronics Hardware

**Output**: Microcontrollers can generate DTMF by outputting two sine waves
simultaneously (using PWM, DAC, or external DTMF generator ICs like the MT8870
or HT9200).

**Input**: DTMF tones can be detected using dedicated decoder ICs (like MT8870)
or by sampling audio with an ADC and performing a frequency analysis (e.g.,
Goertzel algorithm) in software.

#### DTMF in Web Pages (HTML/JS Sound APIs)

**Output**: The Web Audio API can generate two sine waves at the required DTMF
frequencies and play them together when a button is pressed on a virtual keypad.

**Input**: Using the Web Audio API and getUserMedia, you can capture microphone
input and analyze the audio stream (using FFT or Goertzel algorithm in
JavaScript) to detect which two frequencies are present, thus decoding the DTMF
key.

---

## Future Ideas

### 🧠 Edge AI Integration (On-Device Inference + Cloud Trigger)

**What**: Connect microcontrollers with AI accelerators (e.g., ESP32-S3 with
NPU, or RP2040 + Edge Impulse) to phones/computers for AI-driven I/O.

Why it's leading edge: On-device processing → Only insights are sent.

**How**: Run inference on-device (e.g., keyword spotting, gesture detection)
Trigger BLE/Wi-Fi events to phone/computer/cloud Example: ESP32-S3 listens for
specific gestures → triggers webhook on mobile.

### 📶 Matter (formerly CHIP) for IoT + Phone Integration

**What**: An emerging smart home standard supported by Apple, Google, Amazon,
and open-source platforms.

Why it's leading edge: Native integration with phone OS without proprietary
ecosystems.

**How**: Devices using ESP32, nRF5340, or Silicon Labs chips can speak Matter
over Wi-Fi, Thread, or BLE.

**Example**: A DIY light switch works natively with iPhone’s Home app without
needing HomeKit certification.

### 🛰️ LoRa + Mobile Gateway (Phone as Gateway)

**What**: Use the phone’s Bluetooth/Wi-Fi as a bridge for long-range, low-power
LoRa devices.

Why it's leading edge: DIY sensors can now connect globally via a phone in your pocket.

**How**:
- LoRa device → BLE → Mobile app → Cloud

**Example**: A soil moisture sensor in a remote field sends LoRa data to a
hiker’s phone, which uploads to a dashboard.

### 🔐 Passkeys & Cryptographic Tokens via Microcontrollers

**What**: DIY device acts as a secure authenticator using FIDO2/WebAuthn.

Why it's leading edge: DIY hardware tokens for 2FA and login (like Yubikey, but DIY).

**How**: Use RP2040, nRF52, or STM32 with USB HID or BLE.

**Example**: A custom-built keychain with fingerprint scanner logs you into Google securely.

### 🧲 Magnetic Field Communication / Magnetometers

**What**: Use magnetometers in phones and controlled magnetic pulses to send
info (silent, invisible).

Why it's leading edge: No RF needed, works in shielded environments.

**How**: Magnetic pulses encoded as binary → detected by phone’s compass sensor.

**Example**: A badge broadcasts presence to phone via subtle magnetic pulses.

### 🎥 7. Camera-Driven Interfaces (Visual Modulation)

**What**: Communicate via patterns of blinking lights, color shifts, or QR
sequences.

Why it's leading edge: Phones are good at seeing, even if they can't connect.

**How**: LED blinks encode data → phone camera reads (Li-Fi-like).

**Example**: Device shows “blinking QR” status that mobile app decodes.

### 🛠️ Hardware Supporting Leading-Edge Methods

Platform    | Leading Feature
============|===============================================
ESP32-S3    | BLE + USB + Edge AI (vector instructions)
RP2040      | USB + PIO (programmable I/O) + great community
nRF5340     | BLE 5.3 + Thread + Matter + low power
Teensy 4.1  | USB HS, Audio, Ethernet, HID tricks

#### TL;DR – Top 5 Leading-Edge DIY Interfaces in 2025:

Tech                              | What it enables        | Why it matters
==================================|========================|=============================
Web Bluetooth/USB                 | Direct browser control | No installs
Matter                            | Native smart home      | Works with iOS/Android directly
On-device AI (Edge Impulse, etc.) | Smarter sensors        | Only actionable data sent
LoRa + Phone as gateway           | Remote sensing         | Low power + global reach
Camera/light/magnetic tricks      | No RF, no pairing      | Pure creativity

---

_from another prompt, might have some repeats_

### 🔗 1. Web Serial / WebUSB / WebBluetooth (Direct Browser Access)

**What it is**:
Use Chrome/Edge browsers to directly communicate with microcontrollers via USB,
serial, or BLE.

Why it’s leading-edge:
Eliminates the need for apps or drivers.

Enables real-time dashboards, programming tools, and interfaces right in the browser.

**Example:**
Flash firmware to an ESP32 from a browser.

Stream sensor data live to a web dashboard.

### 📶 2. Wi-Fi + WebSockets / MQTT over TLS

**What it is**:
Secure bi-directional communication using MQTT or WebSockets over Wi-Fi.

Why it’s cutting-edge:
Enables cloud-native DIY devices with secure and fast messaging.

MQTT is ideal for smart home or industrial IoT.

**Example**:
ESP32 connects to an MQTT broker (e.g., Mosquitto, AWS IoT) and is controlled
via a phone app or web interface.

### 🌐 3. Matter (Connected Home over IP)

**What it is**:
A smart home standard backed by Apple, Google, Amazon, etc.

Why it’s leading:
Your DIY device (using ESP32 or Nordic nRF chip) can now natively join smart
home ecosystems like Apple Home, Google Home, etc.

Requires secure onboarding and local network control.

**Example**:
DIY light switch, thermostat, or sensor that's automatically detected by a Home
app.

### 📱 4. BLE + GATT over Web Bluetooth

**What it is**:
Connect to BLE DIY devices via browser without needing an app.

Why it’s powerful:
Works across platforms (Android, Chromebooks, desktops).

No app install = frictionless.

**Example**:
BLE heart rate sensor logs to web app or mobile site directly.

### 🧠 5. AI-on-the-Edge + Cloud Sync (TinyML + EdgeTPU)

**What it is**:
Devices like ESP32-S3 or Raspberry Pi + Google Edge TPU doing on-device AI
inference, then syncing with cloud services or apps.

Why it’s advanced:
Adds intelligence to interfacing.

Syncs actionable insights rather than raw data.

Edge AI + Cloud APIs = efficient hybrid interaction.

**Example**:
DIY camera that detects emotion or gestures and logs data to
Firebase/ThingSpeak.

### 🛰️ 6. Satellite IoT (Swarm, Lacuna, etc.)

**What it is**:
Very low-bandwidth global communication via small satellites (e.g., Swarm by
SpaceX).

Why it’s frontier tech:
Enables DIY remote tracking, sensor networks, or emergency systems with no
ground infrastructure needed.

**Example**:
Remote environmental sensor sends data via LoRa to a satellite, viewable via
cloud dashboard.

### 🔋 7. NFC Tap + Web App

**What it is**:
Tap your phone to a passive NFC tag (or an NFC-enabled microcontroller), which
opens a web app or shares data.

Why it’s modern:
No power required (for tags), and NFC is widely supported in Android and newer
iPhones.

Good for access control, provisioning, product info, etc.

**Example**:
NFC tag in DIY business card or device opens a config page when tapped.

### 🕸️ 8. Mesh Networking (BLE Mesh / Thread)

**What it is**:
DIY devices communicate with each other over a mesh, not just point-to-point.

Why it’s forward-looking:
Scalable, self-healing networks for smart environments.

Thread is a base layer of Matter.

**Example**:
BLE Mesh lighting system controlled by a phone via one node.

### 🛜 9. WebRTC + P2P Control

**What it is**:
Direct peer-to-peer communication using WebRTC.

Why it’s innovative:
Allows real-time video/audio/control streaming from microcontrollers (like
ESP32-CAM) without needing a server.

**Example**:
Control a robot remotely from a browser with live video and low latency.

### 🔒 10. Secure Element Chips + App Pairing

**What it is**:
Using chips like ATECC608A to securely pair with a mobile app or computer.

Why it’s next-gen:
Cryptographic security and identity verification at hardware level for DIY
devices.

Crucial for secure IoT and blockchain integration.

**Example**:
DIY crypto wallet or secure access control unit.

more:
- 🧬 Brain-Computer Interface (using OpenBCI)
- 🐝 Haptic interfaces (with vibration motors to send signals you "feel")
- 📸 Gesture recognition via camera and ML
- 🗣️ Voice-to-Microcontroller via streaming Google STT → ESP over MQTT

Or simply cutting edge things to connect to
- use BLE/WiFi to connect to Edge AI integrations

## Other unorganised

And there are all the other ways to do it. This is a look at showing different
ways to connect.

### 1. Wired Communication Methods (Conventional)

#### A. Serial Communication USB (Universal Serial Bus)

Via USB-to-Serial adapters (e.g., FTDI, CH340)

Common with Arduino, ESP32, Raspberry Pi Pico

UART (Universal Asynchronous Receiver-Transmitter)

- TTL logic (+5v)
- RS232 (-15-3v – 3-15v)

Directly to a PC (via USB adapter) or to another microcontroller

SPI (Serial Peripheral Interface)

For high-speed interfacing with peripherals (less common directly to PC)

I2C (Inter-Integrated Circuit)

Used between microcontrollers/sensors, sometimes with USB bridges

#### B. Audio Jack Communication

Older phones supported data-over-audio, like:

DHT11/22 data via audio

FSK modulation (like 300 baud audio modems)

#### C. Ethernet / LAN

Microcontrollers like ESP32, Teensy 4.1, or with Ethernet shields

Used for TCP/IP, HTTP, MQTT communication

## 2. Wireless Communication Methods (Conventional)

#### A. Bluetooth / BLE
Bluetooth Classic for audio/serial

Bluetooth Low Energy (BLE) for sensor data (e.g., nRF52, ESP32)

Used with mobile apps or PC applications

#### B. Wi-Fi

Via ESP8266, ESP32, Raspberry Pi

Use HTTP, WebSockets, MQTT, or TCP/UDP protocols

Control via web browsers, mobile apps, or Python servers

#### C. NFC (Near-Field Communication)

Short-range, used in Android phones

Modules: PN532, RC522

Communicate with phones or read/write tags

#### D. Infrared (IR)

IR transceivers to send/receive commands to/from TV remotes or phones with IR
blasters (older Androids)

#### E. Zigbee / LoRa / Sub-GHz RF
Not direct to phones/computers, but via gateway devices

E.g., LoRa → LoRa Gateway → Internet → Phone

### 3. Unconventional / Creative Methods

#### A. HID Emulation (Human Interface Device)
Microcontrollers like Teensy or Arduino Leonardo can act as:

Keyboards (send keystrokes)

Mice

Game controllers

#### B. MIDI over USB

Some microcontrollers can send MIDI signals over USB, interfacing with DAWs or
music apps

#### C. Wi-Fi to Web or REST APIs

DIY electronics serve a web page or expose a REST API

Access via phone/computer browser

#### D. QR Code Display or Generation

Microcontroller outputs data via a displayed QR code → scanned by phone

Or vice versa: phone displays QR → read by camera module (e.g. OpenMV)

#### E. Light / Color / Camera Detection

Send data using blinking LEDs, read by phone camera (e.g., Li-Fi-like)

Color sensors on microcontrollers detect screen flashes

#### F. Capacitive Sensing (Touchscreen Tricks)

Use conductive material to "touch" a smartphone screen in a controlled way
(like capacitive styluses)

Rare, but seen in novelty devices

#### G. Vibration / Accelerometer Input

Phone detects vibration patterns generated by a device

Or microcontroller reacts to phone movement (if mounted together)

### 4. Software-Based Interfaces

#### A. Custom Apps

Android: MIT App Inventor, Kivy, or Flutter to create a UI

iOS: Xcode/Swift (less friendly for DIY)

#### B. Terminal Interfaces

Serial console using tools like PuTTY, CoolTerm, screen, or Arduino Serial
Monitor

#### C. Web Dashboards

Microcontroller hosts a webpage, or sends data to a dashboard (e.g., Blynk,
ThingSpeak, Node-RED, Grafana)

#### D. Voice Assistants

Indirect interface via Alexa/Google Home through IFTTT or custom skills

#### E. File-based Communication

Device appears as USB Mass Storage, reads/writes files the computer/mobile
later accesses

#### 5. Physical Interfaces

A. GPIO to GPIO
Interfacing directly with Raspberry Pi, using GPIO pins for signaling

#### B. Sensor Triggers

Light sensors, magnetic reed switches, etc., trigger microcontroller to take
actions based on environment (then log/report to phone/PC)

### Summary Table

Method           | Direction | Platform(s)            | Complexity | Notes
=================|===========|========================|============|==========================
USB Serial       | Both      | PC                     | Low        | Most common with Arduinos
BLE              | Both      | Mobile                 | Medium     | Native in ESP32, nRF52840
Wi-Fi            | Both      | PC/Mobile (Browser)    | Medium     | Supports many protocols
HID Emulation    | To PC     | PC                     | Medium     | Acts like keyboard/mouse
NFC              | To/from   | Mobile Mobile          | Medium     | Phone acts as tag reader
QR Code          | From      | Device Mobile          | Low        | No connection needed
IR               | Both      | Phone (with IR)        | Low        | Infrared remote control
Audio Jack       | Both      | Mobile/PC (old)        | High       | Rare, retro hobby use
Capacitive Touch | To Mobile | Mobile                 | High       | Hacky but fun
Voice Assistant  | Indirect  | Cloud / Home Assistant | Medium     | Smart home integration

