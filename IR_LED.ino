int ir=A0;
int led=4;

void setup(){
  Serial.begin(9600);
  pinMode(ir,INPUT);
  pinMode(led,OUTPUT);

}
void loop(){
  int read=analogRead(ir);
  Serial.print("sensor=");
  Serial.print(read);
  if(read<=300){
    digitalWrite(led,HIGH);

  }
  else{
    digitalWrite(led,LOW);
  }
}