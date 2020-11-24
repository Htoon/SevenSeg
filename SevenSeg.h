// SevenSeg.h
// Single-digit Seven Segment Display library header
// Written by Htoon Aung Kyaw, 2020 November, 11

#ifndef SevenSeg_h
#define SevenSeg_h

#include <Arduino.h>

class SevenSeg
{
  public:
	// Constructors
	SevenSeg(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, bool is_common_cathode = true);
	SevenSeg(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, int led_dot, bool is_common_cathode = true);
	
	// Method to write a digit to Seven Segment
	void write(int digit, bool is_dot = false);
	// Method to turn-off all LEDs
	void turnOff();
	
  private:
	// Method to handle initiallization process
	void initiallize(int led_a, int led_b, int led_c, int led_d, int led_e, int led_f, int led_g, bool is_common_cathode);
	
	// Array to store segment bits from 0 to 9 and off
	int seg_bits [11][7]={
		{1, 1, 1, 1, 1, 1, 0},              	//0
		{0, 1, 1, 0, 0, 0, 0},              	//1
		{1, 1, 0, 1, 1, 0, 1},              	//2
		{1, 1, 1, 1, 0, 0, 1},              	//3
		{0, 1, 1, 0, 0, 1, 1},              	//4
		{1, 0, 1, 1, 0, 1, 1},              	//5
		{1, 0, 1, 1, 1, 1, 1},              	//6
		{1, 1, 1, 0, 0, 0, 0},              	//7 
		{1, 1, 1, 1, 1, 1, 1},              	//8
		{1, 1, 1, 1, 0, 1, 1},              	//9
		{0, 0, 0, 0, 0, 0, 0}              		//off
	};
	// Variables to store LED pins from constructor
	int pins[7];
	// Variable to store dot pin from constructor
	int dot_pin;
	
	// Variable to store if Common Cathode or not
	bool _is_common_cathode = true;
};

#endif