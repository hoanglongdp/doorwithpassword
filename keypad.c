#ifndef __KEYPAD_C__
#define __KEYPAD_C__
#include <lcd.c>

int i=0;
char A[10];

void key_init(void) {
   output_drive(COL1);  //Set output
   output_drive(COL2);
   output_drive(COL3);
   output_float(ROW1);  //Set input
   output_float(ROW2);
   output_float(ROW3);
   output_float(ROW4);
}

unsigned char quet_phim(int x) {
   output_b(0b11111101);   //Quet col1
   delay_ms(50);
   if (!input(ROW1)) {
      delay_ms(250);
      while(!input(ROW1));
      lcd_gotoxy(x+i, 1);
      lcd_putc("1");
      A[i]='1';
      i++;
      return '1';
   }

   if (!input(ROW2)) {
      delay_ms(250);
      while(!input(ROW2));
      lcd_gotoxy(x+i, 1);
      lcd_putc("4");
      A[i]='4';
      i++;
      return '4';
   }

   if (!input(ROW3)) {
      delay_ms(250);
      while(!input(ROW3));
      lcd_gotoxy(x+i, 1);
      lcd_putc("7");
      A[i]='7';
      i++;
      return '7';
   }

   if (!input(ROW4)) {
      delay_ms(250);
      while(!input(ROW4));
      lcd_gotoxy(x+i, 1);
      lcd_putc("*");
      A[i]='*';
      i++;
      return '*';
   }

   output_b(0b11111011);   //Quet col2
   delay_ms(50);
   if (!input(ROW1)) {
      delay_ms(250);
      while(!input(ROW1));
      lcd_gotoxy(x+i, 1);
      lcd_putc("2");
      A[i]='2';
      i++;
      return '2';
   }

   if (!input(ROW2)) {
      delay_ms(250);
      while(!input(ROW2));
      lcd_gotoxy(x+i, 1);
      lcd_putc("5");
      A[i]='5';
      i++;
      return '5';
   }

   if (!input(ROW3)) {
      delay_ms(250);
      while(!input(ROW3));
      lcd_gotoxy(x+i, 1);
      lcd_putc("8");
      A[i]='8';
      i++;
      return '8';
   }

   if (!input(ROW4)) {
      delay_ms(250);
      while(!input(ROW4));
      lcd_gotoxy(x+i, 1);
      lcd_putc("0");
      A[i]='0';
      i++;
      return '0';
   }

   output_b(0b11110111);   //Quet col3
   delay_ms(50);
   if (!input(ROW1)) {
      delay_ms(250);
      while(!input(ROW1));
      lcd_gotoxy(x+i, 1);
      lcd_putc("3");
      A[i]='3';
      i++;
      return '3';
   }

   if (!input(ROW2)) {
      delay_ms(250);
      while(!input(ROW2));
      lcd_gotoxy(x+i, 1);
      lcd_putc("6");
      A[i]='6';
      i++;
      return '6';
   }

   if (!input(ROW3)) {
      delay_ms(250);
      while(!input(ROW3));
      lcd_gotoxy(x+i, 1);
      lcd_putc("9");
      A[i]='9';
      i++;
      return '9';
   }

   if (!input(ROW4)) {
      delay_ms(250);
      while(!input(ROW4));
      lcd_gotoxy(x+i, 1);
      lcd_putc("#");
      A[i]='#';
      i++;
      return '#';
   }
   
}

int checkpass() {
   if (i<=0 && i<6) {
      return 0;
   }else {
      if (A[0]=='1' && A[1]=='2' && A[2]=='3'&& A[3]=='4'&& A[4]=='5'&& A[5]=='6' && A[6]=='*') {
         return 1;
      }else {
         return 0;
      }
   }
}

#endif
