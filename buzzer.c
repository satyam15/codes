
const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){
 
  digitalWrite(buzzer,HIGH); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
   digitalWrite(buzzer,LOW);
  delay(1000);        // ...for 1sec
  
}
