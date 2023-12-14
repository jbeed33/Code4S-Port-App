using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
	static class Helper
	{
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

		public static bool inputValidator(string name, string weight)
		{
			if(name == "NULL" || name == "" || name == "UNUSED")
			{
				return false;
			}
			double tmp;
			if (true == double.TryParse(weight, out tmp))
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

		public static void saveToLog(string filePath)
		{

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
	}
}
