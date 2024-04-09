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

    }


    protected void Button1_Click(object sender, EventArgs e)
    {
        //RequiredFieldValidator1.IsValid
        // if(Page.IsValid)
        // { }

        if (TextBox1.Text == String.Empty)
        {
            Label1.Text = "Invalid Text";
        }
    }

    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
    {
        if (TextBox1.Text == String.Empty && TextBox2.Text == String.Empty)
        {
            args.IsValid = false;
        }
        else
        {
            args.IsValid = true;
        }
    }
}