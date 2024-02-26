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
