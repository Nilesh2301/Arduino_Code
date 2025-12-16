int ldr=A0;
int led=3;
int threshold=700;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop(){
  int LDR_value=analogRead(ldr);
  Serial.print("sensor=");
  Serial.print(LDR_value);

  if(LDR_value<=threshold){
    digitalWrite(led,HIGH);
    
  }
  else{
    digitalWrite(led,LOW);
  }

}