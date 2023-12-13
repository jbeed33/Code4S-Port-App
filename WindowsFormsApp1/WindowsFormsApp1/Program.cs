using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    static class Program
    {
		public static int numToLoad = 0;
		public static bool displayingSteps = false;
		public static string manifestFile = "";
		public static List<Form> windows = new List<Form>();
		public static string user = "";
		public const int MAXUSERLENGTH = 256;
		public const int MAXSHIPLENGTH = 256;
		public const int MAXWEIGHTPRECISION = 3;

		public static List<List<string>> shipNames = new List<List<string>> {
			new List<string> { "",		"",		"",			"",	"", "",			"",	"",			"",			"",	"",			"" },
			new List<string> { "",		"",		"",			"",	"", "",			"",	"",			"",			"",	"",			"" },
			new List<string> { "",		"",		"",			"",	"", "",			"",	"",			"",			"",	"",			"" },
			new List<string> { "",		"",		"",			"",	"", "",			"",	"",			"",			"",	"",			"" },
			new List<string> { "Void",	"",		"",			"",	"", "",			"", "",			"",			"",	"",         "Void" },
			new List<string> { "Void",	"",		"",			"",	"", "",			"",	"",			"",			"",	"",         "Void" },
			new List<string> { "Void",	"",		"",			"", "", "",			"", "",			"",			"", "Cranes",   "Void" },
			new List<string> { "Void",	"Void", "Toys",		"", "", "",			"", "",			"Spiders",	"", "Void",		"Void" },
			new List<string> { "Void",	"Void", "Storage",	"", "", "Boats",	"", "Traps",	"Cavemen",	"", "Void",		"Void" }
		};
		
		public static List<List<int>> shipStates = new List<List<int>>
		{
			new List<int> {  0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
			new List<int> {  0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
			new List<int> {  0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
			new List<int> {  0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
			new List<int> { -1, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0, -1 },
			new List<int> { -1, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0, -1 },
			new List<int> { -1, 0,	0,	0,	0,	0,	0,	0,	0,	0,	2, -1 },
			new List<int> { -1,-1,	2,	0,	0,	0,	0,	0,	2,	0, -1, -1 },
			new List<int> { -1,-1,	2,	0,	0,	1,	0,	2,	2,	0, -1, -1 },
		};
		public static List<List<int>> bufferStates = new List<List<int>>();

		/*	startRow, startCol, startZone
		* 	endRow, endCol, endZone
		*	justCrane
		*/
		
		public static List<List<List<int>>> path = new List<List<List<int>>>
		{
			new List<List<int>> { 
				new List<int> { 6, 10, 0 },
				new List<int> { 0, 0, 1 }
			},
			new List<List<int>> {
				new List<int> { 0, 0, 1 },
				new List<int> { 3, 0, 0 }
			},
			new List<List<int>> {
				new List<int> { 7, 2, 0 },
				new List<int> { 4, 20, 2 }
			},
			new List<List<int>> {
				new List<int> { 8, 2, 0 },
				new List<int> { 3, 11, 0 }
			}
		};

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
			windows.Add(new mainMenu());
            Application.Run(windows[0]);
        }
    }
}
