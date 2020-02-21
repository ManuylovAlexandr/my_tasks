using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlHomework
{
    class Area
    {
        public Area(string okrug, string rayon)
        {
            Okrug = okrug;
            Rayon = rayon;
        }

        public string Okrug { get; set; }
        public string Rayon { get; set; } 
    }
}
