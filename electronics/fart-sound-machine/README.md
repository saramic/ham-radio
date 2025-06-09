# Fart Machine

My son got to wiring up a two tone siren on one of those "130 in 1 electronic
lab" kits where you connect components using spring terminals. Very quickly he
experimented with capcitors and got a low "fart" sound. This mixed with a
recent Instagram post of a public prankster playing fart sounds on purpose and
recording the reaction of the people around him got him acting out the farting
whilst pressing the sound switch. This lead us on how to actually create such a
circuit.

After a short shearch we found there is an electric guitar fart pedal

## Fart Pedal

**I Made My Own Fart Pedal - 66Samus**

[![
  I Made My Own Fart Pedal - 66Samus
](
  http://img.youtube.com/vi/8FReojp5L4c/0.jpg
)](https://youtu.be/8FReojp5L4c)

which is made by this mob
and sells at the price you might imagine for a pro guitar pedal ~$500

You can even customise it

**Customize your Fart Pedal with NEW sound effects! - The Fart Pedal**

[![
  Customize your Fart Pedal with NEW sound effects! - The Fart Pedal
](
  http://img.youtube.com/vi/dYP5L-hNBe8/0.jpg
)](https://youtu.be/dYP5L-hNBe8)

unfortunately the link no longer works

https://thefartpedal.com/pages/downloads

but is on wayback machine

https://web.archive.org/web/20250209210738/http://thefartpedal.com/pages/downloads

linking off to the shopify links

```sh
wget https://cdn.shopify.com/s/files/1/0621/2452/3771/files/ClassicPack.zip?v=1678754246
wget https://cdn.shopify.com/s/files/1/0621/2452/3771/files/MonoNeon.zip?v=1678754246
wget https://cdn.shopify.com/s/files/1/0621/2452/3771/files/SuperFarts.zip?v=1678754246
wget https://cdn.shopify.com/s/files/1/0621/2452/3771/files/LumpyDumpers.zip?v=1678756103
```

yes please

Which got me thinking, is this a circuit thing?

## Analog farting synthesizer


**THE FART BOX, A Completely Analog Farting Synthesizer - LOOK MUM NO
COMPUTER**

[![
  THE FART BOX, A Completely Analog Farting Synthesizer - LOOK MUM NO COMPUTER
](
  http://img.youtube.com/vi/F7qlc5EVydo/0.jpg
)](https://youtu.be/F7qlc5EVydo)

curcuit board
- https://store.lookmumnocomputer.com/products/fart-box-pcb-limited-edition-white
- uses a bunch of TL072/TL074's and
- an **AS3340 VCO** Analog VCO with three waveforms (Ramp, Triangle,
  Square/Pulse)
    - The AS3340 chip is Alfa’s modern equivalent of the famous CEM3340
      voltage-controlled oscillator. It provides Ramp, Pulse/Square, and
      Triangle outputs, has inputs for oscillator sync, is temperature
      compensated and stable, and provides excellent 1V/Oct tracking. In short,
      it’s everything you need from an analog oscillator, on a chip. There
      hasn’t been a better design than the 3340.
    - https://electricdruid.net/product/as3340-vco/
    - or via EBay - https://www.ebay.com.au/itm/332525404566
    - https://sdiy.info/wiki/CEM3340
and the build
- https://www.lookmumnocomputer.com/projects#/fart-box

a follow up with an equivalent built using the software Rekator
- https://www.youtube.com/live/q9ED9f3Z5To
and even build videos
- https://www.youtube.com/watch?v=9hK8nuSInkE

some genuinely cool other projects there
- https://www.lookmumnocomputer.com/projects

## MP3 player cuircuit

as the synthesizer does not come with a schematic, maybe the best option is to
use those fart ogg vorbis/mp3 files and just play them using an SD card MP3
player curcuit.

probably a DFPlayer mini MP3 vs the older SOMO-14D?
    - https://www.rpelectronics.com/dev-09534-audio-module-somo-14d.html
    - https://www.mouser.com/ProductDetail/4D-Systems/SOMO-14D

and library to play it

- https://www.hackerspace-ffm.de/wiki/index.php?title=SimpleSDAudio

## Farts on GitHub

- https://github.com/alexmfink/compufart
- https://github.com/RohanGautam/fart
- https://github.com/miguelmota/fart-button

## Fart sound effects

- https://www.soundjay.com/fart-sound-effect.html
- https://uppbeat.io/sfx/category/body/fart

Even on Wiki Commons

https://commons.wikimedia.org/wiki/File:Wet_fart_tummy_rumbles.ogg

originally from a now defunct **pdsounds**

https://web.archive.org/web/20250420222924/https://pdsounds.org/fart-sound-2/

## Fart powered TV changer

More based on the actual gas produced by real farts I think

- https://forum.arduino.cc/t/fart-operated-random-channel-tv-remote/8271
- https://www.instructables.com/Fart-Operated-Random-Channel-TV-Remote/

## Fart Bugger

**The Fart Bugger - Makes 6 Random Fart Sounds! ASSEMBLY & Demo Video - patrickikis**

On YouTube -> https://www.youtube.com/watch?v=m0QNnpusX-c

and website http://www.engineeringshock.com/

where they actually have some tutorials linked
- http://www.engineeringshock.com/tutorials.html
- awesome voice changer kit
- ultrasonic experimenters page
- buddy talker kick starter -
  http://www.engineeringshock.com/the-little-buddy-talker-project-page.html
- rfid - http://www.engineeringshock.com/fast-rfid-project-page.html
- ninja counter -
  http://www.engineeringshock.com/ninja-counter-project-page.html

another website that is defunct but has a ripper track on startup
- https://web.archive.org/web/20180305233732/http://electroniclessons.com/
- which leads to the ebay store
    - https://web.archive.org/web/20180214032708/http://stores.ebay.com/engineeringshockelectronics
    - which seems to have a bunch of very expensive escape room props, some
      good ideas in there:
        - A Key Based Solenoid Lock Switch! An Escape Room Prop !
        - A Light Sensor Based Escape Room Prop With Electromagnetic Lock
        - A Secret Drawer/Bookshelf Electronic Escape Room Prop!
        - A Stranger Things LED Christmas Lights Message Board - Escape Room
          Prop Set
        - Betty paintball bomb prop game
        - Charge The System To Open The Secret Compartment Escape Room Prop -
          v2.0 
        - Charge The System To Open The Secret Compartment! An Escape Room Prop
        - Escape Room Prop: Blow out simulated Candles (LEDs) To Release A
          Magnetic Lock
        - Escape room props game - Insert USB Stick
        - Laser tripwire heist game for escape rooms - TONs of hardware!
          Escape room prop
        - North-Korea escape room prop game
        - Paintball / airsoft vibration based target practice module + AC
          adapter & siren
        - RFID escape room prop - 5x readers with magnetic lock
        - RFID escape room prop game
        - Speech Controlled Linear Actuator Door Opener - Escape Room Prop Set 
        - THE SASSY & SARCASTIC KEYPAD BASED escape room prop !
        - The "Homeland Artificial Intelligence Defence System" Escape Room
          Prop
        - The 11-IN-1 Multi Escape Room Prop Set! RFID / laser grid / bomb prop
          + MORE!
        - The 20x digit 5x button electromagnetic lock controller escape room
          prop set !
        - The 3x Foot Switch Electromagnetic Controller Escape Room Prop ! 
        - The 8 - Digit Electromagnetic Combination Lock Escape Room Prop With
          LCD
        - The 9-IN-1 Multi Escape Room Prop Set! USE THIS PROP OVER AND OVER!
        - The Bio-Hazardous Materials Lab Escape Room Talking escape room prop
        - The Centre For Disease Control Escape Room Prop Game - PRIMUS XR555 
        - The DEFCON 1 Escape Room Prop - NUCLEAR WAR IS IMMINENT ! 
        - The Dual Key Switch Electromagnetic Lock Controller Escape Room Prop
        - The Escape Room Specific Explosive BOMB Prop! Escape room prop
        - The Extinction Level Event "ELE" Escape Room Game Prop!
        - The Keypad Controlled Linear Actuator Secret Door Compartment Escape
          Room Prop
        - The LED Button Based Combination Lock Escape Room Prop - TONS OF
          HARDWARE
        - The Laser Controlled Linear Actuator Escape Room Prop Set
        - The Pulsar -  paintball airsoft laser tag time bomb prop w/ PULSING
          LEDs
          + MORE!
        - The RFID Controlled Linear Actuator Escape Room Prop
        - The Speech Controlled Linear Actuator Door Opener - Escape Room Prop
          Set
        - The Talking Coin Slot Magnetic Lock Escape Room Prop
        - The domination box - capture the flag - electronic paintball airsoft
          milsim prop
        - The mine cutter electronic paintball time bomb prop with countdown
          timer V2.0
        - The wireless Betty V4.0 talking escape room bomb prop - fully
          assembled & tested
        - escape room prop - speech recognition game
        - escape room prop game - electronic safe
        - stranger things christmas message lights escape room prop
        - switch based escape room prop game

looks intruiging but no logger seems to make mention of the fart bugger
¯\_(ツ)_/¯

