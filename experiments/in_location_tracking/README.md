# Experiments in location tracking

## Wiring

## ESP32

```
                              ------------------
                             | |--|  |--|  |--| |
                      EN     | |  |--|  |--|  | | GPIO23
                      GPIO36 |  --------------  | GIPO22    I2C_SCL ---- QMC5883L - SCL
                      GPIO39 | |              | | GIPO1
                      GPIO34 | | ESP-WROOM-32 | | GPI03
                      GPIO35 | |              | | GPI021    I2C_SDA ---- QMC5883L - SDA
                      GPIO32 | |              | | GPI019
                      GPIO33 | |              | | GPI018
                      GPIO25 | |              | | GPI05
                      GPIO26 |  --------------  | GPI017
                      GPIO27 |                  | GPI016
                      GPIO14 |                  | GPI04
                      GPIO12 |                  | GPI02
                      GPIO13 |                  | GPI015
                      GND    | RST  _____  BOOT | GND
                      VIN    | [ ] / USB \  [ ] | VDD 3V3
                              ------------------
```

## QMC5883L

```
                              ------------
                         VCC |          O |
                         GND |            |
           I2C_SCL       SCL |            |
           I2C_SDA       SDA |            |
                        DRDY |          O |
                              ------------
```

