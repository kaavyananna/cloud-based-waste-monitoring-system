# cloud-based-waste-monitoring-system
cloud based waste monitoring system

#### Hardware

1. [NodeMcu](https://www.nodemcu.com/index_en.html)
2. HC-SR04 Ultrasonic Sensor

#### Software
[Arduino IDE](https://www.arduino.cc/en/software)

#### Installation

Install ThingSpeak Library and ESP8266wifi-master

[Installing Libraries guide](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

#### Connections

ultrasonic sensor -> NodeMcu module
1. trig pin  -> D0 
2. echo pin -> D1 
3. gnd -> gnd
4. Vcc -> Vin 

#### Sending sensor data to ThingSpeak

Send the sensor data from NodeMcu to [ThingSpeak](https://thingspeak.com/)

