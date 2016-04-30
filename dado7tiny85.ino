// == CONSTANTS ==
// pin connected to ST_CP of 74HC595
const byte PIN_LATCH = 2;
// pin connected to SH_CP of 74HC595
const byte PIN_CLOCK = 3;
// pin connected to DS of 74HC595
const byte PIN_DATA = 1;
// pin su cui si trova il pulsante per far ruotare i numeri
const int buttonPin = 4;

const int pontePin = 0;

int lus = 0;

int segment[10] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144 }; // for common anode

void setup()
{
  //set pins to output so you can control the shift register
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);

  pinMode(buttonPin, INPUT);
  pinMode(pontePin, INPUT);
  // the LEDs don't change while you're sending in bits
  digitalWrite(PIN_LATCH, LOW);
  // shift out the bits
  shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, 128);
  //take the latch pin high so the LEDs will light up
  digitalWrite(PIN_LATCH, HIGH);
  //Serial.begin(9600);
  randomSeed(0);

}

void loop () {



  int reading = digitalRead(buttonPin);
  int ponte = digitalRead(pontePin);

  while ( reading == 1 ) {

    if ( ponte == 0) {
      lus = random(0, 10);
    } else {
      lus = random(1, 7);
    }

    //Serial.println(lus);
    digitalWrite(PIN_LATCH, LOW);
    shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, segment[lus]);
    digitalWrite(PIN_LATCH, HIGH);
    reading = digitalRead(buttonPin);

    delay(10);
  }
}
