# Microcontroller-based Digital Voltmeter

## Project Outline

The aim of the project is to create a device which is able to take an unknown input voltage, use a microprocessor to assign that voltage a number, verified by a digital multimeter (DMM) and display the number on an output display. The motivation behind this project is to bring together concepts I have encountered in my modules in my first semester while also providing experience working on a project without the benefits of supplementary lectures or laboratory briefs.

## Requirements

### Functional Requirements:
- Measure DC voltage
- Display measured value
- Powered via USB
- Safe under accidental misuse

### Performance Targets (Initial)
- Voltage range: 0-15 V
- Resolution: ≥10 mV
- Update rate: ~5-10 Hz

## Platform
- MCU: ATmega328P (Seeeduino Lotus)
- ADC: 10 bit, single-ended
- Reference: Default 5 V (initial)
