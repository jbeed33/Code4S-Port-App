﻿
namespace WindowsFormsApp1
{
    partial class moves
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
			System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
			this.ship = new System.Windows.Forms.DataGridView();
			this.buffer = new System.Windows.Forms.DataGridView();
			this.truck = new System.Windows.Forms.Label();
			this.login = new System.Windows.Forms.Button();
			this.progress = new System.Windows.Forms.Label();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.label2 = new System.Windows.Forms.Label();
			this.newWeight = new System.Windows.Forms.MaskedTextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.newName = new System.Windows.Forms.MaskedTextBox();
			this.nextStep = new System.Windows.Forms.Button();
			this.timeRemaining = new System.Windows.Forms.Label();
			this.notes = new System.Windows.Forms.GroupBox();
			this.noteButton = new System.Windows.Forms.Button();
			this.label5 = new System.Windows.Forms.Label();
			this.maskedTextBox5 = new System.Windows.Forms.MaskedTextBox();
			this.nameLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.ship)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.buffer)).BeginInit();
			this.groupBox1.SuspendLayout();
			this.notes.SuspendLayout();
			this.SuspendLayout();
			// 
			// ship
			// 
			this.ship.AllowUserToAddRows = false;
			this.ship.AllowUserToDeleteRows = false;
			this.ship.AllowUserToResizeColumns = false;
			this.ship.AllowUserToResizeRows = false;
			this.ship.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.ship.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
			this.ship.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.ship.Cursor = System.Windows.Forms.Cursors.Hand;
			dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
			dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Window;
			dataGridViewCellStyle5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
			dataGridViewCellStyle5.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle5.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
			this.ship.DefaultCellStyle = dataGridViewCellStyle5;
			this.ship.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
			this.ship.Location = new System.Drawing.Point(1278, 47);
			this.ship.MultiSelect = false;
			this.ship.Name = "ship";
			this.ship.ReadOnly = true;
			this.ship.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
			this.ship.RowTemplate.Height = 87;
			this.ship.RowTemplate.ReadOnly = true;
			this.ship.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.False;
			this.ship.ScrollBars = System.Windows.Forms.ScrollBars.None;
			this.ship.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
			this.ship.Size = new System.Drawing.Size(694, 796);
			this.ship.TabIndex = 97;
			this.ship.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.genericButton);
			this.ship.CellMouseEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.ship_CellMouseEnter);
			this.ship.CellMouseLeave += new System.Windows.Forms.DataGridViewCellEventHandler(this.ship_CellMouseLeave);
			this.ship.SelectionChanged += new System.EventHandler(this.ship_SelectionChanged);
			// 
			// buffer
			// 
			this.buffer.AllowUserToAddRows = false;
			this.buffer.AllowUserToDeleteRows = false;
			this.buffer.AllowUserToResizeColumns = false;
			this.buffer.AllowUserToResizeRows = false;
			this.buffer.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
			this.buffer.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.buffer.Cursor = System.Windows.Forms.Cursors.Hand;
			dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
			dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Window;
			dataGridViewCellStyle6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
			dataGridViewCellStyle6.SelectionBackColor = System.Drawing.SystemColors.Highlight;
			dataGridViewCellStyle6.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
			dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
			this.buffer.DefaultCellStyle = dataGridViewCellStyle6;
			this.buffer.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
			this.buffer.Location = new System.Drawing.Point(12, 573);
			this.buffer.MultiSelect = false;
			this.buffer.Name = "buffer";
			this.buffer.ReadOnly = true;
			this.buffer.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
			this.buffer.RowTemplate.Height = 50;
			this.buffer.RowTemplate.ReadOnly = true;
			this.buffer.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.False;
			this.buffer.ScrollBars = System.Windows.Forms.ScrollBars.None;
			this.buffer.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
			this.buffer.Size = new System.Drawing.Size(905, 270);
			this.buffer.TabIndex = 98;
			this.buffer.SelectionChanged += new System.EventHandler(this.buffer_SelectionChanged);
			// 
			// truck
			// 
			this.truck.Anchor = System.Windows.Forms.AnchorStyles.Top;
			this.truck.BackColor = System.Drawing.Color.White;
			this.truck.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.truck.Location = new System.Drawing.Point(979, 629);
			this.truck.Name = "truck";
			this.truck.Size = new System.Drawing.Size(227, 214);
			this.truck.TabIndex = 99;
			this.truck.Text = "Truck";
			this.truck.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// login
			// 
			this.login.Location = new System.Drawing.Point(12, 12);
			this.login.Name = "login";
			this.login.Size = new System.Drawing.Size(80, 23);
			this.login.TabIndex = 100;
			this.login.Text = "Change User";
			this.login.UseVisualStyleBackColor = true;
			// 
			// progress
			// 
			this.progress.BackColor = System.Drawing.SystemColors.Control;
			this.progress.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.progress.Location = new System.Drawing.Point(923, 9);
			this.progress.Name = "progress";
			this.progress.Size = new System.Drawing.Size(349, 38);
			this.progress.TabIndex = 101;
			this.progress.Text = "Progress Tracker";
			this.progress.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Controls.Add(this.newWeight);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Controls.Add(this.newName);
			this.groupBox1.Location = new System.Drawing.Point(12, 65);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(762, 193);
			this.groupBox1.TabIndex = 102;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "New Container Info";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(6, 104);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(89, 13);
			this.label2.TabIndex = 106;
			this.label2.Text = "Container Weight";
			// 
			// newWeight
			// 
			this.newWeight.Location = new System.Drawing.Point(6, 120);
			this.newWeight.Name = "newWeight";
			this.newWeight.Size = new System.Drawing.Size(750, 20);
			this.newWeight.TabIndex = 105;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(6, 27);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(83, 13);
			this.label1.TabIndex = 104;
			this.label1.Text = "Container Name";
			// 
			// newName
			// 
			this.newName.Location = new System.Drawing.Point(6, 43);
			this.newName.Mask = "00000";
			this.newName.Name = "newName";
			this.newName.Size = new System.Drawing.Size(750, 20);
			this.newName.TabIndex = 103;
			this.newName.ValidatingType = typeof(int);
			// 
			// nextStep
			// 
			this.nextStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.nextStep.Location = new System.Drawing.Point(985, 110);
			this.nextStep.Name = "nextStep";
			this.nextStep.Size = new System.Drawing.Size(229, 148);
			this.nextStep.TabIndex = 103;
			this.nextStep.Text = "Next Step";
			this.nextStep.UseVisualStyleBackColor = true;
			this.nextStep.Click += new System.EventHandler(this.nextStep_Click);
			// 
			// timeRemaining
			// 
			this.timeRemaining.BackColor = System.Drawing.SystemColors.Control;
			this.timeRemaining.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.timeRemaining.Location = new System.Drawing.Point(923, 47);
			this.timeRemaining.Name = "timeRemaining";
			this.timeRemaining.Size = new System.Drawing.Size(349, 38);
			this.timeRemaining.TabIndex = 104;
			this.timeRemaining.Text = "Time Remaining";
			this.timeRemaining.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// notes
			// 
			this.notes.Controls.Add(this.noteButton);
			this.notes.Controls.Add(this.label5);
			this.notes.Controls.Add(this.maskedTextBox5);
			this.notes.Location = new System.Drawing.Point(12, 330);
			this.notes.Name = "notes";
			this.notes.Size = new System.Drawing.Size(762, 141);
			this.notes.TabIndex = 107;
			this.notes.TabStop = false;
			this.notes.Text = "Add Log Note";
			// 
			// noteButton
			// 
			this.noteButton.Location = new System.Drawing.Point(286, 88);
			this.noteButton.Name = "noteButton";
			this.noteButton.Size = new System.Drawing.Size(143, 30);
			this.noteButton.TabIndex = 105;
			this.noteButton.Text = "Add Note";
			this.noteButton.UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(6, 27);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(83, 13);
			this.label5.TabIndex = 104;
			this.label5.Text = "Container Name";
			// 
			// maskedTextBox5
			// 
			this.maskedTextBox5.Location = new System.Drawing.Point(6, 43);
			this.maskedTextBox5.Name = "maskedTextBox5";
			this.maskedTextBox5.Size = new System.Drawing.Size(750, 20);
			this.maskedTextBox5.TabIndex = 103;
			// 
			// nameLabel
			// 
			this.nameLabel.BackColor = System.Drawing.Color.White;
			this.nameLabel.Location = new System.Drawing.Point(1278, 9);
			this.nameLabel.Name = "nameLabel";
			this.nameLabel.Size = new System.Drawing.Size(694, 22);
			this.nameLabel.TabIndex = 108;
			this.nameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// moves
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
			this.ClientSize = new System.Drawing.Size(1984, 855);
			this.Controls.Add(this.nameLabel);
			this.Controls.Add(this.notes);
			this.Controls.Add(this.timeRemaining);
			this.Controls.Add(this.nextStep);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.progress);
			this.Controls.Add(this.login);
			this.Controls.Add(this.truck);
			this.Controls.Add(this.buffer);
			this.Controls.Add(this.ship);
			this.MinimumSize = new System.Drawing.Size(2000, 894);
			this.Name = "moves";
			this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
			this.Text = "Move Order";
			this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.moves_FormClosed);
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.ship)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.buffer)).EndInit();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.notes.ResumeLayout(false);
			this.notes.PerformLayout();
			this.ResumeLayout(false);

        }

        #endregion
		private System.Windows.Forms.DataGridView ship;
		private System.Windows.Forms.DataGridView buffer;
		private System.Windows.Forms.Label truck;
		private System.Windows.Forms.Button login;
		private System.Windows.Forms.Label progress;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.MaskedTextBox newName;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.MaskedTextBox newWeight;
		private System.Windows.Forms.Button nextStep;
		private System.Windows.Forms.Label timeRemaining;
		private System.Windows.Forms.GroupBox notes;
		private System.Windows.Forms.Button noteButton;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.MaskedTextBox maskedTextBox5;
		private System.Windows.Forms.Label nameLabel;
	}
}

