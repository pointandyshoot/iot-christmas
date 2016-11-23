# iot-christmas

This project uses an Adafruit HUZZAH esp8266 feather with a relay. It connects through adafruit.io so it can be actiavted from my iPhone (using a DO button on IFTTT). I can turn the relay on and off from the start screen. I am using it to control the lights of our christmas tree. The Christmas of Things is here!

The sketch is adapted from the adafruit.io library, which is required.

You'll need to create a digital (toggle switch) feed in adafuit.io. The code works with up to 5 relays and is easily expanded. You'll also need to add login data to config.h for adafruit.io and wifi.
