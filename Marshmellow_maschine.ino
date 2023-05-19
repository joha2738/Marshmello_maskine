/*Stepper motor driver uden bibliotek, til Den perfekt Marshmello maskine*/
#include <Adafruit_NeoPixel.h>
#define PIN 23 //Indbyggede WS2812 LED
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int buttonPushCounter = 0;  // tæller til antal tastetryk
int buttonState = 0;        // Nuværende position af tastetryk
int lastButtonState = 0;    // Forrige position af tastetryk

// Define stepper motor connections and steps per revolution:
#define dirPin      2           //  m0Pin  m1Pin  m2Pin    Step
#define stepPin     3           //  L   L   L     Full
#define sleepPin    4           //  H   L   L     1/2
#define resetPin    5           //  L   H   L     1/4
#define m2Pin       9           //  H   H   L     1/8
#define m1Pin       6           //  L   L   H     1/16
#define m0Pin       7           //  H   L   H     1/32
#define enablePin   8           //  Disconected = L L L

#define dirPin2     18 
#define stepPin2    19
#define sleepPin2   20
#define resetPin2   21
#define m2Pin2      22
#define m1Pin2      26
#define m0Pin2      27
#define enablePin2  28

#define sensor      29
#define sensorLED   23

#define steps       125
#define steps2      2
#define buttonPin   17
#define buttonPin2  16
#define pause       1


void setup() {
  // Declare pins as output:
  pinMode(dirPin, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  pinMode(sleepPin2, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(resetPin2, OUTPUT);
  pinMode(m2Pin, OUTPUT);
  pinMode(m2Pin2, OUTPUT);
  pinMode(m1Pin, OUTPUT);
  pinMode(m1Pin2, OUTPUT);
  pinMode(m0Pin, OUTPUT);
  pinMode(m0Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  pinMode(sensor, INPUT)
  pinMode(sensorLED, OUTPUT)

  pixels.begin();
  pixels.clear();
  pixels.show();

  digitalWrite(m0Pin, LOW);
  digitalWrite(m1Pin, HIGH);
  digitalWrite(m2Pin, LOW);

  digitalWrite(m0Pin2, LOW);
  digitalWrite(m1Pin2, HIGH);
  digitalWrite(m2Pin2, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      skuffe();
      rotor();
    }
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
  }
  lastButtonState = buttonState;
}

void skuffe(){
//Start motor
      digitalWrite(sleepPin, HIGH);
      digitalWrite(resetPin, HIGH);
      //Sæt retning højreom
      digitalWrite(dirPin, LOW);
      //Tænd LED Grøn
      pixels.setPixelColor(0, pixels.Color(0, 5, 0));
      pixels.show();
      //Drejer motoren i antallet af steps
      for (int i = 0; i < steps; i++) {
        delay(pause);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
      delay(200);


      //Sæt retning venstreom
      digitalWrite(dirPin, HIGH);
      //Tænd LED Blå
      pixels.setPixelColor(0, pixels.Color(0, 0, 5));
      pixels.show();
      //Drejer motoren i antallet af steps
      for (int i = 0; i < steps; i++) {
        delay(pause);
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }

            //Sluk motor
      digitalWrite(sleepPin, LOW);
      digitalWrite(resetPin, LOW);

}

void rotor(){
  //Start motor
    digitalWrite(sleepPin2, HIGH);
    digitalWrite(resetPin2, HIGH);
  //Sæt retning højreom
    digitalWrite(dirPin2, LOW);
  //Tænd LED Grøn
    pixels.setPixelColor(0, pixels.Color(0, 5, 5));
    pixels.show();
  //Drejer motoren i antallet af steps
    for (int i = 0; i < steps2; i++) {
      delay(pause);
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(500);
      }
    delay(200);
  //Sluk motor
    digitalWrite(sleepPin2, LOW);
    digitalWrite(resetPin2, LOW);

}