#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#include<SoftwareSerial.h>

String voice;
/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  


unsigned int ic;
void AND_Gate()         //AND Gate Verification code is written here!
{
  int Result = 0,TD = 50;
  // Pin Configuration for AND gate IC.
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,LOW);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  digitalWrite(5,LOW);

  pinMode(8,INPUT);
  digitalWrite(8,LOW);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(11,INPUT);
  digitalWrite(11,LOW);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

// Testing the AND Gates.

  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(TD);
  if(digitalRead(2) == LOW)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(TD);
    if(digitalRead(2) == LOW)
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      delay(TD);
      if(digitalRead(2) == LOW)
      {
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        delay(TD);
        if(digitalRead(2) == HIGH)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(TD);
  if(digitalRead(5) == LOW)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(TD);
    if(digitalRead(5) == HIGH)
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      delay(TD);
      if(digitalRead(5) == HIGH)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        delay(TD);
        if(digitalRead(5) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  delay(TD);
  if(digitalRead(8) == LOW)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(TD);
    if(digitalRead(8) == HIGH)
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      delay(TD);
      if(digitalRead(8) == HIGH)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        delay(TD);
        if(digitalRead(8) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(TD);
  if(digitalRead(11) == LOW)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(TD);
    if(digitalRead(11) == HIGH)
    {
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      delay(TD);
      if(digitalRead(11) == HIGH)
      {
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        delay(TD);
        if(digitalRead(11) == LOW)
        {
          Result++;
        }
      }
    }
  }
  if(Result == 4)
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
   {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
  }
}
void XOR_Gate()         //XOR Gate Verification code is written here!
{
  int Result = 0,TD = 50;
  // Pin Configuration for AND gate IC.
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,LOW);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  digitalWrite(5,LOW);

  pinMode(8,INPUT);
  digitalWrite(8,LOW);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(11,INPUT);
  digitalWrite(11,LOW);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

// Testing the XOR Gates.

  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(TD);
  if(digitalRead(2) == LOW)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(TD);
    if(digitalRead(2) == LOW)
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      delay(TD);
      if(digitalRead(2) == LOW)
      {
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        delay(TD);
        if(digitalRead(2) == HIGH)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(TD);
  if(digitalRead(5) == LOW)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(TD);
    if(digitalRead(5) == LOW)
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      delay(TD);
      if(digitalRead(5) == LOW)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        delay(TD);
        if(digitalRead(5) == HIGH)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  delay(TD);
  if(digitalRead(8) == LOW)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(TD);
    if(digitalRead(8) == LOW)
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      delay(TD);
      if(digitalRead(8) == LOW)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        delay(TD);
        if(digitalRead(8) == HIGH)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(TD);
  if(digitalRead(11) == LOW)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(TD);
    if(digitalRead(11) == LOW)
    {
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      delay(TD);
      if(digitalRead(11) == LOW)
      {
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        delay(TD);
        if(digitalRead(11) == HIGH)
        {
          Result++;
        }
      }
    }
  }
  if(Result == 4)
   {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
    {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
  }
}
void OR_Gate()                   //OR Gate Verification code is written here!
{
  int Result = 0;
  // Pin Configuration for OR gate IC.
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,LOW);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  digitalWrite(5,LOW);

  pinMode(8,INPUT);
  digitalWrite(8,LOW);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(11,INPUT);
  digitalWrite(11,LOW);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

// Testing the OR Gates.
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  if(digitalRead(2) == LOW)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    if(digitalRead(2) == HIGH)
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      if(digitalRead(2) == HIGH)
      {
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        if(digitalRead(2) == HIGH)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  if(digitalRead(5) == LOW)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    if(digitalRead(5) == HIGH)
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      if(digitalRead(5) == HIGH)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        if(digitalRead(5) == HIGH)
        {
          Result++;
        }
      }
    }
  }
/////////////////////////////////////////////////////////////
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  if(digitalRead(8) == LOW)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    if(digitalRead(8) == HIGH)
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      if(digitalRead(8) == HIGH)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        if(digitalRead(8) == HIGH)
        {
          Result++;
        }
      }
    }
  }
/////////////////////////////////////////////////////////////
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  if(digitalRead(11) == LOW)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    if(digitalRead(11) == HIGH)
    {
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      if(digitalRead(11) == HIGH)
      {
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        if(digitalRead(11) == HIGH)
        {
          Result++;
        }
      }
    }
  }
  if(Result == 4)
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
   {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
}
}
void NAND_Gate()         //NAND Gate Verification code is written here!
{
  int Result = 0,TD = 50;
  // Pin Configuration for AND gate IC.
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,LOW);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  digitalWrite(5,LOW);

  pinMode(8,INPUT);
  digitalWrite(8,LOW);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(11,INPUT);
  digitalWrite(11,LOW);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

// Testing the NAND Gates.

  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(TD);
  if(digitalRead(2) == HIGH)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(TD);
    if(digitalRead(2) == HIGH)
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      delay(TD);
      if(digitalRead(2) == HIGH)
      {
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        delay(TD);
        if(digitalRead(2) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(TD);
  if(digitalRead(5) == HIGH)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(TD);
    if(digitalRead(5) == HIGH)
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      delay(TD);
      if(digitalRead(5) == HIGH)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        delay(TD);
        if(digitalRead(5) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  delay(TD);
  if(digitalRead(8) == HIGH)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(TD);
    if(digitalRead(8) == HIGH)
    {
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      delay(TD);
      if(digitalRead(8) == HIGH)
      {
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        delay(TD);
        if(digitalRead(8) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(TD);
  if(digitalRead(11) == HIGH)
  {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(TD);
    if(digitalRead(11) == HIGH)
    {
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      delay(TD);
      if(digitalRead(11) == HIGH)
      {
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        delay(TD);
        if(digitalRead(11) == LOW)
        {
          Result++;
        }
      }
    }
  }
  if(Result == 4)
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
}
}
void NOR_Gate()                   //NOR Gate Verification code is written here!
{
  int Result = 0;
  // Pin Configuration for OR gate IC.
  pinMode(2,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  digitalWrite(12,LOW);
  
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);
  digitalWrite(3,LOW);

  pinMode(6,INPUT);
  digitalWrite(6,LOW);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(9,INPUT);
  digitalWrite(9,LOW);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

// Testing the OR Gates.
  digitalWrite(2,LOW);
  digitalWrite(13,LOW);
  if(digitalRead(0) == HIGH)
  {
    digitalWrite(2,LOW);
    digitalWrite(13,HIGH);
    if(digitalRead(0) == LOW)
    {
      digitalWrite(2,HIGH);
      digitalWrite(13,LOW);
      if(digitalRead(0) == LOW)
      {
        digitalWrite(2,HIGH);
        digitalWrite(13,HIGH);
        if(digitalRead(0) == LOW)
        {
          Result++;
        }
      }
    }
  }
///////////////////////////////////////////////////////////
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  if(digitalRead(3) == HIGH)
  {
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    if(digitalRead(3) == LOW)
    {
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      if(digitalRead(3) == LOW)
      {
        digitalWrite(5,HIGH);
        digitalWrite(4,HIGH);
        if(digitalRead(3) == LOW)
        {
          Result++;
        }
      }
    }
  }
/////////////////////////////////////////////////////////////
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  if(digitalRead(6) == HIGH)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    if(digitalRead(6) == LOW)
    {
      digitalWrite(8,HIGH);
      digitalWrite(7,LOW);
      if(digitalRead(6) == LOW)
      {
        digitalWrite(8,HIGH);
        digitalWrite(7,HIGH);
        if(digitalRead(6) == LOW)
        {
          Result++;
        }
      }
    }
  }
/////////////////////////////////////////////////////////////
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  if(digitalRead(9) == HIGH)
  {
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    if(digitalRead(9) == LOW)
    {
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      if(digitalRead(9) == LOW)
      {
        digitalWrite(11,HIGH);
        digitalWrite(10,HIGH);
        if(digitalRead(9) == LOW)
        {
          Result++;
        }
      }
    }
  }
  if(Result == 4)
   {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
}
}
void NOT_Gate()         //NOT Gate Verification code is written here!
{
  int Result = 0,TD = 50;
  // Pin Configuration for AND gate IC.
  pinMode(12,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  

  pinMode(13,INPUT);
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(8,INPUT);
  pinMode(10,INPUT);

  
  digitalWrite(13,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);

// Testing the NOT Gates.

  digitalWrite(12,LOW);
  delay(TD);
  if(digitalRead(13) == HIGH)
  {
    digitalWrite(12,HIGH);
  
    delay(TD);
    if(digitalRead(13) == LOW)
    {      
          Result++;
        }
      }
    
///////////////////////////////////////////////////////////
  digitalWrite(2,LOW);
  delay(TD);
  if(digitalRead(3) == HIGH)
  {
    digitalWrite(2,HIGH);
  
    delay(TD);
    if(digitalRead(3) == LOW)
    {      
          Result++;
        }
      }
///////////////////////////////////////////////////////////
  digitalWrite(4,LOW);
  delay(TD);
  if(digitalRead(5) == HIGH)
  {
    digitalWrite(4,HIGH);
  
    delay(TD);
    if(digitalRead(5) == LOW)
    {      
          Result++;
        }
      }
///////////////////////////////////////////////////////////
  digitalWrite(7,LOW);
  delay(TD);
  if(digitalRead(8) == HIGH)
  {
    digitalWrite(7,HIGH);
  
    delay(TD);
    if(digitalRead(8) == LOW)
    {      
          Result++;
        }
      }
///////////////////////////////////////////////////////////
  digitalWrite(11,LOW);
  delay(TD);
  if(digitalRead(6) == HIGH)
  {
    digitalWrite(11,HIGH);
  
    delay(TD);
    if(digitalRead(6) == LOW)
    {      
          Result++;
        }
      }
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
  digitalWrite(9,LOW);
  delay(TD);
  if(digitalRead(10) == HIGH)
  {
    digitalWrite(9,HIGH);
  
    delay(TD);
    if(digitalRead(10) == LOW)
    {      
          Result++;
        }
      }
///////////////////////////////////////////////////////////
  if(Result == 6)
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
   lcd.print("IC Working");
   delay(3000);
    lcd.clear();
  }

  else
  {lcd.clear();
   delay(20);
   lcd.setCursor(0,0);
    lcd.print("IC not Working");
    delay(3000);
    lcd.clear();
  }
}
void setup() 
{ Serial.begin(9600);
  bt.begin(9600);
  int error;
  // See http://playground.arduino.cc/Main/I2cScanner
  Wire.begin();
  Wire.beginTransmission(0x27); //Your LCD Address
  error = Wire.endTransmission();
  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if

  lcd.begin(16, 2); // initialize the lcd
 lcd.setBacklight(255);
  
  lcd.print("  TEAM SPARKS  ");
  lcd.setCursor(0, 1);
  lcd.print("  I.C TESTER   ");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
   
  for(int i = 0; i<12; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  int td=1000;
  }
  

void loop()
{ lcd.clear();
delay(50);
   lcd.print("Enter I.C No.:");
 /* if(Serial.available()>0){
    ic=Serial.read();
    Serial.print("Checking IC:");
    Serial.println(ic);
  }  */
/*    char buffer[] = {' ',' ',' ',' ',' '}; // Receive up to 4 bytes
 while (!Serial.available()); // Wait for characters
 Serial.readBytesUntil('\n', buffer, 5);
 int ic = atoi(buffer);*/
 Serial.println(ic); 
 while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{break; }
voice += c;
}
lcd.setCursor(0,1);


int ic = voice.toInt();
Serial.println(ic);
lcd.print(ic);
if (voice.length() > 0){
  
  switch(ic){
    case 7400:
           {
            NAND_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
           break;
      }
    case 7402:
           {
            NOR_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
             break;
      }

    case 7404:
           {
            NOT_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
            break;
      }
    
    case 7408:
          {
            AND_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
            break;
      }

    case 7432:
           {
            OR_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
           break;
      }
    case 7486:
           {
            XOR_Gate();
             delay(4000);
             lcd.clear();
             lcd.setCursor(0,0);
            break;
      }
    }
  }
  delay(5000);
  voice ="";
}


              ///////////////////////////   THE END ////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// For more information contact : Mr. Vaibhav K Sugandhi, Founder and CEO of Unique Tech Designs - Hubli    //
//                                74118-04972                                                               //
//                                uniquetechdesigns555@gmail.com                                               //
//                                FB: Unique Tech Designs - Hubli                                           //
//                                    https://www.facebook.com/UTDUBL/                                      //
//                                Web:https://utdhbl.wordpress.com/                                         //  
//                                    Happy to build your ideas ..!                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
