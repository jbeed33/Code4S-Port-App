using System;
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

		//Constants
		const int BUFFERWIDTH = 24;
		const int BUFFERHEIGHT = 5;

		DataTable shipData;
		DataTable bufferData;
		int iterator = 0;

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
			for(int i = 0; i < BUFFERHEIGHT; i++)
			{
				for(int j = 0; j < BUFFERWIDTH; j++)
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
            shipData = new DataTable();
			DataColumn col;
			for(int i = 0; i < 12; i++)
			{
				col = new DataColumn();
				col.DataType = System.Type.GetType("System.String"); ;
				col.ColumnName = i.ToString();
				col.Caption = i.ToString();
				col.Unique = false;
				shipData.Columns.Add(col);
			}

			for(int i = 0; i < 9; i++)
			{
				DataRow row = shipData.NewRow();
				shipData.Rows.Add(row);
			}
			for(int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					shipData.Rows[i][j] = Program.shipNames[i][j];
				}
			}
			ship.DataSource = shipData;
        }

		void createBuffer()
		{
			bufferData = new DataTable();
			DataColumn col;
			for (int i = 0; i < BUFFERWIDTH; i++)
			{
				col = new DataColumn();
				col.DataType = System.Type.GetType("System.String"); ;
				col.ColumnName = i.ToString();
				col.Caption = i.ToString();
				col.Unique = false;
				bufferData.Columns.Add(col);
			}

			for (int i = 0; i < BUFFERHEIGHT; i++)
			{
				DataRow row = bufferData.NewRow();
				bufferData.Rows.Add(row);
			}

			//Setup the buffer states
			for(int i = 0; i < BUFFERHEIGHT; i++)
			{
				List<int> row = new List<int>();
				for(int j = 0; j < BUFFERWIDTH; j++)
				{
					row.Add(0);
				}
				Program.bufferStates.Add(row);
			}
			buffer.DataSource = bufferData;
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
			int state = 2;
			if (0 == startZone)
			{
				name = shipData.Rows[startRow][startCol].ToString();
				shipData.Rows[startRow][startCol] = "";
				state = Program.shipStates[startRow][startCol];
				Program.shipStates[startRow][startCol] = 0;
			}
			else if (1 == startZone)
			{
				name = newName.Text;
				truck.BackColor = start;
			}
			else
			{
				state = Program.bufferStates[startRow][startCol];
				Program.bufferStates[startRow][startCol] = 0;
				name = bufferData.Rows[startRow][startCol].ToString();
				bufferData.Rows[startRow][startCol] = "";
			}

			if (0 == endZone)
			{
				shipData.Rows[endRow][endCol] = name;
				Program.shipStates[endRow][endCol] = state;

			}
			else if (2 == endZone)
			{
				bufferData.Rows[endRow][endCol] = name;
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
            if (ticked == backColor)
                backColor = unticked;
            else
                backColor = ticked;
			ship.Rows[row].Cells[col].Style.BackColor = backColor;
		}

		private void ship_SelectionChanged(object sender, EventArgs e)
		{
			ship.ClearSelection();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			int max = ship.Columns.Count;
			for (int i = 0; i < max; i++)
			{
				ship.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
			}
			max = ship.Rows.Count;
			for (int i = 0; i < max; i++)
			{
				ship.Rows[i].HeaderCell.Value = (max - i - 1).ToString();
			}
			max = BUFFERWIDTH;
			for (int i = 0; i < max; i++)
			{
				buffer.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
			}
			max = BUFFERHEIGHT;
			for (int i = 0; i < max; i++)
			{
				buffer.Rows[i].HeaderCell.Value = (max - i - 1).ToString();
			}
			colorStates();
			displayMove(Program.path[iterator]);
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
			iterator = 0;
		}

		void finishedSteps()
		{
			reminder rem = new reminder();
			rem.ShowDialog();
		}

		void loadContainer(string name, double weight)
		{
			int endRow = Program.path[iterator][1][0];
			int endCol = Program.path[iterator][1][1];

			shipData.Rows[endRow][endCol] = name;
			ship.Refresh();
		}

		void invalidContainerInput()
		{

		}

		private void nextStep_Click(object sender, EventArgs e)
		{
			moveContainer(Program.path[iterator]);
			if (Program.path.Count <= iterator + 1)
			{
				finishedSteps();
				return;
			}
			if (1 == Program.path[iterator][0][2])	//Starting on the truck means loading a container
			{
				if(true == Helper.inputValidator(newName.Text, newWeight.Text))
				{
					loadContainer(newName.Text, double.Parse(newWeight.Text));
				}
				else
				{
					invalidContainerInput();
					return;
				}
			}
			iterator++;
			colorStates();
			displayMove(Program.path[iterator]);

		}

		private void login_Click(object sender, EventArgs e)
		{
			Program.user = username.Text;
			username.Clear();
		}

		private void textbox_TextChanged(object sender, EventArgs e)
		{
			Helper.textBoxValidator(sender, @"^[a-zA-Z\s]+$", Program.MAXUSERLENGTH);
		}

		private void newWeight_TextChanged(object sender, EventArgs e)
		{
			Helper.textBoxValidator(sender, @"^\d{1,5}(\.\d*)?$", 7 + Program.MAXWEIGHTPRECISION);
		}

		private void textBox_Focused(object sender, EventArgs e)
		{
			TextBox obj = (TextBox)sender;
			obj.SelectionStart = 0;
			obj.SelectionLength = obj.Text.Length;
		}
	}
}
