---
layout: post
title:  "Caught First Radiosonde, 🛬"
date:   2024-04-07 12:00:00 +1000
categories: Radiosonde
---

_caught 2024-04-05 1am written 2024-04-07 12pm_

Finally after a number of failed attempts I have caught a radiosonde.

![](
  /ham-radio/assets/images/20240404_radiosonde_trophy_at_home.jpg
){: width="480"}

I had attempted to drive out to a few nearby radiosondes like when
[V2431368](https://radiosondy.info/sonde_archive.php?sondenumber=V2431368)

![](
  /ham-radio/assets/images/20240404radiosondy.info_sonde_archive.php_sondenumber=V2431368.jpg
){: width="480"}


landed in Wollert near Mill Park - but as it is subrubia it was found, most
likely on landing so rocking up 1 hour late was not going to cut it. On last
Thursday  4th of April I decided to see if I could still get a signal from that
days radiosonde which seemed to land in an industrial estate and or the nearby
grass lands it was heading for around Epping
[V2431234](https://radiosondy.info/sonde_archive.php?sondenumber=V2431234).

![](
  /ham-radio/assets/images/20240404radiosondy.info_sonde_archive.php_sondenumber=V2431234.jpg
){: width="480"}

As I got into the car I decided to fire up the radio just to make sure it works
and what do I hear? the sound of a fresh radiosonde. Sure enough
[V2430897](https://radiosondy.info/sonde_archive.php?sondenumber=V2430897) is
bound to land around Sunbry so if I was luck I could pick both of them up.

I got out to Epping and nothing, just the sound of the currently sounding one
heading for Sunbry. I attempted to predict an updated path of where it might
fall using [predict.sondehub.org launch_altitude=21000
](https://predict.sondehub.org/?profile=standard_profile&pred_type=single&launch_altitude=21396&launch_latitude=-37.6775&launch_longitude=144.915&ascent_rate=5&burst_altitude=30000&descent_rate=8&format=csv&prediction_type=single)
using the launch and coordinates of where the radiosonde was currently sounding
21km up. I got a prediction 9minutes down the road, so I headed there. When I
got there I saw where the balloon was and it seemed to be landing back near the
airport. Off I drove and arrived at the back of the airport and sure enough, as
I corner, right there barely 5 meters from the airport perimmiter fence, on the
road is the triangle reflector. I park the car, grab the reflector and follow
the string towards some grass and finally a tree. I pull on the string, and too
late realise that the radiosonde was likely at my height but I have just pulled
it up into a 7 metere gum tree. Luckly it does not get stuck and the little
syrofoam box falls to the ground at my feet. I grab it all and stuff it into
the back of the car. I switch my radio on and it still receives the familiar
signal. I pry the radiosonde appart, pop out one of the Enegrizer lithium
batteries and radio silence. I drive home listening to ABC late night quiz,
hang the radio sonde in the living room as some kind of a hunting trophy and go
to sleep

![](
  /ham-radio/assets/images/20240404radiosondy.info_sonde_archive.php_sondenumber=V2430897.jpg
){: width="480"}

![](
  /ham-radio/assets/images/20240404_radiosonde_landed_near_airport.jpg
){: width="480"}

## Next time

So I have started experimenting with some Microcontroller (ESP32) based
[experiments/in_location_tracking](https://github.com/saramic/ham-radio/tree/main/experiments/in_location_tracking)
using GPS, Magnetic sensor and OLED display to track direction. Looking at
driving and trying to get an update on where the radiosonde is and where it is
planning to land I would imagine a system like the following would be
beneficial

- mounting in the car
- large display that stays on and gives all the relevant data - like an iPad
- a live decoded radio signal - with coordinates and altitude, say from my
  computer or in future from a de-tuned LoRa module. In the mean time it could
  just be fed directly from the
  [https://radiosondy.info/](https://radiosondy.info/) site?
- a zoomed in version of the map on the balloon and the predicted land site
- updates of the land site given current data and maybe looking up the
  [https://predict.sondehub.org](https://predict.sondehub.org) site, not sure
  how it deal with a falling object only? maybe put in current coordinates and
  say that is the hight of the pop?
- a clear indication of it is rising and or falling
- prediction of when it will fall
- updated prediction of fall based on descent rate and hight
- updated driving instructions to the location it is predicted to land
- and given I am trying to brush up on some angular in my other learning blog
  [https://saramic.github.io/learning/](https://saramic.github.io/learning/)
  may as well look at that. it will probably just be an extension of my
  [experiments/in_radiosonde_notifier
  ](https://github.com/saramic/ham-radio/tree/main/experiments/in_radiosonde_notifier)

TODO - image of this dashboard idea!!!


