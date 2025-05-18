---
layout: post
title:  "Getting back into electronics"
date:   2025-05-19 09:00:00 +1000
categories: electronics
---

I want to build up my electronics capability to be able to design and build a
medium complexity circuit and have a completed project and boxed project. The
aim would be to do this in such a way that I am also able to share some of
these learnings maybe through a set of blogs, tutorials, live streams or videos
on YouTube, TikTok or Instagram.

### LM3914

Some things that have been of interest recently in discussions with the kids,
as I had them setup the first project in the Dick Smith Funway series was to
light an LED based on sound. I brought out an [LM3914](
https://www.ti.com/product/LM3914) Bar Graph driver to highlight how a
different voltage could light a different amount of LED's using a
potentiometer. Ofcourse I had a wrong connection, followed by shorting it using
the potentiometer and making the mini trim pot glow yellow with the short
circuit and let out some smoke. The pot now has a "weak spot" but mostly works.
I missed the kids on having the opportunity to see the destruction. Maybe I do
a few of these experiments with them, like how to reverse the voltage on a
capcitor and bow it up, burn a fuse, burn a wire, make a spark gap etc.

I wanted to extend the idea of the `LM3914` circuit to be sound activated, sort
of a VU (Volume Unit) meter. Sort of like this one [CircuitDigest: LED VU Meter
using LM3914 and LM358](
https://circuitdigest.com/electronic-circuits/vu-meter-using-lm3914)
The idea here would be to maybe see how loud they can yell into a microphone to
detect it on the VU meter. Also this would allow them to compare the "digital"
nature of the LED VU meter and an analog one. Another extension would be to
build out a VU meter with resistors and transistors, like the Funway
Electronics II project.

### Microphone Pre-amp

To do this, I would use an electret microphone and presumably I would need a
pre-amp. There seems to be an interesting review of what an electret microhpone
is in [Hack-a-day: A Bit More Than A Microphone: The Electret Story - Jenny
List - March 7, 2018](
https://hackaday.com/2018/03/07/a-bit-more-than-a-microphone-the-electret-story/)
There is some discussion between using an Op-amp and discrete components in a
series of blogs mentioning the 990 discrete op amp
- [ ] https://www.hairballaudio.com/catalog/parts-store/discrete-op-amps/je-990-discrete-op-amp
- [ ] http://www.johnhardyco.com/pdf/990.pdf
- [ ] https://warmaudio.com/blog/is-a-discrete-mic-preamp-a-good-thing

Ofcourse there are some ready to go modules like
- [Aliexpress (~$4): TL072 Op Amp High Impedance Preamplifier Preamp
  Pre-amplifier Board Module](
  https://www.aliexpress.com/item/1005006084978737.html)
- [Aliexpress (~$1): Electret Microphone Amplifier Stable MAX9814 module Auto
  Gain Control MAX4466](
  https://www.aliexpress.com/item/1005002826729816.html)
- [Aliexpress (~$4): MAX9814 Microphone AGC Amplifier Board Sound sensor Module
  Auto Gain Control Attack for Arduino MAX4466 PCB Board Diy Kit](
  https://www.aliexpress.com/item/1005006468621971.html)

There is some discussion on the Arduino forums [Microphone to Op
Amp](https://forum.arduino.cc/t/microphone-to-op-amp/886878) between the
[MAX9814](
https://www.analog.com/media/en/technical-documentation/data-sheets/max9814.pdf)
and [LM358](https://www.ti.com/lit/ds/symlink/lm358.pdf)

Some YouTube videos:

- **build guide Building a DIY Mic preamp! - Thomas van Opstal**

  [![
   build guide Building a DIY Mic preamp! - Thomas van Opstal
  ](
    http://img.youtube.com/vi/kMFH5MH3zn0/0.jpg
  )](https://youtu.be/kMFH5MH3zn0)

  more about how to build a complex kit

- **Simple inline microphone preamps part 1 - design & schematics Robert
  Jenkins Technolog**
  [![
   Simple inline microphone preamps part 1 - design & schematics Robert Jenkins
   Technolog 
  ](
    http://img.youtube.com/vi/nKuYq5OVaIE/0.jpg
  )](https://youtu.be/nKuYq5OVaIE)

Some more designs below:

- [ ] https://www.instructables.com/Build-The-5-Microphone-Preamp/
- [ ] [Texas Instruments (PDF): Analog Engineer's Circuit Non-inverting
  microphone pre-amplifier circuit](
  https://www.ti.com/lit/an/sboa290a/sboa290a.pdf)
- [ ] https://www.reddit.com/r/AskElectronics/comments/9237jk/microphone_preamplifier_circuit_and_understanding/
- [ ] https://www.nutsvolts.com/magazine/article/how-to-design-a-microphone-amplifier
- [ ] https://www.thatcorp.com/datashts/AES129_Designing_Mic_Preamps.pdf
- [ ] https://www.eevblog.com/forum/projects/help-with-design-considerations-of-a-proper-microphone-preamp/

### Function generator

Which brings me to, How to test such a pre-amp, or at least consistently set it
off. Clearly I would need a Functionn Generator. I do have one under the house
utilising an [XR2206](https://cdn.sparkfun.com/assets/8/a/b/3/9/XR2206.pdf).
These are cheap and easy to get on Aliexpress:

- [Aliexpress (~$10): Signal Generator Kit, XR2206 Precise Function Signal
  Generator Frequency Module DIY Kit Sine Triangle Square Output Adjustable](
  https://www.aliexpress.com/item/1005009013635032.html)

The following great video from Great Scott suggests DDS (Digital Direct
Synthesis) is the way to go, but also reviews some Op-amp and XR2206 designs:

- **Function/Waveform Generator || DIY or Buy GreatScott!**
  [![
    Function/Waveform Generator || DIY or Buy GreatScott!
  ](
    http://img.youtube.com/vi/Y1KE8eAC9Bk/0.jpg
  )](https://youtu.be/Y1KE8eAC9Bk)

- this mentions the AE20125 Function Generator, a review below

  **Ascel AE20125 Function Generator Review and Teardown - electronupdate**
  [![
    Ascel AE20125 Function Generator Review and Teardown - electronupdate
  ](
    http://img.youtube.com/vi/Ghypzo6YK6c/0.jpg
  )](https://youtu.be/Ghypzo6YK6c)

- and this article that the DDS design is based on [How to Build Your Own
  Function Generator Using Analog Devices’ AD9833 January 17, 2018 by Cezar
  Chirila](
  https://www.allaboutcircuits.com/projects/how-to-DIY-waveform-generator-analog-devices-ad9833-ATmega328p/)

There are a bunch of other options:

- [Aliexpress (~$7): ICL8038 Multi-Function Low-Frequency Signal Generator
  Multi-Wave Welding Electronic Circuit Experiment Kit DIY Electronic Kit](
  https://www.aliexpress.com/item/1005006153569826.html)
- [Aliexpress (~$30): FG-200 DDS Function Signal Generator Frequency Counter
  0.01Hz - 500KHz Signal Source Module Sine+Square+Sawtooth Waveform](
  https://www.aliexpress.com/item/1005006969180708.html)
  - a review on [Hack-a-day: Review: Unnamed Chinese DDS Function Generator -
    Jenny List - February 25, 2020](
    https://hackaday.com/2020/02/25/review-unnamed-chinese-dds-function-generator/)
- [Aliexpress (~$7): AD9833 AD9833BRMZ Programmable Microprocessors Serial
  Interface Module Sine Square DDS Signal Generator Module](
  https://www.aliexpress.com/item/1005006781769236.html)
- [Aliexpress: (~$80): Digital DDS Function Generator Dual-channel 12Bits
  250MSa/s Sine Wave 24MHz Arbitrary Waveform/Pulse Frequency Signal
  Generator](
  https://www.aliexpress.com/item/1005006994683337.html)

### Test equipment

At which point this leads me into another look at test equipment and the idea
of building from scratch and augmenting with Arduino like this volt meter as
inspiration:

- https://www.instructables.com/Arduino-Precise-Accurate-Volt-Meter-0-90V-DC/

#### FNIRSI DPS-150

There is also a need for a smaller and USB-C powered power supply, in this case
probably this off the shelf device might be the best. Some review notes from
EEVBlog:
- https://www.eevblog.com/forum/testgear/new-miniature-programmable-dc-power-supply-fnirsi-dps-150/100/

### Errata

Back on the learning tack there are a bunch of articles from places like

- [DIY Engineers: How to use the BC547 Transistor (NPN) (with examples)](
  https://www.diyengineers.com/2022/05/05/how-to-use-the-bc547-transistor-npn-with-examples/)
