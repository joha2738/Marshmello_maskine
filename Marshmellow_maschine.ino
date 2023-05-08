/*Stepper motor driver uden bibliotek, til Den perfekt Marshmello maskine*/
#include <Adafruit_NeoPixel.h>
#define PIN 23 //Indbyggede WS2812 LED
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int buttonPushCounter = 0;  // tæller til antal tastetryk
int buttonState = 0;        // Nuværende position af tastetryk
int lastButtonState = 0;    // Forrige position af tastetryk

// Define stepper motor connections and steps per revolution:
#define dirPin     2           //  m0Pin  m1Pin  m2Pin    Step
#define stepPin    3           //  L      L      L        Full
#define sleepPin   4           //  H      L      L        1/2
#define resetPin   5           //  L      H      L        1/4
#define m2Pin      9           //  H      H      L        1/8
#define m1Pin      6           //  L      L      H        1/16
#define m0Pin      7           //  H      L      H        1/32
#define enablePin  8           //  
#define pause      1           //  Disconected = L L L
#define steps      125         // 125 steps passer med 1/4 step hastiged
#define buttonPin  17          // Bruges til at aktivere mekanismen
#define buttonPin2 16          // Ikke i brug endnu men lagt ud i skrueterminal

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(m2Pin, OUTPUT);
  pinMode(m1Pin, OUTPUT);
  pinMode(m0Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pixels.begin();
  pixels.clear();
  pixels.show();

  // 1/4 steps er meget passende til den roterende skuffe
  digitalWrite(m0Pin, LOW);
  digitalWrite(m1Pin, HIGH);
  digitalWrite(m2Pin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      //Start motor
      digitalWrite(sleepPin, HIGH);
      digitalWrite(resetPin, HIGH);
      //Sæt retning: skub ud
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


      //Sæt retning: træk ind
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
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
  }
  lastButtonState = buttonState;
}
