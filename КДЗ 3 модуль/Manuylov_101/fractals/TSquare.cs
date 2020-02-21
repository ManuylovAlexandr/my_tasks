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
    class TSquare : fractal
    {
        // конструктор от родительского класса
        public TSquare(Color startColor, Color endColor, int depth, Size pictureBoxSize) 
            : base(startColor, endColor, depth, pictureBoxSize){ }
        
        /// <summary>
        /// переопределенный метод отрисовки
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="gr"></param>
        /// <param name="colorList"></param>
        /// <param name="pn"></param>
        public override void Draw(PointF center, PointF A, ref Graphics gr, List<Color> colorList, Pen pn, float size)
        {
            SolidBrush br = new SolidBrush(colorList[(int)colorList.LongCount() - 1]);
            if (depthscore == 0)
            {
                center = new PointF(center.X - size / 2, center.Y - size / 2);
            }
            //Рекурсивная функция отрисовки фрактала
            //size - длина стороны

            //База рекурсии
            //Если итерация одна, просто рисуем заполненный прямоугольник
            if (depthscore == depth - 1)
            {
                gr.FillRectangle(br, center.X, center.Y, size, size);
                return;
            }

            float d = size / 4; //Вспомогательная переменная, четверть длины исходного квадрата
            PointF[] M = new PointF[4];  //Координаты левых верхних углов порожденных квадратов

            for (int i = 0; i < 4; i++)
            {
                M[i] = new PointF();
            }

            //Левый верхний квадрат
            M[0].X = center.X - d;
            M[0].Y = center.Y - d;

            //Левый нижний квадрат
            M[1].X = center.X - d;
            M[1].Y = center.Y + size - d;

            //Правый верхний квадрат
            M[2].X = center.X + size - d;
            M[2].Y = center.Y - d;

            //Правый нижний квадрат
            M[3].X = center.X + size - d;
            M[3].Y = center.Y + size - d;

            //Вызываем рекурсивно для каждого квадрата
            for (int i = 0; i < 4; i++)
            {
                depthscore++;
                Draw(M[i], M[i], ref gr, colorList, pn, size / 2);
                depthscore--;
            }
            // меняем цвет кисти в зависимости от глубины рекурсии
            br = new SolidBrush(colorList[depthscore]); 

            //Отрисовываем исходный квадрат
            gr.FillRectangle(br, center.X, center.Y, size, size);
            return;
        }
    }
}
