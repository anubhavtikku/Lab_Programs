using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class MasterPage : System.Web.UI.MasterPage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        HttpCookie cookie = Request.Cookies["Themes"];
        if (cookie == null)
        {
            cookie = new HttpCookie("Themes");
            cookie["Theme"] = "Day";
            cookie.Expires = DateTime.Today.AddDays(10);
            Response.Cookies.Add(cookie);
            
        }
        else
        {
            if (cookie["Theme"].ToString() == "Night")
            {
                cookie["Theme"] = "Day";
                
            }
            else
            {
                cookie["Theme"] = "Night";
                
            }
            cookie.Expires = DateTime.Today.AddDays(10);
            Response.Cookies.Add(cookie);
        }
        Server.Transfer(Request.FilePath);
    }
}
