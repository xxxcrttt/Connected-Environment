# Connected-Environment
This contains projects for CASA0014 -- Connected Environment.

## Part 1. Blinking Monster -- not assessed but required, due on Week 2. 

Use Arduino programming skills to create an object with LED light, could be character or tool, to represent yourself. 

1. single page of montage with 4 ideas. (A4 page sketch, paint, photo etc.) 
2. Blinking Monster, including functioning Arduino sketch and pysical embodiment. (could use paper, card, not important) 
3. Repo: photo of finished product, scan/photo of sletchbook with 4 ideas, and Arduino sketch.


## Part 2. Plant Monitor -- due on Week 5. 40% 

locate a plant around CASA office,  to monitor that plant, sensing the plant environment and sending data to the internet. 

### Preparation: software packages and hardware development board.
1. Arduino IDE
2. MQTT explorer
3. Adafruit Feather Huzzah ESP8266, an 'all-in-one' ESP9266 WiFi development board with USB and battery charging. 
4. Raspberry Pi 4 

### Set-up and Connecting to WiFi, Getting the Time 
Need to install the CP22014 driver and package for esp8266 (the json format) first, then instal the esp8266 under 'Additional Board Manager'.
Check this by 'blink' example. 

Being able to connect to Wi-Fi is one of the most important feature of ESP8266. First include the wifi library <ESP8266WiFi.h> to the code. 
Then use 'CE-Hub' and corresponding passport as ssid and password. The web host we are connecting is: iot.io

======== need to add some picture ============



### Sensing Soil 
In order to make the sensors of the plant, we need 2 items, a DHT22 temperature / humidity sensor and 2 nails that could be inserted into soil.

The figures below show the circuit for connecting a soil sensor.

![fritzing diagram](https://github.com/xxxcrttt/Connected-Environment/blob/main/Figures/diagram.png)

Below are the actual item that I've made. 
![actual item1](https://github.com/xxxcrttt/Connected-Environment/blob/main/Figures/actual1.jpg)
![actual item2](https://github.com/xxxcrttt/Connected-Environment/blob/main/Figures/actual2.jpg)

In order to keep it tidy, we solded and simplify the board. 
===== need pic ==============


### MQTT 
Now we can start sending the data from the sensor to a MQTT server. The server we are using is: mqtt://mqtt.cetools.org::1884.
Same as previous Wifi connection, we set the ssid and password to 'CE-Hub'.

In 'setup()' function we use a builtin LED to check that if the MQTT is actually connected and initialise the MQTT client. Then in the 'sendMQTT()' function, we firstly check that whether there is a connection or not by using if statement. Then doing the loop function, by using value to kep tracking the number of messages coming into the server. Finally using client.publish to sent the message. (In this case is my own topic: 'student/CASA0014/plant/ucfnrc0'

Then we started to sending soil data to MQTT server. The libraries that we need for the skecth includes: 




## Part 3. BLOG POST -- due on 18th. Nov, 60%, 1500 words

"What role do connected devices play in helping us make sense of the environment around us? " 
