---
layout: post
title:  "New Quansheng UV-K5 radios"
date:   2024-02-26 18:00:00 +1100
categories: quansheng radios radiosonde arduino
---

Received a pair of Quansheng UV-K5 radios for my son and I to get our
foundation license and have something to talk on. There is quite a number of
settings to get my head around but jumping on the UHF CB frequencies, looks all
good on a quick RX/TX test.

One of the reasons I went for the Quansheng over the Baofeng, was the larger
number of frequencies it receives on and the fact you can update the firmware.
I might look at the firmware at a later point but one frequency it does seem to
receive on is `400.5MHz`, `401.5MHz` and `402.5MHz` which I have been recently
listening to on an RTl-SDR USB dongle to get radiosonde signals on my computer.
I managed to live decode the signals on the laptop today via blackhole virtual
audo interface and `sondedump` program, setup as [disucssed
yesterday](./2024-02-25-finally-ordered-nanovna.md). Given that I can receive
the same frequencies on a hand held radio, shouldn't I be able to take the
audio output and process that to get the radiosonde coordinates? This should
suggest a much simpler setup then the RasPi/RTL-SDR I was [originally thinking
of](./2024-02-23-where-to-start.md), all I need is something like an Arduino
and to work out how to decode the audio signals? I came across the following
proof of concept video

[![
  Décodeur radiosonde M10 Arduino F4GMU (M10 Arduino F4GMU radiosonde decoder)
](
  http://img.youtube.com/vi/W40DpmFwOr0/0.jpg
)](https://youtu.be/W40DpmFwOr0)

by [**djecom2**
_@F4GMU_](https://www.youtube.com/channel/UCUObG148Oik72W2dLRQNjeQ). On the
vide there seems to be an interaction 6 years ago:

> @fats699
>
> Can you share the coding with me please
>
> > @F4GMU
> >
> > Martin Fraser Years of work. So no. Sorry

after looking around on the web I did manage to find
[https://github.com/djecom1/rdz_ttgo_sonde](https://github.com/djecom1/rdz_ttgo_sonde)
which just may do the trick, although it does look overly complicated. It seems
that it may actually run the radio via a LoRa module as well as decoding the
sound? Still that and the `sondedump` C code should be enough to get a simpler
prototype up and running. I am thinking along the lines of:

```
 ------------
| Quansheng  |         ----------
| UV-K5      |        | Arduino/ |                            ---------
| 400-403MHz |-audio->|  ESP32   |           ---------       | OLED    |
| Audio out  |        | ADC pin  |-digital->| Decoder |-SPI->| display |
 ------------          ----------            ---------        ---------
```

- an ADC (Analog to Digital) converter gets the signal
- some decoding and filtering is performed to identify the signal and extract
  the bits of data
- finally display it on a small OLED display

it's the decoding and filtering that sound like the hard parts `¯\_(ツ)_/¯`

either way, first thing would be to confirm that the signal can be received by
the radio tomorrow at 10am when the next balloon is released and also check
that the computer is able to decode the sound via the microphone, to confirm an
audio coupling is satisfactory

The other thing I need to focus on is the foundation license. Appart from the

[The Foundation Manual - Your Entry Into Amateur
Radio](https://www.wia.org.au/licenses/foundation/foundationmanual/)

![](https://www.wia.org.au/licenses/foundation/foundationmanual/images/flcover.jpg)

there is this YouTube series:

REAST Training & Assessment - Reast Hobart

[![
  REAST Training & Assessment - Reast Hobart
](
  http://img.youtube.com/vi/42N22G2pVNk/0.jpg
)](https://youtu.be/playlist?list=PLsnsP_zjw831mdC6sY4XqavRUY-53ZWUn)

hopefully I'll let some soldersmoke out tonight on one of those morse code
practice oscillators ...

### More radiosonde info

Found this really detailed blog on radiosondes [Alex's blog - Radiosonde
Hunting Sunday, May 24, 2020
](https://flux242.blogspot.com/2020/05/radiosonde-hunting.html). This makes
mention of a lot of resrouces like:
- how people have re-puropsed radiosondes to transmit
- how people find radiosondes including building their own power meters
  [![
    Wetter-Sonden-Tracker von OE3AJC - lerrypage
  ](
    http://img.youtube.com/vi/j-vJQBvxPKM/0.jpg
  )](https://youtu.be/j-vJQBvxPKM)

  althought it seems hard to find the source code
- some ideas on making a yagi using a TV rabbit ear antenna
- a whole bunch of software and hardware options for listening and decoding
  signals (_althought none of these really seem to be of any need compared to
  sondedump_)
- as well as [https://rdzsonde.mooo.com/](https://rdzsonde.mooo.com/) using
  TTGO ESP32 LoRa hardware
  - with the code
    [https://github.com/dl9rdz/rdz_ttgo_sonde](https://github.com/dl9rdz/rdz_ttgo_sonde)
    seems to be more upto date and the original of
    https://github.com/djecom1/rdz_ttgo_sonde mentioned above.
- also smartphone App controlled devices?
  [https://github.com/einergehtnochrein/ra-hardware](https://github.com/einergehtnochrein/ra-hardware)
- the author's approach of using `rtl-sdr` package and a bunch of shell scripts
  that seem to define the radio? - as well as setting up an SPP (Serial Port
  Profile) to communicate data from a backpack computer to a smartphone to
  simplify hands free finding.
- a video around how to use the LoRa TTGO board

  #360 Tracking and Chasing Weather Balloons with TTGO LoRa Board and Raspberry
  Pi. Fun and Adventure - Andreas Spiess

  [![
    #360 Tracking and Chasing Weather Balloons with TTGO LoRa Board and
    Raspberry Pi. Fun and Adventure - Andreas Spiess
  ](
    http://img.youtube.com/vi/vQfztG60umI/0.jpg
  )](https://youtu.be/vQfztG60umI)
- which makes me think, is it just a question of decoding `APRS` ?

  Tracker APRS bi-frequences - djecom2

  [![
    Tracker APRS bi-frequences - djecom2
  ](
    http://img.youtube.com/vi/91j5z73_nHw/0.jpg
  )](https://youtu.be/91j5z73_nHw)

  but still no code from `@djecom2`

- Receiving APRS using Baofeng UV-5R and ESP32 - Ryan Kinnett
  [![
    Receiving APRS using Baofeng UV-5R and ESP32 - Ryan Kinnett
  ](
    http://img.youtube.com/vi/HL8Il7bdnJ8/0.jpg
  )](https://youtu.be/HL8Il7bdnJ8)

  seems to stream sound via Wifi and uses the PC to decode the APRS signal

  - [https://github.com/rkinnett/ESP32-VBAN-Audio-Source](https://github.com/rkinnett/ESP32-VBAN-Audio-Source)
  - [https://hackaday.io/project/170710-esp32-tnc-and-audio-relay-for-hfvhf-packet-radio](https://hackaday.io/project/170710-esp32-tnc-and-audio-relay-for-hfvhf-packet-radio)

- Finally Arduino Decoder for APRS monitoring with using OLED as well as
  MP3-Player - DJ7OO

  [![
    Decoder for APRS monitoring with using OLED as well as MP3-Player - DJ7OO
  ](
    http://img.youtube.com/vi/S-wt9EOdMKE/0.jpg
  )](https://youtu.be/S-wt9EOdMKE)

  seems to actually decode on Arduino, using 2 Arduino Pro's, but again no code

  > @amessiah_ 5 years ago
  >
  > Same. Share code with us.
  >
  > @CharudattUplap 6 years ago
  >
  > Klaus , where can I find the code for this.
  >
  > > @MeineVideokasetten 3 years ago
  > >
  > > He'll never answer!

  - although it seems it is documented here
    [http://www.kh-gps.de/aprspeak3.htm](http://www.kh-gps.de/aprspeak3.htm)
    with a what seems a standard way to connect to the audio output

  ![](/ham-radio/assets/images/www.kh-gps.de_aprspeak3_codec_101.jpg){: width="480" }

  and references the code being at
    - http://unsigned.io/projects/libaprs/
    - which can only be viewed via
      https://web.archive.org/web/20180611013225/https://github.com/markqvist/LibAPRS
    - which links off to [https://github.com/markqvist/LibAPRS](https://github.com/markqvist/LibAPRS)
    - but presumably any APRS libary may be enough?
      - [https://unsigned.io/shop/arduino-aprs-library/](https://unsigned.io/shop/arduino-aprs-library/)
      - [https://github.com/EvanKrall/LibAPRS-esp32-i2s](https://github.com/EvanKrall/LibAPRS-esp32-i2s)
        it would be interesting to see more of the details here

      > The ESP32's adc1_get_raw() / adc2_get_raw() methods can only be called
      > at about 6000Hz; LibAPRS wants 9600Hz. To get around this limitation,
      > this fork uses the ESP32's I2S peripheral to drive both the ADC and the
      > DAC.

      - there is no doubt a lot to read about ADC within ESP32's
        [https://lastminuteengineers.com/esp32-basics-adc/](https://lastminuteengineers.com/esp32-basics-adc/)

---

ok and about those UV-K5's, maybe one time there will be time to put some of
the alternate software

[https://github.com/piotr022/UV_K5_playground](https://github.com/piotr022/UV_K5_playground)

