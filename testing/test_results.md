# Divider Validation Results

- Tested divider scaling using board 5 V and 3.3 V rails as input sources
- Measured midpoint voltage was ~3-4% lower than predicted at both points
- This indicates a small systematic gain error (likely reference uncertainty + resistor tolerance)
- Wider-range validation will be done when additional voltage sources are available

## Raw Test Data (Excerpt)

```csv
Test_ID,Vin_Set_V,Vin_Measured_V,Vadc_Measured_V,ADC_Count,Predicted_Vadc_V,Error_Vadc_V,Notes
1,5.00,5.070,1.533,308,1.584,-0.051,Board 5V rail as Vin
2,3.30,3.301,0.995,198,1.032,-0.037,Board 3.3V rail as Vin
```
