# Shepard tone

As my son played with his "130 in 1 electronic circuits", he built a falling
bomb sound, going from high pitch to low and that is it. This got me thinking
of the shepard tone. A continual descending tone illusino created by numerous
descending parts that are quieter when they start and end.
A Shepard tone is an auditory illusion that creates the impression of a tone
that continually ascends (or descends) in pitch, yet never seems to get any
higher or lower—like an audio version of a barber’s pole.


__START GPT__

It is produced by layering several sine waves separated by octaves. As the
pitch of all the sine waves rises, the highest fades out and the lowest fades
in, so the overall sound seems to rise endlessly without ever reaching a limit.
This effect tricks the brain into perceiving a never-ending scale.

Shepard tones are used in music, sound design, and film to create tension or
the illusion of infinite movement.

## Hardware circuit

To create a Shepard tone in hardware, you need to generate several sine waves
separated by octaves, mix them together, and control their amplitudes so that
the highest and lowest fade in and out as the pitch rises or falls. The core
components are:

- **Multiple Oscillators:** At least 6–10 sine wave oscillators, each tuned to
  a frequency one octave apart. These can be implemented with:
  - Analog sine wave oscillators (e.g., Wien-bridge, XR2206, ICL8038, or
    function generator ICs)
  - Digital synthesis using a microcontroller with a DAC (e.g., Arduino/ESP32
    with external DAC or audio shield)

- **Voltage-Controlled Amplifiers (VCAs):** To fade each oscillator in and out
  smoothly as their pitch rises or falls. VCAs can be built with op-amps,
  transistors, or dedicated ICs (e.g., LM13700).

- **Mixer:** An analog summing circuit (op-amp mixer) to combine all oscillator
  outputs into a single audio signal.

- **Control Circuit:** A way to sweep the frequencies of all oscillators
  together (e.g., a ramp generator or microcontroller with timers) and modulate
  the VCAs for the fade effect.

- **Audio Output:** The mixed signal is sent to an amplifier and speaker or
  headphones.

**Summary:**
- 6–10 sine wave oscillators (analog or digital)
- 6–10 VCAs for amplitude envelopes
- Summing mixer
- Frequency sweep/control circuit
- Audio output (amplifier + speaker)

A microcontroller with audio output (DAC or PWM + filter) can implement all of
this digitally, but a fully analog version is possible with the above building
blocks.

__END COPILOT__

seems to me like I would need:
- a number of oscillators
- have those oscillators to be voltage controlled VCO's
- a ramp circuit that would controll the VCO's
- a way to trigger the ramp circuits
- keep them all in sync together

- or maybe just a custom wave form that has these characteristics and just
  looped?

- so let's start with some ramps and oscillators?

## Ramp generator

https://electronics.stackexchange.com/questions/202943/ramp-generator-using-op-amp

Which got me looking for integrators

**#61: Op amp oscillators, integrators, and waveforms - Radio Physics and
Electronics**

[![
  #61: Op amp oscillators, integrators, and waveforms - Radio Physics and
  Electronics
](
  http://img.youtube.com/vi/PIsNKq9kDTQ/0.jpg
)](https://youtu.be/PIsNKq9kDTQ)

- seems a bit un clear
- no ramp here
- need to build along maybe
- [ ] need to re-watch

and function genertor circuits
- https://learningaboutelectronics.com/Articles/Function-generator-circuit.php#google_vignette

**Build A Simple Sine Wave Oscillator - The AudioPhool**

[![
  Build A Simple Sine Wave Oscillator - The AudioPhool
](
  http://img.youtube.com/vi/9Y9yS2hhsik/0.jpg
)](https://youtu.be/9Y9yS2hhsik)

- [ ] need to watch

**OpAmp, the Ultimate Component (ElectroBOOM101 – 013) - ElectroBOOM**

[![
  OpAmp, the Ultimate Component (ElectroBOOM101 – 013) - ElectroBOOM
](
  http://img.youtube.com/vi/9Y9yS2hhsik/0.jpg
)](https://youtu.be/9Y9yS2hhsik)

- [ ] need to watch

A great simple introduction to making sine waves, in particular by using
filters that change the phase, there by removing all other harmonics from a
square wave and leaving the dominant sine wave 🤯.

**5 Ways To Generate A Sine Wave (Analog) - Sine Lab**

[![
  5 Ways To Generate A Sine Wave (Analog) - Sine Lab
](
  http://img.youtube.com/vi/EhMk6DUbbPk/0.jpg
)](https://youtu.be/EhMk6DUbbPk)
