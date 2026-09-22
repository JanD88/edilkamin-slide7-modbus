# Edilkamin Slide 7 — Home Assistant control over Modbus

An ESPHome config that brings an **Edilkamin Slide 7 (PELE1712)** pellet stove
into Home Assistant, over the Modbus RTU bus already present on its control
board. An ESP32 sits on the board's A/B pair and is discovered by Home Assistant
over the ESPHome API


## Entities

Discovered automatically once the node is adopted. With `friendly_name: Stove`
they land as `sensor.stove_*`, `switch.stove_power` and so on.

| Group | Entities |
|---|---|
| Control | Power, Target temperature, Power level demand |
| Status | State, Alarm active, Alarm, Power output, Flue gas temperature, Exchanger temperature, Extractor rpm, Power level (actual) |
| Diagnostics | Setpoints, operating points, raw registers, LED state and controls |



## Hardware

- **LilyGO T-CAN485**  ESP32 with a MAX13487E RS485 transceiver on board
- Tapped onto the control board's **A/B header**


## Install

Copy **both** `edilkamin-slide7.yaml` and `stove_states.h` into your ESPHome
config directory. `includes:` resolves relative to the YAML, so if the header is
missing the build gets all the way through validation and then fails at the C++
step with `stove_states.h: No such file or directory`.


Then install as usual.

## Also works without Home Assistant

`web_server` serves a control page from the ESP32 at `http://<device-ip>/`, and
`api: reboot_timeout: 0s` is what stops ESPHome rebooting the device every 15
minutes when no API client is connected.

The page is password-protected because it carries the power switch and the
setpoint. 


## Known limitation

The A/B pair is shared with the board's GSM module polling `AT` (~2.1 s bursts
every ~13 s). ESPHome has no bus-silence detection, so roughly **16% of
transactions collide**. Mitigated, not solved: the poll is three commands per
30 s (merged with `reuse_previous_range`), retried six times. The power switch is
polled back, so a write lost to a collision shows up in Home Assistant as the
switch flipping back rather than as a silent no-op.



## What is verified

Verified on hardware across a full logged burn: the power coil, the state enum,
`Power output` (ref 1002), the flue gas temperature (ref 1015  confirmed by the
panel's own TSMOK, by the ignition ramp, and by an 18-minute cooldown), and that
both the setpoint and the power level accept writes.


## Licence

MIT — see [LICENSE](LICENSE).
