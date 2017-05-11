  const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm; // fjöldi cm sem mældir eru


int xPin = A1;
int yPin = A0;
int buttonPin = 10;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
int ledpin = 4;


#include <Servo.h> //using the servo library


Servo myservo; // create an servo object
int potient = A0;
int potientValue = 0;
int snua = 90;
int att = 0;


void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledpin,OUTPUT);
}

void loop() {
   xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  if (cm < 20){
      digitalWrite(ledpin,HIGH);
  }
  else { digitalWrite(ledpin,LOW);}

  //delay(100); // add some delay between reads

  
  potientValue = analogRead(potient);
  potientValue = map(potientValue, 0, 1023, 0, 180);     
myservo.write(snua);
  if(att == 0) {
    snua+=4;
    if(snua >= 180) {
      att = 1;  
    }
  }
  
  else {
    snua-=4;  
    if(snua <= 0) {
      att = 0;  
    }
  }
  Serial.println(snua);
  myservo.write(snua);
  //delay (15);

  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  
  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  Serial.println(cm);
}
