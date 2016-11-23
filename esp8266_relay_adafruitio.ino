// Adafruit IO Subscription Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// set up the 'counter' feed
//AdafruitIO_Feed *counter = io.feed("counter");
AdafruitIO_Feed *relay1 = io.feed("relay1");
AdafruitIO_Feed *relay2 = io.feed("relay2");
AdafruitIO_Feed *relay3 = io.feed("relay3");
AdafruitIO_Feed *relay4 = io.feed("relay4");
AdafruitIO_Feed *relay5 = io.feed("relay5");

#define pin1 14
#define pin2 12
#define pin3 13
#define pin4 15
#define pin5 16

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // set up relay outputs
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);

  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);

  // wait for serial monitor to open
  while (! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // set up a message handler for the count feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  relay1->onMessage(handleMessage1);
  relay2->onMessage(handleMessage2);
  relay3->onMessage(handleMessage3);
  relay4->onMessage(handleMessage4);
  relay5->onMessage(handleMessage5);

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

}

// this function is called whenever a 'counter' message
// is received from Adafruit IO. it was attached to
// the counter feed in the setup() function above.
/*
  void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());

  }
*/
void handleMessage1(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  if (data->toPinLevel() == LOW) {
    Serial.println("OFF");
    digitalWrite(pin1, HIGH);
  }
  if (data->toPinLevel() == HIGH) {
    Serial.println("ON");
    digitalWrite(pin1, LOW);
  }
}

void handleMessage2(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  if (data->toPinLevel() == LOW) {
    Serial.println("OFF");
    digitalWrite(pin2, HIGH);
  }
  if (data->toPinLevel() == HIGH) {
    Serial.println("ON");
    digitalWrite(pin2, LOW);
  }
}

void handleMessage3(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  if (data->toPinLevel() == LOW) {
    Serial.println("OFF");
    digitalWrite(pin3, HIGH);
  }
  if (data->toPinLevel() == HIGH) {
    Serial.println("ON");
    digitalWrite(pin3, LOW);
  }
}

void handleMessage4(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  if (data->toPinLevel() == LOW) {
    Serial.println("OFF");
    digitalWrite(pin4, HIGH);
  }
  if (data->toPinLevel() == HIGH) {
    Serial.println("ON");
    digitalWrite(pin4, LOW);
  }
}

void handleMessage5(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  if (data->toPinLevel() == LOW) {
    Serial.println("OFF");
    digitalWrite(pin5, HIGH);
  }
  if (data->toPinLevel() == HIGH) {
    Serial.println("ON");
    digitalWrite(pin5, LOW);
  }
}

