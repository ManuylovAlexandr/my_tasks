using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlHomework
{
    internal class College
    {
        public College(string number, string name, string address, Area zone, string formOfIncorporation,
            string submission, string tipUchrezhdeniya, string vidUchrezhdeniya, string telephone,
            string webSite, string eMmail, string x, string y, string globalID)
        {
            Number = number;
            Name = name;
            Zone = zone;
            Address = address;
            FormOfIncorporation = formOfIncorporation;
            Submission = submission;
            TipUchrezhdeniya = tipUchrezhdeniya;
            VidUchrezhdeniya = vidUchrezhdeniya;
            Telephone = telephone;
            WebSite = webSite;
            EMmail = eMmail;
            X = x;
            Y = y;
            GlobalID = globalID;
        }

        public string Number { get; set; }
        public string Name { get; set; }
        public Area Zone { get; set; }
        public string Address { get; set; }
        public string FormOfIncorporation { get; set; }
        public string Submission { get; set; }
        public string TipUchrezhdeniya { get; set; }
        public string VidUchrezhdeniya { get; set; }
        public string Telephone { get; set; }
        public string WebSite { get; set; }
        public string EMmail { get; set; }
        public string X { get; set; }
        public string Y { get; set; }
        public string GlobalID { get; set; }

        public bool IsCollegeState()
        {
            return FormOfIncorporation == "Государственное" ? true : false;
        }

    }
}
