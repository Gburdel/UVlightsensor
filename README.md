# UVlightsensor
Ultraviolet UVA, UVB, and UVC Light Sensor

For about the same price as a UV flashlight, you can build a UV light sensor that measures UV light output at the three standard UVA (LW) UVB (MW) and UVC (SW) wavelengths. Beginning level knowledge of electronics and microprocessors is required. The Arduino IDE is used to program the ESP32 processor module via a USB C cable. All code is provided, but the IDE must be used to compile and upload the code to the processor. Soldering of one wire is required, but other parts plug together using Qwiic cable connectors.

# A battery powered version with an OLED display

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/78e72acd-2772-413b-8417-c29580e27386)



The UV sensor assembly mounted inside a plastic "black box" with an OLED display, battery, and power switch for portable operation. The sensor uses a 2-wire I2C digital interface, so a microprocessor running software is needed to read out and print the data. Here is a link to the plastic box from Amazon https://www.amazon.com/dp/B07Q14K8YT?ref=ppx_yo2ov_dt_b_product_details&th=1 (mine was 3.62 x 2.28 x 1.26 size). This was used for the power switch, https://www.amazon.com/dp/B07MYRWFFW?psc=1&ref=ppx_yo2ov_dt_b_product_details . The battery from Sparkfun comes with a JST connector that fits the one on the ESP32 board, https://www.sparkfun.com/products/13853 or perhaps a larger one. Mounting holes need to be drilled out on the plastic case and a rectangle cut out for the OLED display area. Another option would be to design and use a 3D printer to make a case.

# Sparkfun's UV spectral sensor module and ESP32 development board

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/f127e40c-00cd-446c-9e9d-424988e7fd5d)

The Sparkfun UV sensor seen on the top, https://www.sparkfun.com/products/23517 or https://www.amazon.com/dp/B0CQHQTQ8R?psc=1&ref=ppx_yo2ov_dt_b_product_details and the QWIIC Pocket Development Board on the bottom, https://www.sparkfun.com/products/22925 or https://www.amazon.com/dp/B0CL6GGT7Q?psc=1&ref=ppx_yo2ov_dt_b_product_details can be bolted together using standoffs. Note: Sparkfun only has free shipping for a $100 order. In this bare board only configuration a USB cable is required for power. The USB cable can print sensor data over the USB virtual serial port to a PC running a terminal application program such as the serial monitor in the Arduino IDE, TeraTerm, or RealTerm. I prefer plastic standoffs and screws to avoid the possiblitly of larger screws shorting things out on the PCB. I found this standoff set handy https://www.amazon.com/dp/B0B5LTQXX8?psc=1&ref=ppx_yo2ov_dt_b_product_details

## Using Sparkfun Qwiic cables to connect sensor modules to processor modules

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2b331aa1-8549-415f-8748-a9a7e211efd0)

Sparkfun makes handy 4-wire cables to connect the modules https://www.sparkfun.com/search/results?term=QWiic+cables or https://www.amazon.com/dp/B08HQ1VSVL?psc=1&ref=ppx_yo2ov_dt_b_product_details. I used a short one to connect the sensor module to the ESP32 module. A second Qwiic cable with female jumpers was used to connect to the pins on the OLED https://www.sparkfun.com/products/17261.
The cable wires have been color coded to red, black, blue and yellow. Additionally, the female Qwiic connector features a basic 1mm pitch, while the female hookup pins can easily connect to a standard 0.1" male connector.

All Qwiic cables have the following color scheme and arrangement:

- Black = GND
- Red = 3.3V DC
- Blue = SDA (I2C data signal)
- Yellow = SCL (I2C clock)

# Adding an OLED display for standalone operation

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/3e799224-9420-40f1-9954-2e2ffc695200)


128x64 Pixel SSD1306 blue OLED from Amazon https://www.amazon.com/dp/B0BFD4X6YV?ref=ppx_yo2ov_dt_b_product_details&th=1

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2a1cd0b9-9849-424d-a095-bf7439b44d42)

Note the OLED module comes set with a jumper to use I2C address 0x3C (and not 0x3D like Sparkfun's out of stock OLED). It works using the Sparkfun Qwiic OLED library driver once the address is changed. I had to carefully enlarge the mounting holes a bit in the OLED and add a small spacer to keep pressure off of the glass. Be careful, the glass is very thin and it is easy to crack the glass and destroy the OLED if you put pressure on it.

# Mounting the Parts in a Case

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/cb358408-6615-45a0-9e63-4a8c9b5b8d40)


View inside the black box case. Note the small lithium battery on the right. The battery was attached using sticky back Velcro.  It comes with a JST connector that plugs into the ESP32 module. The module includes a charger circuit, and it will automatically charge the small lithium battery when a USB C cable is attached (and the power switch is on). The power switch is on the left side of the case.

# Hardware Assembly 
A short Qwiic cable attaches the sensor board to the processor board. You also to solder one jumper wire from UV sensor board INT (interrupt pin) to the processor board IO4 pin as the UV sensor code example uses pin 4 for the interrupt (the sensor sets an interrupt signal when a new value is available - the program will crash without this wire!). You will also need a USB C cable (if you don’t have one – one does not come with the processor board). Optional Standoffs, nuts and bolts if you want to attach the two boards. The female Qwiic cable is used to attach from the sensor board's second Qwiic connector to the pins on the OLED.

# Software Development
Install the Arduino IDE on your PC and then using Board Manager add the ExpressIf ESP32 board package so that the IDE has support that allows you to select the “SparkFun Qwiic Pocket Development Board - ESP32-C6” as your board. Once the board is selected, pick the COM port to use. See https://docs.sparkfun.com/SparkFun_Qwiic_Pocket_Dev_Board_ESP32_C6/software_setup/ for more details. Then you need to install the libraries (use Tools-> Manage Libraries) search for and install the "Sparkfun UV sensor AS7331" and if you are adding the OLED install the "Sparkfun QWIIC OLED" library. 
The example code prints data to the USB virtual serial port, but when no USB cable is attached the Serial function hangs. If you are running standalone with an OLED and battery with no USB cable attached, under Tools disable the "USB CDC on boot" option, then compile and download.

 
