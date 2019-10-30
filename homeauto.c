void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  int data=Serial.read();
  switch(data)
  {
    case 1:digitalWrite(8,HIGH);break;
    case 0:digitalWrite(8,LOW);break;
    default:break;
  }
  Serial.println(data);
}
delay(50);
}
