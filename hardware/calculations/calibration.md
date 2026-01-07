# Calibration Strategy

## Purpose

The purpose of calibration is to reduce systematic measurement error caused by uncertainty in the ADC reference voltage and component tolerances.

## Observed Behaviour
Initial test results show that the measured ADC midpoint voltage is consistently lower than the predicted value. The error magnitude increased proportionally with the input voltage.
This indicates a dominant gain error rather than a fixed offset error.

##  Initial Calibration Hypothesis
Given the proportional nature of the observed error, a single-point gain calibration model is sufficient:

$$ V_{corrected} = V_{measured} * K $$

where K is a calibration gain constant.

## Exploratory Gain Constant (Pre-model Correction)
The gain constant is determined using a known reference voltages:

$$ K = {V_{reference}\over V_{measured} } $$


Using Vin = 5 V from the MCU , 3.3 V from the MCU
- Measured Vin = 5.070 V, 3.301 V 
- Uncalibrated computed Vin = 4.906 V, 3.184 V

$$ K_1 = {5.070\over 4.906} = 1.0334 $$

$$ K_2 = {3.301 \over 3.184} = 1.0367 $$

These values are very close, confirming error is primarily gain and a single gain calibration is appropriate.
An average gain constant was selected: 

$$ K_avg = {1.0334 + 1.0367 \over 2} = 1.0351 $$

$$ K = 1.035 $$

This gain-only calibration was not applied, as further investigation revealed the dominant error source to be an incomplete divider model rather than true system gain error.


## Model Correction

Further investigation showed that the apparent gain error was largely caused by omitting the 1 kΩ series protection resistor from the divider model. After updating the divider equation to include Rseries, measured midpoint voltages closely match predictions.

A model-corrected validation dataset is provided in `testing/results_corrected_divider.csv`.

At this stage, no additional gain calibration constant is applied. Remaining error is expected to be dominated by ADC reference uncertainty and component tolerances.

## Final Calibration Method: Two-Point Linear Model 

After correcting the divider model, a two-point linear calibration was selected as the final calibration method due to limited available reference voltage.

$$ V_{in} = m*ADC + b $$

Reference points used:
- Vin = 5.113 V at ADC = 307
- Vin = 3.301 V at ADC = 198

Computed calibration parameters:
$$ m = {(5.113 - 3.301)\over (307-198)} = 0.0166548 V/count $$
$$ b = 5.113 - (m* 307) = 0.0082 V $$

This model reduces dependence on the assumed ADC reference voltage and compensates for systematic gain/offset within the tested range.

## Calibration Verification

With the two-point calibration applied, the computed input voltage closely matches DMM measurements at both available reference points. Remaining error is within a few millivolts, confirming correct end-to-end behaviour within the tested range.

Verification results are recorded in `testing/results_calibration_accuracy.csv`.


