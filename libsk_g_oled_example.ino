// Arduino Project - stemkraf
// https://github.com/teaksoon/project_stemkraf
//
// Program: libsk_g_oled_example.ino
// libsk_g_oled - "G" Version - Graphics and Text
// by TeakSoon Ding for STEMKRAF ( OCT-2021 ) - Release 1
// ----------------------------------------------------------------------
//
// Sketch uses 5748 bytes (17%) of program storage space. Maximum is 32256 bytes.
// Global variables use 1139 bytes (55%) of dynamic memory, leaving 909 bytes for local variables. Maximum is 2048 bytes.
//
#include <libsk_g_oled.h>

char bitmap_8bit_u[14] = {
  0b10000000,
  0b10000000,
  0b11110000,
  0b10001000,
  0b10001000,
  0b10001000,
  0b11111111,
  0b11111111,  
  0b10001000,
  0b10001000,    
  0b10001000,
  0b11110000,
  0b10000000,
  0b10000000
};
char bitmap_8bit_d[14] = {
  0b00000001,
  0b00000001,
  0b00001111,
  0b00010001,
  0b00010001,
  0b00010001,
  0b11111111,
  0b11111111,
  0b00010001,  
  0b00010001,  
  0b00010001,
  0b00001111,
  0b00000001,
  0b00000001
};
// Turn this bitmap array 90degrees anti-clockwise, that is how the bitmap will look like

char bitmap_8bit_clear[14] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

int8_t bmp_u_col  = 57;
int8_t bmp_d_col  = 57;
int8_t time_mm    = 0;
char   a_tmp[3];

void setup() {  
  
  sk_oled_begin(); // Run this just once

  // LIBSK OLED "G" Version Text Functions
  sk_oled_showChar_L(3, 21, '1'); sk_oled_showChar_L(3, 97, 'G'); // "G Version"
  //
  // Show Full 8-bit Bitmap
  // Use within Limits ( Row = 0 to 7, Col( depends on bitmap size) = 0 to 127 )
  sk_oled_showBitmap(6, bmp_u_col, bitmap_8bit_u, 14,0); // show Bitmap 1
  sk_oled_showBitmap(7, bmp_d_col, bitmap_8bit_d, 14,0); // show Bitmap 2  
  
  // Show a Single ASCII Char ( 5 pixel each )
  // Use within Limits, ( Row = 0 to 7, Col = 0 to 123 )
  sk_oled_showChar(0,123, 'A');           
  sk_oled_showChar(7,  0, 'B'); 
  
  // Show a Single "Large" ASCII Char ( 10 pixel each )
  // "Large" Char uses 2 Rows
  // Use within Limits, ( Row = 0 to 6, Col = 0 to 118 )
  sk_oled_showChar_L(0,  0, 'A');           
  sk_oled_showChar_L(6,118, 'B'); 

  // Show a String, Max 21 Chars
  // Row and Col Limits are based on Char display Limits
  // Col = Total Number of Chars x (5+1) Col, Minus 1 Col
  // There is a 1 Col gap between 2 Chars in STring, only last Char does not
  sk_oled_showString(0, 35, "LIBSK OLED");
     
  // Show a "Large" String, Max 10 Chars
  // Row and Col Limits are based on "Large" Char display Limits
  // Col = Total Number of Chars x (10+2) Col, Minus 2 Col
  // There is a 2 Col gap between 2 Chars in String, only last Char does not
  sk_oled_showString_L(3, 41, "OLED");
  
  delay(3500); 
  sk_oled_clearScreen();

  // LIBSK OLED "G" Version Graphics Functions
  //
  sk_oled_showChar_L(3, 21, '1'); sk_oled_showChar_L(3, 97, 'G'); // "G Version"
  sk_oled_showString(0, 35, "LIBSK OLED");
  sk_oled_showString_L(3, 41, "OLED");  

  // Show a Single Pixel (dot)
  // There are no Row and Col Limit correction in Library.
  // Use within Limits, ( Row = 0 to 63, Col = 0 to 122 )  
  sk_oled_showDot( 0,   0, 1);
  sk_oled_showDot(63,   0, 1);
  sk_oled_showDot( 0, 127, 1);
  sk_oled_showDot(63, 127, 1);
  delay(1000); 
  sk_oled_showDot( 0,   0, 0);
  sk_oled_showDot(63,   0, 0);
  sk_oled_showDot( 0, 127, 0);
  sk_oled_showDot(63, 127, 0);  
  delay(1000);  
  sk_oled_showDot( 0,   0, 1);
  sk_oled_showDot(63,   0, 1);
  sk_oled_showDot( 0, 127, 1);
  sk_oled_showDot(63, 127, 1);  

  delay(1000);
  // Show Horizontal Line
  // Use within Limits, ( Row = 0 to 63, Col(depends on line length) = 0 to 127 )  
  sk_oled_showHLine( 8,  14, 98, 1);
  sk_oled_showHLine(45,  14, 98, 1);

  // Show Vertical Line
  // Use within Limits, ( Row(depends on line length) = 0 to 63, Col = 0 to 127 )   
  sk_oled_showVLine( 8, 14,  37,1);
  sk_oled_showVLine( 8,112,  37,1);  
  
  // Show Diagonal Line
  // Use within Limits, ( Row = 0 to 63, Col = 0 to 127 )   
  sk_oled_showLine( 8,  14,   8+12,  14+24,1);
  sk_oled_showLine( 8, 112,   8+12, 112-24,1);   

  delay(1000);
  sk_oled_showString_L(3, 41, "    ");  // Clear Text for Circle
  
  // Show Circle
  // Row and Col for Circle starts from Middle,
  // ( Row - radius >= 0, Row + radius <=  63 )
  // ( Col - radius >= 0, Col + radius <= 127 )  
  sk_oled_showCircle(26, 64, 14, 1);

  // Show Radial Spokes
  // Row and Col for Radial Spokes starts from Middle,
  // ( Row - Spokes Len >= 0, Row + Spokes Len <=  63 )
  // ( Col - Spokes Len >= 0, Col + Spokes Len <= 127 )
  for (uint8_t i=0; i < 8; i++) {
    sk_oled_showRadialSpokes(26, 64, 12, 0, 8, i, 1);  
  }
  
  // --- Animation Show ---
  //
  for (int8_t i=5; i >= 0; i--) {
    g_nStr2L(i, a_tmp); // Convert running number i, to a String, stored in tmp array
    sk_oled_showString_L(6, 54, a_tmp);  // show String "Large"
    g_pauseMillis(1000);
  }
  sk_oled_showString_L(6, 54, "  ");
  
  for (uint8_t i=0; i < 8; i++) {
    sk_oled_showRadialSpokes(26, 64, 12, 0, 8, i, 0);  
    g_pauseMillis(100);
  }
    
  sk_oled_showBitmap(6, bmp_u_col,   bitmap_8bit_u, 7,0);g_pauseMillis(300);  
  sk_oled_showBitmap(6, bmp_u_col+7, bitmap_8bit_u, 7,7);g_pauseMillis(300);    
  sk_oled_showBitmap(7, bmp_d_col+7, bitmap_8bit_d, 7,7);g_pauseMillis(300);  
  sk_oled_showBitmap(7, bmp_d_col,   bitmap_8bit_d, 7,0);g_pauseMillis(300);
  
  sk_oled_showRadialSpokes(26, 64, 11, 0, 60, time_mm, 1);
}

void loop() {  
  sk_oled_showBitmap(6, bmp_u_col, bitmap_8bit_clear, 14,0);  // Clear bitmap 1
  sk_oled_showBitmap(7, bmp_d_col, bitmap_8bit_clear, 14,0);  // Clear bitmap 2
  sk_oled_showRadialSpokes(26, 64, 11, 0, 60, time_mm, 0);    // Clear Radial spokes   
    
  bmp_u_col += 4; if (bmp_u_col > 113) bmp_u_col =   0; 
  bmp_d_col -= 4; if (bmp_d_col <   0) bmp_d_col = 113;
  time_mm   += 1; if (time_mm > 59) time_mm = 0;
  
  sk_oled_showBitmap(6,bmp_u_col,bitmap_8bit_u,14,0);       // Show Bitmap 1
  sk_oled_showBitmap(7,bmp_d_col,bitmap_8bit_d,14,0);       // Show Bitmap 2  
  sk_oled_showRadialSpokes(26, 64, 11, 0, 60, time_mm, 1);  // Show Radial Spokes
  
  g_pauseMillis(80);    
}

void g_nStr2L(uint8_t nn, char *a3_ch) {
// Convert a 2 digit number to a 2 char String, pad left with zero
uint8_t idx = 1;
  a3_ch[2]  = 0;
  a3_ch[0]  = '0'; a3_ch[1]='0';
  while (nn > 0) { // Load Numbers
    a3_ch[idx] = (nn%10) + 48; // ASCII 48 = 0
    nn = nn/10; idx--;
  }
}

void g_pauseMillis(unsigned long nn ) {
// Same as Arduino delay() function
unsigned long startMillis = millis();
  while( !( (millis()-startMillis)> nn) ) {}  
}
