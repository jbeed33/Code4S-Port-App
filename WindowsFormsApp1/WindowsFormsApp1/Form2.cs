using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
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
			Program.ship = ManifestManager.ReadManifest(Program.manifestFile);
			Program.shipNames = new List<List<string>>();
			Program.shipWeights = new List<List<int>>();
			Program.shipStates = new List<List<int>>();
			Program.bufferWeights = new List<List<int>>();
			Program.bufferStates = new List<List<int>>();

			List<int> filler = new List<int>();
			for (int col = 0; col < Program.BUFFERWIDTH; col++)
			{
				filler.Add(0);
			}
			for (int row = 0; row < Program.BUFFERHEIGHT; row++)
			{
				Program.bufferWeights.Add(filler);
				Program.bufferStates.Add(filler);
			}

			List<string> firstNames = new List<string>();
			List<int> firstStates = new List<int>();
			for(int i = 0; i < Program.ship[0].Count(); i++)
			{
				firstNames.Add("");
				firstStates.Add(0);
			}
			Program.shipStates.Add(firstStates);
			Program.shipNames.Add(firstNames);
			for(int row = 0; row < Program.ship.Count(); row++)
			{
				List<string> rowNames = new List<string>();
				List<int> rowStates = new List<int>();
				List<int> rowWeights = new List<int>();

				for(int col = 0; col < Program.ship[0].Count(); col++)
				{
					string name = Program.ship[row][col].Name;
					if (name == "NULL" || name == "UNUSED")
						name = "";
					rowNames.Add(name);
					rowStates.Add(Program.ship[row][col].Status);
					rowWeights.Add(Program.ship[row][col].Weight);
				}
				Program.shipNames.Add(rowNames);
				Program.shipStates.Add(rowStates);
				Program.shipWeights.Add(rowWeights);
			}
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
			if ("" == username.Text)
				return;
			Helper.changeUser(username.Text);
			username.Clear();
		}

		private void exportlog_Click(object sender, EventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			sfd.Filter = "txt files (*.txt)|*.txt";
			sfd.Title = "Choose a location to copy log.txt to";
			sfd.DefaultExt = "txt";
			sfd.FileName = "log" + DateTime.Now.Year.ToString();
			sfd.ShowDialog();
			if("" != sfd.FileName)
			{
				File.Copy(Helper.getPathToLog(), sfd.FileName);
			}
		}

		private void mainMenu_Load(object sender, EventArgs e)
		{

		}
	}
}
