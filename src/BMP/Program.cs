using System;

namespace BMP
{
    class Program
    {
        static void Main(string[] args)
        {
            var patternPath = $"../../patterns/{args[0]}.bmp";
            int colorEqualityDeltaE = args.Length == 2 ? int.Parse(args[1]) : 3;

            var patternConverter = new PatternConverter();
            var pattern = patternConverter.ConvertPathToPattern(patternPath, colorEqualityDeltaE);

            var patternSimulator = new PatternSimulator();
            patternSimulator.Simulate(pattern);
            Console.WriteLine(pattern.Code());
        }
    }
}
