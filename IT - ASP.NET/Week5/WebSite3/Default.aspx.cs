using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["Login"] == null)
        {
            Session["Login"] = 0;
        }
        else if (Convert.ToInt32(Session["Login"]) >= 3)
        {
            TextBox1.Enabled = false;
            TextBox2.Enabled = false;
            Button1.Enabled = false;
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        if (TextBox1.Text != "HACKERMAN" || TextBox2.Text != "PACKMAN")
        {
            Session["Login"] = Convert.ToInt32(Session["Login"].ToString()) + 1;
            Label1.Text = "Incorrect password ";

        }
        else
        {
            Label1.Text = "Success";
        }


    }
}