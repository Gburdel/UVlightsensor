# UVlightsensor
Ultraviolet UVA, UVB, and UVC Light Sensor

For about the same price as a UV flashlight, you can build a UV light sensor that measures UV light output at the three standard UVA (LW) UVB (MW) and UVC (SW) wavelengths. Begining level knowledge of electronics and micrprocessors is required. The Arduino IDE is used to program the ESP32 processor module via a USB C cable. All code is provided. Soldering of one wire is required, but other parts plug together using Qwiic cable connectors.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/1def4f33-1fe1-4b02-a64a-0ae15217a079)

The UV sensor assembly mounted inside a "black box" with an OLED display, battery, and power switch for portable operation. Here is a link to the plastic box from Amazon https://www.amazon.com/dp/B07Q14K8YT?ref=ppx_yo2ov_dt_b_product_details&th=1 (mine was 3.62 x 2.28 x 1.26 size). This was used for the power switch, https://www.amazon.com/dp/B07MYRWFFW?psc=1&ref=ppx_yo2ov_dt_b_product_details . The battery from Sparkfun comes with a JST connector that fits the one on the ESP32 board, https://www.sparkfun.com/products/13853 or perhaps a larger one.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/f127e40c-00cd-446c-9e9d-424988e7fd5d)

The Sparkfun UV sensor, https://www.sparkfun.com/products/23517 or https://www.amazon.com/dp/B0CQHQTQ8R?psc=1&ref=ppx_yo2ov_dt_b_product_details and the QWIIC Pocket Development Board, https://www.sparkfun.com/products/22925 or https://www.amazon.com/dp/B0CL6GGT7Q?psc=1&ref=ppx_yo2ov_dt_b_product_details can be bolted together using standoffs. In this bare board only configuration a USB cable is required for power. The USB cable can print sensor data over the USB virtual serial port to a PC running a terminal application program such as the serial monitor in the Ardruino IDE, TeraTerm, or RealTerm. I prever plastic standoffs and screws to avoid the posiblitly of larger screws shorting things out on the PCB. I found this standoff set handy https://www.amazon.com/dp/B0B5LTQXX8?psc=1&ref=ppx_yo2ov_dt_b_product_details

#Adding an OLED display

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/2a1cd0b9-9849-424d-a095-bf7439b44d42)

128x64 Pixel SSD1306 blue OLED from Amazon https://www.amazon.com/dp/B0BFD4X6YV?ref=ppx_yo2ov_dt_b_product_details&th=1

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/3e799224-9420-40f1-9954-2e2ffc695200)

Note the OLED module comes set with a jumper to use I2C address 0x3C (and not 0x3D like Sparkfun's out of stock OLED). It works using the Sparkfun Qwicc OLED driver once the address is changed.

![image](https://github.com/Gburdel/UVlightsensor/assets/30203498/cb358408-6615-45a0-9e63-4a8c9b5b8d40)

View inside the black box case. Note the small battery on the right. It comes with a JST connector that plugs into the ESP32 module. The module includes a charger circuit and it will charge to battery when a USB C cable is attached (and the power switch is on.
 
 
