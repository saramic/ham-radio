---
layout: post
title:  "More radiosonde with project Horus"
date:   2024-02-29 20:00:00 +1100
categories: radiosonde morse
---

### Watching STM32 Dev boards from the sky

watched

STM32 Development Boards (literally) Falling From The Sky - linux.conf.au

[![
  STM32 Development Boards (literally) Falling From The Sky - linux.conf.au
](
  http://img.youtube.com/vi/YBy-bXEWZeM/0.jpg
)](https://youtu.be/YBy-bXEWZeM)

seems like a whole bunch of tools and links I had not come across

- Recycling the radiosondes
  - https://github.com/darksidelemm/RS41FOX - for fox hunting
  - https://github.com/darksidelemm/RS41HUP (no longer maintained)
    - alternative for custom software for Vaisala RS41
      [https://github.com/mikaelnousiainen/RS41ng](https://github.com/mikaelnousiainen/RS41ng)
    - It is possible to recycle RS41-SGP sondes for amateur radio use without
      any electrical changes
      [https://github.com/whallmann/RS41HUP_V2](https://github.com/whallmann/RS41HUP_V2)
  - programmer like [STLINK-V3MINIE](https://au.mouser.com/ProductDetail/STMicroelectronics/STLINK-V3MINIE?qs=MyNHzdoqoQKcLQe5Jawcgw%3D%3D)
  - reuse for own telemetry balloons
    - https://github.com/projecthorus/horusbinary
        - now use
          [https://github.com/projecthorus/horusdemodlib](https://github.com/projecthorus/horusdemodlib)
          - High Altitude Balloon Telemetry Library
        - has input from David Grant Rowe - desinger of [Codec
          2](https://en.wikipedia.org/wiki/Codec_2) -
          [https://www.rowetel.com](https://www.rowetel.com)
            - [https://github.com/drowe67/codec2](https://github.com/drowe67/codec2)
            - this is the guy who's video I remember where he was introduced as
              donig something better than closed source companies?
            - should watch David Rowe presents on codec2 and SM1000
              [![
                David Rowe presents on codec2 and SM1000 - Peter Marks
              ](
                http://img.youtube.com/vi/MxqdGL8QfIA/0.jpg
              )](https://youtu.be/MxqdGL8QfIA)
            - and take a look at his
              [SM1000](https://www.rowetel.com/wordpress/?page_id=3902)
  - could reuse them for something like [Open Glider
    Network](http://wiki.glidernet.org/)
- [http://www.projecthorus.org/](http://www.projecthorus.org/) is an amateur
  high altitude balloon project based in Adeliade
- they upload to [https://sondehub.org/](https://sondehub.org/)
- ultimately they suggest your run [Automatic Radiosonde Receiver
  Utilities](https://github.com/projecthorus/radiosonde_auto_rx)
  - upload to [https://sondehub.org](https://sondehub.org)
  - use
    [https://github.com/projecthorus/chasemapper](https://github.com/projecthorus/chasemapper)
    if offline
- they do mention that APRS data is also uploaded to sites, presumably like [https://aprs.fi](https://aprs.fi)
