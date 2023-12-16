﻿using System;
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
			return findFileInAppdatad(filePath);
		}

		public static string findFileInAppdatad(string fileName)
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
			if(name == "NULL" || name == "" || name == "UNUSED")
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
			try
			{
				//Ship variable paths
				//string shipPath = findFileInAppdatad("ship.shp");
				string shipStatePath = findFileInAppdatad("shipState.shp");
				string shipWeightPath = findFileInAppdatad("shipWeight.shp");
				string shipDataPath = findFileInAppdatad("shipData.xml");
		{
			//Ship variable paths
			string shipPath = findFileInAppdatad("ship.shp");
			string shipStatePath = findFileInAppdatad("shipState.shp");
			string shipWeightPath = findFileInAppdatad("shipWeight.shp");
			string shipDataPath = findFileInAppdatad("shipData.xml");

				//Buffer variable paths
				string bufferStatePath = findFileInAppdatad("bufferState.shp");
				string bufferWeightPath = findFileInAppdatad("bufferWeight.shp");
				string bufferDataPath = findFileInAppdatad("bufferData.xml");

				//Other variable paths
				string pathPath = findFileInAppdatad("path.shp");
				string iteratorPath = findFileInAppdatad("iterator.shp");

				//Save ship object
				//saveObjectToFile(shipPath, Program.ship);

				// Save shipStates object
				saveObjectToFile(shipStatePath, Program.shipStates);

				// Save shipWeights object
				saveObjectToFile(shipWeightPath, Program.shipWeights);

				// Save bufferStates object
				saveObjectToFile(bufferStatePath, Program.bufferStates);

				// Save bufferWeights object
				saveObjectToFile(bufferWeightPath, Program.bufferWeights);

				// Save path object
				saveObjectToFile(pathPath, Program.path);

				// Save iterator object
				saveObjectToFile(iteratorPath, moves.iterator);

				moves.shipData.TableName = "ShipData";
				using (Stream stream = File.Open(shipDataPath, FileMode.Create))
				{
					moves.shipData.WriteXml(stream);
				}
				moves.bufferData.TableName = "BufferData";
				using (Stream stream = File.Open(bufferDataPath, FileMode.Create))
				{
					moves.bufferData.WriteXml(stream);
				}
			}
			catch (Exception ex)
			{
				// Handle the exception (e.g., log, report, or retry)
				Console.WriteLine($"Error during save operation: {ex.Message}");
			}
		}

		public static void saveObjectToFile<T>(string filePath, T obj)
		{
			string tempFilePath = filePath + ".temp";

			try
			{
				using (Stream stream = File.Open(tempFilePath,FileMode.Create))
				{
					BinaryFormatter formatter = new BinaryFormatter();
					formatter.Serialize(stream, obj);
				}

				File.Delete(filePath);
				File.Move(tempFilePath, filePath);
			}
			catch (Exception)
			{
				Console.WriteLine($"Error saving {filePath}");
			}
		}

		public static void loadVariablesFromFile()
		{
			try
			{
				string shipStatePath = findFileInAppdatad("shipState.shp");
				string shipWeightPath = findFileInAppdatad("shipWeight.shp");
				string shipDataPath = findFileInAppdatad("shipData.xml");

				//Buffer variable paths
				string bufferStatePath = findFileInAppdatad("bufferState.shp");
				string bufferWeightPath = findFileInAppdatad("bufferWeight.shp");
				string bufferDataPath = findFileInAppdatad("bufferData.xml");

				//Other variable paths
				string pathPath = findFileInAppdatad("path.shp");
				string iteratorPath = findFileInAppdatad("iterator.shp");


				// Ship variable paths
				loadObjectFromFile(shipStatePath, out Program.shipStates);
				loadObjectFromFile(shipWeightPath, out Program.shipWeights);

				// Buffer variable paths
				loadObjectFromFile(bufferStatePath, out Program.bufferStates);
				loadObjectFromFile(bufferWeightPath, out Program.bufferWeights);

				// Other variable paths
				loadObjectFromFile(pathPath, out Program.path);
				loadObjectFromFile(iteratorPath, out moves.iterator);

				// Ship data
				using (Stream stream = File.Open(findFileInAppdatad("shipData.xml"), FileMode.Open))
				{
					moves.shipData.ReadXml(stream);
				}

				// Buffer data
				using (Stream stream = File.Open(findFileInAppdatad("bufferData.xml"), FileMode.Open))
				{
					moves.bufferData.ReadXml(stream);
				}
			}
			catch (Exception ex)
			{
				// Handle the exception (e.g., log, report, or retry)
				Console.WriteLine($"Error during load operation: {ex.Message}");
			}
		}


		public static void loadObjectFromFile<T>(string filePath, out T obj)
		{
			obj = default(T); // Initialize obj with default value for type T

			try
			{
				using (Stream stream = File.Open(filePath, FileMode.Open))
				{
					BinaryFormatter formatter = new BinaryFormatter();
					obj = (T)formatter.Deserialize(stream);
				}
			}
			catch (Exception ex)
			{
				Console.WriteLine($"Error loading {filePath}: {ex.Message}");
			}
			using (Stream stream = File.Open(bufferDataPath, FileMode.Create))
			{
				moves.bufferData.WriteXml(stream);
			}*/
		}

		public static void runAi()
		{/*
			string path = "D:\\phoen\\Documents\\ship_cases\\a.exe";
			Process process = new Process()
			{
				StartInfo = new ProcessStartInfo(path, Program.manifestFile)
				{
					WindowStyle = ProcessWindowStyle.Normal,
					WorkingDirectory = Path.GetDirectoryName(path)
				}
			};
			
			process.Start();
			process.WaitForExit();
			process.Close();
			*/
		}
	}
}
