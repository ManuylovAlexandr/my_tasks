using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Курсач
{
    public partial class browser : Form
    {
        string client_id = "5906178";
        public string accessToken;
        public string userId;

        public browser()
        {
            InitializeComponent();
            string address = $"https://oauth.vk.com/authorize?client_id={client_id}&display=popup&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=token&v=5.52&revoke=1";
            webBrowser1.Navigate(address);
            Size = webBrowser1.ClientSize;
        }

        public void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            
            if (e.Url.ToString().IndexOf("access_token") != -1)
            {
                Regex myReg = new Regex(@"(?<name>[\w\d\x5f]+)=(?<value>[^\x26\s]+)", RegexOptions.IgnoreCase | RegexOptions.Singleline);
                foreach (Match m in myReg.Matches(e.Url.ToString()))
                {
                    if (m.Groups["name"].Value == "access_token")
                    {
                        accessToken = m.Groups["value"].Value;
                    }
                    else if (m.Groups["name"].Value == "user_id")
                    {
                        userId = m.Groups["value"].Value;
                    }
                }
                if (String.IsNullOrEmpty(accessToken))
                {
                    MessageBox.Show("Ошибка. Ключ доступа не найден.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            if (userId != null && accessToken != null)
                this.Close();

        }
    }
}
