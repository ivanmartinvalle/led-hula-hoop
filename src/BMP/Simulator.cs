using System;
using System.Drawing;
using System.Linq;
using System.Threading;

using uint8_t = System.Int32;
using uint32_t = System.Int32;

namespace BMP
{
	internal class PatternSimulator
	{
		private static readonly int PATTERN_DELAY = 4;
		private static int[] Pixels = new int[100];
		private static int[] Pattern;
		private Pattern _pattern;

		public void Simulate(Pattern pattern)
		{
			_pattern = pattern;
			Pattern = pattern.CollapseIntoBytes().ToArray();
			printPattern();
		}

		private void printPattern() {
			int width = byteAt(0);			
			int height = byteAt(1);
			int bitsPerPixel = byteAt(2);

			int imageCount = (Pixels.Length / width) + 1;
			
			for (int y=0; y<height; y++) {
				for(int x=0; x<width; x++) {
					for (int imageIteration=0; imageIteration<imageCount; imageIteration++) {
						int indexOffset = imageIteration * width;
						color_from_coordinates(bitsPerPixel, width, x, y, x + indexOffset);
					}
				}
				show();
				delay(PATTERN_DELAY);
			}
		}

		private void color_from_coordinates(int bitsPerPixel, int width, int x, int y, int index) {
			int sizeOffset = 3;

			bool endOfHoop = index >= Pixels.Length;
			if (endOfHoop)
			{
				return;
			}

			int bitIndex = (x + width*y) * bitsPerPixel;
			int numberOfColorsPerByte = 8 / bitsPerPixel;
			int byteIndex = bitIndex / 8;
			int bitIndexWithinByte = bitIndex % numberOfColorsPerByte;

			uint8_t data = byteAt(sizeOffset + byteIndex);

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

			Pixels[index] = colorFromColorIndex(shiftedResult);
		}

		private uint32_t colorFromColorIndex(uint8_t colorIndex)
		{
			return colorIndex;
		}

		private int byteAt(int index)
		{
			return Pattern[index];
		}

		private void delay(int delay)
		{
			Thread.Sleep(delay);
		}

		private void show()
		{
			var colors = _pattern.CollapseIntoColorBytes().ToArray();
			foreach (var pixel in Pixels)
			{
				uint32_t mask = 0xFF;
				uint32_t rgb = Color.FromArgb(colors[pixel]).ToArgb();
				uint8_t r = (rgb & (mask << 16)) >> 16;
				uint8_t g = (rgb & (mask << 8)) >> 8;
				uint8_t b = rgb & mask;

				var realColor = Color.FromArgb(r, g, b);
				var consoleColor = FromColor(realColor);
				Console.ForegroundColor = consoleColor;
				Console.Write("x");
			}
			Console.WriteLine();
			Console.ResetColor();
		}

		// https://stackoverflow.com/a/29192463/4780595
		public static ConsoleColor FromColor(Color c) {
			int index = (c.R > 128 | c.G > 128 | c.B > 128) ? 8 : 0; // Bright bit
			index |= (c.R > 64) ? 4 : 0; // Red bit
			index |= (c.G > 64) ? 2 : 0; // Green bit
			index |= (c.B > 64) ? 1 : 0; // Blue bit
			return (ConsoleColor)index;
		}
	}
}