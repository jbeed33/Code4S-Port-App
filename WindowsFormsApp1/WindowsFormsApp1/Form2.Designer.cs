
namespace WindowsFormsApp1
{
	partial class mainMenu
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
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.username = new System.Windows.Forms.TextBox();
			this.login = new System.Windows.Forms.Button();
			this.exportlog = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(318, 71);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(148, 108);
			this.button1.TabIndex = 0;
			this.button1.Text = "Balance";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(318, 204);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(148, 108);
			this.button2.TabIndex = 1;
			this.button2.Text = "Load / Unload";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.button2_Click);
			// 
			// username
			// 
			this.username.Location = new System.Drawing.Point(98, 14);
			this.username.Name = "username";
			this.username.Size = new System.Drawing.Size(163, 20);
			this.username.TabIndex = 2;
			this.username.TextChanged += new System.EventHandler(this.username_TextChanged);
			// 
			// login
			// 
			this.login.Location = new System.Drawing.Point(12, 12);
			this.login.Name = "login";
			this.login.Size = new System.Drawing.Size(80, 23);
			this.login.TabIndex = 101;
			this.login.Text = "Change User";
			this.login.UseVisualStyleBackColor = true;
			this.login.Click += new System.EventHandler(this.login_Click);
			// 
			// exportlog
			// 
			this.exportlog.Location = new System.Drawing.Point(12, 415);
			this.exportlog.Name = "exportlog";
			this.exportlog.Size = new System.Drawing.Size(75, 23);
			this.exportlog.TabIndex = 102;
			this.exportlog.Text = "Export Log";
			this.exportlog.UseVisualStyleBackColor = true;
			this.exportlog.Click += new System.EventHandler(this.exportlog_Click);
			// 
			// mainMenu
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.exportlog);
			this.Controls.Add(this.login);
			this.Controls.Add(this.username);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Name = "mainMenu";
			this.Text = "Main Menu";
			this.Load += new System.EventHandler(this.mainMenu_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.TextBox username;
		private System.Windows.Forms.Button login;
		private System.Windows.Forms.Button exportlog;
	}
}