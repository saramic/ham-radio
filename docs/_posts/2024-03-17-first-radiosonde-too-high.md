---
layout: post
title:  "First Radiosonde, too high 🌴"
date:   2024-03-17 22:30:00 +1100
categories: Radiosonde
---

Finally had a clear day to do some radiosonde tracking, the winds had aligned
and it was likely to land just over an hour away from home in and around
Toolangi out of Melbourne. So I packed my laptop, SDR USB, Quansheng UV-K5 and
the Yagi I made for radiosondes out of tape measure. The last reported point
was barely 50 meters off a road in some forrest. Unfrotunately the road was
private property so I had to walk the last 800m and skirted the bush land. I
was all set and pulled out my directionaly yagi and hit my first hurdle. No
matter which way I pointed, I had the same reading. So the guy from MERC club
was right, when the signal is too close in a fox hunt, you need to attenuate it
to lower it to the point where the signal strength meter on the handy talkie
could distinguish the direction the antenna is pointed in.

Still it was a positive that I was getting a loud and clear signal. It was also
lucky I brought my laptop and SDR with me, for that would mean I should be able
to decode the radiosonde APRS telemetry and, it's GPS coordinates.

[
  https://radiosondy.info/sonde_archive.php?sondenumber=V2431106
](https://radiosondy.info/sonde_archive.php?sondenumber=V2431106)

```
» dbdexter-dev-sondedump/build/sondedump

==============================
Please select an audio device:
0) BlackHole 2ch
1) MacBook Pro Microphone
Device index: 0
Selected samplerate: 48000
[decode.c:177] Autodetected: RS41
(V2431106) [24337]  67.2'C   6%    37.51369S 145.45833E    511m     0.0m/s 107'  +0.1m/s
(V2431106) [24338]  67.2'C   6%    37.51369S 145.45833E    510m     0.1m/s 272'  -0.0m/s
(V2431106) [24339]  67.1'C   6%    37.51369S 145.45833E    510m     0.0m/s 188'  -0.1m/s
(V2431106) [24340]  67.2'C   6%    37.51369S 145.45833E    510m     0.0m/s 246'  -0.0m/s
(V2431106) [24341]  67.2'C   6%    37.51369S 145.45833E    510m     0.2m/s 314'  +0.1m/s
(V2431106) [24342]  67.2'C   6%    37.51369S 145.45833E    510m     0.1m/s 280'  -0.1m/s
(V2431106) [24343]  67.2'C   6%    37.51369S 145.45833E    510m     0.1m/s  26'  -0.1m/s
(V2431106) [24344]  67.2'C   6%    37.51369S 145.45833E    510m     0.2m/s 201'  +0.1m/s
(V2431106) [24345]  67.3'C   6%    37.51369S 145.45833E    510m     0.2m/s 133'  -0.1m/s
```

With a lock on the coordinates it was time to walk out and find it. I circled a
number of times, seeing the same logs before a straight line in the sky caught
my eye. I followed it one way and found a swinging radiosonde, a good 5-10
meters up in the sky along a long and straight Eucalyptus regnans, "the tallest
flowering plants in the world", commonly known as the Mountain Ash.

<div style="width: 100%; display: flex; justify-content: flex-between;">
    <div style="padding-right: 0.2em">
        <img src="/ham-radio/assets/images/20240307_radiosonde_radar_reflector_in_tree.jpg" width="360">
        <div>
            <strong>Note: </strong>
            <i>Most likely the radar reflector</i>
        </div>
    </div>
    <div style="padding-left: 0.2em">
        <img src="/ham-radio/assets/images/20240317_radiosonde_up_tree.jpg" width="360">
        <div>
            <strong>Note: </strong>
            <i>Radiosonde, 2 trees across</i>
        </div>
    </div>
</div>

<div style="width: 100%; display: flex; justify-content: flex-between;">
    <div style="padding-right: 0.2em">
        <img
          src="/ham-radio/assets/images/20240317_phone_GPS.png"
          width="218">
        <div>
            <strong>Note: </strong>
            <i>GPS for next time</i>
        </div>
    </div>
    <div style="padding-left: 0.2em">
        <img
          src="/ham-radio/assets/images/20240317_radiosonde_caught_trout.jpg"
          width="710">
        <div>
            <strong>Note: </strong>
            <i>The Radiosonde may have got away but this brown was caught and
            released</i>
        </div>
    </div>
</div>


I was certainly not surprised, having been in these hills before, but a little
bit underprepared. Still what could I do to give it a go? I did have a spool of
3mm nylon rope, maybe about 10meters. I tied it to a rotten stick and found out
I could barely throw that high, the knot came undone and I am not even sure if
the rope had fully unfurled if it could reach the beacon. Next I tried to make
a tall proding stick, there was a bunch of wattle growing straight and thin. I
found a piece that had been broken by a falling tree. I attempted to push this
up the mountain ash, root first, to see how hight it could go, maybe a third of
the way before it fell down. I attempted to lash another piece and at this
point the whole contraption was too long and flimsy to push up the tree. I
tried but could just not get it moving anywhere near it.

Next time I go, I certainly should bring a few things with me.

1. long pants and long sleeve shirt - gone are the tough man days of getting
   all scratched up bush bashing.
1. a saw
1. a pocket knife
1. thinner rope - sounds like arborists would use a 30m - 45m throwline that is
   1.8 - 2.2mm diameter. Certainly 30m of thinner bricklayers line "builders
   line" might be a good idea
1. a "throw bag" - sounds like common sizes are 8oz 226g, 10oz 283g, 12oz 340g,
   14oz 397g - basically a metal ring on one end, and a tear drop shaped bag
   loaded with shot
1. rope for a ladder - certainly there was plenty of timber to make a ladder
   that could have got me to half the height? some rope offcuts to make a
   ladder would come in handy
1. squid pole? - supposedly you can get 8-13m for under $60
   [AliExpress](https://www.aliexpress.com/item/1005006340119901.html) - also
   if I got a heavy duty squid pole, I might be able to use it for a temporary
   aerial setup like
   [https://www.vk5pas.com/squid-poles.html](https://www.vk5pas.com/squid-poles.html)
1. drone? - not sure how exactly you would connect it to the radiosonde, but
   certainly in this case there was plenty of room to fly a drone

All these ideas still have a little left to the imagination as to how they
connect to the radio sonde? If an arborists throw bag, flies right over the
connection between the sonde and the rope, will it hold? do I need enough rope
to feed it back to earth? do I need to bring up a thicker rope? With a squid
pole, what do you exactly have at the end? just a throwline? how do you release
it? I don't think I am getting a drone any time soon.

Also for posterity I have added this as a demo snippet to the `sondedump` demo

```sh
git clone git@github.com:saramic/ham-radio.git
cd ham-radio/experiments/in_radiosonde_sondedump

make
make build
make demo
```

output

```log
make demo
sondedump v1.1 +portaudio +ncurses
[decode.c:177] Autodetected: RS41
(V2431106) [24387]  66.7'C   3%    37.51370S 145.45834E    509m     0.1m/s 112'  +0.1m/s
afplay demo/gqrx_20240317_radiosonde_V2431106.wav
```

and the recording from the
[experiments/in_radiosonde_sondedump](https://github.com/saramic/ham-radio/tree/main/experiments/in_radiosonde_sondedump)
directory

{%
  include embed-audio.html
  src="https://github.com/saramic/ham-radio/raw/main/experiments/in_radiosonde_sondedump/demo/gqrx_20240317_radiosonde_V2431106.wav"
%}

