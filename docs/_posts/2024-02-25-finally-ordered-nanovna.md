---
layout: post
title:  "Finally ordered a NanoVNA"
date:   2024-02-25 20:30:00 +1100
categories: ham antenna test equipment nanovna tinysa 
---

Finally ordered a NanoVNA and TinySA although I must say I am still confused
around attenuation and the whole dB thing. Reading from the TinySA wiki

[https://tinysa.org/wiki/pmwiki.php?n=Main.Transmitters](https://tinysa.org/wiki/pmwiki.php?n=Main.Transmitters)

> **Safe measurement of the output of transmitters**
>
> Calculating with dB is not too difficult.
> Every factor of 10 decrease of the power of a signal reduces the dB level
> with -10dB
>
> Typical output power of a transmitter
> 
> * 100W equals +50dBm
> * 10W equals +40dBm
> * 1W equals +30dBm
>
> For best measurement of harmonics in the output of transmitters the input
> level of the tinySA should aim between -20dBm and -10dBm
>
> Required attenuation between transmitter and tinySA
>
> * For 100W : between 60 and 70dB
> * For 10W : between 50 and 60dB
> * For 1W : between 40 and 50dB
>
> The best approach is to use **ALWAYS a 30dB attenuator** directly connected
> to the tinySA and to use power attenuators to reduce the output of the
> transmitter to the target input level of this 30dB attenuator, that is +10dBm
>
> So you will need these power attenuators
>
> * For 100W output: 30-40dB
> * For 10W output: 20-30dB
> * For 1W output: 10-20dB
>
> Another option is to use a dummy load and an inline 50dB attenuating sampler.
> A nice example of how to build one yourself can be found here
>  (here link is http://www.ad5x.com/images/Articles/Tap50dbRevA.pdf but no
>  longer exists) - _see below_


**From my reading of the above** I should get a `30dB` attenuator on my
NanoVNA, and for a `1W` rig, I would need another `20dB` of **power**
attenuation, or for a `10W` rig another `20dB` of **power** attenuation. It
seems there are a bunch of cheap `2W` attenuators in various steps:
`1,3,6,10,15,20,30,40dB` (eg [2W SMA attenuator on
AliExpress](https://www.aliexpress.com/item/1005006075206869.html)) and I would
also need a higher power attenuator, sort of like a dummy load?so I got a [10W
SMA Attenuator at 30dB](https://www.aliexpress.com/item/1005006031464052.html).

This was also influenced by
[https://groups.io/g/tinysa/topic/102097320](https://groups.io/g/tinysa/topic/102097320#:~:text=60db%20of%20attenuation%20is%20perfect%2D%2Dresults%20in%201%20millionth%20of%20a%20watt%20going%20into%20the%20tinysa)
where Matthew Rapaport (10/22/23 #13069) writes

> I have only HTs to test and transmit 1 watt. 60db of attenuation is
> perfect--results in 1 millionth of a watt going into the tinysa. 30db is on
> the radio (10 watt capacity so HT output is 1 thousandth of a watt) and
> another 30db (2 watt capacity) on the tinySA port. See pictures). If you're
> transmitting 100 watts you're going to need 80db attenuation to get the same
> 1 millionth of a watt. I would put 50 on the radio and then you can use the
> 30db on the port.. 

so I think I am in the ball park.

I did also watch another ([_NanoVNA as a synthesized CW signal
generator_](https://www.youtube.com/watch?v=TJciolN-PAQ)) of
[MegawattKS](https://www.youtube.com/@MegawattKS)
informative videos where he uses a step attenuator like a `AGILENT/ HP 355D
STEP ATTENUATOR DC TO 1000 MHZ` but these seem hard to come by. He mentions
building your own?

- this one
  [https://www.arrl.org/files/file/Technology/tis/info/pdf/9506033.pdf](https://www.arrl.org/files/file/Technology/tis/info/pdf/9506033.pdf)
  seems like to be a big resistor network with a bunch of switches to turn
  various parts on/off to get desired attenuation: 1,2,3,5,10,10,10,10,10,10
- you can buy one for ~$40 [RF Programmable Attenuator 1MHZ-3800MHz Digital
  programmable RF attenuator control 0-31dB adjustable step 1dB PC
  controllable](https://www.aliexpress.com/item/1005005949446098.html)
  althought it seems to be a little limited in power
- there is a thread on building your own attenuator
  [https://www.eevblog.com/forum/projects/20db-rf-attenuator-seeking-feedback-to-improve/](https://www.eevblog.com/forum/projects/20db-rf-attenuator-seeking-feedback-to-improve/)
  has a bunch of comments and photos and circuit ideas as well as pointing to 
  - [DC-4.0GHz RF Fixed Attenuator Radio Frequency Fixed](https://www.banggood.com/DC-4_0GHz-RF-Fixed-Attenuator-Radio-Frequency-Fixed-p-1119478.html)
  - and a video by [https://www.youtube.com/@w2aew](https://www.youtube.com/@w2aew)
    #91: Basic RF Attenuators - Design, Construction, Testing - PI and T style
    A Tutorial
    [![
      #91: Basic RF Attenuators - Design, Construction, Testing - PI and T style - A Tutorial
    ](
      http://img.youtube.com/vi/A5gGeV7CiQ0/0.jpg
    )](https://youtu.be/A5gGeV7CiQ0)
  - the above lead me to find
    [https://www.youtube.com/@IMSAIGuy](https://www.youtube.com/@IMSAIGuy)

    #545b TinySA Using Attenuators

    [![
      #545b TinySA Using Attenuators
    ](
      http://img.youtube.com/vi/Sdb_cs13njk/0.jpg
    )](https://youtu.be/Sdb_cs13njk)

    and #581 Digital Programmable RF Attenuator

    [![
      #581 Digital Programmable RF Attenuator
    ](
      http://img.youtube.com/vi/cWDHQppfR38/0.jpg
    )](https://youtu.be/cWDHQppfR38)

Have added all the above to a _watch later_ list on YouTube. I do feel like
more of a librarian, sifting and saving a bunch of stuff for later, rather than
an experimenter in RF.

regarding the lost http://www.ad5x.com/images/Articles/Tap50dbRevA.pdf it does
via the web archive
https://web.archive.org/web/20170124004030/http://www.ad5x.com/images/Articles/Tap50dbRevA.pdf
but I have copied it for posterity [archive:
http://www.ad5x.com/images/Articles/Tap50dbRevA.pdf](/ham-radio/archives/www.ad5x.com_images_Articles_Tap50dbRevA.pdf.html)

Talking of the web archive, also found some other interesting stuff relating to
the original tape measure antenna article
[/ham-radio/archives/pages.videotron.com_ve2jmk_tape_bm.htm.md](/ham-radio/archives/pages.videotron.com_ve2jmk_tape_bm.htm.md)
- another tape measure antenna [WebArchive: RDF2 YAGI WITH TAPE MEASURE
  ELEMENTS](https://web.archive.org/web/20100113064132/http://home.att.net/~jleggio/projects/rdf/snif_bm.htm)
- [WebArchive: THE FOX - 40 milliwatt
  transmitter](https://web.archive.org/web/20120504131547/http://theleggios.net/wb2hol/projects/rdf/40mw_tx.htm)
  with a bunch of cool "ugly construction" and "manhattan" build
- and [WebArchive: THE FOX750 - 750 milliwatt
  transmitter](https://web.archive.org/web/20110816224730/http://theleggios.net/wb2hol/projects/rdf/750mw_tx.htm)

Another interest that comes to mind is making available a bunch of software
that seems to have been hidden or closed sourced. There is a big collection
here
[https://github.com/AxiomYT/Ham-Radio-Manuals-and-hard-to-find-tools](https://github.com/AxiomYT/Ham-Radio-Manuals-and-hard-to-find-tools).
Of particular interest seem to be: Super Morse and YagiCad. But outside of that
I am also interested in Radiosonde decoding and decoding general recordings of
digital signals, in real time.

Although for Radiosonde there seems to be this
[https://github.com/dbdexter-dev/sondedump](https://github.com/dbdexter-dev/sondedump)

```
git clone git@github.com:dbdexter-dev/sondedump.git dbdexter-dev-sondedump
cd dbdexter-dev-sondedump
mkdir build && cd build
cmake ..
# errored, I didn't have cmake
brew install cmake

cmake ..
# errored, it wanted portaudio, or I could turn it off
cmake .. -DENABLE_AUDIO=OFF
make
./sondedump ~/gqrx_20240224_234742_401500000.wav
    [decode.c:177] Autodetected: RS41
    (U4824694) [ 3486] -17.8'C  11%    37.73016S 145.16373E   9847m    27.1m/s  84'  +2.5m/s
    (U4824694) [ 3487] -17.8'C  11%    37.73013S 145.16403E   9850m    26.4m/s  83'  +3.2m/s
    (U4824694) [ 3488] -17.9'C   6%    37.73011S 145.16432E   9854m    25.8m/s  84'  +4.8m/s
    (U4824694) [ 3489] -17.9'C   6%    37.73009S 145.16461E   9858m    25.9m/s  85'  +3.4m/s
    (U4824694) [ 3490] -18.0'C   6%    37.73007S 145.16490E   9862m    26.3m/s  85'  +3.8m/s
    ...

# found out I could
brew install portaudio
rm -rf ../build/*
cmake ..
make
./sondedump --audio-device 0
# will listen to microphone? but did not seem to work when I played a recording
afplay ~/gqrx_20240224_234742_401500000.wav
```

will need to work out how to treat GQRX as input stream?

also was interesting that you can put in your coordinates to get _"relative
(az, el, range)"_ presumably
[https://en.wikipedia.org/wiki/Horizontal_coordinate_system](https://en.wikipedia.org/wiki/Horizontal_coordinate_system):

- **az** - Azimuth
- **el** - Elevation
- **range** - distance?

```
./sondedump -h

Usage: ./sondedump [options] file_in
   -a, --audio-device <id>      Use PortAudio device <id> as input (default:
                                choose interactively)
   -c, --csv <file>             Output data to <file> in CSV format
   -f, --fmt <format>           Format output lines as <format>
   -g, --gpx <file>             Output GPX track to <file>
   -k, --kml <file>             Output KML track to <file>
   -l, --live-kml <file>        Output live KML track to <file>
   -r, --location <lat,lon,alt> Set receiver location to <lat, lon, alt>
                                (default: none)
   -t, --type <type>            Enable decoder for the given sonde type.
                                Supported values:
                                    auto: Autodetect (default)
                                    c50: Meteolabor SRS-C50
                                    dfm: GRAW DFM06/09
                                    imet4: InterMet iMet-4
                                    ims100: Meisei iMS-100/RS-11G
                                    m10: MeteoModem M10/M20
                                    mrzn1: Meteo-Radiy MRZ-N1
                                    rs41: Vaisala RS41-SG(P,M)
   -T, --tui                    Enable TUI display

   -h, --help                   Print this help screen
   -v, --version                Print version info

Available format specifiers:
   %a      Altitude (m)
   %b      Burstkill/shutdown timer
   %c      Climb rate (m/s)
   %d      Dew point (degrees Celsius)
   %f      Frame counter
   %h      Heading (degrees)
   %l      Latitude (decimal degrees + N/S)
   %o      Longitude (decimal degrees + E/W)
   %p      Pressure (hPa)
   %r      Relative humidity (%)
   %s      Speed (m/s)
   %S      Sonde serial number
   %t      Temperature (degrees Celsius)
   %T      Timestamp (yyyy-mm-dd hh:mm::ss, local)
   %x      Decoded XDATA

TUI keybinds:
   Arrow keys: change active decoder
   Tab: toggle between absolute (lat, lon, alt) and relative (az, el, range)
   coordinates (requires -r, --location)
```

how about routing some audio to be the input using
[https://existential.audio/blackhole/](https://existential.audio/blackhole/)
- give email and download via link - I got 2 ch version
- install
- go to **Audio MIDI Setup** - as per https://existential.audio/blackhole/support/#system
    - create a **Multi-Output Device** for sound and blackhole 2ch
- under **System Settings** > **Sound** change the output to be the multi-output device
- now playing with `afplay` will decode when running `./sondedump` against the
  **BlackHole 2ch** device

```
./sondedump

==============================
Please select an audio device:
0) BlackHole 2ch
1) MacBook Pro Microphone
```

will listen to the Radiosonde tomorrow and then it's a question of switching it
to a RasPi - for portability and safety for the computer(a RasPi is cheaper to
replace)

**Update** to run sondedump just run

```sh
git clone git@github.com:saramic/ham-radio.git
cd ham-radio/experiments/in_radiosonde_sondedump

make
make build
make demo

# to clean up
make clean
```
