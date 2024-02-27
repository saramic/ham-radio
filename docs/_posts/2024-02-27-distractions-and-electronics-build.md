---
layout: post
title:  "More distractions and an electronics build"
date:   2024-02-27 23:00:00 +1100
categories: radiosonde
---

### Dev boards falling from the sky

I love the fact that radiosondes are described as

> "ARM/STM32 Development boards literally falling from the sky"

EEVblog #1207 - ARM Dev Boards Falling From The Sky!

[![
  EEVblog #1207 - ARM Dev Boards Falling From The Sky!
](
  http://img.youtube.com/vi/ZQq8V73b4io/0.jpg
)](https://youtu.be/ZQq8V73b4io)

- also a bunch of stuff discussed here
  - [https://www.eevblog.com/forum/blog/eevblog-1207-arm-dev-boards-falling-from-the-sky!/](https://www.eevblog.com/forum/blog/eevblog-1207-arm-dev-boards-falling-from-the-sky!/)

STM32 Development Boards (literally) Falling From The Sky - linux.conf.au

[![
  STM32 Development Boards (literally) Falling From The Sky - linux.conf.au
](
  http://img.youtube.com/vi/YBy-bXEWZeM/0.jpg
)](https://youtu.be/YBy-bXEWZeM)

### Radiosonde reception on UV-K5

Tried receiving radiosonde signal with my Quansheng `UV-K5` at `401.500MHz` but
it seems the sound coming out of the speaker, was not good enough quality to use
`sondedump` to decode? maybe the "acoustic coupling" between the output speaker
of the `UV-K5` and the microphone of the Mac with outside noise is not good
enough?

Or maybe the transmission band is too wide? The `UV-K5` has an FM wide/narrow
setting. I used wide but am not sure how wide that is? on the internet I have
found that braodcast FM can be 75kHz wide? and a wide FM setting on a radio can
be 25kHz whilst a narrow setting is 12.5kHz, but I have seen something
suggesting as narrow as 5kHz. I could not seem to find a specification for the
`Quansheng UV-K5` for how wide the wide FM is either.

- [Reddit: Wide vs narrow
  FM](https://www.reddit.com/r/amateurradio/comments/q8y42l/wide_vs_narrow_fm/)

From previous experiments with the `RTL-SDR` USB dongle using GQRX software, I
know I can adjust the width of the reception and it was wide enough to get
`sondedump` to decode the signal. I have an idea for a couple of experiments
for tomorrow or next time I have a chance to listen to a radiosonde.

**Experiments in listening and decoding radiosonde**

- determine the width of the required signal using laptop and `GQRX`

  1. setup laptop with `RTL-SDR` USB dongle and decode using `sondedump`
  1. adjust the width of the input to see when `sondedump` fails to process
     data
  1. record sound for comparison to `UV-K5`

- determine if `UV-K5` can decode using `sondedump` via "audio coupling"
  1. try with a nearer signal
  1. potentially try with 2 radios, each tuned up and down the band to emulate
     a wider band? not sure if this will work
  1. record the sound check for quaulity and compare to `RTL-SDR`

#### On recylding radiosondes

Not trying to get ahead of myself but this is a cool article with some internals etc

- [http://www.om3bc.com/docs/rs41/rs41_en.html](http://www.om3bc.com/docs/rs41/rs41_en.html)
- ![](http://www.om3bc.com/docs/rs41/rs41_1.png){: width="480" }
- ![](http://www.om3bc.com/docs/rs41/rs41_2.png){: width="480" }

### ESP32 signal processing

What are the limits of the ESP32 and sound?
  - https://dronebotworkshop.com/esp32-i2s/
another `RS41` specific decoding library
  - [https://github.com/bazjo/RS41_Decoding](https://github.com/bazjo/RS41_Decoding)
  - which mentions `FSK` Frequency-shift Keying [https://en.wikipedia.org/wiki/Frequency-shift_keying](https://en.wikipedia.org/wiki/Frequency-shift_keying)

Finally isn't it just APRS?
  - [https://github.com/nakhonthai/ESP32IGate](https://github.com/nakhonthai/ESP32IGate)
    > ESP32IGate is a APRS Internet Gateway + TNC Built In that is implemented
    > for Espressif ESP32 processor.
  - [https://www.rpc-electronics.com/esp32-aprs-tracker.php](https://www.rpc-electronics.com/esp32-aprs-tracker.php)
    > The ESP32-APRS Tracker is an all new APRS Tracker meant for the 21st
    > century. We started with the powerful ESP32 WROOM module and built the
    > platform on it's vast array of built-in peripherals. Adding a high
    > quality, fast locking GPS, sensors and other devices, we have created a
    > small form factor, feature rich APRS Tracker/Digipeater/iGate/Modem that
    > will fit your APRS operating needs.

    ![](https://www.rpc-electronics.com/img/esp32-aprs/esp32-aprs-tracker.jpg){:
    width="480" }
  - did I post this already?

    Receiving APRS using Baofeng UV-5R and ESP32 - Ryan Kinnett
    [![
      Receiving APRS using Baofeng UV-5R and ESP32 - Ryan Kinnett
    ](
      http://img.youtube.com/vi/HL8Il7bdnJ8/0.jpg
    )](https://youtu.be/HL8Il7bdnJ8)
  - [https://hackaday.com/2021/06/15/aprs-implemented-at-low-cost-and-small-size/](https://hackaday.com/2021/06/15/aprs-implemented-at-low-cost-and-small-size/)
    - ![](https://hackaday.com/wp-content/uploads/2021/06/aprs-small-main.jpg?w=800){:
      width="480" }
    - [https://www.curiouselectron.com/?p=595](https://www.curiouselectron.com/?p=595)
    - code and design [https://repo.curiouselectron.com/curiousmuch/arrow-firmware](https://repo.curiouselectron.com/curiousmuch/arrow-firmware)
    - Arrow - TNC with Bluetooth and 2M Radio - curiousmuch

      [![
        Arrow - TNC with Bluetooth and 2M Radio - curiousmuch
      ](
        http://img.youtube.com/vi/fh8neKRE4Ao/0.jpg
      )](https://youtu.be/fh8neKRE4Ao)
    - but what is an Arrow?
    
    ![](http://repo.curiouselectron.com/curiousmuch/arrow-firmware/raw/master/Arrow-Render-01.png){:
    width="480" }

    - not something you can buy but you need to make it

    - [repo.curiouselectron.com Arrow-Schematic.pdf](https://repo.curiouselectron.com/curiousmuch/arrow-firmware/src/master/Arrow-Schematic.pdf)

    ![](/ham-radio/assets/images/arrow_tnc_radio_cc1200.png){: width="480" }
    ![](/ham-radio/assets/images/arrow_tnc_esp32.png){: width="480" }
    ![](/ham-radio/assets/images/arrow_tnc_power.png){: width="480" }

    - right using a [CC1200 - Low power and high performance wireless transceiver](https://www.ti.com/product/CC1200#tech-docs) Sub-1 GHz RF Transceivers - sounds like it is good for packet radio and streaming data over RF?
      - which appart from a pretty heavy data sheet has a security
        vulnerability

      > Absence of Frame Counter Validation
      >
      > The TI WiSUN® stack did not include logic to check the frame counter of
      > incoming packets... This allows attackers to capture network packets
      > and resend those packets. The receiving device will process the packet
      > as if it was sent by the original source of the packet.

    - a 2 board? development kit from digikey for ~$200
      - [CC1200EMK-420-470](https://www.digikey.com.au/en/products/detail/texas-instruments/CC1200EMK-420-470/4271562)
      - SimpleLink™ CC1200 Transceiver, ISM 420MHz ~ 470MHz Evaluation Board

      ![](https://mm.digikey.com/Volume0/opasdata/d220001/medias/images/528/CC1200EMK-420-470.jpg){: width="480" }

      > The Cc1200Emk-420-470 Evaluation Module Kit For 420Mhz To 470Mhz, Can
      > Be Used In Conjunction With The Cc1200 Development Kit To Evaluate The
      > Operation Of The Cc1200 In The Mentioned Frequency Range. The Cc1200 Is
      > A Fully Integrated Single Chip Radio Transceiver Designed For High
      > Performance At Very Low Power And Low Voltage Operation In Cost
      > Effective Wireless Systems. All Filters Are Integrated, Removing The
      > Need For Costly External Saw And If Filters. The Device Is Mainly
      > Intended For The Industrial, Scientific And Medical And Short Range
      > Device Frequency Bands At 164Mhz To 190Mhz, 410Mhz To 475Mhz And 820Mhz
      > To 950Mhz. The Cc1200 Provides Extensive Hardware Support For Packet
      > Handling, Data Buffering, Burst Transmissions, Clear Channel
      > Assessment, Link Quality Indication And Wake On Radio. The Cc1200 Main
      > Operating Parameters Can Be Controlled Via An Spi Interface. In A
      > Typical System, The Cc1200 Will Be Used Together With A Microcontroller
      > And Only Few External Passive Components

      - but there seem to be `CC1101` `433Mhz` `10mW` **transciever** related
        boards for ~$3 - note this is a trnasciever as opposed to a lot of
        `433MHz` boards that are either TX or RX
        - [https://electropeak.com/cc1101-moduale-10mw](https://electropeak.com/cc1101-moduale-10mw)
      - Texas Instruments LAUNCHXL-CC1310 Dev Board, Launchpad ~$70
        - [https://au.mouser.com/ProductDetail/Texas-Instruments/LAUNCHXL-CC1310](https://au.mouser.com/ProductDetail/Texas-Instruments/LAUNCHXL-CC1310)
      - a LoRa 915MHz model is ~$20 for comparison
        - [https://littlebirdelectronics.com.au/products/lora-fsk-transceiver-module-915mhz-rfm97cw](https://littlebirdelectronics.com.au/products/lora-fsk-transceiver-module-915mhz-rfm97cw)
    - this did allow me to find this intruiguing device [FM Walkie Talkie Circuit Board Transceiver All-in-One Module FM Transmitter Receiver Module 7 Frequency 27-480MHz DC3.3-6V](https://www.aliexpress.com/item/1005006457592854.html) for only ~$7

      ![](/ham-radio/assets/images/aliexpress.com_1005006457592854_fm_radio_module.png){:
      width="480" }
    - also found some more solid looking 433MHz modules like
      - [RF TRANSCEIVER MODULE FOR ARDUINO PROJECTS](https://www.auselectronicsdirect.com.au/rf-transceiver-module-for-arduino-projects) ~$15
        ![](https://www.auselectronicsdirect.com.au/assets/full/TA0032.jpg?20210309030217){:
        width="480" }

### Code practice circuit

I prototyped a qiuck version using a 555 on a breadboard - sounds better than
the 1k transformer one I have so will go with a proper build tomorrow.

