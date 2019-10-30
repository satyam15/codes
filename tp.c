#include <Password.h>

#include <Keypad.h>

#include <LiquidCrystal.h>
LiquidCrystal MyLCD(12,11,5,4,3,2);
#define Password_Lenght 7
char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123456";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;


  //4x4 Matrix key pad

  const byte ROWS = 4; // Four rows

  const byte COLS = 4; // Four columns

  // Define the Keymap

  char keys[ROWS][COLS] = 

  {

   
  {'1','2','3','A'},

   
  {'4','5','6','B'},

   
  {'7','8','9','C'},

   
  {'*','0','#','D'}

  };

  // Connect keypad ROW0, ROW1, ROW2 and ROW3 to Arduino pins.

  byte rowPins[ROWS] = { A0, A1, A2, A3 };

  // Connect keypad COL0, COL1, COL2 and COL3 to Arduino pins.

  byte colPins[COLS] = { A4, A5, 10, 9 }; 

  // Create the Keypad

  Keypad kpd= Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  // put your setup code here, to run once:
MyLCD.begin(16,2);
MyLCD.home();

MyLCD.print("Hello World");
MyLCD.setCursor(0,1);

}

void loop() {
  // put your main code here, to run repeatedly:
   char key= kpd.getKey();
    MyLCD.setCursor(0, 1);
     MyLCD.print("SEC= ");

   
  MyLCD.print(millis() / 1000);

    // Check  for a valid key

   
  if(key)  

    {

       // set  the cursor to column 9, line 1

       //  (note: line 1 is the second row, since counting begins with 0):

      
  MyLCD.setCursor(9, 1);

      
  //Print the detected key

      
  MyLCD.print("KEY= ");

      
  MyLCD.print(key);

    }  

  }

