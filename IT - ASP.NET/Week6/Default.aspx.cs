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
        if(!IsPostBack)
        {
            DropDownList1.Items.Add("ABC");
            DropDownList1.Items.Add("CAT");
            DropDownList1.Items.Add("DOG");
            RadioButtonList1.Items.Add("RED");
            RadioButtonList1.Items.Add("BLUE");
            RadioButtonList1.Items.Add("YELLOW");
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            Label1.Text = "Successfully submitted ";
        }
        else
            Label1.Text = "";

    }

    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
    {
        if(TextBox3.Text.Length==10)
        {
            args.IsValid = true;
        }
        else
            args.IsValid = false;
    }
}