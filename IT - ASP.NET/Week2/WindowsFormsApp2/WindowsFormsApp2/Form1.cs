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
        public Form1()
        {
            InitializeComponent();
            comboBox1.Items.Add("Car 1");
            comboBox1.Items.Add("Car 2");
            comboBox1.Items.Add("Car 3");
            comboBox1.Items.Add("Car 4");
            comboBox2.Items.Add("Red");
            comboBox2.Items.Add("Blue");
            comboBox2.Items.Add("White");
            listBox1.Items.Add("Model 1.0");
            listBox1.Items.Add("Model 2.0");

        }

        private void purchase_click(object sender, EventArgs e)
        {
            MessageBox.Show("Thank you for purchasing.");
        }

        private void click_cancel(object sender, EventArgs e)
        {
            textBox1.Text = "";
            comboBox1.Text = "";
            comboBox1.SelectedItem = null;
            comboBox2.SelectedItem = null;
            listBox1.SelectedItem = null;

        }
    }
}
