# libsk_oled

This is a very small and simple OLED Library for the SSD1306 OLED i2c 64x128 Pixel Display for ATMEGA328 micro-controller ( Arduino Uno ). It is specifically targetted so that this library can be as small as possible ( if you need support for other platform, change the source code since it is available to you ). Many error correction are intentionally not coded, also to keep this library as small as possible, you must use this library within its limits. 

This library has been made so simple that you only need the #include and 2 other functions from this library to get something shown on the OLED Screen. The following code display a single character 'H' to the OLED Screen

------

1. #include <libsk_c_oled.h> 
2. void setup() {
3.   sk_oled_begin(); // Run this just once
4.   sk_oled_showChar(3,61,'H'); // Send a single ASCII Char to OLED screen
5. }
6. void loop(){}

------

- Sketch uses 1302 bytes (4%) of program storage space. Maximum is 32256 bytes.
- Global variables use 35 bytes (1%) of dynamic memory, leaving 2013 bytes for local variables. Maximum is 2048 bytes.


There are 2 version of this library, "C" Version and "G" Version.
---

The "C" Version have a total of just only 7 functions.

1. sk_oled_begin() - Run this just once, before other library display functions
2. sk_oled_clearScreen() - Clears the entire OLED screen
3. sk_oled_showBitmap(_row,_col,_a_byt,_len,_len_idx) - display 8-bit bitmap (1-128 pixel)
4. sk_oled_showChar(_row,_col,_cha) - Show a ASCII Char ( 32 to 126 )
5. sk_oled_showString(_row,_col,_str) - Show a String ( array of Char terminated by NULL )
6. sk_oled_showChar_L(_row,_col,_cha) - Same as "_showChar()" but doubled in size
7. sk_oled_showString_L(_row,_col,_str) - Same as "_showString()" but doubled in size

The "G" Version have all the functions in the "C" Version, with 6 more addtional functions
to deal with pixel level graphics

1. sk_oled_showDot(_row,_col,_state ) - display a single dot on the screen
2. sk_oled_showHLine(_row,_col,_len,_state) - Draw Horizontal Line
3. sk_oled_showVLine(_row,_col,_len,_state) - Draw Vertical Line
4. sk_oled_showCircle(_row,_col,__radius,_state) - Draw a Circle
5. sk_oled_showLine(_row_1,_row_2,_col_1,_col_2,_state) - Draw a Diagonal Line
6. sk_oled_showRadialSpokes(_row,_col,_len,_len_idx,_step,__step_idx,_state) - Draw Radial Spokes

NOTE: The "C" version have smaller memory footprint as it does not need to use a video buffer of 1024 bytes to handle pixel based rendering.
---

How to install this library into Arduino IDE Software ?
---

1. Find [Arduino User Program Folder] from the Arduino IDE Software, "File | Preferences | Sketchbook Location: [Arduino User Program Folder]"

2. Use the Computer File Browser, Look for an existing folder named "libraries" inside the [Arduino User Program Folder]

3. Inside the "libraries" folder, Create a new folder named "libsk_oled"

4. Copy "libsk_c_oled.h" into the newly created "libsk_oled" folder 
- [Arduino User Program Folder] / libraries / libsk_oled / libsk_c_oled.h
 
5. Copy "libsk_g_oled.h" into the newly created "libsk_oled" folder 
- [Arduino User Program Folder] / libraries / libsk_oled / libsk_g_oled.h

Installation DONE!!!
---
   
There are two Arduino example program for this library, 
- one for "C" version "libsk_c_oled_example.ino"
- one for "G" version "libsk_g_oled_example.ino"

NOTE: 

You CANNOT use both "C" and "G" version at the same time because both versions are using
the same function names. Having same function names, allows us to swap between the two 
versions by just changing the include header.

We code either #include <libsk_c_oled.h> or #include <libsk_g_oled.h> but not both at the same time.
---

My suggestion is to use the "C" version first, #include <sklib_c_oled.h> , because all the 
functions in this version will work the same when you switch to the "G" by just changing the 
include to #include <libsk_g_oled.h> with no change in the other codes. 



