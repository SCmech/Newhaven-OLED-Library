/* 
*/
#ifndef nh_OLED
#define nh_OLED

#include <Arduino.h>
#include "Print.h" 
#include <SPI.h>

#define NO_PIN 255

class nhOLED : public Print { 
public:
  byte new_line[4] = {0x80, 0xA0, 0xC0, 0xE0}; // DDRAM address for each line of the display
  nhOLED(byte lines, byte cols, byte mosiPin, byte sckPin, byte csPin, byte rstPin);
  void begin();
  void end();
  void clear();
  void command(byte c);
  void data(byte d);
  void setCursor(int col, int row); //not working
  byte write(int col, int row, char c);
  // implementation for Print 
  virtual size_t write(uint8_t character);
  //byte write(char c);
  byte write(const char* s);
  

private:
  byte Lines, Cols;
  int  cursorC, cursorR;
  byte MOSI_pin, SCK_pin, CS_pin, RST_pin;
  byte Row_bit;
  //void clock_cycle();
  void send_byte(byte c);
  byte row_address[4];
  
};
#endif
