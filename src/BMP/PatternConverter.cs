using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using Colourful;
using Colourful.Conversion;
using Colourful.Difference;

namespace BMP
{
	public class PatternConverter
	{
		public Pattern ConvertPathToPattern(string path, int colorEqualityDeltaE)
		{
			// https://msdn.microsoft.com/en-us/library/system.drawing.imaging.pixelformat(v=vs.110).aspx
			// PixelFormat does a lot of my math...hmm...
			var file = System.Drawing.Image.FromFile(path);
			var bitmap = new System.Drawing.Bitmap(file);

			if (bitmap.Width > 25 && bitmap.Height > 25)
			{
				bitmap = new Bitmap(bitmap, 25, 25);
			}

			return ConvertBitmapToPattern(bitmap, colorEqualityDeltaE);
		}

		private Pattern ConvertBitmapToPattern(Bitmap bitmap, int colorEqualityDeltaE)
		{
			var pixels = new List<Color>();

			for(var y=0; y<bitmap.Height; y++)
			{
				for(var x=0; x<bitmap.Width; x++)
				{
					var pixelColor = bitmap.GetPixel(x, y);
					var collapsedColor = CollapseColor(pixelColor, colorEqualityDeltaE);

					// pixels.Add(pixelColor);
					pixels.Add(collapsedColor);
				}
			}
			
			return new Pattern(bitmap.Width, bitmap.Height, pixels);
		}

		private List<Color> _collapsedColors = new List<Color>();
		private Color CollapseColor(Color color, int colorEqualityDeltaE)
		{
			var differ = new CIEDE2000ColorDifference();
			var similarColors = _collapsedColors.Where(x => differ.ComputeDifference(ToLabColor(x), ToLabColor(color)) < colorEqualityDeltaE);
			if (similarColors.Any())
			{
				return similarColors.First();
			}

			_collapsedColors.Add(color);
			return color;
		}

		private static LabColor ToLabColor(Color color)
		{
			var converter = new ColourfulConverter { TargetLabWhitePoint = Illuminants.D65 };
			return converter.ToLab(new RGBColor(color.R / 255.0, color.G / 255.0, color.B / 255.0));
		}
	}
}