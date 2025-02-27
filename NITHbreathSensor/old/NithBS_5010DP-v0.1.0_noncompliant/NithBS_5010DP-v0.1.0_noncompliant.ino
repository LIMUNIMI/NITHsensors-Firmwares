int LEDc = 2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LEDc, OUTPUT);
  digitalWrite(LEDc, HIGH);
}

void loop() {
  
  int sensorValue = analogRead(A0); // read the input on analog pin 0
  float voltage = sensorValue;
  Serial.println(voltage, 1); // Serial print
}
