#ifndef PIXELS_H
#define PIXELS_H

#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

// Note: Hyperion uses a 4.167 ms delay
// 1 s / 240 lines per second = 4.167 ms per line
// Not using delay here because this drawing pattern is a bit slower
// ...except let's actually use 4 for a little bit...
#define PATTERN_DELAY 4

const uint8_t pattern_0_psychedelic_sunset_grad[] PROGMEM = {21, 21, 4, 1, 35, 19, 19, 19, 17, 49, 49, 49, 50, 17, 2, 33, 33, 51, 17, 17, 51, 18, 18, 32, 1,35, 19, 20, 20, 17, 65, 65, 49, 50, 16, 33, 20, 65, 21, 85, 85, 81, 20, 65, 18, 35, 17, 21, 85, 22, 17, 97, 85, 81, 17, 49, 20, 17, 22, 17, 23, 113, 17, 97, 17, 65, 35, 69, 17, 119, 24, 136, 129, 119, 17, 84, 49, 20, 86, 113, 136, 145, 25, 136, 23, 101, 65, 33,21, 23, 137, 17, 170, 17, 152, 113, 81, 19, 20, 17, 24, 26, 177, 27, 161, 129, 17, 65, 20, 17, 24, 145, 177, 204, 27, 25, 129, 17,65, 21, 103, 129, 161, 193, 28, 26, 24, 118, 81, 17, 86, 120, 26, 28, 17, 193, 161, 135, 101, 17, 65, 17, 137, 27, 28, 193, 177, 152, 17, 20, 49, 65, 17, 129, 171, 17, 186, 24, 17, 20, 18, 17, 81, 120, 145, 26, 161, 25, 135, 21, 17, 17, 69, 103, 24, 137, 17, 152, 129, 118, 84, 18, 52, 81, 23, 113, 136, 136, 23, 113, 21, 67, 17, 65, 17, 97, 17, 119, 17, 22, 17, 20, 18, 49, 17, 85, 81, 97, 22, 22, 85, 17, 19, 34, 17, 68, 65, 85, 85, 85, 21, 68, 17, 2};
const uint32_t palette_0_psychedelic_sunset_grad[] PROGMEM = {-5640449, -16777216, -8132865, -10697473, -13596417, -15204097, -10152709, -6548229, -3836929, -1852161, -279297, -622594, -840449};

const uint8_t pattern_1_10x10_chaser_fire[] PROGMEM = {10, 10, 3, 1, 9, 9, 9, 9, 10, 9, 9, 9, 9, 9, 25, 9, 9, 9, 9, 12, 9, 9, 9, 9, 9, 41, 9, 9, 9, 9,12, 9, 9, 9, 9, 9, 25, 9, 9, 9, 9, 10, 9, 9, 9, 9, 9, 1, 9, 9, 9, 9, 14};
const uint32_t palette_1_10x10_chaser_fire[] PROGMEM = {-36352, -16777216, -22528, -13312, -5632, -2952, -65536};

const uint8_t pattern_2_interlock_line_rbw[] PROGMEM = {51, 16, 4, 0, 0, 0, 0, 0, 1, 16, 2, 48, 0, 0, 0, 0, 0, 68, 0, 85, 0, 0, 0, 0, 0, 6, 96, 7, 112,0, 0, 0, 0, 0, 17, 0, 35, 0, 0, 0, 0, 0, 4, 64, 5, 80, 0, 0, 0, 0, 0, 102, 0, 119, 0, 1, 17, 17, 17, 17, 16, 2, 48, 0, 68, 68, 68,68, 68, 0, 85, 0, 6, 102, 102, 102, 102, 96, 7, 112, 0, 17, 17, 17, 17, 17, 0, 35, 0, 4, 68, 68, 68, 68, 64, 5, 80, 0, 102, 102, 102, 102, 102, 0, 119, 0, 1, 16, 0, 0, 0, 0, 2, 48, 0, 68, 0, 0, 0, 0, 0, 85, 0, 6, 96, 0, 0, 0, 0, 7, 112, 0, 17, 0, 0, 0, 0, 0, 35, 0, 4, 64, 0, 0, 0, 0, 5, 80, 0, 102, 0, 0, 0, 0, 0, 119, 0, 1, 16, 3, 51, 51, 51, 50, 48, 0, 68, 0, 85, 85, 85, 85, 85, 0, 6, 96,7, 119, 119, 119, 119, 112, 0, 17, 0, 51, 51, 51, 51, 51, 0, 4, 64, 5, 85, 85, 85, 85, 80, 0, 102, 0, 119, 119, 119, 119, 119, 0, 1, 16, 3, 48, 0, 0, 0, 0, 0, 68, 0, 85, 0, 0, 0, 0, 0, 6, 96, 7, 112, 0, 0, 0, 0, 0, 17, 0, 51, 0, 0, 0, 0, 0, 4, 64, 5, 80, 0, 0, 0, 0, 0, 102, 0, 119, 0, 0, 0, 0, 0, 1, 17, 17, 17, 17, 16, 0, 0, 0, 68, 68, 68, 68, 68, 0, 0, 0, 6, 102, 102, 102, 102, 96, 0, 0, 0, 17, 17, 17, 17, 17, 0, 0, 0, 4, 68, 68, 68, 68, 64, 0, 0, 0, 102, 102, 102, 102, 102, 0, 0, 0, 0, 0, 3, 48, 8, 16, 0, 0, 0, 0, 0, 85, 0, 68, 0, 0, 0, 0, 0, 7, 112, 6, 96, 0, 0, 0, 0, 0, 51, 0, 17, 0, 0, 0, 0, 0, 5, 80, 4, 64, 0, 0, 0, 0, 0, 119, 0, 102, 0, 0,0, 0, 0, 3, 35, 51, 35, 51, 48, 0, 0, 0, 85, 85, 85, 85, 85, 0, 0, 0, 7, 119, 119, 119, 119, 112, 0, 0, 0, 51, 51, 50, 51, 51, 0, 0, 0, 5, 85, 85, 85, 85, 80, 0, 0, 0, 119, 119, 119, 119, 119};
const uint32_t palette_2_interlock_line_rbw[] PROGMEM = {-16777216, -63698, -1032699, -48374, -1536, -13172953, -16476673, -5294640, -1309401};

//const uint8_t pattern_3_circles_blue_yellow_green[] PROGMEM = {25, 25, 6, 0, 1, 0, 2, 3, 4, 3, 1, 5, 2, 6, 6, 6, 1, 4, 2, 4, 1, 6, 1, 1, 1, 1, 1, 7, 6, 2, 3, 8, 1, 9, 1, 1, 10, 6, 2, 1, 2, 6, 0, 9, 11, 12, 13, 0, 14, 0, 15, 16, 17, 18, 2, 19, 14, 20, 21, 0, 0, 1, 22, 0, 4, 0, 16, 2, 0, 0,9, 11, 0, 6, 16, 0, 1, 11, 1, 2, 1, 21, 2, 11, 1, 1, 1, 6, 2, 21, 2, 6, 2, 1, 20, 2, 5, 15, 6, 1, 4, 5, 0, 22, 2, 2, 2, 11, 8, 0, 5, 23, 1, 6, 19, 6, 22, 16, 22, 24, 2, 5, 11, 2, 6, 0, 1, 6, 25, 2, 2, 1, 4, 9, 0, 18, 22, 26, 2, 1, 22, 2, 15, 27, 1, 24, 5, 23, 4, 0, 1, 0, 1, 24, 0, 20, 15, 28, 0, 6, 1, 10, 1, 6, 2, 22, 5, 0, 0, 15, 22, 0, 21, 12, 8, 29, 27, 1, 22, 2, 4, 0, 5, 30, 1, 11, 1, 15, 1, 26, 22, 5, 0, 0, 15, 22, 10, 12, 4, 0, 9, 15, 27, 14, 0, 11, 0, 12, 22, 13, 1, 21, 1, 10, 6, 22, 1, 15, 27, 1, 24, 5, 28, 0,2, 15, 5, 5, 31, 2, 5, 0, 5, 10, 1, 11, 1, 11, 2, 18, 0, 22, 25, 25, 24, 10, 1, 20, 1, 15, 1, 19, 30, 1, 5, 1, 9, 0, 0, 6, 2, 0, 2, 6, 1, 17, 11, 1, 0, 5, 28, 2, 0, 4, 30, 18, 2, 1, 16, 1, 11, 12, 2, 5, 0, 30, 25, 32, 1, 27, 15, 0, 2, 4, 4, 4, 3, 1, 0, 6, 7, 4,4, 15, 11, 1, 9, 1, 5, 1, 0, 0, 0, 5, 0, 9, 15, 2, 4, 4, 4, 21, 11, 1, 16, 15, 8, 5, 0, 11, 29, 5, 9, 1, 6, 7, 33, 6, 1, 34, 0, 9,5, 15, 4, 19, 15, 1, 20, 6, 1, 5, 9, 1, 21, 0, 35, 4, 33, 0, 20, 20, 0, 0, 5, 15, 1, 0, 19, 1, 15, 11, 0, 14, 19, 6, 0, 19, 4, 1, 1, 36, 5, 19, 1, 3, 3, 0, 18, 5, 16, 19, 16, 3, 14, 1, 1, 19, 14, 21, 14, 1, 2, 30, 5, 1, 9, 11, 2, 6, 1, 1, 6, 2, 11, 0, 6, 1, 2, 19, 22, 0, 0, 37, 14, 19, 1, 9, 36, 1, 16, 35, 34, 1, 0, 22, 22, 1, 11, 1, 10, 22, 8, 0, 22, 10, 4, 5, 1, 25, 1, 4, 12, 9, 5, 10, 1, 6, 1, 1, 22, 1, 4, 1, 0, 5, 1, 24, 25, 0, 5, 21, 9, 0, 6, 27, 15, 2, 0, 0, 11, 25, 1, 4, 5, 10, 6, 0, 2, 4, 1, 5, 9, 1, 22, 35, 5, 4, 2, 38, 5, 8, 2, 4, 35, 1, 22, 11, 2, 2, 5, 0, 1, 0, 4, 0, 1, 2, 5, 18, 18, 2, 1, 14, 1, 28, 27, 2, 9, 4, 0, 28, 9, 20, 1, 5, 32, 1, 1, 35, 15, 0, 0, 11, 7, 1, 38, 8, 1, 1, 5, 9, 8, 1, 5, 0, 0, 11, 16, 5, 0, 1, 0, 5, 1, 25, 39, 40, 6, 6, 39, 24, 0, 0, 22, 1,11, 4, 5, 9, 1, 1, 10, 15, 1, 0, 13, 38, 18, 6, 10, 11, 5, 0, 11, 9, 5, 5, 4, 0, 6, 35, 9, 2, 11, 10, 16, 5, 1, 10, 27, 1, 1, 1, 0, 15, 17, 20, 11, 1, 4, 35, 21, 21, 11, 22, 0, 4};
//const uint32_t palette_3_circles_blue_yellow_green[] PROGMEM = {-16248219, -16580193, -16317717, -16710634, -131837, -4406001, -13381882, -15327181, -16442879, -12364028, -14208929, -7166456, -3343607, -14275456, -12849916, -8744696, -11702004, -14143965, -14595777, -15972091, -16645843, -15724273, -12612604, -5908725, -15569397, -14310138, -15840467, -9735165, -14472188, -10850500, -15912379, -16372221, -15974333, -15653592, -13418431, -11840465, -12958124, -9589749, -15440334, -14528664, -14130595};

// NeoPixel wrapper
class Pixels {
	public:
		Pixels(int pin, int numPixels, int brightness) :
		_pixels(Adafruit_NeoPixel(numPixels, pin, NEO_GRB + NEO_KHZ800)),
		_numPixels(numPixels),
		_brightness(brightness) {
		}

		void setup() {
			_pixels.begin();
		}

   int _beadAStart = 0;
   int _beadBStart = 50;
   int beadWidth = 13;
   
   void bead() {
      uint32_t color = _pixels.Color(255, 255, 255);
      uint32_t black = _pixels.Color(0, 0, 0);
      for(uint16_t i=0; i<_pixels.numPixels(); i++) {
        bool isInBeadA = i >= _beadAStart && i < _beadAStart + beadWidth;
        bool isInBeadB = i >= _beadBStart && i < _beadBStart + beadWidth;
        if (isInBeadA || isInBeadB) {
          _pixels.setPixelColor(i, color);
        } else {
          _pixels.setPixelColor(i, black);
        }
      }

      _pixels.show();
      _beadAStart++;
      _beadBStart++;
      if (_beadAStart == _pixels.numPixels()) {
        _beadAStart = 0;
      }
      if (_beadBStart == _pixels.numPixels()) {
        _beadBStart = 0;
      }
      //delay(5);
   }

   uint32_t createColor(uint8_t r, uint8_t g, uint8_t b) {
      return _pixels.Color(r, g, b);
   }

		// Fill the dots one after the other with a color
		void colorWipe(uint32_t c, uint8_t wait) {
			for(uint16_t i=0; i<_pixels.numPixels(); i++) {
				_pixels.setPixelColor(i, c);
				_pixels.show();
				delay(wait);
			}
		}

    int rainbowCounter = 0;
		void rainbow(uint8_t wait) {
			uint16_t i;
			
				for(i=0; i<_pixels.numPixels(); i++) {
					_pixels.setPixelColor(i, Wheel((i+rainbowCounter) & 255));
				}
				_pixels.show();
        rainbowCounter++;

        if (rainbowCounter == 256) {
          rainbowCounter = 0;
        }
				delay(wait);
		}
		
		// Slightly different, this makes the rainbow equally distributed throughout
		void rainbowCycle(uint8_t wait) {
			uint16_t i, j;
			
			for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
				for(i=0; i< _pixels.numPixels(); i++) {
					_pixels.setPixelColor(i, Wheel(((i * 256 / _pixels.numPixels()) + j) & 255));
				}
				_pixels.show();
				delay(wait);
			}
		}
		
		// Input a value 0 to 255 to get a color value.
		// The colours are a transition r - g - b - back to r.
		uint32_t Wheel(byte WheelPos) {
			if(WheelPos < 85) {
				return _pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
			} else if(WheelPos < 170) {
				WheelPos -= 85;
				return _pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
			} else {
				WheelPos -= 170;
				return _pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
			}
		}

		void all(uint32_t color) {
			for(int i=0;i<_numPixels;i++){
	 			_pixels.setPixelColor(i, color);
			}

			_pixels.show();
		}

   void one(int index, uint32_t color) {
    uint32_t black = _pixels.Color(0, 0, 0);
    for(int i=0;i<_numPixels;i++){
        _pixels.setPixelColor(i, black);
    }
    
    _pixels.setPixelColor(index, color);
    _pixels.show();
   }

		uint8_t byteAt(int bmpFile, uint32_t at) {
      switch(bmpFile) {
        case 0:
          return pgm_read_byte_near(pattern_0_psychedelic_sunset_grad + at);
        case 1:
          return pgm_read_byte_near(pattern_1_10x10_chaser_fire + at);
        case 2:
          return pgm_read_byte_near(pattern_2_interlock_line_rbw + at);
//        case 3:
//          return pgm_read_byte_near(pattern_3_circles_blue_yellow_green + at);
      }
		}

   uint32_t dwordAt(int bmpFile, uint32_t at) {
      switch(bmpFile) {
        case 0:
          return pgm_read_dword_near(palette_0_psychedelic_sunset_grad + at);
        case 1:
          return pgm_read_dword_near(palette_1_10x10_chaser_fire + at);
        case 2:
          return pgm_read_dword_near(palette_2_interlock_line_rbw + at);
//        case 3:
//          return pgm_read_dword_near(palette_3_circles_blue_yellow_green + at);
      }
   }

    uint32_t colorFromColorIndex(int bmpFile, uint8_t colorIndex) {
      uint32_t mask = 0xFF;
      
      uint32_t rgb = dwordAt(bmpFile, colorIndex);
      uint8_t r = (rgb & (mask << 16)) >> 16;
      uint8_t g = (rgb & (mask << 8)) >> 8;
      uint8_t b = rgb & mask;
      
      return _pixels.Color(r, g, b);
    }

		void pattern(int bmpFile) {
      int width = byteAt(bmpFile, 0);      
      int height = byteAt(bmpFile, 1);
      int bitsPerPixel = byteAt(bmpFile, 2);

      int imageCount = (_numPixels / width) + 1;
      
      for (int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
          for (int imageIteration=0; imageIteration<imageCount; imageIteration++) {
            int indexOffset = imageIteration * width;
            color_from_coordinates(bmpFile, bitsPerPixel, width, x, y, x + indexOffset);
          }
        }
        _pixels.show();
        if (PATTERN_DELAY > 0) {
          delay(PATTERN_DELAY);
        }
      }
    }

   void color_from_coordinates(int bmpFile, int bitsPerPixel, int width, int x, int y, int index) {
     int sizeOffset = 3;

      bool endOfHoop = index >= _numPixels;
      if (endOfHoop)
      {
        return;
      }

      int bitIndex = (x + width*y) * bitsPerPixel;
      int numberOfColorsPerByte = 8 / bitsPerPixel;
      int byteIndex = bitIndex / 8;
      int bitIndexWithinByte = bitIndex % numberOfColorsPerByte;

      uint8_t data = byteAt(bmpFile, sizeOffset + byteIndex);

      uint8_t smallMask = 0;
      for (uint8_t i=0; i<bitsPerPixel; i++)
      {
        smallMask = (smallMask << 1) | 1;
      }

      uint8_t unshiftedMask = smallMask << (8 - bitsPerPixel);
      uint8_t shiftedMask = unshiftedMask >> (bitIndexWithinByte * bitsPerPixel);
      uint8_t unshiftedResult = data & shiftedMask;
      uint8_t amountToShiftResult = 8 - (bitIndexWithinByte * bitsPerPixel) - bitsPerPixel;
      uint8_t shiftedResult = unshiftedResult >> amountToShiftResult;

      uint32_t color = colorFromColorIndex(bmpFile, shiftedResult);
      _pixels.setPixelColor(index, color);
    }

	private:
		Adafruit_NeoPixel _pixels;
		int _numPixels;
		int _brightness;
};

#endif  /* PIXELS_H */
