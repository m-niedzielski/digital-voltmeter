# Voltage Divider Calculations

## Assumptions
- Maximum input voltage: 15 V DC
- MCU: ATmega328P (Seeeduino Lotus)
- ADC reference voltage: 5 V (default)
- Target ADC max input: ≤ 4.8 V (margin)

The ATmega328P ADC requires a source impedance ≤ 10 kΩ for accurate conversion.

## Choosing Divider Ratio 

$$ V_{ADC,max}​=V_{IN,max}​*{R2\over R1​+R2}​​​≤4.8V $$
$$ {R2\over R1 + R2} ≤ {4.8\over 15} = 0.32 $$

## Choosing Practical Resistor Values

### Constraints:
- Uses common E12/E24 values
- Keeps source impedance ≤ 10kΩ
- Minimises power dissipation

The selected resistor values are R1 = 22 kΩ and R2 = 10 kΩ (ratio = 0.3125). The resistor values were selected so that the ADC input voltage remains below 5 V at the maximum input voltage while also keeping below the source impedance outlined in the ATmega328P ADC specification. Common resistor values are used to simplify prototyping.

### Checking Scaling:

$$ V_{ADC, max} = 15 * {10\over 22 + 10} = 4.69V $$

4.69 V ≤ 4.8 V, so we have a safe margin.

## Checking Source Impedance

$$ R_{source} = R1 || R2 ≈ 6.9kΩ $$

6.9 kΩ ≤ 10 kΩ therefore our source impedance is within the ADC spec.

## Checking Power Dissipation

Worst case current:

$$ I = {15\over 32kΩ} ≈ 0.47mA $$

Power in R1:

$$ P ≈ 5mW $$

This is well below the limits of the system.

## Resolution Analysis

ADC step size: 

$$ LSB = {5V\over 1023} ≈ 4.88mV $$

At the input: 

$$ LSB_{input} = {4.88\over 0.3125} ≈ 15.6mV $$

This matches the resolution target of ≥ 10 mV.

## Effect of Series Resistor

Rseries is in series with the voltage divider, therefore it is significant in calculations. The updated divider ratio to accommodate this is:

$$ V_{midpoint} = V_{in} * {R_2 \over R_{series} + R_1 + R_2 } $$

$$ V_{in} = V_{midpoint} * {33k \over 10k} = V_{midpoint} * 3.3 $$

Including Rseries slightly reduces the divider ratio compared to the ideal case, and this corrected model is used in subsequent calibration and firmware calculations.

This divider design satisfies voltage, impedance, resolution and power constraints for the intended operating range.

​​​
