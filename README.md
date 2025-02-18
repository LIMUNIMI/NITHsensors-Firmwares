# NITHsensors

A collection of firmwares for some Open-Source Hardware sensor peripherals dedicated to Accessibility.

In this repo are found the necessary files (especially Arduino firmwares) to reproduce those sensors on your own, DIY.

## Instructions for building

### Building the sensors

Refer to the page [Sensors](https://neeqstock.github.io/sensors/) in Nicola Davanzo's personal website for instructions on how to build them, both software and hardware part.

Most of them are made using Arduino microcontrollers.
You may need [Arduino IDE](https://www.arduino.cc/en/software) to upload the various code sketches to your Arduino microcontroller.

### Uploading the firmware

For each sensor, you can follow a common procedure:

1. Clone (green "Code" button -> Clone) or download a ZIP of this repository somewhere on your computer;
2. Open the folder of the sensor version you desire;
3. Open the ".ino" file with the same name as the folder;
4. Compile and upload the sketch into your Arduino.

## Instructions for making

### Standard output

All NithSensors comply to a standard which defines how the output lines must be formatted. A line complying to the standard is formatted as follows:

``$sensor_name-version|status_codes|valuetype=value&valuetype=value/ceiling``

- All standard Nith output lines start with a "``$``", to distinguish them from other kinds of output lines, and for simple line start discrimination;

- There are three main fields, separated by  "``|``";

- First field contains sensor name and version, separated by "``-``". Sensor name words are usually separated by "``_``", and may contain info on which sensor is used to build it. Version is usually on the format "``vX.X.X``", but may contain other details separated by "``_``"  (*e.g. "v.0.2.3_full"*).

- Second field contains three-letters status codes, which give informations on the current state of the sensor;

- Third field contains different output arguments, separated by "``&``". Each argument consists of a value type *(e.g. "yaw_acc")* and its value *(e.g. "50")*;

- For any value it can be specified a ceiling (i.e. upper limit), using the character "``/``". In such case, the Nith libraries will output the value as a percentage by default. 

**Tables containing standardized status codes and value types will come soon**.

### Standard baud rate

Standard baud rate for NithSensors is 115200.
