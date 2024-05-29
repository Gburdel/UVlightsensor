# UVlightsensor
Ultraviolet UVA, UVB, and UVC Light Sensor

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/6968f935-d1a2-40ec-970b-06930bc12dfc)

For about the same price as a UV flashlight, you can build a UV light sensor that measures UV light output at the three standard UVA (LW) UVB (MW) and UVC (SW) wavelengths. Beginning level knowledge of electronics and microprocessors is required. The Arduino IDE is used to program the ESP32 processor module via a USB C cable. All code is provided, but the IDE must be used to compile and upload the code to the processor. Soldering of one wire is required, but other parts plug together using Qwiic cable connectors. To mount it in the plastic case some drilling and cutting is required.

# A battery powered version with an OLED display

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/3706eee4-f3e6-4e09-88e4-e9e2db6f55e4)




The UV sensor assembly mounted inside a plastic "black box" with an OLED display, battery, and power switch for portable operation. A C8 LW UV flashlight is pointed at the sensor. The sensor uses a 2-wire I2C digital interface, so a microprocessor running software is needed to read out and print the data. Here is a link to the plastic box from Amazon https://www.amazon.com/dp/B07Q14K8YT?ref=ppx_yo2ov_dt_b_product_details&th=1 (mine was 3.62 x 2.28 x 1.26 size). This was used for the power switch, https://www.amazon.com/dp/B07MYRWFFW?psc=1&ref=ppx_yo2ov_dt_b_product_details . The battery from Sparkfun comes with a JST connector that fits the one on the ESP32 board, https://www.sparkfun.com/products/13853 or perhaps a larger one. Mounting holes need to be drilled out on the plastic case and a rectangle cut out for the OLED display area. Another option would be to design and use a 3D printer to make a case.

# Sparkfun's UV spectral sensor module and ESP32 development board

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/f127e40c-00cd-446c-9e9d-424988e7fd5d)

The Sparkfun UV sensor seen on the top, https://www.sparkfun.com/products/23517 or https://www.amazon.com/dp/B0CQHQTQ8R?psc=1&ref=ppx_yo2ov_dt_b_product_details and the QWIIC Pocket Development Board on the bottom, https://www.sparkfun.com/products/22925 or https://www.amazon.com/dp/B0CL6GGT7Q?psc=1&ref=ppx_yo2ov_dt_b_product_details can be bolted together using standoffs. Note: Sparkfun only has free shipping for a $100 order. In this bare board only configuration a USB cable is required for power. The USB cable can print sensor data over the USB virtual serial port to a PC running a terminal application program such as the serial monitor in the Arduino IDE, TeraTerm, or RealTerm. I prefer plastic standoffs and screws to avoid the possiblitly of larger screws shorting things out on the PCB. I found this standoff set handy https://www.amazon.com/dp/B0B5LTQXX8?psc=1&ref=ppx_yo2ov_dt_b_product_details . Be careful using the pushbuttons often on the processor board, the black plastic button top can break off. If this does happen, you can hit the center of the button with a pin until you hear the click. The good news is that once you have things programmed and setup they are not needed - cycling power with the switch or plugging in the USB cable will reset the processor.



# Adding an OLED display for standalone operation

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/3e799224-9420-40f1-9954-2e2ffc695200)


Sparkfun has a Qwiic OLED but it is on backorder https://www.sparkfun.com/products/23453 . Similar devices that work with the software are available elsewhere at a lower cost. This one is a 128x64 Pixel SSD1306 blue OLED from Amazon https://www.amazon.com/dp/B0BFD4X6YV?ref=ppx_yo2ov_dt_b_product_details&th=1

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2a1cd0b9-9849-424d-a095-bf7439b44d42)

Note in the image above that the OLED module comes with a jumper set to use I2C address 0x3C (and not 0x3D like Sparkfun's out of stock OLED). It works using the Sparkfun Qwiic OLED library driver once the address is changed. I had to carefully enlarge the mounting holes a bit in the OLED and add a small spacer to keep pressure off of the glass. Be careful, the glass is very thin and it is easy to crack the glass and destroy the OLED if you put pressure on it.

# Adding a 3.7V Lithium Battery with a JST connector for standalone operation without a USB C cable
![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/efbea552-7464-4a7b-b264-5970e7e16b2a)

A 3.7 volt Lituim battery with a JST connector will plug into the processor board, run the device standalone, and recharge the battery when a USB C cable is attached. A yellow LED on the processor board indicates the battery is charging and it turns off when the battery is full charged. Sparkfun has several battery options https://www.sparkfun.com/search/results?term=jst+lithium+battery. They can also be found at Amazon https://www.amazon.com/s?k=jst+lithium+batteries&i=toys-and-games&rh=n%3A165793011%2Cp_n_feature_two_browse-bin%3A23534446011%2Cp_n_feature_seven_browse-bin%3A64613661011%2Cp_n_feature_seventeen_browse-bin%3A23568374011&dc&crid=10E7UCI1ERO6A&qid=1716750012&rnid=10467359011&sprefix=JST+lithuim+batt%2Caps%2C109&ref=sr_nr_p_n_feature_seventeen_browse-bin_1&ds=v1%3AftxJz0WyAGK7GWcGj2c%2FDgT0o5DGM7bj%2B74I3Arb1LE

# Mounting the Parts in a Case

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/cb358408-6615-45a0-9e63-4a8c9b5b8d40)


View inside the black box case. Note the small lithium battery on the right. The battery was attached using sticky back Velcro.  It comes with a JST connector that plugs into the ESP32 module. The module includes a charger circuit, and it will automatically charge the small lithium battery when a USB C cable is attached (and the power switch is on). The power switch is on the left side of the case. The three boards are mounted using standoffs with screws.

# Hardware Used 
## Parts Needed

Here is a copy of everything I needed from my Amazon shopping cart to make the standalone sensor module in a case with a battery: https://www.amazon.com/hz/wishlist/ls/1359G3EURTYWQ?ref_=wl_share

## Assembly

A short Qwiic cable attaches the sensor board to the processor board. You also have to solder one jumper wire from UV sensor board INT (interrupt pin) to the processor board IO4 pin as the UV sensor code example uses pin 4 for the interrupt (the sensor sets an interrupt signal when a new value is available - the program will crash without this wire!). You will also need a USB C cable (if you don’t have one – one does not come with the processor board). Optional Standoffs, nuts and bolts if you want to attach the two boards. The female Qwiic cable is used to attach from the sensor board's second Qwiic connector to the pins on the OLED.

## Using Sparkfun Qwiic cables to connect sensor modules to processor modules

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2b331aa1-8549-415f-8748-a9a7e211efd0)

Sparkfun makes handy 4-wire cables to connect the modules https://www.sparkfun.com/search/results?term=QWiic+cables or https://www.amazon.com/dp/B08HQ1VSVL?psc=1&ref=ppx_yo2ov_dt_b_product_details. I used a short one to connect the sensor module to the ESP32 module. A second Qwiic cable with female jumpers was used to connect to the pins on the OLED https://www.sparkfun.com/products/17261.
The cable wires have been color coded to red, black, blue and yellow. Additionally, the female Qwiic connector features a basic 1mm pitch, while the female hookup pins can easily connect to a standard 0.1" male connector. The pins are labeled on one side of the OLED.

All Qwiic cables have the following color scheme and arrangement:

- Black = GND
- Red = 3.3V DC
- Blue = SDA (I2C data signal)
- Yellow = SCL (I2C clock)
# Software Development
Install the Arduino IDE on your PC and then using Board Manager add the ExpressIf ESP32 board package so that the IDE has support that allows you to select the “SparkFun Qwiic Pocket Development Board - ESP32-C6” as your board. Once the board is selected, pick the COM port to use. See https://docs.sparkfun.com/SparkFun_Qwiic_Pocket_Dev_Board_ESP32_C6/software_setup/ for more details. Then you need to install the libraries (use Tools-> Manage Libraries) search for and install the "Sparkfun UV sensor AS7331" and if you are adding the OLED install the "Sparkfun QWIIC OLED" library. 
The example code prints data to the USB virtual serial port, but when no USB cable is attached the Serial function hangs. If you are running standalone with an OLED and battery with no USB cable attached, under Tools disable the "USB CDC on boot" option, then compile and download. 

The shortest and easiest to understand software fix for the Amazon Hoysund alternate OLED default I2C address is to edit the library include file  “qwiic_oled_1in3.h”. The path on my setup was something like this:
Documents\Arduino\libraries\SparkFun_Qwiic_OLED_Arduino_Library\src\qwiic_oled_1in3.h
Find this line: "default_address = kOLED1in3DefaultAddress;". Then change it to: "default_address = kOLED1in3AltAddress;"

To fix it using the hardware alternative instead of this software fix you could desolder and move the jumper on the Hoysund OLED board from “3C” to “3D”

Use this source code below that adds OLED output in your sketch after installing and patching the libraries:

```
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
 //not Sparkfun's Qwiic1in3OLED this Amazon Hoysond one uses I2C address 0x3C

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
```

Make a new sketch in the Arduino IDE, clear it out, click on the square icon on the code block above to copy the code, and paste it into the IDE editor. Source code files and a zip are also included for those that want to use that alternative. Compile and upload. Output should appear on the display. In case nothing appears on the display watch for a blue flash on the LED on the ESP32 board at startup. If the LED blinks and nothing appears on the display, something is likely incorrect on the OLED wiring.

# Using a PC or Android Phone for power and data display

Here the light meter is running with a USB C cable connected to an Android phone. The phone powers it and also displays the live data. A SW LED flashlight is pointed at the sensor. The numbers are a bit blurry since they are changing fast in this long exposure time photo.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/a7888b5e-ba87-48a7-9a59-68bfe60123e8)

If you don't mind always having a USB C cable plugged in, you can skip purchase of the OLED, the second Qwiic cable for the OLED, battery, and switch. Then it will fit in a smaller case like this one shown below: https://www.amazon.com/dp/B0BY2CZ7LB?ref=ppx_yo2ov_dt_b_product_details&th=1

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/053ef636-7c20-4409-9f3c-5d159f10a34b)

As seen below, the modules are mounted inside on standoffs with longer standoffs on the UV sensor board to place the sensor near the opening in the top of the small case.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/121a4b3b-81d7-4024-a297-0258620a4c64)


For this use, the code has no OLED display output, but you will need to set the Tools -> enable the "USB CDC on boot" option, then compile and download. USB CDC is the protocol used to send serial data over the USB cable. The PC or Android Phone will need one of the free "Terminal Emulator" programs. The terminal emulator will need to be setup with the correct baud rate and USB serial port. The data output from prints will them show up in the window on the PC or Android phone. iPhones do not support other non-Apple USB devices like this without a lot of work that would also likely void the warranty. 
```
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

  Hardware Connections:
  IoT RedBoard --> AS7331
  QWIIC --> QWIIC
  26  --> INT

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

void setup() {
  Serial.begin(115200);
  while(!Serial){delay(100);}
  Serial.println("UV Light Meter uW/cm2");

  Wire.begin();

  // Configure Interrupt.
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), dataReadyInterrupt, RISING);

  // Initialize sensor and run default setup.
  if(myUVSensor.begin() == false) {
    Serial.println("Sensor failed to begin. Please check your wiring!");
    Serial.println("Halting...");
    while(1);
  }

  Serial.println("Sensor began.");

  // Set the delay between measurements so that the processor can read out the 
  // results without interfering with the ADC.
  // Set break time to 900us (112 * 8us) to account for the time it takes to poll data.
  if(kSTkErrOk != myUVSensor.setBreakTime(112)) {
    Serial.println("Sensor did not set break time properly.");
    Serial.println("Halting...");
    while(1);
  }

  // Set measurement mode and change device operating mode to measure.
  if(myUVSensor.prepareMeasurement(MEAS_MODE_CONT) == false) {
    Serial.println("Sensor did not get set properly.");
    Serial.println("Spinning...");
    while(1);
  }

  Serial.println("Set mode to continuous. Starting measurement...");

  // Begin measurement.
  if(kSTkErrOk != myUVSensor.setStartState(true))
    Serial.println("Error starting reading!");

}

void loop() {

  // If an interrupt has been generated...
  if(newDataReady) {
    newDataReady = false;

    if(kSTkErrOk != myUVSensor.readAllUV())
      Serial.println("Error reading UV.");
  
    Serial.print("\f"); //screen erase on some terminal emulators
    Serial.println("\n\r  UV Light Meter uW/cm2\n\r      ");
    Serial.print("  LW   ");
    Serial.println(myUVSensor.getUVA());
    Serial.print("  MW   ");
    Serial.println(myUVSensor.getUVB());
    Serial.print("  SW   ");
    Serial.println(myUVSensor.getUVC());
    Serial.print("\n\n\r");
  }

}

void dataReadyInterrupt() {
  newDataReady = true;
}
```
  
