if(Serial.available())
{

  bluetooth.print((char)Serial.read);
  
  // put your setup code here, to run once:

}
if(lightBlink)
{
  digitalWrite(led, HIGH);
  bluetooth.print("1");
  Serial.println("HIGH");
  delay(500);
  digitalWrite(led ,LOW);
  bluetooth.print("0");
  Serial.println("LOW");
  delay(500);
  // put your main code here, to run repeatedly:
}
