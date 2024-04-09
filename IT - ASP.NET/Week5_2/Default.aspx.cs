using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {   if (!IsPostBack)
        {
            dropdownlist1.Items.Add("Honda");
            dropdownlist1.Items.Add("Maruti");
            dropdownlist1.Items.Add("Ford");
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        string url = "Default2.aspx?";
        url += "item=" + dropdownlist1.SelectedItem.Text;
        Response.Redirect(url);
    }
}