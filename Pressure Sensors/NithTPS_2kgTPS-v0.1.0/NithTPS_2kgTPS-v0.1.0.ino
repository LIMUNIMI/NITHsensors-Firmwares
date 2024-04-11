/* Definition of constants */
#define SAMPLING_DELAY_MS (5)
#define SENSOR_NAME ("NithTPS_FSR-0.1.0")
#define MAX 400
#define DEADZONE 300

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

void loop() {
  
  int sensorValue = analogRead(A0); // read the input on analog pin 0
  float voltage = sensorValue - DEADZONE;
  if(voltage < 0){
    voltage = 0;
  }
  if(voltage > MAX){
    voltage = MAX;
  }
  
  /* Print output line */
  /* =============================================== */
  
  /* Line start character */
  Serial.print("$");
  
  /* Sensor name and version */
  Serial.print(SENSOR_NAME);
  Serial.print("|");

  /* Status line */
  Serial.print("OPR");
  Serial.print("|");
  
  /* Values */
  Serial.print("teeth_press=");
  Serial.print(voltage, 0);
  Serial.print("/");
  Serial.println(MAX);
  delay(SAMPLING_DELAY_MS);
}
