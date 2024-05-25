# UVlightsensor
Ultraviolet UVA, UVB, and UVC Light Sensor

For about the same price as a UV flashlight, you can build a UV light sensor that measures UV light output at the three standard UVA (LW) UVB (MW) and UVC (SW) wavelengths. Begining level knowledge of electronics and microprocessors is required. The Arduino IDE is used to program the ESP32 processor module via a USB C cable. All code is provided, but the IDE must be used to compile and upload the code to the processor. Soldering of one wire is required, but other parts plug together using Qwiic cable connectors.

# A battery powered version with an OLED display

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/1def4f33-1fe1-4b02-a64a-0ae15217a079)

The UV sensor assembly mounted inside a "black box" with an OLED display, battery, and power switch for portable operation. The sensor uses a 2-wire I2C digital interface, so a microprocessor running software is needed to read out and print the data. Here is a link to the plastic box from Amazon https://www.amazon.com/dp/B07Q14K8YT?ref=ppx_yo2ov_dt_b_product_details&th=1 (mine was 3.62 x 2.28 x 1.26 size). This was used for the power switch, https://www.amazon.com/dp/B07MYRWFFW?psc=1&ref=ppx_yo2ov_dt_b_product_details . The battery from Sparkfun comes with a JST connector that fits the one on the ESP32 board, https://www.sparkfun.com/products/13853 or perhaps a larger one. Mounting holes need to be drilled out on the plastic case and a rectangle cut out for the OLED display area. Another option would be to design and use a 3D printer for the case.

# Sparkfun's UV spectral sensor module and ESP32 development board

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/f127e40c-00cd-446c-9e9d-424988e7fd5d)

The Sparkfun UV sensor, https://www.sparkfun.com/products/23517 or https://www.amazon.com/dp/B0CQHQTQ8R?psc=1&ref=ppx_yo2ov_dt_b_product_details and the QWIIC Pocket Development Board, https://www.sparkfun.com/products/22925 or https://www.amazon.com/dp/B0CL6GGT7Q?psc=1&ref=ppx_yo2ov_dt_b_product_details can be bolted together using standoffs. Note: Sparkfun only has free shipping for a $100 order. In this bare board only configuration a USB cable is required for power. The USB cable can print sensor data over the USB virtual serial port to a PC running a terminal application program such as the serial monitor in the Ardruino IDE, TeraTerm, or RealTerm. I prever plastic standoffs and screws to avoid the posiblitly of larger screws shorting things out on the PCB. I found this standoff set handy https://www.amazon.com/dp/B0B5LTQXX8?psc=1&ref=ppx_yo2ov_dt_b_product_details

# Sparkfun Qwiic cables to connect modules

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2b331aa1-8549-415f-8748-a9a7e211efd0)

Sparkfun makes handy 4-wire cables to connect the modules https://www.sparkfun.com/search/results?term=QWiic+cables or https://www.amazon.com/dp/B08HQ1VSVL?psc=1&ref=ppx_yo2ov_dt_b_product_details. I used a short one to connect the sensor module to the ESP32 module. A second Qwiic cable with female jumpers was used to connect to the pins on the OLED.
The cable wires have been color coded to red, black, blue and yellow. Additionally, the female Qwiic connector features a basic 1mm pitch, while the female hookup pins can easily connect to a standard 0.1" male connector.

All Qwiic cables have the following color scheme and arrangement:

Black = GND
Red = 3.3V
Blue = SDA
Yellow = SCL

# Adding an OLED display for standalone operation

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2a1cd0b9-9849-424d-a095-bf7439b44d42)

128x64 Pixel SSD1306 blue OLED from Amazon https://www.amazon.com/dp/B0BFD4X6YV?ref=ppx_yo2ov_dt_b_product_details&th=1

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/3e799224-9420-40f1-9954-2e2ffc695200)

Note the OLED module comes set with a jumper to use I2C address 0x3C (and not 0x3D like Sparkfun's out of stock OLED). It works using the Sparkfun Qwicc OLED library driver once the address is changed. I had to carefully enlarge the mounting holes a bit in the OLED and add a small spacer to keep pressure off of the glass. Be careful, the glass is very thin and it is easy to crack the glass and destroy the OLED it you put pressure on it.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/cb358408-6615-45a0-9e63-4a8c9b5b8d40)

# Mounting the Parts in a Case
View inside the black box case. Note the small lithium battery on the right. The battery was attached using sticky back velcro.  It comes with a JST connector that plugs into the ESP32 module. The module includes a charger circuit and it will automaticaly charge the small lithuim battery when a USB C cable is attached (and the power switch is on). The power switch is on the left side of the case.


 
 
