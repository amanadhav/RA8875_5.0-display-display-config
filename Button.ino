void setupButtons() {
  pinMode(CATEGORY_BUTTON_PIN, INPUT_PULLUP);
  resetButtons();
  pinMode(WPS_LED_PIN, OUTPUT);
}

void resetButtons() {
  storageCategory = 0;
  cookedCategory = 0;
  foodCategory = 0;
  Serial.println("RESETTING BUTTONS");

}

void checkButtons() {
  short buttonPress = analogRead(CATEGORY_BUTTON_PIN);

  if (buttonPress < 39) {
    foodCategory = 4;
    Serial.println("Button 1 was pressed!");
  }
  else if (buttonPress < 87) {
    foodCategory = 3;
    Serial.println("Button 2 was pressed!");
  }
  else if (buttonPress < 130) {
    foodCategory = 2;
    Serial.println("Button 3 was pressed!");
  }
  else if (buttonPress < 169) {
    foodCategory = 1;
    Serial.println("Button 4 was pressed!");
  }
  else if (buttonPress < 202) {
    foodCategory = 0;
    Serial.println("Button 5 was pressed!");
  }
  else if (buttonPress < 235) {
    storageCategory = 0;
    Serial.println("Button 6 was pressed!");
  }
  else if (buttonPress < 265) {
    storageCategory = 1;
    Serial.println("Button 7 was pressed!");
  }
  else if (buttonPress < 292) {
    cookedCategory = 0;
    Serial.println("Button 8 was pressed!");
  }
  else if (buttonPress < 317) {
    cookedCategory = 1;
    Serial.println("Button 9 was pressed!");
  }
  else if (buttonPress < 353) {
    cookedCategory = 2;
    Serial.println("Button 10 was pressed!");
  }


  ///////////////////////////////////////////////////////
  //  WPS CHECK

  ms = millis();               //record the current time
  myWPSButton.read();                //Read the button

  switch (STATE) {

    //This state watches for short and long presses, switches the LED for
    //short presses, and moves to the TO_BLINK state for long presses.
    case ONOFF:
      if (myWPSButton.wasReleased()) {
        switchLED();
        scannerState = !scannerState;
      }
      else if (myWPSButton.pressedFor(LONG_PRESS))
        STATE = TO_BLINK;
      else if (ledState == true) {
        if (ms - myWPSButton.lastChange() > 10000) {
          digitalWrite(WPS_LED_PIN, LOW);
          ledState = false;
          scannerState = ADD;
        }
        else if (scannerState == ADD) {
          digitalWrite(WPS_LED_PIN, LOW);
          ledState = false;
        }
      }
      break;

    case TO_BLINK:
      if (myWPSButton.wasReleased())
        STATE = BLINK;
      else
        fastBlink();
      break;

    case BLINK:
      if (myWPSButton.pressedFor(LONG_PRESS)) {
        STATE = TO_ONOFF;
        digitalWrite(WPS_LED_PIN, LOW);
        ledState = false;
      }
      else
        fastBlink();
      break;

    case TO_ONOFF:
      if (myWPSButton.wasReleased())
        STATE = ONOFF;
      break;
  }
}

void switchLED()
{
  msLast = ms;                 //record the last switch time
  ledState = !ledState;
  digitalWrite(WPS_LED_PIN, ledState);
}

void fastBlink()
{
  if (ms - myWPSButton.lastChange() > 60000) {
    digitalWrite(WPS_LED_PIN, LOW);
    ledState = false;
    STATE = ONOFF;
  }
  else if (ms - msLast >= BLINK_INTERVAL)
    switchLED();
}


