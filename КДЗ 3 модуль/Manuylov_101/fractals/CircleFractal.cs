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
    class CircleFractal : fractal
    {
        // конструктор от родительского класса
        public CircleFractal(Color startColor, Color endColor, int depth, Size pictureBoxSize)
            : base(startColor, endColor, depth, pictureBoxSize) { }


        // size  используем как радиус
        public override void Draw(PointF center, PointF A, ref Graphics gr, List<Color> colorList, Pen pn, float size)
        {
            pn.Color = colorList[depthscore];
            if (depthscore == depth - 1)
            {
                //pn.Color = colorList[(int)colorList.LongCount() - 1];
                gr.DrawEllipse(pn, center.X - size / 2, center.Y - size / 2, size, size);
                return;
            }

            float d = size / 3; //Вспомогательная переменная, треть радиуса исходной окружности
            PointF[] M = new PointF[7];  //Координаты центров порожденных окружностей

            for (int i = 0; i < 7; i++)
            {
                M[i] = new PointF();
            }

            M[0].X = center.X;
            M[0].Y = center.Y;

            M[1].X = center.X;
            M[1].Y = center.Y - d;

            M[2].X = center.X;
            M[2].Y = center.Y + d;

            M[3].X = (float)(- (M[1].Y - center.Y) * Math.Sin(Math.PI / 3) + center.X);
            M[3].Y = (float)(+ (M[1].Y - center.Y) * Math.Cos(Math.PI / 3) + center.Y);

            M[4].X = (float)( - (M[1].Y - center.Y) * Math.Sin(-Math.PI / 3) + center.X);
            M[4].Y = (float)( + (M[1].Y - center.Y) * Math.Cos(-Math.PI / 3) + center.Y);

            M[5].X = (float)(- (M[2].Y - center.Y) * Math.Sin(Math.PI / 3) + center.X);
            M[5].Y = (float)(+ (M[2].Y - center.Y) * Math.Cos(Math.PI / 3) + center.Y);
                             
            M[6].X = (float)( - (M[2].Y - center.Y) * Math.Sin(-Math.PI / 3) + center.X);
            M[6].Y = (float)( + (M[2].Y - center.Y) * Math.Cos(-Math.PI / 3) + center.Y);

            for (int i = 0; i < 7; i++)
            {
                depthscore++;
                Draw(M[i], M[i], ref gr, colorList, pn, size / 3);
                depthscore--;
            }
            //Отрисовываем исходную окружность
            pn.Color = colorList[depthscore];
            gr.DrawEllipse(pn, center.X - size / 2, center.Y - size / 2, size, size);
            return;
        }
    }
}
