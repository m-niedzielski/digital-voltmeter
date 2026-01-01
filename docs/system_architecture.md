# System Architecture

## Overview
This document describes the high-level architecture of the microcontroller-based digital voltmeter.

## Block Diagram

<img width="211" height="541" alt="block_diagram" src="https://github.com/user-attachments/assets/3505e723-30d1-4c06-90f1-3a3d7ab59987" />

## Block Descriptions

### Input Protection
Limits current and voltage to protect the ADC input in case of overvoltage.

### Voltage Divider
Scales the input voltage to within the ADC input range.

### RC Filter
Reduces high-frequency noise and limits aliasing.

### ADC (ATmega328P)
Samples the conditioned analogue signal and converts it to a digital value.

### Firmware Processing
Performs scaling, filtering and calibration.

### Output Interface
Displays the measured voltage via serial output or display.
