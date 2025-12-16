char data;
int in1=3;
int in2=4;

void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()){
    data=Serial.read();

    if(data=='F'){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);}

    else if(data=='B'){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);}
    else{
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
    }
  }
}