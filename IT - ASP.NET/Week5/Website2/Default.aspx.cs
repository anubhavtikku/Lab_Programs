using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    HttpCookie cookie;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            Label1.Text = "Welcome";
        }
      

        cookie = Request.Cookies["Preferences"];
        Console.WriteLine(cookie);
        if (cookie == null)
        {
            cookie = new HttpCookie("Preferences");
            cookie.Expires = DateTime.Now.AddDays(1);
        }
        else
        {
            Label1.Text = "Welcome "+ cookie["Name"];
            TextBox1.Text=cookie["Name"];
            TextBox2.Text= cookie["List"] ;
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        cookie["Name"]=TextBox1.Text;
        Label1.Text = "Welcome " + cookie["Name"];
        cookie["List"] = TextBox2.Text;
        Response.Cookies.Add(cookie);
    }
}