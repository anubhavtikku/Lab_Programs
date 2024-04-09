using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Page_PreInit(Object sender, EventArgs e)
    {
        HttpCookie cookie = Request.Cookies["Themes"];
        if (cookie == null)
        {
            Page.Theme = "Day";
        }
        else
        {
            Page.Theme = cookie["Theme"];
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string cmdInsertText = "insert into Users(Name,Password,Isadmin) values(@NAME, @PASSWORD,0)";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(cmdInsertText, conn))
            {
                cmd.Parameters.AddWithValue("@NAME", Username.Text);
                cmd.Parameters.AddWithValue("@PASSWORD", Password.Text);
                conn.Open();
                cmd.ExecuteNonQuery();
                

                
            }
        }
        regLabel.Text = "User Created Succesffuly.";

    }
}