using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
	public partial class mainMenu : Form
	{
		public mainMenu()
		{
			InitializeComponent();
		}

		private void buttonClicked()
		{
			string path = Helper.getFilePath("txt files (*.txt)|*.txt");
			if ("" == path)
				return;
			Program.manifestFile = path;
			moves newWindow = new moves();
			newWindow.Show();
			Program.windows.Add(newWindow);
			this.Hide();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			Program.displayingSteps = true;
			buttonClicked();
		}

		private void button2_Click(object sender, EventArgs e)
		{
			Program.displayingSteps = false;
			buttonClicked();
		}

		private void username_TextChanged(object sender, EventArgs e)
		{
			Helper.textBoxValidator(sender, @"^[a-zA-Z\s]+$", Program.MAXUSERLENGTH);
		}

		private void login_Click(object sender, EventArgs e)
		{
			Program.user = username.Text;
			username.Clear();
		}

		private void exportlog_Click(object sender, EventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			sfd.Filter = "txt files (*.txt)|*.txt";
			sfd.Title = "Choose a location to copy log.txt to";
			sfd.ShowDialog();
			if("" != sfd.FileName)
			{
				Helper.saveToLog(sfd.FileName);
			}
		}
	}
}
