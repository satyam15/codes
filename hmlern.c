
/*Thanks. Remember to visit my Youtube channel
  I've used a i2c LCD screen module. 
*/
//LCD config
#include <Wire.h>



int ScalepF=8;
int ScalenF=13;

//High values//
#define analogPin      A0          
#define chargePin      5         
#define dischargePin   A3      
#define resistorValue  10000.0F  //Remember, we've used a 10K resistor to charge the capacitor

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                
float nanoFarads;

//Low values//
const int OUT_PIN = A2;
const int IN_PIN = A0;
const float IN_STRAY_CAP_TO_GND = 50.28; //We have to change te resistance in this configuration. The 10K and 220 resistors 
                                         //are changeing the values
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 30.0;  
const int MAX_ADC_VALUE = 1023;




void setup() {
  
  

  pinMode(ScalepF,INPUT);
  pinMode(ScalenF,INPUT);

  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);
  pinMode(chargePin, OUTPUT);     
   

}

void loop() {


//////////////////////////nF/////////////////////////////////////////

if(digitalRead(ScalenF))
{
  pinMode(OUT_PIN,OUTPUT);
  digitalWrite(OUT_PIN,LOW); //to make it GND
  pinMode(analogPin,INPUT); //This pin will read the voltage
  
  digitalWrite(chargePin, HIGH);  
  startTime = micros();
  while(analogRead(analogPin) < 648){       
  }

  elapsedTime= micros() - startTime;
  microFarads = ((float)elapsedTime / resistorValue) ;

     
  
  if (microFarads > 1){

    
    Serial.print("SCALE:  100nF-4F");
  
    Serial.print(microFarads);
          
    Serial.print("uF");   
    delay(500);    
  }

  else{
    nanoFarads = microFarads * 1000.0; 
   
   
    Serial.print("SCALE:  100nF-4F");
      
    Serial.print(nanoFarads);  
          
    Serial.print("nF");          
    delay(500); 
  }

  
  digitalWrite(chargePin, LOW);            
  pinMode(dischargePin, OUTPUT);            
  digitalWrite(dischargePin, LOW);     //discharging the capacitor     
  while(analogRead(analogPin) > 0){         
  }//This while waits till the capaccitor is discharged

  pinMode(dischargePin, INPUT);      //this sets the pin to high impedance
  
 
  Serial.print("DISCHARGING.....");
   
  
}

//////////////////////////pF/////////////////////////////////////////

if(digitalRead(ScalepF))
{
    
    pinMode(chargePin,INPUT);
    pinMode(dischargePin,INPUT);//We give high impedance to the two pins. We don't use this pins


  
    pinMode(IN_PIN, INPUT);
    digitalWrite(OUT_PIN, HIGH);
    int val = analogRead(IN_PIN);
    digitalWrite(OUT_PIN, LOW);

    if (val < 976)
    {
      
      pinMode(IN_PIN, OUTPUT);

      float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);
     
   
      Serial.print("Scale:   1pF-1nF");
    
      Serial.print(capacitance,3);
  
      Serial.print("pF");
      delay(200);
    }
    
    else
    {
      pinMode(IN_PIN, OUTPUT);
      delay(1);
      pinMode(OUT_PIN, INPUT_PULLUP);
      unsigned long u1 = micros();
      unsigned long t;
      int digVal;

      do
      {
        digVal = digitalRead(OUT_PIN);
        unsigned long u2 = micros();
        t = u2 > u1 ? u2 - u1 : u1 - u2;
      } 
      
      while ((digVal < 1) && (t < 400000L));

      pinMode(OUT_PIN, INPUT);  
      val = analogRead(OUT_PIN);
      digitalWrite(IN_PIN, HIGH);
      int dischargeTime = (int)(t / 1000L) * 5;
      delay(dischargeTime);   
      pinMode(OUT_PIN, OUTPUT);  
      digitalWrite(OUT_PIN, LOW);
      digitalWrite(IN_PIN, LOW);

      float capacitance = -(float)t / R_PULLUP / log(1.0 - (float)val / (float)MAX_ADC_VALUE);

   
      Serial.print("Scale:   1pF-1nF");
      
      if (capacitance > 1000.0)
      {
        
        Serial.print("Scale:   1pF-1nF");
      
        Serial.print(capacitance / 1000.0, 3);
        
        Serial.print("uF ");
        delay(200);
        
      }
        
      else
      {
       
       
        Serial.print("Scale:   1pF-1nF");

        Serial.print(capacitance,3);
        
        Serial.print("nF");
        delay(200);
        
      }
  }
    while (micros() % 1000 != 0);
}
}
