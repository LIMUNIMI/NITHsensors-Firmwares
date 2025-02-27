/* Definition of constants */
#define SAMPLING_DELAY_MS (5)
#define SENSOR_NAME ("NithTPS_FSR-0.1.0")
//#define MAX 400
//#define DEADZONE 300

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

void loop() {
  
  int sensorValue = analogRead(A0); // read the input on analog pin 0
  float voltage = sensorValue;
  
  #ifdef DEADZONE
  voltage -= DEADZONE;
  if(voltage < 0){
    voltage = 0;
  }
  #endif
  
  #ifdef MAX
  if(voltage > MAX){
    voltage = MAX;
  }
  #endif
  
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
  #ifdef MAX
  Serial.print("/");
  Serial.println(MAX);
  #else
  Serial.println();
  #endif
  delay(SAMPLING_DELAY_MS);
}
