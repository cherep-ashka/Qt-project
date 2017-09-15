using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;


namespace project_Csharp
{
    public partial class  Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
             Process.Start(@"D:\C#\Work_version\Custom\x64\Debug\Custom.exe", "Disloc1.txt");
        }
    }
}
