// Shift reg LCD trial
// No complex state M/C, motors or other stuff

#include <ShiftRegLCD.h>
#include "CLCD.h"
#include "PinsNo.h"

//#define OK 1

ShiftRegLCD LCDDisplay(m_dataPin, m_clockPin, m_EnablePin, m_MaxY);
CLCD MyLCDDisplay;
//int ErrLvl = 3;      // Error Level 0 none, 1 some and 3 verbose

void setup()
{
  pinMode(led, OUTPUT); 
  pinMode(m_dataPin, OUTPUT);
  pinMode(m_clockPin, OUTPUT);
  pinMode(m_EnablePin, OUTPUT);

  Serial.begin(9600);
  MyLCDDisplay.Clear(LCDDisplay);
  MyLCDDisplay.Write(LCDDisplay, "Initialisation");
  delay(1000);
  MyLCDDisplay.Clear(LCDDisplay);
  SystemState = Init;
}

void loop()
{
  char a ='.';
  String Command = NULL;
  
  switch( SystemState )
  {  
    case Init:
      Serial.println("Thunderbirds are GO !");
      SystemState = SystemIdle;
      break;
      
    case SystemIdle:
      MyLCDDisplay.Clear(LCDDisplay);
      MyLCDDisplay.Write(LCDDisplay, "SystemIdle");
      delay(1000);
      SystemState = e_CheckSerial;
      break;
   
    default:
      Serial.println("Main Loop Default trap !");
      SystemState = Init;
      break;
  }
}
