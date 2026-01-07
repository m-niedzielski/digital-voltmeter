# Calibration Strategy

## Purpose

The purpose of calibration is to reduce systematic measurement error caused by uncertainty in the ADC reference voltage and component tolerances.

## Observed Behaviour
Initial test results show that the measured ADC midpoint voltage is consistently lower than the predicted value. The error magnitude increased proportionally with the input voltage.
This indicates a dominant gain error rather than a fixed offset error.

## Calibration Model Selection
Given the proportional nature of the observed error, a single-point gain calibration model is sufficient:

$$ V_{corrected} = V_{measured} * K $$

where K is a calibration gain constant.

## Determining The Gain Constant
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

## Model Correction

Initial apparent gain error was largely caused by omitting the 1 kΩ series protection resistor from the divider model. After updating the divider equation to include Rseries, measured midpoint voltages closely match predictions.

A model-corrected validation dataset is provided in `testing/results_corrected_divider.csv`.

At this stage, no additional gain calibration constant is applied. Remaining error is expected to be dominated by ADC reference uncertainty and component tolerances.
