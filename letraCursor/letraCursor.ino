#include <LiquidCrystal.h>
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int adc_key_in  = 0;
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
int botonRecibido = btnNONE;
int col = 0;
int row = 0;
int letra = 65;



int read_LCD_buttons()
{
  adc_key_in = analogRead(A0);
  if (adc_key_in > 900) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;
  return btnNONE;
}

int moverCursor(int botonRecibido) {
  if (botonRecibido == btnRIGHT) {
    if (col < 16) {
      col = col + 1;
      return col;
      
    }
   
    
  }

  if (botonRecibido == btnLEFT) {
    if (col > 0 ) {
      
      col = col -1;
      return col;
    }
  }

  if (botonRecibido == btnUP) {
    if (row == 1) {
      row = 0;
    }
    return row;
  }

  if (botonRecibido == btnDOWN) {
    if (row == 0) {
      row = 1;
    }
    return row;
  }

  return 16;
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
 lcd.setCursor(0, 0);
  lcd.print((char)letra);
}

void loop()
{
 
   
  delay(100);
  botonRecibido = read_LCD_buttons();
  
  
  if (botonRecibido != btnNONE) {
    int retorno = moverCursor(botonRecibido);

   
    if(botonRecibido == btnSELECT){
     
      
      if(letra < 90){
      letra = letra +1;
      }else{
      letra = 65;
      
      }
      
  Serial.print(letra);
    
    }
  }
  
  
  lcd.clear();
  lcd.setCursor(col,row);
  lcd.print((char)letra);
  
 
 

}

