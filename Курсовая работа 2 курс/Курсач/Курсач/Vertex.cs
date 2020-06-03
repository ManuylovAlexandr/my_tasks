using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;

namespace Курсач
{
    class Vertex
    {
        public PointF Coord;
        public Vertex(string iD, PointF coord, string[] com_vert)
        {
            ID = iD;
            Coord = coord;
            Common_Vertexes = com_vert;
            Group = iD;
        }
        public string[] Common_Vertexes { get; }
        public string ID { get; }
        public string Group { get; set; }
        public bool IsPicked { get; set; }

        public bool IsVertexCommon(Vertex v)
        {
            if (this.Common_Vertexes.Contains(v.ID)) return true;
            return false;
        }
    }

    class Edge
    {
        public Vertex V1, V2;
        public Edge(Vertex v1, Vertex v2)
        {
            V1 = v1;
            V2 = v2;
        }

        public bool IsVertexPicked()
        {
            if (V1.IsPicked || V2.IsPicked) return true;
            return false;
        }
    }
}
