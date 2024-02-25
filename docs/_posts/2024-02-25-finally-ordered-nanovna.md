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
