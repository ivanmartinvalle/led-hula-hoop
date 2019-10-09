using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace BMP
{
	public class Pattern
	{
		public Pattern(int width, int height, IEnumerable<Color> pixels)
		{
			Width = width;
			Height = height;
			Pixels = pixels;
		}

		public int Width { get; }
		public int Height { get; }
		public IEnumerable<Color> Pixels { get; }

		private IEnumerable<Color> UniqueColors()
		{
			return Pixels.GroupBy(x => x).Select(x => x.Key);
		}

		private IEnumerable<int> PixelsAsColorIndex()
		{
			var uniqueColors = UniqueColors().ToList();

			return Pixels.Select(x => uniqueColors.IndexOf(x));
		}

		public IEnumerable<int> CollapseIntoBytes()
		{
			var pixelsAsColorIndex = PixelsAsColorIndex();
			var colors = UniqueColors();
			var numberOfColors = colors.Count();
			var bitsPerPixel = (int) Math.Ceiling(Math.Log(numberOfColors, 2));

			if (bitsPerPixel > 8)
			{
				throw new Exception("Too many colors: " + numberOfColors);
			}
			var pixelsPerByte = 8 / bitsPerPixel;

			// https://stackoverflow.com/a/5215512/4780595
			var collapsedBitsAsBytes = pixelsAsColorIndex.Select((p, index) => new {p, index})
				.GroupBy(a => a.index/pixelsPerByte)
				.Select((grp => grp.Select(g => g.p).ToList()))
				.Select(x => ToIntFromGroupedColorIndexes(x, bitsPerPixel))
				.ToList();
			
			return new[] {Width, Height, bitsPerPixel}.Concat(collapsedBitsAsBytes);
		}

		public IEnumerable<int> CollapseIntoColorBytes()
		{
			var colors = UniqueColors();
			return colors.Select(x => x.ToArgb());
		}

		private static int ToIntFromGroupedColorIndexes(List<int> bits, int bitsPerPixel)
		{
			Func<int, string> binaryString = x => Convert.ToString(x, 2);
			var wholeString = bits.Select(binaryString).Select(x => x.PadLeft(bitsPerPixel, '0')).Aggregate((x, y) => x + y);
			return Convert.ToInt32(wholeString, 2);
		}

		public string Code()
		{
			string debugData= $"Color count: {UniqueColors().Count()}";
			const string patternHead = "const uint8_t pattern[] PROGMEM = {";
			const string patternTail  = "};";
			var patternBytes = string.Join(", ", CollapseIntoBytes());
			var pattern = $"{patternHead}{patternBytes}{patternTail}";

			const string paletteHead = "const uint32_t palette[] PROGMEM = {";
			const string paletteTail  = "};";
			var colors = CollapseIntoColorBytes();
			var paletteBytes = string.Join(", ", colors);
			var palette = $"{paletteHead}{paletteBytes}{paletteTail}";

			return string.Join(Environment.NewLine, debugData, pattern, palette);
		}
	}
}