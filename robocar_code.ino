#include <AFMotor.h>
#include <SoftwareSerial.h>


SoftwareSerial HC05(10, 9); // RX, TX
char cmd;
bool manualMode = false;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int trigPin = 12;
int echoPin = 7;


int buzzer = 2;

long duration, distance;


void stopAll() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void forwardAll() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backwardAll() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void leftTurn() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void rightTurn() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}


long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0) return -1;

  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  HC05.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  digitalWrite(buzzer, LOW);
  stopAll();
}

void loop() {

  
  if (HC05.available()) {
    cmd = HC05.read();
    Serial.println(cmd);

    manualMode = true;

    if (cmd == 'F') forwardAll();
    else if (cmd == 'B') backwardAll();
    else if (cmd == 'L') leftTurn();
    else if (cmd == 'R') rightTurn();
    else if (cmd == 'S') {
      stopAll();
      manualMode = false;
    }

    
    else if (cmd == 'V') {          
      digitalWrite(buzzer, LOW);
    }
    else if (cmd == 'v') {         
      digitalWrite(buzzer, HIGH);
    }

    return;
  }


  if (!manualMode) {
    distance = getDistance();

    if (distance > 0 && distance <= 8) {
      leftTurn();
      digitalWrite(buzzer, LOW);
    }
    else if (distance > 8 && distance <= 20) {
      forwardAll();
      digitalWrite(buzzer, LOW);
    }
    else {
      stopAll();
      digitalWrite(buzzer, HIGH);
    }
  }
}