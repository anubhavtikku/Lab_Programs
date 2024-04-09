using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            if (!IsPostBack)
            {
                DropDownList1.Items.Add(new ListItem("Red", "#FF0000"));
                DropDownList1.Items.Add(new ListItem("Blue", "#2C8FDB"));
                DropDownList1.Items.Add(new ListItem("Green", "#2EF241"));
            }
        }

        protected void generate_cover(object sender, EventArgs e)
        {
            string x =DropDownList1.Items[DropDownList1.SelectedIndex].Value;
            cover.BackColor = System.Drawing.ColorTranslator.FromHtml(x);
        }
    }
}