const int VIN_ADC_PIN = A3;
const float M = 0.016625f; // V per ADC count
const float B = 0.008f; // V offset

void setup() {
 Serial.begin(9600);
}

void loop() {
  int adc = analogRead(VIN_ADC_PIN);
  float vin = M * adc + B; // Calibration

   Serial.print("ADC=");
  Serial.print(adc);
  Serial.print("  Vin=");
  Serial.println(vin, 3);

  delay(200);
}
