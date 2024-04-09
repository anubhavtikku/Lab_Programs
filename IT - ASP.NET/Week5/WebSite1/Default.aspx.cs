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
        cookie = Request.Cookies["GroupName"];
        if (cookie == null)
        {
            cookie = new HttpCookie("GroupName");
        }
        else
        {
            txtname.Text =cookie["Key1"];
        }
    }

    protected void btnSaveCookie_Click(object sender, EventArgs e)
    {
        cookie["Key1"] = txtname.Text;
        cookie.Expires = DateTime.Now.AddYears(1);
        Response.Cookies.Add(cookie);
        Response.Redirect("Default2.aspx");
    }
}