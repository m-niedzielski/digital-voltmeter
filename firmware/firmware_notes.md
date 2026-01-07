# Calibration Implementation Notes

## Overview
A two-point linear calibration is applied to convert raw ADC counts directly to the input voltage. This approach compensates for ADC reference uncertainty and component tolerances within the tested operating range.

## Calibration Process
1. The raw ADC count is read from the analogue input.
2. The input voltage is computed using a linear model:
   
   Vin = m · ADC + b

3. The computed voltage is output via the serial interface.

## Calibration Constants
The calibration constants m and b are stored as compile-time constants in firmware.

These constants were derived experimentally using two DMM-measured reference voltages and their corresponding ADC readings, as documented in `hardware/calculations/calibration.md`.

## Rationale
A two-point linear calibration was selected due to limited available reference voltages and observed session-to-session variation in ADC reference voltage. This method provides accurate end-to-end voltage measurement without relying on an assumed fixed ADC reference.
