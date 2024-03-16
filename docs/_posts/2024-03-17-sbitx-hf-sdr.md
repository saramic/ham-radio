---
layout: post
title:  "sBitx and HF SDR"
date:   2024-03-17 10:30:00 +1100
categories: sBITx SDR DSP
---

Reflecting on the last time I was interested in radio, and at that time I was
listening tot he Soldresmoke podcast. 2 things stuck out for me from that
podcast, the talk of ["Experimental Methods in RF Design", Wes Hayward et
al](https://www.amazon.com.au/Experimental-Methods-Design-ARRL-Inc/dp/087259923X)
and some dude in India who had created a low cost radio based on easily
accessible parts from a television, the BITX20 built by [Ashhar
Farhan](https://www.vu2ese.com/). So after a little bit of searching I cam
across the fact that the old BITX20 had grown to be the sBITX SDR radio.

- [https://soldersmoke.blogspot.com/search/label/sBITX
](https://soldersmoke.blogspot.com/search/label/sBITX)
  - which links to Dean's KK4DAS site where he homebrewed his own sBITX
    [https://kk4das.blogspot.com/2024/02/homebrew-sbitx-receiver-gound-bounce.html
    ](https://kk4das.blogspot.com/2024/02/homebrew-sbitx-receiver-gound-bounce.html)
    with some discussion of the build

searching deeper on Soldersmoke, I found
[https://soldersmoke.blogspot.com/2021/05](https://soldersmoke.blogspot.com/2021/05)
which has a video that goes back to the source and Farham himself talking about
his inspirations for the `sBITX`

**Ashhar Farhan "sBITX - An Open-Source SDR the YOU Can Hack!"
FDIM 2021 - FDIM Archives**

[![
  Ashhar Farhan "sBITX - An Open-Source SDR the YOU Can Hack!"
  FDIM 2021 - FDIM Archives
](
  http://img.youtube.com/vi/9mFxyS6_2t8/0.jpg
)](https://youtu.be/9mFxyS6_2t8)

in this phenomenal video, Farhan, spells out the game changer that
microcontrollers are to modern electronics and HAM radio builds. I love his
embrace of the OpenSource, hackable ethos and accepting changes and advances in
technology whilst still keeping to a true, amateur build in a back yard shed.

In the video he mentions the evolution of microcontrollers controlling radios,
starting with a **Raspberry Pi Pico**

**uSDR-Pico: Homemade SDR-Transceiver with Raspberry Pi Pico -
juthoff62**

[![
  uSDR-Pico: Homemade SDR-Transceiver with Raspberry Pi Pico -
  juthoff62
](
  http://img.youtube.com/vi/h149AujiFM4/0.jpg
)](https://youtu.be/h149AujiFM4)

running
- [https://github.com/ArjanteMarvelde/uSDR-pico
  ](https://github.com/ArjanteMarvelde/uSDR-pico) (_last updated 2
  years ago_)
- expanded on here [https://github.com/kaefe64/Arduino_uSDX_Pico_FFT_Proj
  ](https://github.com/kaefe64/Arduino_uSDX_Pico_FFT_Proj) (_last
  updated 2 months ago_)

**uSDR-Pico with FFT/Waterfall on TFT Display - Klaus F - PY2KLA**

[![
  uSDR-Pico with FFT/Waterfall on TFT Display - Klaus F - PY2KLA
](
  http://img.youtube.com/vi/0zGAnkRjizE/0.jpg
)](https://youtu.be/0zGAnkRjizE)

**uSDR-Pico with FFT/Waterfall on TFT Display + Visual Scope -
Klaus F PY2KLA**

[![
  uSDR-Pico with FFT/Waterfall on TFT Display + Visual Scope -
  Klaus F - PY2KLA
](
  http://img.youtube.com/vi/BiaS002xZfw/0.jpg
)](https://youtu.be/BiaS002xZfw)

and from RasPi pico moving onto the **Teensy**

A Teensy based SDR is described here
[https://www.pjrc.com/convolution-software-defined-radio/
](https://www.pjrc.com/convolution-software-defined-radio/)
- [https://github.com/DD4WH/Teensy-ConvolutionSDR/tree/master
  ](https://github.com/DD4WH/Teensy-ConvolutionSDR/tree/master)
  ![](https://www.pjrc.com/wp-content/uploads/2020/02/teensy-SDR-e1581459166428.jpg){:
  width="480"}
  - [https://www.janbob.com/electron/SDR_Ctrl1/SDR_Ctrl1.html
    ](https://www.janbob.com/electron/SDR_Ctrl1/SDR_Ctrl1.html)
    ![](https://www.janbob.com/electron/SDR_Ctrl1/SDR_Ctrl1BoxP695.jpg){: width="480"}
    - also intersting circuits on this page W7PUA like a noise
      generator -
      [https://www.janbob.com/electron/Noise/NoiseGen1.htm
      ](https://www.janbob.com/electron/Noise/NoiseGen1.htm)

a next step might be moving onto a RasPi with a PiHat like
Radioberry? [SDR Radioberry V2.0 b4 for RPi 4-Wireless Card Analog
Device AD986 Supports the
10CL25](https://www.aliexpress.com/item/1005006456715216.html)

  ![](/ham-radio/assets/images/aliexpress.com_1005006456715216_radioberry_v2-RPi-4-AD986-10CL25.jpg){:
  width="480"}

but in this case the answer is the sBitx SDR from Farhan.

[https://www.sbitx.net/](https://www.sbitx.net/)

![](https://www.sbitx.net/wp-content/uploads/2022/09/sbitx_hero-768x471.jpg){:
width="480"}

there is also intresting comment here about using the `WM8731` Wolfsom Audio
CODEC chip with inbuilt Headphone Driver

![](/ham-radio/assets/images/20240317_uBITX_design.png){:
width="480"}

![](/ham-radio/assets/images/20240317_wm8731_from_uBITX.png){:
width="480"}

- available as a pre built board
  [https://www.aliexpress.com/item/1005004007148615.html
  ](https://www.aliexpress.com/item/1005004007148615.html)

He seems to mention "the paper" a number of times, and also refers to his github

- [https://github.com/afarhan](https://github.com/afarhan)
- the paper from the YouTube description
  [https://tinyurl.com/5xn7v22a](https://tinyurl.com/5xn7v22a) and
  here for posterity
    - **sBITX – An open source SDR that you can hack - By Ashhar
    Farhan, VU2ESE**

      [sbitx_v4.pdf](/ham-radio/assets/pdfs/sbitx_v4.pdf)

I am yet to listen in more detail to: crystal filter, thermal noise, FFT,
Specturm display, convolutional filtering

Skipping to the end I found a bunch of interesting references

- A Software-Defined Radio for the Masses part 1-4 via
  [https://www.arrl.org/](https://www.arrl.org/)
  1. [A Software-Defined Radio for the Masses part
     1](/ham-radio/assets/pdfs/A_Software-Defined_Radio_for_the_Masses_Part_1.pdf)
  1. [A Software-Defined Radio for the Masses part
     2](/ham-radio/assets/pdfs/A_Software-Defined_Radio_for_the_Masses_Part_2.pdf)
  1. [A Software-Defined Radio for the Masses part
     3](/ham-radio/assets/pdfs/A_Software-Defined_Radio_for_the_Masses_Part_3.pdf)
  1. [A Software-Defined Radio for the Masses part
     4](/ham-radio/assets/pdfs/A_Software_Defined_Radio_for_the_Masses_Part_4.pdf)
- The Scientist and Engineer's Guide to Digital Signal Processing
  By Steven W. Smith, Ph.D. -
  [https://dspguide.com/](https://dspguide.com/) available free
  online - pdf per chapter
- Experimental Methods in RF Design (with CD) is also a great resource for
  Digital Methods **EMRFD**
- finally a lot of the C code was written by [Phil Karn,
  KA9Q](https://www.ka9q.net/)
  - the quoted page `http://www.ka9q.net/ka9q-radio.tar.xz`
  - via
    [https://web.archive.org/web/20220408114116/http://www.ka9q.net/ka9q-radio.tar.xz
    ](https://web.archive.org/web/20220408114116/http://www.ka9q.net/ka9q-radio.tar.xz)
    - [ka9q-radio.tar.xz](/ham-radio/assets/other/ka9q-radio.tar.xz)

