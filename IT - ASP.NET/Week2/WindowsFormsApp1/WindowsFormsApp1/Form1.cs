using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox1.Items.Add("Level 1");
            comboBox1.Items.Add("Level 2-4");
            comboBox1.Items.Add("Level 5-7");
            comboBox1.Items.Add("Level 8-10");

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double salary = Convert.ToDouble(textBox1.Text);
            double level=0;
            if (comboBox1.SelectedIndex == 0)
                level = 0.1;
            else if (comboBox1.SelectedIndex == 1)
                level = 0.09;
            else if (comboBox1.SelectedIndex == 2)
                level = 0.07;
            else if (comboBox1.SelectedIndex == 3)
                level = 0.05;
            double bonus=salary*level;
            MessageBox.Show("Bonus is "+bonus);
            
        }

    }
}
