using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {   
        static int count = 0;
        int p;
        int i;
        static int[] a=new int[3];
        public Form1()
        {
     
            InitializeComponent();
            comboBox1.Items.Add("1");
            comboBox1.Items.Add("2");
            comboBox1.Items.Add("3");
            
            for (i = 0; i < 3; i++)
            {
             
                a[i] = 0;
            }
        }

        private void btnclick(object sender, EventArgs e)
        {
            p = Convert.ToInt32(textBox2.Text);

            if (p < 75)
            {   a[comboBox1.SelectedIndex]++;
                count=a[comboBox1.SelectedIndex];

                label1.Text = "Hello World";
                
                if (count == 1)
                {
                    textBox1.BackColor = Color.Yellow;
                    label1.Text = "Warning";
                }
                if (count >= 2)
                {
                    textBox1.BackColor = Color.Red;
                    label1.Text = "Warning";
                }
            }
        }
    }
}
