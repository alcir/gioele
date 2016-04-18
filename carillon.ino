#include <rtttl.h>

#include <AccelStepper.h>

#define HALFSTEP 8

// motor pins
#define motorPin1  12     // IN1 on the ULN2003 driver 1
#define motorPin2  11    // IN2 on the ULN2003 driver 1
#define motorPin3  10     // IN3 on the ULN2003 driver 1
#define motorPin4  9     // IN4 on the ULN2003 driver 1

AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

const char song_A[] PROGMEM = "The final countdown:d=4,o=5,b=125:p,8p,16b,16a,b,e,p,8p,16c6,16b,8c6,8b,a,p,8p,16c6,16b,c6,e,p,8p,16a,16g,8a,8g,8f#,8a,g.,16f#,16g,a.,16g,16a,8b,8a,8g,8f#,e,c6,2b.,16b,16c6,16b,16a,1b";
const char song_B[] PROGMEM = "StWars:d=4,o=5,b=180:8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6,p,8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6";
const char song_C[] PROGMEM = "Barbie girl:d=4,o=5,b=125:8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f#,8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f#,8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f#";
const char song_D[] PROGMEM = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
const char song_E[] PROGMEM = "Argentina:d=4,o=5,b=70:8e.4,8e4,8e4,8e.4,8f4,8g4,8a4,g4,8p,8g4,8a4,8a4,8g4,c,g4,8f4,e.4,8p,8e4,8f4,8g4,8d4,d4,8d4,8e4,8f4,c4,16p,8c4,8d4,8c4,8e4,g4,16p,8g4,8g4,8a4,c,16p";
const char song_F[] PROGMEM = "FunkyTown:d=4,o=4,b=125:8c6,8c6,8a#5,8c6,8p,8g5,8p,8g5,8c6,8f6,8e6,8c6,2p,8c6,8c6,8a#5,8c6,8p,8g5,8p,8g5,8c6,8f6,8e6,8c6";
const char song_G[] PROGMEM = "Greensleaves:d=4,o=5,b=140:g,2a#,c6,d.6,8d#6,d6,2c6,a,f.,8g,a,2a#,g,g.,8f,g,2a,f,2d,g,2a#,c6,d.6,8e6,d6,2c6,a,f.,8g,a,a#.,8a,g,f#.,8e,f#,2g";
const char song_H[] PROGMEM = "killing me softly:d=4,o=5,b=90:p,8e,f,g,8a,a,8g,d,g.,p,8p,8a,g,8f,8e,8e,8f,2c,p,8e,f,g,8a,a,8g,a,b,8b,8c6,8b,16a,8g,16a,2a,2a.";
const char song_I[] PROGMEM = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
const char song_L[] PROGMEM = "starwars:d=4,o=5,b=180:8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6,p,8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6";
const char song_M[] PROGMEM = ":d=4,o=6,b=112:8d.,16p,8d.,16p,8d.,16p,8a#5,16p,16f,8d.,16p,8a#5,16p,16f,d.,8p,8a.,16p,8a.,16p,8a.,16p,8a#,16p,16f,8c#.,16p,8a#5,16p,16f,d.,8p,8d.7,16p,8d,16p,16d,8d7,8p,8c#7,16p,16c7,16b,16a#,8b,8p,16d#,16p,8g#,8p,8g,16p,16f#,16f,16e,8f,8p,16a#5,16p,8c#,8p,8a#5,16p,16c#,8f.,16p,8d,16p,16f,a.,8p,8d.7,16p,8d,16p,16d,8d7,8p,8c#7,16p,16c7,16b,16a#,8b,8p,16d#,16p,8g#,8p,8g,16p,16f#,16f,16e,8f,8p,16a#5,16p,8c#,8p,8a#5,16p,16f,8d.,16p,8a#5,16p,16f,d.";
const char song_N[] PROGMEM = "Blue Moon:d=4,o=5,b=100:2p,8p,32p,8d6,8p,2d6,8p,32p,16p,16c6,16p,16d6,32p,16d.6,16p,8d.6,16p,32p,16c.6,d.6,16p,32p,16p,16a,16p,16b,32p,16b,16p,32p,8b,32p,16a,32p,b.,32p,16p,16g,16p,16a,16g,16p,32p,8g,16p,16e,32p,2g";
const char song_O[] PROGMEM = "PostmanPat:d=4,o=5,b=100:16f#,16p,16a,16p,8b,8p,16f#,16p,16a,16p,8b,8p,16f#,16p,16a,16p,16b,16p,16d6,16d6,16c#6,16c#6,16a,16p,b.,8p,32f#,16g,16p,16a,16p,16b,16p,16g,16p, 8f#.,8e,8p,32f#,16g,16p,16a,16p,32b.,32b.,16g,16p,8f#.,8e,8p,32f#,16g,16p,16a,16p,16b,16p,16g,16p,16f#,16p,16e,16p,16d,16p,16c#,6p,2d";
const char song_P[] PROGMEM = "Flntstn:d=4,o=5,b=200:g#,c#,8p,c#6,8a#,g#,c#,8p,g#,8f#,8f,8f,8f#,8g#,c#,d#,2f,2p,g#,c#,8p,c#6,8a#,g#,c#,8p,g#,8f#,8f,8f,8f#,8g#,c#,d#,2c#";
const char song_Q[] PROGMEM = "ScoobyDoo:d=4,o=5,b=160:8e6,8e6,8d6,8d6,2c6,8d6,e6,2a,16p,8a,b,g,e6,8e6,d6,c6,2p,8e6,8e6,8d6,8d6,2c6,8d6,e6,2f6,8a,g,g,e6,8e6,8d6,8d6,c6,2p,8e6,8e6,8d6,8d6,2c6,8d6,f6,a,8p,8a,8b,8b,g,e6,8e6,d6,e6,2p,8e6,8e6,8d6,8d6,c6,8p,8c6,8d6,e6,2f6,8a,g,g,e6,8e6,d6,c6,8p,8c6,8d6,8e6,8f6,8e6,8f6,8e6,8f6,8e6,8f6,8e6,16f6,16e6,f6,8e6,16f6,16f6,8f6,16f6,8f6,e6,p,8p,8g6,16g6,8g6,e6,p,8p";
const char song_R[] PROGMEM = "teletubbies:d=4,o=5,b=125:16g.,8p,16g,8e,g.,8p,a,2f.,16g.,8p,16g,8e,g.,8p,2d.,16g.,8p,16g,8e,g.,8p,a,2f.,2g,2b,2c.6";

const char * songs[] = { song_A, song_B, song_C, song_D, song_E, song_F, song_G, 
                         song_H, song_I, song_L, song_M, song_N, song_O, song_P,
                         song_Q, song_R};

int size = sizeof(songs)/2;

const int buttonPin = 8;
int buttonState = 0; 
int lastButtonState = 0;     // previous state of the button
int buttonPushCounter = 0;


unsigned long printedTime = -1;
unsigned long printedPeriod = 500;

ProgmemPlayer player(2);

void setup(void)
{
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(500);  
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
  player.setSong(song_A);
  randomSeed(analogRead(0));
  buttonPushCounter = random(1, size);
  player.setSong(songs[buttonPushCounter]);
}

void loop(void)
{

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonPushCounter);
 
  if (buttonState != lastButtonState) {
     
    if (buttonState == HIGH) {
      buttonPushCounter++;
      player.setSong(songs[buttonPushCounter]);
    } 
    
    // Delay a little bit to avoid bouncing
    delay(200);
   
    lastButtonState = buttonState; 
  }

  //play the tune with no blocking

  if (buttonPushCounter == size) {
    buttonPushCounter = 0;
    player.setSong(songs[buttonPushCounter]);
  }
  
  player.pollSong();
  stepper.runSpeed();

}
