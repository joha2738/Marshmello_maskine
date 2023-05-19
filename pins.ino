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