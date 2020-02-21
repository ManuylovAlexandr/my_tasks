using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ControlHomework
{
    public partial class Form1 : Form
    {
        private List<College> mas = new List<College>();
        private List<Area> arr = new List<Area>();

        public Form1()
        {
            InitializeComponent();
            DoubleBuffered = true;
        }

        int FindInAreas(Area a)
        {
            for (int i = 0; i < arr.Count; i++)
            {
                if (a.Okrug == arr[i].Okrug && a.Rayon == arr[i].Rayon) return i;
            }
            return -1;
        }

        /// <summary>
        /// метод для парсинга исходной строки
        /// </summary>
        /// <param name="data"></param>
        /// <returns></returns>
        private string[] Parser(string data)
        {
            try
            {
                List<string> p = new List<string>();
                int musor = 0;
                string f = String.Empty;
                int count = 0;

                for (int i = 0; i < data.Length; i++)
                {
                    if (data[i] == '\"')
                    {
                        count++;
                        f += '\"';
                    }
                    if (data[i] == ';')
                    {
                        if (count % 2 == 1) f += ';';
                        else
                        {
                            if (int.TryParse(f, out musor)) f = f;
                            else if (f == "\"\"\"\"") f = String.Empty;
                            else
                            {
                                f = f.Replace("\"\"", "\"");
                                f = f.Substring(1, f.Length - 2);
                                f = f.Replace("\"\"", "\"");
                            }
                            p.Add(f);
                            f = String.Empty;
                            count = 0;
                        }
                    }
                    else f += data[i];
                }
                if (int.TryParse(f, out musor)) f = f;
                else if (f == "\"\"\"\"") f = String.Empty;
                else
                {
                    f.Replace("\"\"", "\"");
                    f = f.Substring(1, f.Length - 2);
                    f = f.Replace("\"\"", "\"");
                }
                p.Add(f);

                int k = FindInAreas(new Area(p[3], p[4]));
                if (k == -1)
                {
                    arr.Add(new Area(p[3], p[4]));
                    mas.Add(new College(p[0], p[1], p[2], arr[arr.Count - 1], p[5], p[6],
                        p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14]));
                }
                else
                {
                    mas.Add(new College(p[0], p[1], p[2], arr[k], p[5], p[6],
                        p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14]));
                }

                if (p.Count != 15)
                {
                    throw new ArgumentException();
                }
                return p.ToArray();
            }
            catch (Exception ex)
            {
                throw new Exception();
            }
        }

        /// <summary>
        /// событие для открытия и отображения файла
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void открытьToolStripMenuItem_Click(object sender, EventArgs e) 
        {
            try
            {
                if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                    return;

                string filename = openFileDialog1.FileName;
                string[] lines = null;

                try
                {
                    lines = File.ReadAllLines(filename);
                }
                catch (IOException ex)
                {
                    MessageBox.Show("Закройте докумет");
                    return;
                } // читаем файл

                int length = 0;

                try
                {
                    length = int.Parse(ShowMyDialogBox());
                    if (length < 1 || length > lines.Length) throw new ArgumentException();
                }
                catch (FormatException ex)
                {
                    MessageBox.Show($"Введите целое число от 1 до {lines.Length}");
                    return;
                }
                catch (ArgumentException ex)
                {
                    MessageBox.Show($"Число строк должно быть от 1 до {lines.Length}");
                    return;
                } //счытываем кол-вл отображаемых строк

                for (int i = 0; i < lines.Length; i++)
                {
                    if (lines[i][lines[i].Length - 1] == ';')
                    {
                        lines[i] = lines[i].Substring(0, lines[i].Length - 2);
                    }
                } // убираем ; в конце каждой строки 

                string[] a = lines[0].Split(new char[] { ';' }); // заголовок

                if (a.Length != 15)
                {
                    MessageBox.Show($"Некорректный файл {a.Length}");
                    return;
                }// проверка файла на корректность

                dataGridView1.RowCount = length;
                dataGridView1.ColumnCount = a.Length; // создаем таблицу нужного размера

                for (int i = 0; i < a.Length; i++)
                {
                    dataGridView1.Columns[i].HeaderText = a[i];
                } // заполняем заголовок

                string[][] mas = new string[length - 1][]; // массив - таблица

                try
                {
                    for (int i = 1; i < length; i++)
                    {
                        mas[i - 1] = Parser(lines[i]);
                    }
                }
                catch (ArgumentException ex)
                {
                    MessageBox.Show("Некоректный файл 6");
                    return;
                } // заполнием массив - таблицу


                for (int i = 0; i < mas.GetLength(0); i++) // заполняем таблицу
                {
                    for (int j = 0; j < mas[i].Length; j++)
                    {
                        dataGridView1[j, i].Value = mas[i][j];
                    }
                }

                действияToolStripMenuItem.Enabled = true; // разрешаеем действия
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        /// <summary>
        /// удаление выбранной строки
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void удалитьВыбраннуюСтрокуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (dataGridView1.CurrentRow != null && dataGridView1.CurrentRow.Index != dataGridView1.RowCount - 1)
                {
                    int a = dataGridView1.CurrentRow.Index;
                    dataGridView1.Rows.Remove(dataGridView1.Rows[a]);
                }
                else MessageBox.Show("Выберите строку \n (нельзя удалять последнюю строку)");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        /// <summary>
        /// метод для отображения окна ввода кол-ва отображаемых строк
        /// </summary>
        /// <returns></returns>
        public string ShowMyDialogBox()
        {
            Form2 testDialog = new Form2();
            if (testDialog.ShowDialog(this) == DialogResult.OK)
            {
                string length = testDialog.textBox1.Text;
                testDialog.Dispose();
                return length;
            }
            else return null;
        }

        private void справкаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Для открытия csv файла выберите файл->открыть. Для сохранения файл->сохранить. \n" +
                "Для удаления записи о колледже выберите непустую строку и выберите действия->удалить выбранную строку. \n" +
                "Для добавления новой записи начните заполнять последнюю строку в таблице. \n" +
                "Для редактирования существующей записи выберите необходимую ячейку и введите требуемую информацию вместо текущей \n" +
                "Для сортировки по названию/типу учереждения нажмите на заголовок колонки. \n" +
                "Для сортировки по государственности/негосударственности выберите \n " +
                "действия->Отфильтровать по гос-ти/не гос-ти->(соответсвующий пункт)." +
                "Для фильтрации выберите действия->Отфильтровать по подстроке->(соответсвующий пункт).");
            System.Diagnostics.Process.Start("https://www.youtube.com/watch?v=kMdwE2on2DU");
        }

        /// <summary>
        /// сохранение
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                    return;
                // получаем выбранный файл
                string filename = saveFileDialog1.FileName;
                // сохраняем текст в файл
                File.WriteAllText(filename, Joiner(dataGridView1), Encoding.UTF8);
                MessageBox.Show("Файл сохранен");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        /// <summary>
        /// метод создает строку для сохранения
        /// </summary>
        /// <param name="dataGridView1"></param>
        /// <returns></returns>
        private string Joiner(DataGridView dataGridView1)
        {
            string res = "";
            for (int i = 0; i < dataGridView1.ColumnCount; i++)
            {
                res += dataGridView1.Columns[i].HeaderText + ";";
            }
            res += Environment.NewLine;

            for (int i = 0; i < dataGridView1.RowCount - 1; i++)
            {
                for (int j = 0; j < dataGridView1.ColumnCount; j++)
                {
                    if (dataGridView1[j, i].Value != null)
                        res += '"' + dataGridView1[j, i].Value.ToString() + '"' + ";";
                    else
                        res += ";";
                }
                if (i != dataGridView1.RowCount - 2) res += Environment.NewLine;
            }
            return res;
        }

        /// <summary>
        /// метод для фильтрации гос-ти/не гос-ти для всех
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void дляВсехУчережденийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow != null && dataGridView1.CurrentRow.Index != dataGridView1.RowCount - 1)
            {
                int a = dataGridView1.CurrentRow.Index;
                string flag;
                flag = dataGridView1[5, a].Value.ToString();
                List<int> list = new List<int>();
                for (int i = 0; i < dataGridView1.RowCount - 1; i++)
                {
                    if (dataGridView1.CurrentRow != null)
                    {
                        if (dataGridView1[5, i].Value.ToString() != flag)
                        {
                            list.Add(i);
                        }
                    }
                }
                for (int i = list.Count - 1; i > -1; i--)
                {
                    dataGridView1.Rows.Remove(dataGridView1.Rows[list[i]]);
                }
            }
            else MessageBox.Show("Выберите другую строку");
        }

        /// <summary>
        /// метод для фильтрации гос-ти/не гос-ти для района выбранного колледжа
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void дляРайонаВыбранногоКолледжаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow != null && dataGridView1.CurrentRow.Index != dataGridView1.RowCount - 1)
            {
                int a = dataGridView1.CurrentRow.Index;
                string rayon = dataGridView1[4, a].Value.ToString(); ;
                string flag = dataGridView1[5, a].Value.ToString();
                List<int> list = new List<int>();
                for (int i = 0; i < dataGridView1.RowCount - 1; i++)
                {
                    if (dataGridView1.CurrentRow != null)
                    {
                        if (dataGridView1[5, i].Value.ToString() != flag || dataGridView1[4, i].Value.ToString() != rayon)
                        {
                            list.Add(i);
                        }
                    }
                }
                for (int i = list.Count - 1; i > -1; i--)
                {
                    dataGridView1.Rows.Remove(dataGridView1.Rows[list[i]]);
                }
            }
            else MessageBox.Show("Выберите другую строку");
        }

        /// <summary>
        /// метод для фильтрации гос-ти/не гос-ти для округа выбранного колледжа
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void дляОкругаВыбранногоКолледжаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow != null && dataGridView1.CurrentRow.Index != dataGridView1.RowCount - 1)
            {
                int a = dataGridView1.CurrentRow.Index;
                string okrug = dataGridView1[3, a].Value.ToString(); ;
                string flag = dataGridView1[5, a].Value.ToString();
                List<int> list = new List<int>();
                for (int i = 0; i < dataGridView1.RowCount - 1; i++)
                {
                    if (dataGridView1.CurrentRow != null)
                    {
                        if (dataGridView1[5, i].Value.ToString() != flag || dataGridView1[3, i].Value.ToString() != okrug)
                        {
                            list.Add(i);
                        }
                    }
                }
                for (int i = list.Count - 1; i > -1; i--)
                {
                    dataGridView1.Rows.Remove(dataGridView1.Rows[list[i]]);
                }
            }
            else MessageBox.Show("Выберите другую строку");
        }

        /// <summary>
        /// вывод окна для получения подстроки фильтрации
        /// </summary>
        /// <returns></returns>
        public string ShowMyDialogBox2()
        {
            Form3 testDialog = new Form3();
            if (testDialog.ShowDialog(this) == DialogResult.OK)
            {
                string length = testDialog.textBox1.Text;
                testDialog.Dispose();
                return length;
            }
            else return null;
        }

        /// <summary>
        /// фильтрация по району
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void районToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string filter = ShowMyDialogBox2().ToLower();
            List<int> list = new List<int>();
            for (int i = 0; i < dataGridView1.RowCount - 1; i++)
            {
                if (dataGridView1.CurrentRow != null)
                {
                    if (!dataGridView1[4, i].Value.ToString().ToLower().Contains(filter))
                    {
                        list.Add(i);
                    }
                }
            }
            for (int i = list.Count - 1; i > -1; i--)
            {
                dataGridView1.Rows.Remove(dataGridView1.Rows[list[i]]);
            }
        }

        /// <summary>
        /// фильтрация по округу
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void округToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string filter = ShowMyDialogBox2().ToLower();
            List<int> list = new List<int>();
            for (int i = 0; i < dataGridView1.RowCount - 1; i++)
            {
                if (dataGridView1.CurrentRow != null)
                {
                    if (!dataGridView1[3, i].Value.ToString().ToLower().Contains(filter))
                    {
                        list.Add(i);
                    }
                }
            }
            for (int i = list.Count - 1; i > -1; i--)
            {
                dataGridView1.Rows.Remove(dataGridView1.Rows[list[i]]);
            }
        }
    }
}