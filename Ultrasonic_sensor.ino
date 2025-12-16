int trig=12;
int echo=07;


void setup(){
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}
void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long time = pulseIn(echo,HIGH);
  int distance=time*0.034/2;
  Serial.print("Distance=");
  Serial.println(distance);

}