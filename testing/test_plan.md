# Divider Validation Test
## Purpose
The purpose of this test is to validate the analogue front-end of the digital voltmeter by verifying correct voltage scaling, linearity and basic accuracy prior to calibration.

## Test Setup

- Microcontroller: Seeeduino Lotus (ATmega328P)
- ADC reference: Default 5 V (USB-powered)
- Input network: 22 kΩ / 10 kΩ divider with 1 kΩ series resistor and 100 nF filter
- Measurement tools: Digital multimeter (DMM)

## Test Procedure

1. Power the microcontroller via USB.
2. Connect the voltage source to the input of the divider network.
3. Measure and record the input voltage (Vin) using a DMM.
4. Measure and record the divider midpoint voltage using a DMM.
5. Record the corresponding ADC reading via the serial monitor.
6. Repeat for multiple input voltages across the operating range.

## Test Conditions

- Ambient temperature: Room temperature (~20–22 °C)
- Input signals: DC voltages only
- Test duration: Short-duration measurements (<5 minutes per point)

## Acceptance Criteria

- Divider midpoint voltage should match predicted value within ±5%.
- ADC readings should increase steadily with increasing input voltage.
- No ADC saturation or clipping should occur within the 0–15 V input range.

## Results

Test results are recorded in 'results_divider_test.csv'
