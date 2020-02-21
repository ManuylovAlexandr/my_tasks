namespace ControlHomework
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
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.файлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.открытьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.сохранитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.справкаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.действияToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.удалитьВыбраннуюСтрокуToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.отфильтроватьПоГостинеToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.дляВсехУчережденийToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.отфильтроватьПоПодстрокеToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.районToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.округToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.DefaultExt = "csv";
            this.saveFileDialog1.Filter = "CSV files(*.csv)|*.csv";
            this.saveFileDialog1.RestoreDirectory = true;
            this.saveFileDialog1.Title = "Сохранить";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.DefaultExt = "csv";
            this.openFileDialog1.Filter = "CSV files(*.csv)|*.csv";
            this.openFileDialog1.Title = "Выберите файл";
            // 
            // dataGridView1
            // 
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(0, 49);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 28;
            this.dataGridView1.Size = new System.Drawing.Size(1214, 551);
            this.dataGridView1.TabIndex = 0;
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.файлToolStripMenuItem,
            this.справкаToolStripMenuItem,
            this.действияToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1214, 33);
            this.menuStrip1.TabIndex = 4;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // файлToolStripMenuItem
            // 
            this.файлToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.открытьToolStripMenuItem,
            this.toolStripSeparator2,
            this.сохранитьToolStripMenuItem});
            this.файлToolStripMenuItem.Name = "файлToolStripMenuItem";
            this.файлToolStripMenuItem.Size = new System.Drawing.Size(65, 29);
            this.файлToolStripMenuItem.Text = "&Файл";
            // 
            // открытьToolStripMenuItem
            // 
            this.открытьToolStripMenuItem.Name = "открытьToolStripMenuItem";
            this.открытьToolStripMenuItem.Size = new System.Drawing.Size(182, 30);
            this.открытьToolStripMenuItem.Text = "&Открыть";
            this.открытьToolStripMenuItem.Click += new System.EventHandler(this.открытьToolStripMenuItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(179, 6);
            // 
            // сохранитьToolStripMenuItem
            // 
            this.сохранитьToolStripMenuItem.Name = "сохранитьToolStripMenuItem";
            this.сохранитьToolStripMenuItem.Size = new System.Drawing.Size(252, 30);
            this.сохранитьToolStripMenuItem.Text = "&Сохранить";
            this.сохранитьToolStripMenuItem.Click += new System.EventHandler(this.сохранитьToolStripMenuItem_Click);
            // 
            // справкаToolStripMenuItem
            // 
            this.справкаToolStripMenuItem.Name = "справкаToolStripMenuItem";
            this.справкаToolStripMenuItem.Size = new System.Drawing.Size(93, 29);
            this.справкаToolStripMenuItem.Text = "&Справка";
            this.справкаToolStripMenuItem.Click += new System.EventHandler(this.справкаToolStripMenuItem_Click);
            // 
            // действияToolStripMenuItem
            // 
            this.действияToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.удалитьВыбраннуюСтрокуToolStripMenuItem,
            this.отфильтроватьПоГостинеToolStripMenuItem,
            this.отфильтроватьПоПодстрокеToolStripMenuItem});
            this.действияToolStripMenuItem.Enabled = false;
            this.действияToolStripMenuItem.Name = "действияToolStripMenuItem";
            this.действияToolStripMenuItem.Size = new System.Drawing.Size(99, 29);
            this.действияToolStripMenuItem.Text = "Действия";
            // 
            // удалитьВыбраннуюСтрокуToolStripMenuItem
            // 
            this.удалитьВыбраннуюСтрокуToolStripMenuItem.Name = "удалитьВыбраннуюСтрокуToolStripMenuItem";
            this.удалитьВыбраннуюСтрокуToolStripMenuItem.Size = new System.Drawing.Size(322, 30);
            this.удалитьВыбраннуюСтрокуToolStripMenuItem.Text = "Удалить выбранную строку";
            this.удалитьВыбраннуюСтрокуToolStripMenuItem.Click += new System.EventHandler(this.удалитьВыбраннуюСтрокуToolStripMenuItem_Click);
            // 
            // отфильтроватьПоГостинеToolStripMenuItem
            // 
            this.отфильтроватьПоГостинеToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.дляВсехУчережденийToolStripMenuItem,
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem,
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem});
            this.отфильтроватьПоГостинеToolStripMenuItem.Name = "отфильтроватьПоГостинеToolStripMenuItem";
            this.отфильтроватьПоГостинеToolStripMenuItem.Size = new System.Drawing.Size(383, 30);
            this.отфильтроватьПоГостинеToolStripMenuItem.Text = "Отфильтровать по гос-ти/не гос-ти";
            // 
            // дляВсехУчережденийToolStripMenuItem
            // 
            this.дляВсехУчережденийToolStripMenuItem.Name = "дляВсехУчережденийToolStripMenuItem";
            this.дляВсехУчережденийToolStripMenuItem.Size = new System.Drawing.Size(382, 30);
            this.дляВсехУчережденийToolStripMenuItem.Text = "Для всех учереждений";
            this.дляВсехУчережденийToolStripMenuItem.Click += new System.EventHandler(this.дляВсехУчережденийToolStripMenuItem_Click);
            // 
            // дляРайонаВыбранногоКолледжаToolStripMenuItem
            // 
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem.Name = "дляРайонаВыбранногоКолледжаToolStripMenuItem";
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem.Size = new System.Drawing.Size(382, 30);
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem.Text = "Для района выбранного колледжа";
            this.дляРайонаВыбранногоКолледжаToolStripMenuItem.Click += new System.EventHandler(this.дляРайонаВыбранногоКолледжаToolStripMenuItem_Click);
            // 
            // дляОкругаВыбранногоКолледжаToolStripMenuItem
            // 
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem.Name = "дляОкругаВыбранногоКолледжаToolStripMenuItem";
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem.Size = new System.Drawing.Size(382, 30);
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem.Text = "Для округа выбранного колледжа";
            this.дляОкругаВыбранногоКолледжаToolStripMenuItem.Click += new System.EventHandler(this.дляОкругаВыбранногоКолледжаToolStripMenuItem_Click);
            // 
            // отфильтроватьПоПодстрокеToolStripMenuItem
            // 
            this.отфильтроватьПоПодстрокеToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.районToolStripMenuItem,
            this.округToolStripMenuItem});
            this.отфильтроватьПоПодстрокеToolStripMenuItem.Name = "отфильтроватьПоПодстрокеToolStripMenuItem";
            this.отфильтроватьПоПодстрокеToolStripMenuItem.Size = new System.Drawing.Size(383, 30);
            this.отфильтроватьПоПодстрокеToolStripMenuItem.Text = "Отфильтровать по подстроке";
            // 
            // районToolStripMenuItem
            // 
            this.районToolStripMenuItem.Name = "районToolStripMenuItem";
            this.районToolStripMenuItem.Size = new System.Drawing.Size(252, 30);
            this.районToolStripMenuItem.Text = "Район";
            this.районToolStripMenuItem.Click += new System.EventHandler(this.районToolStripMenuItem_Click);
            // 
            // округToolStripMenuItem
            // 
            this.округToolStripMenuItem.Name = "округToolStripMenuItem";
            this.округToolStripMenuItem.Size = new System.Drawing.Size(252, 30);
            this.округToolStripMenuItem.Text = "Округ";
            this.округToolStripMenuItem.Click += new System.EventHandler(this.округToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1214, 600);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.menuStrip1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem файлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem открытьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem сохранитьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem справкаToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem действияToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem удалитьВыбраннуюСтрокуToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem отфильтроватьПоГостинеToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem дляВсехУчережденийToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem дляРайонаВыбранногоКолледжаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem дляОкругаВыбранногоКолледжаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem отфильтроватьПоПодстрокеToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem районToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem округToolStripMenuItem;
    }
}

