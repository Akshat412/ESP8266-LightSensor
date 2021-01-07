# ESP8266 LightSensor
If you ever want to measure the light intensity in a room you're not in. 

It uses an ESP8266 to measure light intensity using an LDR, and displays it using an asynchronous web server and an HTML page. To use this, enter your network credentials in "secret.h", find your local IP through the Serial Monitor, open the IP on a browser, and connect an LDR to the A0 pin of the ESP board. Make sure you're connected to the same network as the ESP board. 
