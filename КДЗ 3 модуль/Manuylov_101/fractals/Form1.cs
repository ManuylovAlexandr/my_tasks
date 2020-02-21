using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace fractals
{
    public partial class Form1 : Form
    {
        Bitmap map; // Контейнер хранения битов пикселей
        Graphics gr; // инструмент для рисования
        Pen myPen;
        PointF center, nowcenter, mousePos;
        List<Color> colorList;
        int depth;
        int koef;
        bool flag_depth; 
        Color defaultColor;
        string typeFractal;

        public Form1()
        {
            InitializeComponent();
            defaultColor = Color.Black;
            comboBox1.SelectedItem = "1";
            koef = 1;
            myPen = new Pen(Color.Black);
            MinimumSize = new Size(Screen.PrimaryScreen.Bounds.Size.Width / 2,
                Screen.PrimaryScreen.Bounds.Size.Height / 2);
            map = new Bitmap(pictureBox1.Width, pictureBox1.Height);//Подключаем Битмап
            gr = Graphics.FromImage(map);
            colorList = new List<Color>();
        }

        /// <summary>
        /// кнопка нажать, приводящая к отрисовке фрактала
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            center = new PointF(pictureBox1.Width / 2, pictureBox1.Height / 2);

            SelectFractal();
            CheckDepth();
            if (flag_depth)
            {
                flag_depth = false;
                return;
            }// если ошибка то выходим
        }

        /// <summary>
        /// функция узнающая какой фрактал выбрал пользователь
        /// </summary>
        private void SelectFractal()
        {
            try
            {
                if (comboBox2.Text == "Тип фрактала")
                {
                    throw new NullReferenceException();
                }
                typeFractal = comboBox2.Text;
            }
            catch (NullReferenceException)
            {
                MessageBox.Show("Выберете фрактал", "NullReferenceException");
                return;
            }
        }

        /// <summary>
        /// функция проверяющая корректность ввода глубины рекурсии и вызываюцая отрисовку
        /// </summary>
        private void CheckDepth()
        {
            try
            {
                depth = int.Parse(textBox1.Text);
                if (typeFractal == "Т-квадрат")
                {
                    if (depth <= 0 || depth > 11)
                    {
                        MessageBox.Show("Слишком глубокая рекурсия. Глубина должна быть от 1 до 11", "Ошибка"); return;
                    }
                    TFractal();
                }
                if (typeFractal == "С-кривая леви")
                {
                    if (depth <= 0 || depth > 16)
                    {
                        MessageBox.Show("Слишком глубокая рекурсия. Глубина должна быть от 1 до 16", "Ошибка"); return;
                    }
                    CFractal();
                }
                if(typeFractal == "Круговой фрактал")
                {
                    if (depth <= 0 || depth > 6)
                    {
                        MessageBox.Show("Слишком глубокая рекурсия. Глубина должна быть от 1 до 6", "Ошибка"); return;
                    }
                    CircleFractal();
                }
            }
            catch (NullReferenceException)
            {
                MessageBox.Show("Неверное значение глубины рекурсии", "NullReferenceException");
                flag_depth = true;
                return;
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректное значение глубины рекурсии", "FormatException");
                flag_depth = true;
                return;
            }
        }

        /// <summary>
        /// закрашиваем все цветом фона
        /// </summary>
        void Clear()
        {
            gr.Clear(Color.Honeydew);
            pictureBox1.Image = map;
        }

        /// <summary>
        /// вызов отрисовки т-квадрата
        /// </summary>
        private void TFractal()
        {
            Clear();
            Gradient(colorList);
            fractal sq = new TSquare(Color.Black, Color.Black, depth, pictureBox1.Size);
            sq.Draw(center, center, ref gr, colorList, myPen, (pictureBox1.Height / 2 - pictureBox1.Height / 10) * koef);
            pictureBox1.Image = map;
        }

        /// <summary>
        /// вызов отрисовки кругового фрактала
        /// </summary>
        private void CircleFractal()
        {
            Clear();
            Gradient(colorList);
            fractal cf = new CircleFractal(Color.Black, Color.Black, depth, pictureBox1.Size);
            cf.Draw(center, center, ref gr, colorList, myPen, (pictureBox1.Height - pictureBox1.Height / 5) * koef);
            pictureBox1.Image = map;
        }

        /// <summary>
        /// вызов отрисовки с-кривой леви
        /// </summary>
        private void CFractal()
        {
            Clear();
            Gradient(colorList);
            fractal cl = new CLevi(Color.Black, Color.Black, depth, pictureBox1.Size);
            PointF A = new PointF(center.X, center.Y + pictureBox1.Width / 6);
            cl.Draw(center, A, ref gr, colorList, myPen, (pictureBox1.Height / 2 - pictureBox1.Height / 10) * koef);
            pictureBox1.Image = map;
        }

        /// <summary>
        ///  событие дмижения мыши, перерисовывающее фрактал
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                DoubleBuffered = true;
                center.X = nowcenter.X - mousePos.X + MousePosition.X;
                center.Y = nowcenter.Y - mousePos.Y + MousePosition.Y;
                CheckDepth();
            }
        }

        /// <summary>
        /// событие изменения коэффициента приближения 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            koef = int.Parse(comboBox1.Text);
        }

        // события нажатия на кнопку вызывают колор диалог, где мы выбираем цвета
        private void button1_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            button1.ForeColor = colorDialog1.Color;//красим буквы
            button1.BackColor = colorDialog1.Color;//красим кнопку
        }

        private void button3_Click(object sender, EventArgs e)
        {
            colorDialog2.ShowDialog();
            button3.ForeColor = colorDialog2.Color;//красим буквы
            button3.BackColor = colorDialog2.Color;//красим кнопку
        }

        /// <summary>
        /// функция создания градиента в массиве цветов по начальному и конечному цвету
        /// </summary>
        /// <param name="colorList"></param>
        public void Gradient(List<Color> colorList)
        {
            colorList.Clear();
            int rMin = colorDialog1.Color.R;
            int gMin = colorDialog1.Color.G;
            int bMin = colorDialog1.Color.B;
            int argMin = colorDialog1.Color.ToArgb();

            if (argMin == 0)
            {
                argMin = defaultColor.ToArgb();
            }
            int rMax = colorDialog2.Color.R;
            int gMax = colorDialog2.Color.G;
            int bMax = colorDialog2.Color.B;
            int argMax = colorDialog2.Color.ToArgb();

            if (argMax == 0)
            {
                argMax = defaultColor.ToArgb();
            }
            for (int i = 0; i <= depth; i++)
            {
                var rAverage = rMin + ((rMax - rMin) * i / depth);
                var gAverage = gMin + ((gMax - gMin) * i / depth);
                var bAverage = bMin + ((bMax - bMin) * i / depth);
                colorList.Add(Color.FromArgb(rAverage, gAverage, bAverage));
            }
        }

        /// <summary>
        /// сохранение изображения в формате .jpg
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button4_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.ShowDialog();
            string filename = save.FileName + ".jpg";
            map.Save(filename, System.Drawing.Imaging.ImageFormat.Jpeg);
        }

        /// <summary>
        /// изменение размера формы с последующей перерисовкой фрактала
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            try
            {
                map = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                gr = Graphics.FromImage(map);
            }
            catch (ArgumentException ext)
            {
                MessageBox.Show(ext.Message, "Exception");
                return;
            }
            if (depth != 0)
                CheckDepth();
        }

        /// <summary>
        /// событие нажатия мыши для перемещения изображения 
        /// запоминаем где нажали и где был центр
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            mousePos = MousePosition;
            nowcenter = center;
        }
    }
}