namespace Курсач
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.действияToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.отобразитьГрафToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.кластеризоватьГрафToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.запуститьСиловойАлгоритмToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.сброситьМасштабToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.авторизироватьсяToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.сохранитьИзображениеToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.label2 = new System.Windows.Forms.Label();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.опрограммеToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox1.BackColor = System.Drawing.SystemColors.Window;
            this.pictureBox1.Location = new System.Drawing.Point(0, 36);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(1140, 583);
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.pictureBox1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDoubleClick);
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseUp);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.действияToolStripMenuItem,
            this.авторизироватьсяToolStripMenuItem,
            this.сохранитьИзображениеToolStripMenuItem,
            this.опрограммеToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1140, 33);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // действияToolStripMenuItem
            // 
            this.действияToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.отобразитьГрафToolStripMenuItem,
            this.кластеризоватьГрафToolStripMenuItem,
            this.запуститьСиловойАлгоритмToolStripMenuItem,
            this.сброситьМасштабToolStripMenuItem});
            this.действияToolStripMenuItem.Name = "действияToolStripMenuItem";
            this.действияToolStripMenuItem.Size = new System.Drawing.Size(99, 29);
            this.действияToolStripMenuItem.Text = "Действия";
            // 
            // отобразитьГрафToolStripMenuItem
            // 
            this.отобразитьГрафToolStripMenuItem.Enabled = false;
            this.отобразитьГрафToolStripMenuItem.Name = "отобразитьГрафToolStripMenuItem";
            this.отобразитьГрафToolStripMenuItem.Size = new System.Drawing.Size(331, 30);
            this.отобразитьГрафToolStripMenuItem.Text = "Отобразить граф";
            this.отобразитьГрафToolStripMenuItem.Click += new System.EventHandler(this.отобразитьГрафToolStripMenuItem_Click);
            // 
            // кластеризоватьГрафToolStripMenuItem
            // 
            this.кластеризоватьГрафToolStripMenuItem.Enabled = false;
            this.кластеризоватьГрафToolStripMenuItem.Name = "кластеризоватьГрафToolStripMenuItem";
            this.кластеризоватьГрафToolStripMenuItem.Size = new System.Drawing.Size(331, 30);
            this.кластеризоватьГрафToolStripMenuItem.Text = "Кластеризовать граф";
            this.кластеризоватьГрафToolStripMenuItem.Click += new System.EventHandler(this.кластеризоватьГрафToolStripMenuItem_Click);
            // 
            // запуститьСиловойАлгоритмToolStripMenuItem
            // 
            this.запуститьСиловойАлгоритмToolStripMenuItem.Enabled = false;
            this.запуститьСиловойАлгоритмToolStripMenuItem.Name = "запуститьСиловойАлгоритмToolStripMenuItem";
            this.запуститьСиловойАлгоритмToolStripMenuItem.Size = new System.Drawing.Size(331, 30);
            this.запуститьСиловойАлгоритмToolStripMenuItem.Text = "Запустить силовой алгоритм";
            this.запуститьСиловойАлгоритмToolStripMenuItem.Click += new System.EventHandler(this.запуститьСиловойАлгоритмToolStripMenuItem_Click);
            // 
            // сброситьМасштабToolStripMenuItem
            // 
            this.сброситьМасштабToolStripMenuItem.Enabled = false;
            this.сброситьМасштабToolStripMenuItem.Name = "сброситьМасштабToolStripMenuItem";
            this.сброситьМасштабToolStripMenuItem.Size = new System.Drawing.Size(331, 30);
            this.сброситьМасштабToolStripMenuItem.Text = "Сбросить масштаб";
            this.сброситьМасштабToolStripMenuItem.Click += new System.EventHandler(this.сброситьМасштабToolStripMenuItem_Click);
            // 
            // авторизироватьсяToolStripMenuItem
            // 
            this.авторизироватьсяToolStripMenuItem.Name = "авторизироватьсяToolStripMenuItem";
            this.авторизироватьсяToolStripMenuItem.Size = new System.Drawing.Size(177, 29);
            this.авторизироватьсяToolStripMenuItem.Text = "Авторизироваться";
            this.авторизироватьсяToolStripMenuItem.Click += new System.EventHandler(this.авторизироватьсяToolStripMenuItem_Click);
            // 
            // сохранитьИзображениеToolStripMenuItem
            // 
            this.сохранитьИзображениеToolStripMenuItem.Name = "сохранитьИзображениеToolStripMenuItem";
            this.сохранитьИзображениеToolStripMenuItem.Size = new System.Drawing.Size(225, 29);
            this.сохранитьИзображениеToolStripMenuItem.Text = "Сохранить изображение";
            this.сохранитьИзображениеToolStripMenuItem.Click += new System.EventHandler(this.сохранитьИзображениеToolStripMenuItem_Click);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Enabled = false;
            this.label1.Location = new System.Drawing.Point(738, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 20);
            this.label1.TabIndex = 4;
            this.label1.Text = "aaa";
            this.label1.Visible = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox2.Location = new System.Drawing.Point(1065, 0);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(75, 75);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 5;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Visible = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureBox3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.pictureBox3.Location = new System.Drawing.Point(0, 417);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(200, 200);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 6;
            this.pictureBox3.TabStop = false;
            this.pictureBox3.Visible = false;
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 394);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(51, 20);
            this.label2.TabIndex = 7;
            this.label2.Text = "label2";
            this.label2.Visible = false;
            // 
            // pictureBox4
            // 
            this.pictureBox4.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox4.Image")));
            this.pictureBox4.Location = new System.Drawing.Point(0, 45);
            this.pictureBox4.MaximumSize = new System.Drawing.Size(80, 135);
            this.pictureBox4.MinimumSize = new System.Drawing.Size(80, 135);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(80, 135);
            this.pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox4.TabIndex = 8;
            this.pictureBox4.TabStop = false;
            this.pictureBox4.Visible = false;
            // 
            // опрограммеToolStripMenuItem
            // 
            this.опрограммеToolStripMenuItem.Name = "опрограммеToolStripMenuItem";
            this.опрограммеToolStripMenuItem.Size = new System.Drawing.Size(137, 29);
            this.опрограммеToolStripMenuItem.Text = "О программе";
            this.опрограммеToolStripMenuItem.Click += new System.EventHandler(this.справкаToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(1140, 622);
            this.Controls.Add(this.pictureBox4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "vk_graph";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem действияToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem авторизироватьсяToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem отобразитьГрафToolStripMenuItem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ToolStripMenuItem кластеризоватьГрафToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem запуститьСиловойАлгоритмToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem сброситьМасштабToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.ToolStripMenuItem сохранитьИзображениеToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem опрограммеToolStripMenuItem;
    }
}

