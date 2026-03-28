# Electronics basics

- a transister turned on and off
- turn it on and off with an Arduino Nano
  - attempt to see if there is any difference in the wave shape if there is a
    10k resister between the base and GND - NOTHING observed
- turn a pin ON/OFF quickly - observe 8MHz on TinSA if the antena is placed
  next to the wire from the pin

also got this nifty way to manage small main.cpp files as per
- https://community.platformio.org/t/here-is-a-simple-way-to-have-many-small-main-apps/26009

```sh
brew install platformio

pio run -t upload -e blink
pio run -t upload -e radio-pin
```