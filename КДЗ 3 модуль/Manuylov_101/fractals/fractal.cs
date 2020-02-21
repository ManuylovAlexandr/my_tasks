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
    public class fractal
    {
        //public float leng; // коэфициент увеличения
        protected Color startColor; // начальный цвет
        protected Color endColor; // конечный цвет
        protected int depthscore; // счетчик рекурсии
        public int depth; // глубина рекурсии
        protected Size pictureBoxSize;

        /// <summary>
        /// конструктор класса фрактала
        /// </summary>
        /// <param name="startColor"></param>
        /// <param name="endColor"></param>
        /// <param name="depthmax"></param>
        /// <param name="leng"></param>
        public fractal(Color startColor, Color endColor, int depth, Size pictureBoxSize)
        {
            this.startColor = startColor;
            this.endColor = endColor;
            this.depth = depth;
            this.depthscore = 0;
            this.pictureBoxSize = pictureBoxSize;
        }

        //переопределим в классе конкрeтного фрактала функция отрисовки
        public virtual void Draw(PointF center, PointF A, ref Graphics gr, List<Color> colorList, Pen pen, float size) { }
    }
}