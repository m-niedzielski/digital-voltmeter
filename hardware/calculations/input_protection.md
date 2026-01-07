# Input Protection Design

## Fault Scenarios Considered
- Accidental overvoltage 
- Reverse polarity connection
- ESD / transient spikes (limited scope)
Mains-level faults are considered out of scope for this project.

## ADC Pin Limits
From the ATmega328P datasheet:
- ADC input voltage: -0.5 V to Vcc + 0.5 V
- Input protection diodes conduct outside this range

This information indicates that the MCU already has internal clamp diodes and therefore the external circuitry implemented must limit the current into these diodes.

## Protection Strategy

A three-part protection scheme is used, featuring:
- A series resistor
- Clamp diodes (internal to the MCU)
- Existing divider resistors
This strategy was selected as it provides adequate protection with minimal impact on measurement accuracy and without unnecessarily increasing the component count.

## Choosing Series Resistor

The purpose of this resistor is to limit the current into the ADC protection diodes during overvoltage. 
Ideally this resistor value will have a small effect on measurement and cause a large reduction in fault current.
A series resistor of Rseries = 1 kΩ was selected.

### Worst-case example

Suppose that the input voltage is 24 V (a plausible overvoltage scenario; a common lab supply) and the ADC pin is clamped at ~5.5 V, the voltage across Rseries is ≈ 18.5 V.

The current in Rseries is: 

$$ I = {18.5\over 1kΩ} = 18.5mA $$

This is within typical short-duration safe limits for MCU protection diodes.

## Clamp Strategy

While considering the clamp strategy two options were evaluated. 
The first option was to rely on the MCU's internal protection diodes with a series resistor to limit current which would be simple and acceptable for my first iteration. 
In further iterations, I would like to add external Schottky diodes to 5 V and GND to lower the clamp voltage and protect the internal diodes.
However, I do not currently have any Schottky diodes so for the first iteration I will rely on the internal diodes. This approach is considered sufficient for short-duration fault conditions typical of laboratory use.


## Effect On Measurement Accuracy
Naturally, adding a series resistor for the protection network contributes to our source impedance. The total source impedance is now:

$$ R_{source} ≈ R_{series} + (R1 || R2) = 1 kΩ + 6.9 kΩ = 7.9 kΩ $$ 

This is still under the 10 kΩ spec outlined in the datasheet for the ATmega328P.

## Justification

A 1 kΩ series resistor was added to limit the current into the ADC protection diodes in the case of overvoltage. 
This value provides sufficient current limiting while maintaining a total source impedance below 10 kΩ as outlined by the ADC specification, ensuring  measurement accuracy is not significantly degraded.
