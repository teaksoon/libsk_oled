# libsk_oled

The LIBSK OLED Library is targetted specially for the the SSD1306 OLED i2c 64x128 pixel Display Module, to be used with the atmega328 micro-controller ( on Arduino Uno, Nano and etc ). The main aim of creating this library is to have a very small and simple OLED Library. Many error corrections are not coded intentionally, in order to keep this library as small as posssible. Use this library within its limits.

------

There are 2 version of this library, "C" Version and "G" Version. Following are the functions available for both Versions.
---
1. sk_oled_begin() - Run this just once, before other library display functions
2. sk_oled_clearScreen() - Clears the entire OLED screen
3. sk_oled_showBitmap(_row,_col,_a_byt,_len,_len_idx) - display 8-bit bitmap (1-128 pixel)
4. sk_oled_showChar(_row,_col,_cha) - Show a ASCII Char ( 32 to 126 )
5. sk_oled_showString(_row,_col,_str) - Show a String ( array of Char terminated by NULL )
6. sk_oled_showChar_L(_row,_col,_cha) - Same as "_showChar()" but doubled in size
7. sk_oled_showString_L(_row,_col,_str) - Same as "_showString()" but doubled in size

- _row - (0 to 8 - top to bottom ), for Char and Bitmap
- _row - (0 to 7 - top to bottom ), for "Char_L" ( each "Char_L" also uses 2 rows )
- _col - (0 to 127 pixel - left to right), for Bitmap ( each Byte of Bitmap is 1 pixel )
- _col - (0 to 123 pixel - left to right), for Char ( each Char is 5-pixel ) 
- _col - (0 to 118 pixel - left to right), for "Char_L" ( each "Char_L" is 10-pixel ) 
- _cha     - ASCII Char ( 32 to 126 )


The following are functions for the "G" Version Only ( with pixel level graphics )
---
1. sk_oled_showDot(_row,_col,_state ) - display a single dot on the screen
2. sk_oled_showHLine(_row,_col,_len,_state) - Draw Horizontal Line
3. sk_oled_showVLine(_row,_col,_len,_state) - Draw Vertical Line
4. sk_oled_showCircle(_row,_col,__radius,_state) - Draw a Circle
5. sk_oled_showLine(_row_1,_row_2,_col_1,_col_2,_state) - Draw a Diagonal Line
6. sk_oled_showRadialSpokes(_row,_col,_len,_len_idx,_step,__step_idx,_state) - Draw Radial Spokes

- _state    - 1 for ON, 0 for OFF
- _row      - ( 0 to 63 pixel, top to bottom )
- _col      - ( 0 to 127 pixel, left to right )
- _len      - Number of pixel ( Length )
- _radius   - Number of Pixel ( Diameter / 2 ) - for showCircle()
- _len_idx  - Starting index from _len - for showRadialSpokes()
- _step     - Total number of evenly distributed spokes in a "Circle" - for showRadialSpokes()
- _step_idx - Index of step ( 0 to _step-1 ), step_idx=0 is vertical top from center, step_idx=1, in clockwise movement

------


How to install this library into the Arduino IDE Software ?
---
1. Find [Arduino User Program Folder] from the Arduino IDE Software, 
- "File | Preferences | Sketchbook Location: [Arduino User Program Folder]"

2. Use the Computer File Browser, 
- Look for an existing folder named "libraries" inside the [Arduino User Program Folder]

3. Inside the "libraries" folder,
- Create a new folder named "libsk_oled"

4. Copy "libsk_c_oled.h" into the newly created "libsk_oled" folder
- [Arduino User Program Folder] / libraries / libsk_oled / libsk_c_oled.h

5. Copy "libsk_g_oled.h" into the newly created "libsk_oled" folder
- [Arduino User Program Folder] / libraries / libsk_oled / libsk_g_oled.h

Installation DONE!!!

------

After installation, you may want to try out this two small test program for both versions of the Library

"C" Version 
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

"G" Version 
------
1. #include <libsk_g_oled.h> // Simple "G" Version Example
2. void setup() {
3. sk_oled_begin(); // Run this just once
4. sk_oled_showChar(3,61,'H'); // Send a single ASCII Char to OLED screen ( Text Mode )
5. sk_oled_showDot(16,64); // Send a Dot OLED screen ( Graphics Mode )
6. }
7. void loop(){}
------
- Sketch uses 1374 bytes (4%) of program storage space. Maximum is 32256 bytes.
- Global variables use 1059 bytes (51%) of dynamic memory, leaving 989 bytes for local variables. Maximum is 2048 bytes.

------

There are two Arduino example program for this library,

1. "libsk_c_oled_example.ino" - demonstrates all the functions in the "C" Version
2. "libsk_g_oled_example.ino" - demonstrates all the functions in the "G" Version

NOTE: 
---

The "C" version have smaller memory footprint as it does not need to use a video buffer of 1024 bytes to handle pixel based rendering. 

You cannot use both"C" and "G" version at the same time because both versions are using the same function names. Having same function names, allows us to swap between the two versions by just changing the include header. 

My suggestion, is to use the "C" version first, by using #include <libsk_c_oled.h> and when you need to use functions from the "G" Version, simply change to #include <libsk_g_oled.h> and there is no need to change anything else.
