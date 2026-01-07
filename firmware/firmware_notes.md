# Calibration Implementation Notes

## Overview
A single-point gain calibration is applied to the computed input voltage to correct systematic measurement error.

## Calibration Process
1. Raw ADC count is converted to ADC voltage.
2. ADC voltage is scaled to input voltage using divider ratio.
3. A gain correction factor is applied.

## Calibration Constant
The gain correction constant K is stored as a compile-time constant.

The gain correction constant was determined experimentally using two reference voltages and averaged to K = 1.035.

Future versions may store this value in non-volatile memory to allow recalibration without recompilation.

## Rationale
A gain-only calibration was selected due to the observed proportional error behaviour and the absence of a significant offset error.
