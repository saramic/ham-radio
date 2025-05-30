# NOTES

## Fri 30 May 2025

### The Forrest Mims Circuit Scrapbook Volume I

Started reading this and am amazed at the cool approach of "analog comuters" the idea of addition, multiplication and the use of Logs like in a slide rule. A chips of interest showed up, not all of them that easy to get.
- `AD534` IC trimmed multiplier
    - https://www.digikey.com.au/en/products/detail/analog-devices-inc/AD534JD/611754
    - no longer available and was quite expensive
    - https://www.digikey.com.au/en/products/detail/analog-devices-inc/AD534LDZ/1812550
        - $399.11
    - ALTERANTIVE might be the AD633 - low cost analog multiplier
        - https://www.digikey.com.au/en/products/detail/analog-devices-inc/AD633ANZ/750990
        - $31.45 still not too cheap
    - looking at other ALTERNATIVES
        - https://www.digikey.com.au/en/products/filter/linear/analog-multipliers-dividers/772
        - like the GT4123BCDA which is $6 but can only be bought in bulk (x85)
    - more on Analog Multipliers -
      https://en.wikipedia.org/wiki/Analog_multiplier
- `4066` is a standard CMOS Quad Bilateral switch
    - https://www.digikey.com.au/en/products/detail/texas-instruments/CD4066BE/67313
    - $1.19
- `CA3130` BiMOS Op Amp
    - the CA3130 BiMos Op-Amp Linear IC is on clearance at Jaycar at $6.95
    - https://www.jaycar.com.au/ca3130-bimos-op-amp-linear-ic/p/ZL3860
- `TC9400` Voltage to Frequency Converter
    - is also super expensive $14 per unit but bulk (x57)
    - https://au.rs-online.com/web/p/voltage-to-frequency-frequency-to-voltage-converters/1779688
    - ALTERNATIVE LM331 - $6.63
    - https://www.digikey.com.au/en/products/detail/texas-instruments/LM331N-NOPB/6213
    - LMx31x Precision Voltage-to-Frequency Converters
- 2688/MM5837 Noise Generator
    - https://www.analog.com/en/resources/design-notes/building-a-lowcost-whitenoise-generator.html
        - using a MAX2650 DC-to-Microwave, +5V Low-Noise Amplifier
            - https://www.analog.com/en/products/max2650.html
    - also via
      https://www.schematicsforfree.com/files/Oscillators%20and%20Generators/Pink-White%20%26%20Other%20Noise%20Generators/Pink%20%26%20White%20Noise%20Generators%20-%20Misc.pdf
        - [assets/pdfs/Pink_and_White_Noise_Generators.pdf](
          ./assets/pdfs/Pink_and_White_Noise_Generators.pdf)
    - and
      https://schematicsforfree.com/files/Audio/Circuits/Musician/Misc/Circuits/Mm5837N%20Noise%20Generator%20Applications.pdf
        - [assets/pdfs/Mm5837N_Noise_Generator_Applications.pdf](
          assets/pdfs/Mm5837N_Noise_Generator_Applications.pdf)

## Mon 19 May 2025

### Electronics series

The idea is to come up with an electronics series of ideas to feed a bunch of
consecutive videos. One is Arduino vs WebApp -
https://github.com/failure-driven/arduino-vs-web-app. Another might be
"Interfacing Electronics with Computers and Phones". I had a bit of a think
coming up with the following:

- Serial RS232
- USB serial
- BLE (Bluetooth Low Energy)
- WiFi
- Acousting coupling - sound card
- Sound card - direct connection
- Image pixel - light coupling - _how fast can this work? what is the detector?
  what is used in things like a "toslink" opt copuled sound_
- serial via USB-C, 433Mhz modula, LoRa
- QR Codes
- Google Chrome direct to serial connectivity

Later I asked ChatGPT and got some more ideas:

**Wired Communication Methods (Conventional)**

- **Serial Communication**
  - **USB** (Universal Serial Bus)
    - Via USB-to-Serial adapters (e.g., FTDI, CH340)
    - Common with Arduino, ESP32, Raspberry Pi Pico
  - **UART** (Universal Asynchronous Receiver-Transmitter)
    - Directly to a PC (via USB adapter) or to another microcontroller
  - **SPI** (Serial Peripheral Interface)
    - For high-speed interfacing with peripherals (less common directly to PC)
  - **I2C** (Inter-Integrated Circuit)
    - Used between microcontrollers/sensors, sometimes with USB bridges
- **Audio Jack Communication**
  - Older phones supported data-over-audio, like:
    - DHT11/22 data via audio
    - FSK modulation (like 300 baud audio modems)
**Ethernet / LAN**
  - Microcontrollers like ESP32, Teensy 4.1, or with Ethernet shields
  - Used for TCP/IP, HTTP, MQTT communication

**Wireless Communication Methods (Conventional)**

- **Bluetooth / BLE**
  - Bluetooth Classic for audio/serial
  - Bluetooth Low Energy (BLE) for sensor data (e.g., nRF52, ESP32)
  - Used with mobile apps or PC applications
- **Wi-Fi**
  - Via ESP8266, ESP32, Raspberry Pi
  - Use HTTP, WebSockets, MQTT, or TCP/UDP protocols
  - Control via web browsers, mobile apps, or Python servers
- **NFC (Near-Field Communication)**
  - Short-range, used in Android phones
  - Modules: PN532, RC522
  - Communicate with phones or read/write tags
- ((Infrared (IR)**
  - IR transceivers to send/receive commands to/from TV remotes or phones with
    IR blasters (older Androids)
- **Zigbee / LoRa / Sub-GHz RF**
  - Not direct to phones/computers, but via gateway devices E.g., LoRa → LoRa
    Gateway → Internet → Phone

**Unconventional / Creative Methods**

- HID Emulation (Human Interface Device)
  - Microcontrollers like Teensy or Arduino Leonardo can act as:
    - Keyboards (send keystrokes)
    - Mice
    - Game controllers
- MIDI over USB
  - Some microcontrollers can send MIDI signals over USB, interfacing with DAWs
    or music apps
- Wi-Fi to Web or REST APIs
  - DIY electronics serve a web page or expose a REST API
  - Access via phone/computer browser
- QR Code Display or Generation
  - Microcontroller outputs data via a displayed QR code → scanned by phone
  - Or vice versa: phone displays QR → read by camera module (e.g. OpenMV)
- Light / Color / Camera Detection
  - Send data using blinking LEDs, read by phone camera (e.g., Li-Fi-like)
  - Color sensors on microcontrollers detect screen flashes
- Capacitive Sensing (Touchscreen Tricks)
  - Use conductive material to "touch" a smartphone screen in a controlled way
    (like capacitive styluses)
  - Rare, but seen in novelty devices
- Vibration / Accelerometer Input
  - Phone detects vibration patterns generated by a device
  - Or microcontroller reacts to phone movement (if mounted together)

**Software-Based Interfaces**

- Custom Apps
  - Android: MIT App Inventor, Kivy, or Flutter to create a UI
  - iOS: Xcode/Swift (less friendly for DIY)
- Terminal Interfaces
  - Serial console using tools like PuTTY, CoolTerm, screen, or Arduino Serial
    Monitor
- Web Dashboards
  - Microcontroller hosts a webpage, or sends data to a dashboard (e.g., Blynk,
    ThingSpeak, Node-RED, Grafana)
- Voice Assistants
  - Indirect interface via Alexa/Google Home through IFTTT or custom skills
- File-based Communication
  - Device appears as USB Mass Storage, reads/writes files the computer/mobile
    later accesses
- Physical Interfaces
  - GPIO to GPIO
  - Interfacing directly with Raspberry Pi, using GPIO pins for signaling
- Sensor Triggers
  - Light sensors, magnetic reed switches, etc., trigger microcontroller to
    take actions based on environment (then log/report to phone/PC)

**Summary Table**

| Method            | Direction         | Platform(s)               | Complexity    | Notes     |
| ----------------- | ----------------- | ------------------------- | ------------- | --------- |
| USB Serial        | Both              | PC                        | Low           | Most common with Arduinos |
| BLE               | Both              | Mobile                    | Medium        | Native in ESP32, nRF52840 |
| Wi-Fi             | Both              | PC/Mobile (Browser)       | Medium        | Supports many protocols |
| HID Emulation     | To PC             | PC                        | Medium        | Acts like keyboard/mouse |
| NFC               | To/from Mobile    | Mobile                    | Medium        | Phone acts as tag reader |
| QR Code           | From Device       | Mobile                    | Low           | No connection needed |
| IR                | Both              | Phone (with IR)           | Low           | Infrared remote control |
| Audio Jack        | Both              | Mobile/PC (old)           | High          | Rare, retro hobby use |
| Capacitive Touch  | To Mobile         | Mobile                    | High          | Hacky but fun |
| Voice Assistant   | Indirect          | Cloud / Home Assistant    | Medium        | Smart home integration |

### In Blog

- LM3914
- Microphone Pre-amp
- Function generator
- Test equipment
  - FNIRSI DPS-150

### Rolling codes

- **Rolling Codes Explained part 2. I hacked my own garage door #flipperzero
  TechAndFun**
  [![
    Rolling Codes Explained part 2. I hacked my own garage door #flipperzero
    TechAndFun
  ](
    http://img.youtube.com/vi/PJvdIrY6aJY/0.jpg
  )](https://youtu.be/PJvdIrY6aJY)
- [ ]
  https://www.itstactical.com/intellicom/physical-security/how-to-hack-a-garage-door-in-under-10-seconds-and-what-you-can-do-about-it/
- [ ]
  https://www.wired.com/2015/06/hacked-kids-toy-opens-garage-doors-seconds/
- [ ] **OpenSesame - hacking garages in seconds using a Mattel toy - samy
  kamkar**
  [![
    OpenSesame - hacking garages in seconds using a Mattel toy - samy kamkar
  ](
    http://img.youtube.com/vi/iSSRaIU9_Vc/0.jpg
  )](https://youtu.be/iSSRaIU9_Vc)

### Metal detectors

Talked about previously, here are some more ideas, and so I don't loose the
idea of building one. In fact I believe I found a coil body detector in one of
the circuits in [Encyclopedia of Electronic Circuits II](
https://hardwarecomputerist.atariverse.com/pages/resource/resource.general.htm)
but can't seem to find it again. Some more Metal detector inspiration:

- [ ] https://www.instructables.com/Simple-Arduino-Metal-Detector/
- [ ] https://forum.arduino.cc/t/metal-detector-with-arduino/1170539
- Arduino Nano Pulse Induction Metal Detector Project - George Overton
    book with poor reviews
    - https://www.amazon.com.au/Arduino-Pulse-Induction-Detector-Project/dp/B08YQCNSNX
    - https://www.abebooks.com/9780985834203/Metal-Detector-First-In-depth-Book-098583420X/plp
- simple metal detector kit
    - https://www.aliexpress.com/item/1005006391384737.html
      Metal Detector Kit Electronic Kit JS-60 MDS-60 DIY Kit DC 3V-5V 60mm
      Non-contact Sensor Board Module DIY Electronic Part Metal D
    - https://www.aliexpress.com/item/1005008665979941.html DC3-5V Handheld
      Simple Metal Detector Electronic Kit DIY Metal Detector Kit DIY
      Technology Training Welding Metal Detector
- talking electronics
  - https://www.talkingelectronics.com/projects/200TrCcts/MetalDetectors/MetalDetectors-1.html
  - [ ] good resource to have handy

### Radio

- https://github.com/egzumer/uv-k5-firmware-custom

### Home intercom

- https://github.com/AussieMakerGeek/esp32-Multi-room-intercom
- https://www.reddit.com/r/arduino/comments/15nxasl/esp32s_as_intercom_receivers/
- 2Pcs ESP32 SX1276 LoRa 868MHz bluetooth WI-FI Lora Intercom Antenna
  Development Board
  https://www.kogan.com/au/buy/dsport-2pcs-esp32-sx1276-lora-868mhz-bluetooth-wi-fi-lora-intercom-antenna-development-board-bg00006054-868mhz-2pcs/
- DIY In House Wireless Walkie Talkie - Voice Intercom Adventure
  https://community.home-assistant.io/t/diy-in-house-wireless-walkie-talkie-voice-intercom-adventure/496935
- ESP32 Walkie-Talkie It's a Walkie-Talkie based around the ESP32. It transmits
  audio using either UDP Broadcast or ESP-NOW.
  https://hackaday.io/project/178819-esp32-walkie-talkie
- https://www.aliexpress.com/w/wholesale-esp32-intercom.html
- https://community.home-assistant.io/t/diy-2-way-audio-doorbell-intercom/634581
- https://www.elektormagazine.com/articles/diy-walkie-talkie-based-on-esp-now
- https://github.com/pschatzmann/arduino-audio-tools/discussions/1620
- A DIY Smart Doorbell based on ESP32 Smart Solutions for Home
  https://www.youtube.com/watch?v=P4HT_PlZKZg
- ESP32 Walkie-Talkie: DIY Audio Magic atomic14
  https://www.youtube.com/watch?v=d_h38X4_eQQ
- ESP32 Audio Video Intercom Half Greek Geek
  https://www.youtube.com/watch?v=bu97tXM_FbI
- Building a Digital Music Player with I2S?! What is I2S! EB#45 GreatScott!
  https://www.youtube.com/watch?v=qNLvoSQCx60
- https://www.reddit.com/r/arduino/comments/15nxasl/esp32s_as_intercom_receivers/
- https://github.com/AussieMakerGeek/esp32-Multi-room-intercom
- Severance Inspired Bluetooth Speaker #3DPrinting Adafruit Industries
  https://www.youtube.com/watch?v=togv3JSCk14
- I Built Severance’s Speaker – And It Actually Works! Creative Geekery
  https://www.youtube.com/watch?v=PEY1XBFXKp0
- https://www.reddit.com/r/SeveranceAppleTVPlus/comments/1izufjn/made_the_board_speaker_for_my_google_home/
- https://www.therpf.com/forums/threads/severance-speaker-intercom-build.360092/page-2

### Document camera

- Ultra High Definition 8MP USB Document Camera — Mac OS, Windows, Chromebook
  Compatible
  https://www.amazon.com.au/IPEVO-5-880-4-01-00-Definition-Document-Camera/dp/B079DLTG9F
- 4K Digital Microscope 48MP Microscope For Electronics USB-C Industrial
  Cameras HDMI 1-150X Zoom C-Mount Lens Phone Pcb Soldering
  https://www.aliexpress.com/item/1005007543100185.html

### Score board

- https://www.instructables.com/Laserweld-Your-Own-Inflatables/
- https://hackaday.com/2019/04/02/custom-inflatables-are-only-a-laser-beam-away/
- https://arenachamp.com/

### Hackberry

- https://www.elecrow.com/colorberry.html
- https://rootkitlabs.com/

### Art

- https://www.instructables.com/Gimbal-Clock/
