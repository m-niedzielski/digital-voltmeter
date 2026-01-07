# RC Filtering Design

## Why Filter?

Filtering in the context of this project is useful for:
- Reducing high-frequency noise pickup (breadboard wiring, USB noise)
- Reducing ADC reading jitter
- Preventing aliasing when sampling

We are measuring slowly changing DC voltages, impling that a high (kHz-range) bandwidth is not required.

## Choosing The Update Rate & Sample Plan

The target update rate for the displayed value is 5-10 updates per second, since this will be the average of many ADC samples.
- ADC sampling: e.g. 1 kS/s
- Output update: 10 Hz
This will be important for choosing a cutoff.

## Filter Placement

The practical and effective placement for the capacitor is from the ADC input to GND, after the divider and after Rseries. 
The effective resistance before the capacitor is the source impedance calculated in the input protection design: 7.9kΩ
This resistance sets the RC cutoff.

## Choosing Capacitance Value & Cutoff Frequency

The formula for the low-pass cutoff is:

$$ f_{c} = {1\over 2π R_{effective} C} $$ 

The balance we are looking for is a capacitance value that smooths noise but still responds quickly.
The first choice is a 100 nF (0.1 µF ceramic) capacitor due to its availability. 
Computing:

$$ f_{c} = {1\over 2π * 7.9k * 100n} ≈ 200 Hz $$

This is a sensible cutoff since the displayed value at 5-10 Hz will be smooth, but the system will still respond quickly.

### Second Option
If the readings are still jumpy, I will increase the capacitance to 470nF to achieve a cutoff of 40 Hz. 
This will be much smoother at the expense of a slightly slower response (3.7ms).

## Time Constant

$$ τ = R_{effective} C = 7.9k * 100n ≈ 0.79ms $$

The hardware filter won't feel sluggish at that time constant. Most of the smoothing will come from software averaging.

## Implementation notes

- Put the capacitor physically close to the ADC pin and GND
- Use a ceramic capacitor
- Connect directly to the ADC ground reference

