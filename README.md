# Microcontroller-Based Digital Voltmeter

## Overview
This project implements a microcontroller-based digital voltmeter capable of measuring an unknown DC input voltage, converting it to a digital value using an on-chip ADC and reporting the result via a serial interface. Measurements are verified against a digital multimeter (DMM).

The project integrates concepts from first-year Electrical and Electronic Engineering modules including analogue circuits, digital systems and C programming. It was developed independently outside of structured laboratory coursework, with emphasis on correct modelling, validation and documentation.

---

## Requirements

### Functional Requirements
- Measure DC voltage
- Display measured value (serial output)
- Powered via USB
- Safe under accidental misuse (overvoltage)

### Performance Targets
- Voltage range: 0–15 V DC
- Resolution: ≥10 mV
- Update rate: ~5–10 Hz

---

## Platform
- Microcontroller: ATmega328P (Seeeduino Lotus)
- ADC: 10-bit, single-ended (0–1023 counts)
- ADC reference: Default 5 V (USB-powered, variable)

---

## System Architecture
The system is composed of a protected and filtered analogue front-end followed by ADC sampling and firmware-based processing.

**Signal flow:**

Vin → Input Protection → Voltage Divider → RC Filter → ADC → Firmware Processing → Output Interface

Further details are provided in `docs/system_architecture.md`.

---

## Design Approach
The system was developed using a structured engineering process:

1. Requirements definition and operating range selection
2. Analogue front-end design (divider, protection, filtering)
3. Validation of analogue behaviour using DMM measurements
4. Identification and correction of modelling errors
5. Firmware development and calibration
6. End-to-end verification against reference measurements

Design calculations, assumptions and trade-offs are documented in `hardware/calculations/`.

---
## Hardware Prototype

The analogue front-end and microcontroller were prototyped on a breadboard and validated using DMM measurements. Representative build photos are provided in `hardware/photos/`.

---

## Testing and Calibration
Quantitative testing was performed using a digital multimeter as a reference. Initial validation focused on verifying correct divider scaling and ADC behaviour prior to calibration.

Due to limited available reference voltages, final calibration was implemented using a two-point linear model mapping ADC counts directly to input voltage. This approach compensates for ADC reference uncertainty and component tolerances within the tested range.

Test procedures and results are documented in the `testing/` directory.

---

## Results
Using two DMM-measured reference points (3.301 V and 5.113 V), the calibrated output matched the reference within approximately ±1 mV at both points.

This confirms correct end-to-end operation of the measurement system within the tested range.

---

## Limitations and Future Improvements
- Accuracy is limited by ADC reference stability and component tolerances
- Calibration constants are currently stored as compile-time values
- No isolation is provided for high-energy or mains-level faults

Potential future improvements include:
- EEPROM-stored calibration constants
- Use of the internal 1.1 V reference for improved accuracy
- Addition of a display module
- PCB implementation

---

## Repository Structure
- `docs/` – System architecture and high-level documentation
- `hardware/` – Design calculations and hardware-related notes
- `firmware/` – Source code and implementation notes
- `testing/` – Test plans and measurement results (CSV)

---

## Author Notes
This project was developed as a first-year engineering exercise to gain experience in independent design, validation and documentation of an embedded measurement system.
