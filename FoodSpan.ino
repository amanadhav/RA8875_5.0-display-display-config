#include "LibrariesPinsConstants.h"
#include "Structures.h"


Tag tagTable[101];
ControlPanel controlPanel;

MFRC522 mfrc522(NFC_SS_PIN, NFC_RST_PIN);   // Create MFRC522 instance
MFRC522::MIFARE_Key key;

enum {ADD, DELETE};
byte scannerState;

byte storageCategory;
byte cookedCategory;
byte foodCategory;


enum {ONOFF, TO_BLINK, BLINK, TO_ONOFF};
Button myWPSButton(WPS_BUTTON_PIN, PULLUP, INVERT, DEBOUNCE_MS);
uint8_t STATE;                   //The current state machine state
boolean ledState;                //The current LED status
unsigned long ms;                //The current time from millis() //change to long long
unsigned long msLast;          //The last time the LED was switched      //change to long long

void setup()
{
  Serial.begin(9600);

  initializeLocalDatabase();
  initializeScanner();
  setupButtons();

  //connect to wifi
  //update local database

//
//    createTagTable();
//    createControlPanel();
//    updateTablesPresent();
//    
  //////////////////////////////////////////////////////////////////
  // delay(10000);
   databaseDebugPrint();
  //////////////////////////////////////////////////////////////////
}

void loop()
{
  checkButtons();
  checkScanner();





  //mfrc stuff here(button constant)
}



