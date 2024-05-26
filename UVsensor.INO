/*
  Using the AMS AS7331 Spectral UV Sensor in Continuous (CONT) Mode.

  This example shows how operate the AS7331 in CONT mode. The break time
  register sets the delay between measurements so that the processor can read
  out the results without interfering with the ADC.

  By: Alex Brudner
  SparkFun Electronics
  Date: 2023/11/27
  SparkFun code, firmware, and software is released under the MIT License.            
	Please see LICENSE.md for further details.

  Modified for Qwiic Pocket ESP32 and OLED output
  Date: 2024/5/25

  Hardware Connections:
  ESP32 Qwiic --> AS7331
  AS7331 QWIIC --> 128by64 OLED
  4  --> INT

  Serial.print it out at 115200 baud to serial monitor.

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/23517 - Qwiic 1x1
  https://www.sparkfun.com/products/23518 - Qwiic Mini
*/

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_AS7331.h>

SfeAS7331ArdI2C myUVSensor;

const uint8_t interruptPin = 4;
volatile bool newDataReady = false;
#include <SparkFun_Qwiic_OLED.h>      //http://librarymanager/All#SparkFun_Qwiic_OLED
 //not Sparkfun's Qwiic1in3OLED this Amazon Hoysund one uses I2C address 0x3C

Qwiic1in3OLED myOLED;

// Fonts
#include <res/qw_fnt_5x7.h>
#include <res/qw_fnt_8x16.h>
#include <res/qw_fnt_31x48.h>
#include <res/qw_fnt_7segment.h>
#include <res/qw_fnt_largenum.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  while (!Serial) { delay(100); };
  Serial.println("AS7331 UV A/B/C Continuous mode example.");
  Wire.begin();
  // Wire.setClock(400000); //Optionally increase I2C bus speed to 400kHz
  // Initalize the OLED device and related graphics system
  if (myOLED.begin() == false) {
    Serial.println("OLED Device begin failed. Freezing...");
    while (true)
      ;
  }
  myOLED.erase();
  myOLED.display();
  myOLED.setFont(&QW_FONT_5X7);
  myOLED.setCursor(0, 0);
  myOLED.setColor(1);
  myOLED.printf("UV A,B,C Lightmeter\n\r\n\rUV sensor initialize");
  myOLED.setFont(&QW_FONT_8X16);
  myOLED.display();
  delay(1000);
  // Configure Interrupt.
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), dataReadyInterrupt, RISING);

  // Initialize sensor and run default setup.
  if (myUVSensor.begin() == false) {
    Serial.println("Sensor failed to begin. Please check your wiring!");
    Serial.println("Halting...");
    while (1)
      ;
  }

  Serial.println("Sensor began.");



  // Set the delay between measurements so that the processor can read out the
  // results without interfering with the ADC.
  // Set break time to 900us (112 * 8us) to account for the time it takes to poll data.
  if (kSTkErrOk != myUVSensor.setBreakTime(112)) {
    Serial.println("Sensor did not set break time properly.");
    Serial.println("Halting...");
    while (1)
      ;
  }

  // Set measurement mode and change device operating mode to measure.
  if (myUVSensor.prepareMeasurement(MEAS_MODE_CONT) == false) {
    Serial.println("Sensor did not get set properly.");
    Serial.println("Spinning...");
    while (1)
      ;
  }

  Serial.println("Set mode to continuous. Starting measurement...");

  // Begin measurement.
  if (kSTkErrOk != myUVSensor.setStartState(true))
    Serial.println("Error starting reading!");
}

void loop() {

  // If an interrupt has been generated...
  if (newDataReady) {
    newDataReady = false;

    if (kSTkErrOk != myUVSensor.readAllUV())
      Serial.println("Error reading UV.");
    Serial.print("UVA:");
    Serial.print(myUVSensor.getUVA());
    myOLED.erase();
    myOLED.setFont(&QW_FONT_5X7);
    myOLED.setCursor(0, 0);
    myOLED.setColor(1);
    myOLED.printf("UV Lightmeter uW/cm2");
    myOLED.setFont(&QW_FONT_8X16);
    myOLED.setCursor(0, 16);
    myOLED.print("LW ");
    myOLED.println(myUVSensor.getUVA());
    Serial.print(" UVB:");
    myOLED.print("MW ");
    myOLED.println(myUVSensor.getUVB());
    Serial.print(myUVSensor.getUVB());
    Serial.print(" UVC:");
    Serial.println(myUVSensor.getUVC());
    myOLED.print("SW ");
    myOLED.println(myUVSensor.getUVC());
    myOLED.display();
  }
}

void dataReadyInterrupt() {
  newDataReady = true;
}
