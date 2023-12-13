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
			if (isAlpha.IsMatch(txt))
			{
				if (MAXLENGTH == txt.Length)
				{
					txt = txt.Remove(txt.Length - 1);
				}
			}
			else
			{
				if (0 < txt.Length)
				{
					txt = txt.Remove(txt.Length - 1);
				}
				else
				{
					txt = "";
				}
			}
			obj.Text = txt;
			//Move the cursor to the end of the string
			obj.SelectionStart = txt.Length;
			obj.SelectionLength = 0;
		}
	}
}
