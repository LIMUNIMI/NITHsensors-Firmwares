#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* Definition of constants */
#define SAMPLING_DELAY_MS (15)
#define SENSOR_NAME ("NithHT_BNO055-0.1.0")

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);
bool connected = false;

void initialize_bno(){
  if(bno.begin()){
    connected = true;
  }else{
    connected = false;
    Serial.print("$");
    Serial.print(SENSOR_NAME);
    Serial.println("|ERR|$");
    delay(500);
  }
}

void setup(void)
{
  Serial.begin(115200, SERIAL_8E1);
  //Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");
  Serial.print("$");
  Serial.print(SENSOR_NAME);
  Serial.println("|ICA|$");
  initialize_bno();
  
  /* Initialise the sensor */
  // if(!bno.begin())
  //{
    /* There was a problem detecting the BNO055 ... check your connections */
   // Serial.print("$");
   // Serial.print(SENSOR_NAME);
   // Serial.println("|ERR|$");
   // while(1);
  //}
  
  //delay(1000);
  
  /* Display the current temperature */
  //int8_t temp = bno.getTemp();
  //Serial.print("Current Temperature: ");
  //Serial.print(temp);
  //Serial.println(" C");
  //Serial.println("");
  
  //bno.setExtCrystalUse(true);
  
  //Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)
{
  





  
  if(connected){
    // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> radia = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);


  /*
  // Quaternion data
  imu::Quaternion quat = bno.getQuat();
  Serial.print("qW: ");
  Serial.print(quat.w(), 4);
  Serial.print(" qX: ");
  Serial.print(quat.x(), 4);
  Serial.print(" qY: ");
  Serial.print(quat.y(), 4);
  Serial.print(" qZ: ");
  Serial.print(quat.z(), 4);
  Serial.print("\t\t");
  */

  /* Get calibration data */
  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  
  /* Print output line */
  /* =============================================== */
  /* Line start character */
  Serial.print("$");
  
  /* Sensor name and version */
  Serial.print(SENSOR_NAME);
  Serial.print("|");

  /* Status line */
  if(gyro == 3 && mag == 3){
    Serial.print("OPR");
  }
  else{
    Serial.print("ICA");
  }
  
  Serial.print("|");
  
  /* Values */
  // Position (euler)
  Serial.print("head_pos_yaw=");
  Serial.print(euler.x());
  Serial.print("&");
  Serial.print("head_pos_roll=");
  Serial.print(euler.y());
  Serial.print("&");
  Serial.print("head_pos_pitch=");
  Serial.print(euler.z());
  Serial.print("&");

  // Gyroscopic acceleration (rad/s) (conformed with signs with euler position)
  Serial.print("head_acc_yaw=");
  Serial.print(-radia.z());
  Serial.print("&");
  Serial.print("head_acc_roll=");
  Serial.print(-radia.y());
  Serial.print("&");
  Serial.print("head_acc_pitch=");
  Serial.print(-radia.x());
  Serial.print("&");

  // Calibration status
  Serial.print("cal_sys=");
  Serial.print(system, DEC);
  Serial.print("&");
  Serial.print("cal_gyro=");
  Serial.print(gyro, DEC);
  Serial.print("&");
  Serial.print("cal_acc=");
  Serial.print(accel, DEC);
  Serial.print("&");
  Serial.print("cal_mag=");
  Serial.println(mag, DEC);

  delay(SAMPLING_DELAY_MS);
  }
  else{
    initialize_bno();
  }
  
  
}
