using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
	    MasterPage m = (MasterPage)Page.Master;
            HyperLink hl = (HyperLink)m.FindControl("HyperLink1");
            hl.Text = "";

    }
    protected void Page_PreInit(Object sender,EventArgs e)
    {
        HttpCookie cookie = Request.Cookies["Themes"];
        if (cookie == null)
        {
            Page.Theme ="Day";
        }
        else
        {
            Page.Theme = cookie["Theme"];
        }
        
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string authText = "select * from Users where Name=@uname and Password=@pass and Isadmin=1 ";
        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {
                cmd.Parameters.AddWithValue("@uname", AdminID.Text);
                cmd.Parameters.AddWithValue("@pass", AdminPass.Text);
                conn.Open();



                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        Response.Redirect("AdminDashboard.aspx?user=admin");
                        
                    }
                    else
                    {
                        Error.Text = "User not Registered";
                    }
                }
            }
        }
    }


    protected void Button1_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string authText = "select * from Users where Name=@uname and Password=@pass and Isadmin=0 ";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {
                cmd.Parameters.AddWithValue("@uname", UserID.Text);
                cmd.Parameters.AddWithValue("@pass", Password.Text);
                conn.Open();



                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    if (reader.Read())
                    {
                       
                        Session["username"] = UserID.Text;
                        Response.Redirect("UserDashboard.aspx");
                       
                    }
                    else
                    {
                        Error.Text = "User not Registered";
                    }

                }

            }
        }
    }
}