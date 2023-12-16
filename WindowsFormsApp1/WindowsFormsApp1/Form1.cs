﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApp1
{
    public partial class moves : Form
    {
		//Color Choices
		Color ticked = Color.OrangeRed;
		Color unticked = Color.DeepSkyBlue;
		Color empty = Color.White;
		Color wall = Color.Black;
		Color start = Color.LimeGreen;
		Color end = Color.MediumPurple;


		public moves()
        {
            InitializeComponent();
			createShip();
			createBuffer();
			buffer.BackgroundColor = unticked;
			ship.BackgroundColor = unticked;
        }

		void colorStates()
		{
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 12; j++)
				{
					int state = Program.shipStates[i][j];
					Color colorChoice;
					if(-1 == state)
					{
						colorChoice = wall;
					}
					else if(0 == state)
					{
						colorChoice = empty;
					}
					else if (1 == state)
					{
						colorChoice = ticked;
					}
					else
					{
						colorChoice = unticked;
					}
					ship.Rows[i].Cells[j].Style.BackColor = colorChoice;
				}
			}
			truck.BackColor = empty;
			for(int i = 0; i < Program.BUFFERHEIGHT; i++)
			{
				for(int j = 0; j < Program.BUFFERWIDTH; j++)
				{
					int state = Program.bufferStates[i][j];
					Color colorChoice;
					if (-1 == state)
					{
						colorChoice = wall;
					}
					else if (0 == state)
					{
						colorChoice = empty;
					}
					else if (1 == state)
					{
						colorChoice = ticked;
					}
					else
					{
						colorChoice = unticked;
					}
					buffer.Rows[i].Cells[j].Style.BackColor = colorChoice;
				}
			}
		}

        void createShip()
        {
            Program.shipData = new DataTable();
			DataColumn col;
			for(int i = 1; i <= 12; i++)
			{
				col = new DataColumn();
				col.DataType = System.Type.GetType("System.String"); ;
				col.ColumnName = i.ToString();
				if (i < 10)
				{
					col.ColumnName = "0" + col.ColumnName;
				}
				Program.shipData.Columns.Add(col);
			}

			for(int i = 0; i < 9; i++)
			{
				DataRow row = Program.shipData.NewRow();
				Program.shipData.Rows.Add(row);
			}
			for(int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					Program.shipData.Rows[i][j] = Program.shipNames[i][j];
				}
			}
			ship.RowHeadersWidth = 52;
			ship.DataSource = Program.shipData;
        }

		void createBuffer()
		{
			Program.bufferData = new DataTable();
			DataColumn col;
			for (int i = 1; i <= Program.BUFFERWIDTH; i++)
			{
				col = new DataColumn();
				col.DataType = System.Type.GetType("System.String"); ;
				col.ColumnName = i.ToString();
				if (i < 10)
				{
					col.ColumnName = "0" + col.ColumnName;
				}
				Program.bufferData.Columns.Add(col);
			}

			for (int i = 0; i < Program.BUFFERHEIGHT; i++)
			{
				DataRow row = Program.bufferData.NewRow();
				Program.bufferData.Rows.Add(row);
			}

			//Setup the buffer states
			for(int i = 0; i < Program.BUFFERHEIGHT; i++)
			{
				List<int> row = new List<int>();
				for(int j = 0; j < Program.BUFFERWIDTH; j++)
				{
					row.Add(0);
				}
				Program.bufferStates.Add(row);
			}
			buffer.RowHeadersWidth = 48;
			buffer.DataSource = Program.bufferData;
		}

		void displayMove(List<List<int>> move)
		{
			int startRow = move[0][0];
			int startCol = move[0][1];
			int startZone = move[0][2];
			int endRow = move[1][0];
			int endCol = move[1][1];
			int endZone = move[1][2];

			if (0 == startZone)
				ship.Rows[startRow].Cells[startCol].Style.BackColor = start;
			else if (1 == startZone)
				truck.BackColor = start;
			else
				buffer.Rows[startRow].Cells[startCol].Style.BackColor = start;

			if (0 == endZone)
				ship.Rows[endRow].Cells[endCol].Style.BackColor = end;
			else if (1 == endZone)
				truck.BackColor = end;
			else
				buffer.Rows[endRow].Cells[endCol].Style.BackColor = end;

		}

		void moveContainer(List<List<int>> move)
		{
			int startRow = move[0][0];
			int startCol = move[0][1];
			int startZone = move[0][2];
			int endRow = move[1][0];
			int endCol = move[1][1];
			int endZone = move[1][2];

			string name;
			int weight;
			int state;
			if (0 == startZone)	//Ship
			{
				//Get data from starting position
				name = Program.shipData.Rows[startRow][startCol].ToString();
				state = Program.shipStates[startRow][startCol];
				weight = Program.shipWeights[startRow][startCol];
				
				//Update local: make starting position empty
				Program.shipData.Rows[startRow][startCol] = "";
				Program.shipStates[startRow][startCol] = 0;
				Program.shipWeights[startRow][startCol] = 0;
				
				//Update Containers: make starting position empty
				Program.ship[startRow][startCol].Name = "UNUSED";
				Program.ship[startRow][startCol].Weight = 0;
				Program.ship[startRow][startCol].Status = 0;
			}
			else if (1 == startZone)	//Truck
			{
				//Get data from starting position
				name = newName.Text;
				weight = int.Parse(newWeight.Text);
				state = 2;

				//update truck color and inputs
				truck.BackColor = start;
				newName.Clear();
				newWeight.Clear();
			}
			else	//Buffer
			{
				//Get data from starting position
				name = Program.bufferData.Rows[startRow][startCol].ToString();
				weight = Program.bufferWeights[startRow][startCol];
				state = Program.bufferStates[startRow][startCol];

				//Update local: make starting position empty
				Program.bufferData.Rows[startRow][startCol] = "";
				Program.bufferStates[startRow][startCol] = 0;
				name = Program.bufferData.Rows[startRow][startCol].ToString();
			}

			if (0 == endZone)	//Ship
			{
				//Assign data to position
				Program.shipData.Rows[endRow][endCol] = name;
				Program.shipWeights[endRow][endCol] = weight;
				Program.shipStates[endRow][endCol] = state;

				//Update Containers: Assign data to container at position
				Program.ship[endRow][endCol].Name = name;
				Program.ship[endRow][endCol].Weight = weight;
				Program.ship[endRow][endCol].Status = state;

			}
			else if (2 == endZone)	//Buffer
			{
				//Assign data to position
				Program.bufferData.Rows[endRow][endCol] = name;
				Program.bufferWeights[endRow][endCol] = weight;
				Program.bufferStates[endRow][endCol] = state;
			}
			ship.Refresh();
			buffer.Refresh();
		}

        private void genericButton(object sender, DataGridViewCellEventArgs e)
        {
			if (true == Program.displayingSteps)
				return;
			int row = e.RowIndex;
			int col = e.ColumnIndex;
			if (row < 0)
				return;
			if (col < 0)
				return;
			Color backColor = ship.Rows[row].Cells[col].Style.BackColor;
			if (empty == backColor || wall == backColor)
				return;
			string name = ship.Rows[row].Cells[col].Value.ToString();
			if (ticked == backColor)
			{
				backColor = unticked;
				LoadedContainerManager.AddContainerNameToRemoveList(name);
			}
			else
			{
				backColor = ticked;
				LoadedContainerManager.RemoveContainerNameFromRemoveList(name);
			}
			ship.Rows[row].Cells[col].Style.BackColor = backColor;
		}

		private void ship_SelectionChanged(object sender, EventArgs e)
		{
			ship.ClearSelection();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			if(true == Program.displayingSteps)	//Running balance, don't need to wait for user input
			{
				Helper.runAi();
			}
			int max = ship.Columns.Count;
			for (int i = 0; i < max; i++)
			{
				ship.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
			}
			max = ship.Rows.Count;
			for (int i = 0; i < max; i++)
			{
				string header = (max - i).ToString();
				if (max - i < 10)
					header = "0" + header;
				ship.Rows[i].HeaderCell.Value = header;
			}
			max = Program.BUFFERWIDTH;
			for (int i = 0; i < max; i++)
			{
				buffer.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
			}
			max = Program.BUFFERHEIGHT;
			for (int i = 0; i < max; i++)
			{
				string header = (max - i).ToString();
				if (max - i < 10)
					header = "0" + header;
				buffer.Rows[i].HeaderCell.Value = header;
			}
			colorStates();
			displayMove(Program.path[Program.iterator]);
		}

		private void buffer_SelectionChanged(object sender, EventArgs e)
		{
			buffer.ClearSelection();
		}

		private void ship_CellMouseEnter(object sender, DataGridViewCellEventArgs e)
		{
			int row = e.RowIndex;
			int col = e.ColumnIndex;
			if (row < 0 || col < 0)
				return;
			String tmp = ship.Rows[row].Cells[col].Value.ToString();
			nameLabel.Text = tmp;
		}

		private void ship_CellMouseLeave(object sender, DataGridViewCellEventArgs e)
		{
			int row = e.RowIndex;
			int col = e.ColumnIndex;
			if (row < 0 || col < 0)
				return;
			nameLabel.Text = "";
		}

		private void moves_FormClosed(object sender, FormClosedEventArgs e)
		{
			Program.windows.Remove(this);
			Program.windows[0].Show();
			Program.iterator = 0;
		}

		void finishedSteps()
		{
			ManifestManager.UpdateManifest(Program.ship, Program.manifestFile);
			reminder rem = new reminder();
			rem.ShowDialog();
		}

		void loadContainer(string name, int weight)
		{
			int endRow = Program.path[Program.iterator][1][0];
			int endCol = Program.path[Program.iterator][1][1];

			Program.shipData.Rows[endRow][endCol] = name;
			Container cont = new Container();
			cont.Name = name;
			cont.Weight = weight;
			cont.Status = 2;
			Program.ship[endRow][endCol] = cont;
			ship.Refresh();
		}

		void invalidContainerInput()
		{

		}

		private void nextStep_Click(object sender, EventArgs e)
		{
			if (false == Program.displayingSteps)	//Load/unload, still need to get the user input
			{
				Helper.runAi();
				Program.displayingSteps = true;
				return;
			}
			if (Program.path.Count <= Program.iterator + 1)
			{
				finishedSteps();
				return;
			}
			if (1 == Program.path[Program.iterator][0][2])	//Starting on the truck means loading a container
			{
				if(true == Helper.inputValidator(newName.Text, newWeight.Text))
				{
					loadContainer(newName.Text, int.Parse(newWeight.Text));
				}
				else
				{
					invalidContainerInput();
					return;
				}
			}
			moveContainer(Program.path[Program.iterator]);
			Program.iterator++;
			colorStates();
			displayMove(Program.path[Program.iterator]);
			Helper.saveVariablesToFile();
		}

		private void login_Click(object sender, EventArgs e)
		{
			Helper.changeUser(username.Text);
			username.Clear();
		}

		private void textbox_TextChanged(object sender, EventArgs e)
		{
			Helper.textBoxValidator(sender, @"^[a-zA-Z\s]+$", Program.MAXUSERLENGTH);
		}

		private void newWeight_TextChanged(object sender, EventArgs e)
		{
			Helper.textBoxValidator(sender, @"^\d{1,5}$", 1000);	//The regex also manages the length
		}

		private void textBox_Focused(object sender, EventArgs e)
		{
			TextBox obj = (TextBox)sender;
			obj.SelectionStart = 0;
			obj.SelectionLength = obj.Text.Length;
		}
	}
}
