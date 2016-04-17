#include <NewTone.h>

#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 200

int DO = 12;
int RE = 11;
int MI = 10;
int FA = 9;
int SOL = 8;
int LA = 7;
int SI = 6;

void setup() {
  pinMode( DO, OUTPUT);
  pinMode( RE, OUTPUT);
  pinMode( MI, OUTPUT);
  pinMode( FA, OUTPUT);
  pinMode( SOL, OUTPUT);
  pinMode( LA, OUTPUT);
  pinMode( SI, OUTPUT);
  pinMode( TRIGGER_PIN, OUTPUT );
  pinMode( ECHO_PIN, INPUT );
  Serial.begin(9600);
}

void loop() {
  digitalWrite (DO, LOW);
  digitalWrite (RE, LOW);
  digitalWrite (MI, LOW);
  digitalWrite (FA, LOW);
  digitalWrite (SOL, LOW);
  digitalWrite (LA, LOW);
  digitalWrite (SI, LOW);
  //delay(1000);
  //int uS = sonar.ping_median(10);
  //int r = sonar.convert_cm(uS);
  digitalWrite( TRIGGER_PIN, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( TRIGGER_PIN, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( TRIGGER_PIN, LOW );
  long duration = pulseIn( ECHO_PIN, HIGH );
  long r = 0.034 * duration / 2;
  Serial.print("Ping: ");
  Serial.print(r);
  Serial.println("cm");
  if (r < 6 ) {
    tone(3, 523, 400);
    digitalWrite (DO, HIGH);
  } 
  else if (r <= 12) {
    tone(3, 587, 400);
    digitalWrite (RE, HIGH);
  } 
  else if (r <= 18 ) {
    tone(3, 659, 400);
    digitalWrite (MI, HIGH);
  } 
  else if ( r <= 24 ) {
    tone(3, 698, 400);
    digitalWrite (FA, HIGH);
  } 
  else if ( r <=30 ) {
    tone(3, 784, 400);
    digitalWrite (SOL, HIGH);
  } 
  else if ( r <=36 ) {
    tone(3, 880, 400);
    digitalWrite (LA, HIGH);
  } 
  else if ( r > 36 && r <= 50 ) {
    tone(3, 988, 400);
    digitalWrite (SI, HIGH);
  }
  delay( 100 );

}

