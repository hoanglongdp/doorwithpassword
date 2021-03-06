#include <main.h>
#define LCD_ENABLE_PIN  PIN_D0                                    
#define LCD_RS_PIN      PIN_D1                                    
#define LCD_RW_PIN      PIN_D2                                    
#define LCD_DATA4       PIN_D4                                    
#define LCD_DATA5       PIN_D5                                    
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7   
#include <lcd.c>
#define COL1 pin_B1
#define COL2 pin_B2
#define COL3 pin_B3
#define ROW1 pin_B4
#define ROW2 pin_B5
#define ROW3 pin_B6
#define ROW4 pin_B7
#include <keypad.c>


//__LCD_Function__Start
void LCD_Enable( void) {
   output_high(LCD_ENABLE_PIN);
   delay_ms(3);
   output_low(LCD_ENABLE_PIN);
   delay_ms(50);
}

void LCD_Send4Bit(unsigned char Data) {
   output_bit(LCD_DATA4, Data && 0x01);
   output_bit(LCD_DATA5, (Data>>1) && 1);
   output_bit(LCD_DATA6, (Data>>2) && 1);
   output_bit(LCD_DATA7, (Data>>3) && 1);
}

void LCD_SendCommand(unsigned char command) {
   output_low(LCD_RS_PIN);
   LCD_Send4Bit(command>>4);
   LCD_Enable();
   LCD_Send4Bit(command);
   LCD_Enable();
}

void LCD_Clear() {
   LCD_SendCommand(0x01);
   delay_ms(10);
}


void main() {
   lcd_init();
   set_tris_d(0x00);
   lcd_putc("Pass: ");
   char key = ' ';
   int result;
   while (TRUE)
   {
      key = quet_phim(6);
      if (key=='*') {
         result = checkpass();
         if (result) {
            LCD_Clear();
            lcd_putc("RIGHT");
            delay_ms(1000);
            reset_cpu();
         }else {
            LCD_Clear();
            lcd_putc("WRONG");
            delay_ms(1000);
            reset_cpu();
         }
      }
   }
}
