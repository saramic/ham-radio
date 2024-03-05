---
layout: post
title:  "More Videos, more Transciever boards"
date:   2024-03-05 23:59:59 +1100
categories: codec2 SM1000 FreeDV APRS RFM69 packet radio
---

### Codec2
started watching "David Rowe presents on codec2 and SM1000"
[![
  David Rowe presents on codec2 and SM1000 - Peter Marks
](
  http://img.youtube.com/vi/MxqdGL8QfIA/0.jpg
)](https://youtu.be/MxqdGL8QfIA)

- quite interesting on how voice is borkend down by sine waves, how you can
  have 2 kinds of encodings AAA and BBB and how the bits are brokend up to
  encode voice
  
  **Bit Allocation**
  * 52 bits per 40ms frame, or 1,300 bit/s

  | Parameter    | Bits/Frame |
  |--------------|-----------:|
  | Amplitudes   |         36 |
  | Frame Energy |          5 |
  | Voicing      |          4 |
  | Pitch        |          7 |
  |--------------|-----------:|
  | Total        |         52 |

- also sound demos between this and a bunch of other formats
- [https://freedv.org/](https://freedv.org/) fro more on the codec.
- which you can run on a computer
- or via the SM1000
  - probably up to [https://youtu.be/MxqdGL8QfIA?t=1464](https://youtu.be/MxqdGL8QfIA?t=1464)
- also uses **STM32F4** which sounds like a good thing for up power from an arduino
    - [https://core-electronics.com.au/stm32f411-blackpill-development-board-49034.html](https://core-electronics.com.au/stm32f411-blackpill-development-board-49034.html)
    - more of a professional board

    ![](https://core-electronics.com.au/media/wysiwyg/product_images/DFR0864-Pinout-Diagram.jpg)

- at the end he mentions an OpenRadio SDR kit that seems to be offline these days.
  - a good write up [https://blog.marxy.org/2015/01/openradio-sdr-kit-build.html](https://blog.marxy.org/2015/01/openradio-sdr-kit-build.html)
    - original url - http://openradio.net.au/index.php/Main_Page
        [https://web.archive.org/web/20160302125731/http://openradio.net.au/index.php/Main_Page](https://web.archive.org/web/20160302125731/http://openradio.net.au/index.php/Main_Page)
    - construction guide [https://web.archive.org/web/20160306200642/http://openradio.net.au/index.php/Construction_Guide_V2](https://web.archive.org/web/20160306200642/http://openradio.net.au/index.php/Construction_Guide_V2)
    - although there might still be some luck finding something similar when
      searching for "sdr radio kits"
      - https://www.sdr-kits.net/

### All the Transciever options

#### APRS packet radio decoding

- saw this on [Instagram: gridbasedotnet - How I run APRS for grid down comms
  at all times](https://www.instagram.com/p/C28QxvqrLEZ)
  - connect standard radio with something like a DigiRig sound card [VHF/UHF
    Digital Modes with budget
    HTs](https://digirig.net/vhf-uhf-digital-modes-with-budget-hts/)
    - not end-to-end digital systems such as DMR, D-star and Fusion.
    - but ability to connect computer bits and bytest to analog radio beeps and
      boops whilst running a computer or RasPi with Winlink, WSJT-X, JS8Call,
      Fldigi, SSTV/Yoniq etc
      - there sounds like there also used to be [QTMM archived on
        GitHub](https://github.com/csete/qtmm)
        > An obsolete AFSK1200 decoder that uses the soundcard as input device.
  - process through Dire Wolf
    [https://github.com/wb2osz/direwolf](https://github.com/wb2osz/direwolf)
    > Dire Wolf is a software "soundcard" AX.25 packet modem/TNC and APRS
    > encoder/decoder. It can be used stand-alone to observe APRS traffic, as a
    > tracker, digipeater, APRStt gateway, or Internet Gateway (IGate).
  - feed the APRS to YAAC "Yet Another APRS Client"
    [https://www.ka2ddo.org/ka2ddo/YAAC.html](https://www.ka2ddo.org/ka2ddo/YAAC.html)
  - ultimately getting location data and ability to message between nodes

#### LoRa LilyGo T-Bone

- which kind of sounds like my LilyGo T-Bone LoRa radios

#### 433MHz

- or could be something some cheap 433MHz TX/RX boards would want to do

#### Zigbee

- or maybe a zigbee mesh - where I just got some controllers today

#### RFM69

- and if I search for Arduino and PacketRadio I quickly come across `RFM69`
  - which quickly took me to [Adafruit Feather M0 Radio with RFM69 Packet
    Radio](https://learn.adafruit.com/adafruit-feather-m0-radio-with-rfm69-packet-radio/overview)
  - and of course [https://lowpowerlab.com/](https://lowpowerlab.com/)
    - the creators of the library
      [https://github.com/LowPowerLab/rfM69/](https://github.com/LowPowerLab/rfM69/)
    - have a bunch of relevant stuff in their store to build stuff like
      ![Tx Power Tests
      Setup](https://lowpowerlab.com/wp-content/uploads/2021/08/RFM69_HCW_Tx_Power_Tests_Setup.jpg)
    - seem to have an Arduino like clone - [Moteino
      M0](https://lowpowerlab.com/shop/product/184)
    - an [RFGateway (M4)](https://lowpowerlab.com/shop/product/196)
    - and yet another video to watch
      **RF Range Testing a concrete building application - Felix Rusu**
      [![
        RF Range Testing a concrete building application - Felix Rusu
      ](
        http://img.youtube.com/vi/8LS8Q-2GxPs/0.jpg
      )](https://youtu.be/8LS8Q-2GxPs)
    - and ofcourse a bunch of **RFM69CW** transcievers for ~$6
        - 433MHz, 868-915MHz, LoRa - so it sounds like it is a base for various
          frequencies? - ofcourse these are licence free bands and limited to
          100mW
        - [RFM69CW](https://lowpowerlab.com/shop/category/73)

          ![RFM69CW
          433](https://lowpowerlab.com/shop/image/cache/data/transceivers/RFM69CW_433-500x375.jpg)

#### WiFi

- Then ofcourse ESP32 let's you do WiFi
    - [https://github.com/jasoncoon/esp32-fastled-webserver](https://github.com/jasoncoon/esp32-fastled-webserver)

### Another Yagi tape measure build

**How to Make an Incredible DIY Directional Antenna for Almost Nothing - The
Modern Rogue**

[![
  How to Make an Incredible DIY Directional Antenna for Almost Nothing - The
  Modern Rogue
](
  http://img.youtube.com/vi/1nHPbWPUYzk/0.jpg
)](https://youtu.be/1nHPbWPUYzk)

this one kind of was nice to hear a bunch of stuff that seems not obvious like
does the boom have to be metal or not? all the pro ones are metal and the home
brew seem not to be? but I guess it is in the direction of the RF so maybe it
does not matter? still I feel I need to read the ARRL antenna handbook again to
know exactly what and why. Also there was no mention of where the Yagi
calculations came from, a website calculator no doubt? and finally there is no
mention of how close or far the driven beams should be where they are at their
closest? what differenc does it make? oh and throwing in a "hairpin" wire to be
the matching wire? that seems random.

**DIY Yagi Antenna from Tape Measure - Becky Stern**

[![
  DIY Yagi Antenna from Tape Measure - Becky Stern
](
  http://img.youtube.com/vi/yDxv5z3iuv4/0.jpg
)](https://youtu.be/yDxv5z3iuv4)

really nice build with 3D printed parts and some clever joining mechanism,
still no mention of why the haripin is needed and what it does
- uses [CubicSDR cubicsdr.com](https://cubicsdr.com/)
  - [https://github.com/cjcliffe/CubicSDR](https://github.com/cjcliffe/CubicSDR)
  > Cross-Platform Software-Defined Radio Application www.cubicsdr.com
- also using a NanoVNA to try to tune it

and a bunch more videos

**Make Your Own Aircraft Tracking Antenna With RTL SDR - Tech Minds**

[![
  Make Your Own Aircraft Tracking Antenna With RTL SDR - Tech Minds
](
  http://img.youtube.com/vi/TZaENuE_qu8/0.jpg
)](https://youtu.be/TZaENuE_qu8)

- pretty run of the mill and basic
- but gives confidence
- calculator
  [https://m0ukd.com/calculators/quarter-wave-ground-plane-antenna-calculator/](https://m0ukd.com/calculators/quarter-wave-ground-plane-antenna-calculator/)
- uses software [RTL1090](https://rtl1090.com/)
- use of a [Nooelec SAWbird+
  ADS-B](https://www.nooelec.com/store/sawbird-plus-adsb.html) filter
- compares to a pro antenna and reciver and not much in it

**How to make a 2 meter band tape antenna: Lightweight, portable, fun project
for ham radio - Ham Radio Rookie**

[![
  How to make a 2 meter band tape antenna: Lightweight, portable, fun project for ham radio - Ham Radio Rookie
](
  http://img.youtube.com/vi/d5itl1uWGtU/0.jpg
)](https://youtu.be/d5itl1uWGtU)

- mentions inspiration by John Portune - W6NBC
- the idea is to use copper tape to make antennas
- you can easily extend the antenna by adding more copper tape
- using magnets either side to move connector around

**Building A Directional Yagi Antenna for 144 VHF or 433 UHF Amature Radio! -
Concentric Machining**

[![
  Building A Directional Yagi Antenna for 144 VHF or 433 UHF Amature Radio! - Concentric Machining
](
  http://img.youtube.com/vi/oxbjPXNOey4/0.jpg
)](https://youtu.be/oxbjPXNOey4)

- calculator [https://www.changpuak.ch/electronics/yagi_uda_antenna_DL6WU.php](https://www.changpuak.ch/electronics/yagi_uda_antenna_DL6WU.php)
- reflector needs to be grounded - not sure I have heard that before
- hitting copper tube between vice grips and vice to straighten, just bang it
  with a hammer 5 times
- dipole split needs to count to the length of the dipole, ie less metal how
  much the gap, in this casde 1/4 inch
- grouding the entire beam
- way too long a build - and boring


**Cubical Quad Antenna, is this the best directional antenna? - KK6USY Ham
Radio Adventures**

[![
  Cubical Quad Antenna, is this the best directional antenna? - KK6USY Ham Radio Adventures
](
  http://img.youtube.com/vi/E6O6IrLc1kY/0.jpg
)](https://youtu.be/E6O6IrLc1kY)

- difficult build
- lot's of 3D
- calculator
  [https://www.pasty.com/~ccraa/antennas/Cubical-Quad1.htm](https://www.pasty.com/~ccraa/antennas/Cubical-Quad1.htm)
  - seems to be all JS, maybe time to downlaod it as not sure how long it will
    last
  - in fact quite an interesting listing via google
    - [https://www.google.com/search?q=site%3Apasty.com+antenna](https://www.google.com/search?q=site%3Apasty.com+antenna)
- does make me feel if creating the body with solid shapes and lay copper down

### Where to Radiosonde

seems a bunch of sondes landed around Moe/Trarallgon and were found
A bunch landed near Seymour and were not found
and Today's went to King Lake which is kind of driving distance

via [radiosondy.info startplace Melbourne
(AU)](https://radiosondy.info/sonde_table.php?startplace=Melbourne+%28AU%29&table=startplace)

| Number/Type      | Last Frame (UTC)    | lat/long/Alt            | Freq. | Nearest City    | Status  |
|------------------|---------------------|------------------------:|------:|-----------------|---------|
| U4844272 RS41    | 2024-03-05 01:28:44 | -37.4746 145.264 531 m  | 401.5 | Whittlesea (AU) | UNKNOWN |
| U4844264 RS41    | 2024-03-04 13:13:04 | -37.1845 145.058 852 m  | 401.5 | Broadford (AU)  | UNKNOWN |
| U4824680 RS41    | 2024-03-04 01:33:31 | -37.0841 145.077 1034 m | 402.5 | Seymour (AU)    | UNKNOWN |
| U4824664 RS41    | 2024-03-04 01:11:15 | -37.1065 145.064 927 m  | 401.5 | Seymour (AU)    | UNKNOWN |
|                  |                     |                         |       |                 |         |
| U4824676 RS41    | 2024-02-28 07:30:47 | -38.2341 146.434 488 m  | 401.5 | Morwell (AU)    | FOUND   |
| T0340638 RS41    | 2024-02-28 02:38:46 | -38.1968 146.035 588 m  | 401.9 | Trafalgar (AU)  | FOUND   |
| U4824682 RS41-SG | 2024-02-28 01:17:30 | -38.0716 145.942 474 m  | 401.5 | Warragul (AU)   | FOUND   |
|                  |                     |                         |       |                 |         |
| U4844239 RS41-SG | 2024-02-24 13:31:46 | -37.028  145.317 887 m  | 401.5 | Seymour (AU)    | UNKNOWN |
| U4844271 RS41    | 2024-02-24 01:43:31 | -37.1302 145.16  1038 m | 401.5 | Broadford (AU)  | UNKNOWN |
| U4844280 RS41    | 2024-02-23 13:33:29 | -37.3127 145.226 689 m  | 401.5 | Broadford (AU)  | UNKNOWN |
|                  |                     |                         |       |                 |         |
| U4844283 RS41    | 2024-02-23 01:27:14 | -38.0807 146.308 361 m  | 401.5 | Moe (AU)        | FOUND   |
| U4844275 RS41    | 2024-02-22 13:56:58 | -38.291  146.597 574 m  | 401.5 | Traralgon (AU)  | LOST    |

- seems like a bunch of sondes around Moe/Traralgon/Trafalgar are found
- and ones around Seymour/Braodford/Whittlesea are not
- today's being a classic example of not being too far away
  - [https://radiosondy.info/sonde_archive.php?sondenumber=U4844272](https://radiosondy.info/sonde_archive.php?sondenumber=U4844272)

### More videos

**My Fieldcraft Survival Ham Radio Kit - Ham Radio Crash Course**

[![
  My Fieldcraft Survival Ham Radio Kit - Ham Radio Crash Course
](
  http://img.youtube.com/vi/rU0qye0ZK_c/0.jpg
)](https://youtu.be/rU0qye0ZK_c)

- bunch of radios
- small antennas for travelling
- and solar battery
- as well as how to pack a bunch of this stuff
- small back up radio
  [BELKA-DX](https://swling.com/blog/2022/10/13dka-reviews-the-new-2022-belka-generation-3-general-coverage-receiver/)
- upgrade your antenna on a hand held
- get a BNC adapter for quick change overs

**No Signal, No Problem! DIY ESP32 Festival Tracker Unveiled! 🎊🔍 Part 1 -
Auryn Codes**

[![
  No Signal, No Problem! DIY ESP32 Festival Tracker Unveiled! 🎊🔍 Part 1 -
  Auryn Codes
](
  http://img.youtube.com/vi/i7K-_zALYdg/0.jpg
)](https://youtu.be/i7K-_zALYdg)

using:
- LoRa
- direction
- GPS
- ESP32
- round face display

build a direction finding device network to find your friends at a festival -
cool idea

