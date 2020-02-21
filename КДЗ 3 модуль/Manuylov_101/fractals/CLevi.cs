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
    class CLevi : fractal
    {
        // конструктор от родительского класса
        public CLevi(Color startColor, Color endColor, int depth, Size pictureBoxSize) 
            : base(startColor, endColor, depth, pictureBoxSize){ }

        //PointF A нужна только здесь
        public override void Draw(PointF center,PointF A, ref Graphics gr, List<Color> colorList, Pen pn, float size)
        {
            pn.Color = colorList[depthscore];
            if (depthscore == 0)
            {// верхняя точка первой линии
                A = new PointF(center.X, center.Y + size / 2);
                center = new PointF(center.X, center.Y - size / 2);
            }
            if (depthscore == depth - 1)
            {
                gr.DrawLine(pn, center.X, center.Y, A.X, A.Y);
                return;
            }
            else
            {
                PointF newPoint = new PointF((center.X + A.X) / 2 - (A.Y - center.Y) / 2, 
                                            (center.Y + A.Y) / 2 + (A.X - center.X) / 2);
                depthscore++;
                Draw(center, newPoint, ref gr, colorList, pn, size);
                Draw(newPoint, A, ref gr, colorList, pn, size);
                depthscore--;
            }
            // рисуем исходную линию для градиента
            pn.Color = colorList[depthscore];
            gr.DrawLine(pn, center.X, center.Y, A.X, A.Y);
            return;
        }
    }
}