int in1=3;
int in2=4;
int en=5;

void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en,OUTPUT);

}

void loop(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(en,150);
}