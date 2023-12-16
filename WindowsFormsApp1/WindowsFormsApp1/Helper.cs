using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
	static class Helper
	{

		public static string getPathToLog()
		{
			string filePath = "log" + DateTime.Now.Year.ToString() + ".txt";
			return findFileInAppData(filePath);
		}

		public static string findFileInAppData(string fileName)
		{
			string folderPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "shippingAi");
			Directory.CreateDirectory(folderPath);
			return Path.Combine(folderPath, fileName);
		}

		public static void flipShip(List<List<Container>> ship)
		{
			for (int i = 0; i < ship.Count / 2; i++)
			{
				List<Container> row = ship[i];
				ship[i] = ship[ship.Count - 1 - i];
				ship[ship.Count - 1 - i] = row;
			}
		}

		public static void textBoxValidator(object sender, string regex, int MAXLENGTH)
		{
			TextBox obj = (TextBox)sender;
			if (false == obj.Modified)  //Only run if user was the last to modify object, avoid inf recursion
				return;
			string txt = obj.Text;
			Regex isAlpha = new Regex(regex);
			int selectionStart = obj.SelectionStart;
			if (isAlpha.IsMatch(txt))
			{
				if (MAXLENGTH == txt.Length)
				{
					txt = txt.Remove(selectionStart - 1) + txt.Substring(selectionStart);
					selectionStart--;
				}
			}
			else
			{
				if (0 < txt.Length)
				{
					txt = txt.Remove(selectionStart - 1) + txt.Substring(selectionStart);
					selectionStart--;
				}
				else
				{
					txt = "";
				}
			}
			if (txt.Length < selectionStart)
			{
				selectionStart = txt.Length;

			}
			obj.Text = txt;
			//Move the cursor to the end of the string
			obj.SelectionStart = selectionStart;
			obj.SelectionLength = 0;
		}

		public static void changeUser(string newUser)
		{
			if ("" != Program.user)
				LogManager.AddNoteToLogFile(Program.user + " signs out");
			LogManager.AddNoteToLogFile(newUser + " signs in");
			Program.user = newUser;
		}

		public static bool inputValidator(string name, string weight)
		{
			if(name == "NAN" || name == "" || name == "UNUSED")
			{
				return false;
			}
			if ("" == weight)
				return false;
			int tmp;
			if (true == int.TryParse(weight, out tmp))
			{
				if (tmp < 0)
					return false;
			}
			else
			{
				return false;
			}

			return true;
		}

		public static string getFilePath(string filter)
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "txt files (*.txt)|*.txt";
			if (ofd.ShowDialog() == DialogResult.OK)
			{
				return ofd.FileName;
			}
			else
				return "";
		}

		public static void saveVariablesToFile()
		{
			//Ship variable paths
			string shipPath = findFileInAppData("ship.shp");
			string shipStatePath = findFileInAppData("shipState.shp");
			string shipWeightPath = findFileInAppData("shipWeight.shp");
			string shipDataPath = findFileInAppData("shipData.xml");

			//Buffer variable paths
			string bufferStatePath = findFileInAppData("bufferState.shp");
			string bufferWeightPath = findFileInAppData("bufferWeight.shp");
			string bufferDataPath = findFileInAppData("BufferData.xml");

			//Other variable paths
			string pathPath = findFileInAppData("path.shp");
			string iteratorPath = findFileInAppData("iterator.shp");
		/*
			using (Stream stream = File.Open(shipPath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.ship);
			}
			using (Stream stream = File.Open(shipStatePath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.shipStates);
			}
			using (Stream stream = File.Open(shipWeightPath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.shipWeights);
			}
			using (Stream stream = File.Open(bufferStatePath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.bufferStates);
			}
			using (Stream stream = File.Open(bufferWeightPath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.bufferWeights);
			}
			using (Stream stream = File.Open(pathPath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, Program.path);
			}
			using (Stream stream = File.Open(iteratorPath, FileMode.Create))
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Serialize(stream, moves.iterator);
			}

			using (Stream stream = File.Open(shipDataPath, FileMode.Create))
			{
				moves.shipData.WriteXml(stream);
			}
			using (Stream stream = File.Open(bufferDataPath, FileMode.Create))
			{
				moves.bufferData.WriteXml(stream);
			}*/
		}

		public static List<List<int>> ReadFileInAppData(string filename)
        {
			string filePath = findFileInAppData(filename);
            List<List<int>> data = new List<List<int>>();

            try
            {
                foreach (string line in File.ReadAllLines(filePath))
                {
                    List<int> innerList = new List<int>();
                    string[] entries = line.Split(' ');

                    foreach (string entry in entries)
                    {
                        if (int.TryParse(entry, out int number))
                        {
                            innerList.Add(number);
                        }
                    }

                    if (innerList.Count > 0)
                    {
                        data.Add(innerList);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error reading file: {ex.Message}");
            }

            return data;
        }

		public static void setPath(List<List<int>> newPath)
		{
			Program.path = new List<List<List<int>>>();
			for(int i = 0; i < newPath.Count; i++)
			{
				List<List<int>> row = new List<List<int>>();
				List<int> start = new List<int>();
				List<int> end = new List<int>();
				start.Add(newPath[i][0]);
				start.Add(newPath[i][1]);
				start.Add(newPath[i][2]);
				end.Add(newPath[i][3]);
				end.Add(newPath[i][4]);
				end.Add(newPath[i][5]);
				row.Add(start);
				row.Add(end);
				row.Add(new List<int> {newPath[i][6]});
				Program.path.Add(row);
			}
		}


		public static void runAi()
		{
			string path = findFileInAppData("shippingAi.exe");
			string args = Program.manifestFile;
			if(0 < Program.removeList.Count)
			{
				args += " ";
				args += Program.removeList.Count.ToString();
				args += " ";
				args += string.Join(" ", Program.removeList);
			}
			Process process = new Process()
			{
				StartInfo = new ProcessStartInfo(path, args)
				{
					WindowStyle = ProcessWindowStyle.Hidden,
					WorkingDirectory = Path.GetDirectoryName(path)
				}
			};
			
			process.Start();
			process.WaitForExit();
			process.Close();
			setPath(ReadFileInAppData("path.txt"));
		}
	}
}
