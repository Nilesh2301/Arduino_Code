
int buzzer=4;
int trig=2;
int echo=3;

void setup(){
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
}


void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long time=pulseIn(echo,HIGH);
  int distance=time*0.034/2;
  if (distance<=20){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }


  Serial.print("distance=");
  Serial.println(distance);
}


























