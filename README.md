# Microcontroller-based Digital Voltmeter

## Project Outline

The aim of the project is to design and implement a microcontroller-based digital voltmeter capable of measuring an unknown DC input voltage, converting it to a digital value using an on-chip ADC and display the result on an output display.  Measurements are verified against a digital multimeter (DMM). The project integrates concepts from first-year modules while also providing experience working on a project without the benefits of supplementary lectures or laboratory briefs.

## Requirements

### Functional Requirements:
- Measure DC voltage
- Display measured value
- Powered via USB
- Safe under accidental misuse

### Performance Targets (Initial)
- Voltage range: 0-15 V DC
- Resolution: ≥10 mV
- Update rate: ~5-10 Hz

## Platform
- MCU: ATmega328P (Seeeduino Lotus)
- ADC: 10 bit, single-ended
- Reference: Default 5 V (initial)

## Design Approach

The system was developed using a structured engineering process. High-level requirements were defined first, followed by block-level architecture design. The analogue front-end (divider, protection, filtering) was designed and validated using calculations and measurements before firmware development. Quantitative testing and calibration were performed using DMM reference measurements.

