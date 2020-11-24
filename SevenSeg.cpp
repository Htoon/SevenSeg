// SevenSeg.cpp
// Single-digit Seven Segment Display library
// Written by Htoon Aung Kyaw, 2020 November, 11

#include "Arduino.h"
#include "SevenSeg.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Class constructors
/////////////////////////////////////////////////////////////////////////////////////////
SevenSeg::SevenSeg(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, bool is_common_cathode)
{
	SevenSeg::initiallize(led_a, led_b, led_c, led_d, led_e, led_f, led_g, is_common_cathode);
}

SevenSeg::SevenSeg(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, int led_dot, bool is_common_cathode)
{
	// Store dot_pin
	dot_pin = led_dot;
	// Set dot_pin as OUTPUT
	if (dot_pin >= 0) pinMode(dot_pin, OUTPUT);
	
	SevenSeg::initiallize(led_a, led_b, led_c, led_d, led_e, led_f, led_g, is_common_cathode);
}

/////////////////////////////////////////////////////////////////////////////////////////
// Private methods
/////////////////////////////////////////////////////////////////////////////////////////

// Method to handle initiallization process
void SevenSeg::initiallize(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, bool is_common_cathode)
{
	// Store Segment LED pins to pins array
	pins[0] = led_a;
	pins[1] = led_b;
	pins[2] = led_c;
	pins[3] = led_d;
	pins[4] = led_e;
	pins[5] = led_f;
	pins[6] = led_g;
	
	_is_common_cathode = is_common_cathode;
	
	// Set these pins as OUTPUT
	for (int cnt = 0; cnt < 7; cnt++)
	{
		pinMode(pins[cnt], OUTPUT);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
// Public methods
/////////////////////////////////////////////////////////////////////////////////////////

// Method to write a digit to Seven Segment
void SevenSeg::write(int digit, bool is_dot)
{
	for (int cnt = 0; cnt < 7; cnt++) {
		if (_is_common_cathode)
			digitalWrite (pins[cnt], seg_bits[digit][cnt]);
		else
			digitalWrite (pins[cnt], seg_bits[digit][cnt] ^ 1);
	}
	
	if (dot_pin >= 0)
	{
		if (is_dot == true) digitalWrite (dot_pin, HIGH);
		else digitalWrite (dot_pin, LOW);
	}
}

// Method to turn-off Seven Segment
void SevenSeg::turnOff()
{
	for (int cnt = 0; cnt < 7; cnt++) {
		if (_is_common_cathode)
			digitalWrite (pins[cnt], seg_bits[10][cnt]);
		else
			digitalWrite (pins[cnt], seg_bits[10][cnt] ^ 1);
  }
  
  if (dot_pin >= 0) digitalWrite (dot_pin, LOW);
}