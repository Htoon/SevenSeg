// Example sketch for Single-digit Seven Segment Dispaly library
// Written by Htoon Aung Kyaw, 2020 November 11

#include "SevenSeg.h"

// SevenSeg(A, B, C, D, E, F, G, is_Common_Cathode)
SevenSeg seg(6, 7, A5, A4, A3, 5, 4, false);

void setup() {
  //
}

void loop() {
  // Count for zero to nine in every 500 milliseconds
  for (int cnt = 0; cnt <= 9; cnt++) {
    seg.write(cnt);
    delay(500);
  }

  // Wait for 1 second
  seg.turnOff();
  delay(1000);
}
