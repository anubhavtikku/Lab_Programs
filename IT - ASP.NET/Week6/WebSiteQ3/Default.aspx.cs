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
        if (!IsPostBack)
        {
            llthemes.Items.Add("Summer");

            llthemes.Items.Add("Monsoon");
        }
        

    }
    protected void Page_PreInit(object sender, EventArgs e)
    {
        if (Session["Theme"] != null)
            Page.Theme = Session["Theme"].ToString();
        else
        {
            Session["Theme"] = "Summer";
            Page.Theme = "Summer";
        }
    }

    protected void Button3_Click(object sender, EventArgs e)
    {
        Session["Theme"] = llthemes.SelectedValue;
        Label1.Text = Session["Theme"].ToString();
        Server.Transfer("Default.aspx");
        
    }
}