---
layout: post
title:  "Success with Yagi for radiosondes"
date:   2024-03-12 11:30:00 +1100
categories: Yagi radiosonde
---

### Yagi soldered and connected

for better or for worse, I have attached the coax to the Yagi!

![]()

Learnings:
- drill the hole and put the cable through "before" attaching the connector and
  making the job having to be done in reverse with a shorter lead
- bit of a pill trying to cut the coax with a retractable blade utility knife
  but after a few accidental mis cuts I managed.
- Hex cirmping tool probably more important - the hold is pretty loose, and the
  center pin can be retracted

And directing the antenna certainly has a marked difference on the signal
strength readout

<div style="width: 100%; display: flex; justify-content: flex-between;">
    <div style="padding-right: 0.2em">
        <img src="/ham-radio/assets/images/20240312_radiosonde_yagi_full_strength_direction.jpg">
        <div>
            <strong>Note: </strong>
            <i>full strength 📡 📶</i>
        </div>
    </div>
    <div style="padding-left: 0.2em">
        <img src="/ham-radio/assets/images/20240312_radiosonde_yagi_weak_strength_direction.jpg">
        <div>
            <strong>Note: </strong>
            <i>strength reading of only 2 bars</i>
        </div>
    </div>
</div>

### Script to screen grab daily sonde

I wrote a script to predict as well as grab the radiosonde location and map as
an image. The idea is to have this run on CRON somewhere and get a daily
reminder if the radiosonde is likely to land in an easy to get to place. Today
unfortnately it looks like it's 200km away in the middle of Victorian Alps near
Macalister Spring.

![](/ham-radio/assets/images/20240312_demo_radiosonde_notifier.gif){: width="480"}

```sh
git clone git@github.com:saramic/ham-radio.git
cd ham-radio/experiments/in_radiosonde_notifier/
make
make install
make demo
```

