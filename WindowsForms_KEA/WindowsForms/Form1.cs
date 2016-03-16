using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClassLibrary1;

namespace WindowsForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        ClassLibrary1.ListSH l = new ClassLibrary1.ListSH();

        private void Form1_Load(object sender, EventArgs e)
        {
            l.add(1);
            l.add(2);
            l.add(2);
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            
            Brush br = new SolidBrush(Color.Red);
            Font f = panel1.Font;
            int i = 0; 
            int v;
            itr it= l.getIterator(); 
            while(it.hasNext())
            {
                v = it.next();
                g.DrawString(v.ToString(), f, br, i * 20, 0);
                i++;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int v;

            try
            {
                v = Convert.ToInt32(text1.Text);

                l.add(v);

                panel1.Refresh();
                label1.Text = "OK";
            } catch(Exception ee)
            {
                label1.Text = "Error add";
            }

        }
    }
}
