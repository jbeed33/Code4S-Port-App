using System;
using System.Collections.Generic;
using System.Data;
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

		public const int BUFFERHEIGHT = 5;
		public const int BUFFERWIDTH = 24;

		public static List<List<Container>> ship;
		public static List<List<string>> shipNames = new List<List<string>> ();
		public static List<string> removeList = new List<string>();

		public static List<List<int>> shipWeights = new List<List<int>>();
		public static List<List<int>> shipStates = new List<List<int>>();
		public static List<List<int>> bufferWeights = new List<List<int>>();
		public static List<List<int>> bufferStates = new List<List<int>>();

		public static DataTable shipData;
		public static DataTable bufferData;
		public static int iterator = 0;

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
