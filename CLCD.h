#ifndef _CLCD_H
#define _CLCD_H
  
#define m_MaxX 16       // Max Dispaly size
#define m_MaxY 2
  
class CLCD //: public ShiftRegLCD 
{  
public:
  CLCD();
  void Clear(ShiftRegLCD);
  void Write(ShiftRegLCD theLCD, String Message);
  void MoveXY(int Column, int Row);
  void Display(String LCDMessage);
};

#endif
