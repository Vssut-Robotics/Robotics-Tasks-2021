#include <Wire.h>
#include "Adafruit_MPR121.h"
#include <CurieBLE.h>

Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

//Buffer to hold 5 bytes of MIDI data. Note the timestamp is forced
uint8_t midiData[] = {0x80, 0x80, 0x00, 0x00, 0x00};

int midiChannel = 0;

int instruments[] = {
  36, // C3 Kick
  38, // D3 Snare
  42, // F#3 Closed hi-hat
  46, // A#3 Open hi-hat
  49  // C#4 crash symbol
};

BLEPeripheral blePeripheral;
BLEService midiService("03B80E5A-EDE8-4B33-A751-6CE34EC4C700"); 
BLECharacteristic midiCharacteristic("7772E5DB-3868-4112-A1A9-F2669D106BF3", BLEWrite | BLEWriteWithoutResponse | BLENotify | BLERead, sizeof(midiData));

void setupBluetooth()
{
  blePeripheral.setLocalName("MIDI_101");
  blePeripheral.setDeviceName("MIDI_101");

  blePeripheral.setAdvertisedServiceUuid(midiService.uuid());

  blePeripheral.addAttribute(midiService);
  blePeripheral.addAttribute(midiCharacteristic);

  blePeripheral.setEventHandler(BLEConnected, connectHandler);
  blePeripheral.setEventHandler(BLEDisconnected, disconnectHandler);

  blePeripheral.begin();
  Serial.println(("Waiting for Bluetooth connections."));
}

void playNote(uint8_t index) {
  int note = instruments[index];
  
  midiData[2] = 0x90 + midiChannel;
  midiData[3] = note;
  midiData[4] = 127; // velocity
  
  midiCharacteristic.setValue(midiData, sizeof(midiData));
}

void releaseNote(uint8_t index) {
  int note = instruments[index];
  
  midiData[2] = 0x80 + midiChannel;
  midiData[3] = note;
  midiData[4] = 0; // velocity

  midiCharacteristic.setValue(midiData, sizeof(midiData));
}

void connectHandler(BLECentral& central) {
  Serial.print("Central device: ");
  Serial.print(central.address());
  Serial.println(" connected.");
}

void disconnectHandler(BLECentral& central) {
  Serial.print("Central device: ");
  Serial.print(central.address());
  Serial.println(" disconnected.");
}

void setupTouchSensor() {
  Serial.println("Looking for MPR121 Capacitive Touch Sensor"); 
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void setup() {  
  Serial.begin(9600);
  Serial.println("Arduino 101 Bluetooth MIDI Controller\n"); 
  
  setupTouchSensor();
  setupBluetooth();
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, play note
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      playNote(i);
    }
    // if it *was* touched and now *isnt*, release note
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      releaseNote(i);
    }
  }

  // reset our state
  lasttouched = currtouched;
}