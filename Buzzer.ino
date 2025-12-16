int buzzer=10;

void setup(){
  pinMode(buzzer,OUTPUT);

}
void loop(){
  digitalWrite(buzzer,LOW);
  delay(5000);
  digitalWrite(buzzer,HIGH);
  delay(5999);
}