using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Buttonlogin_Click(object sender, EventArgs e)
    {
        string connStr = @"Data Source=(localdb)\mssqllocaldb;Initial Catalog=CollegeDB;Integrated Security=True;Pooling=False";
        string cmdText = "SELECT * FROM [User] WHERE UserName=@userName AND Password=@password ;";
        
        using (SqlConnection conn = new SqlConnection(connStr))
        {  
            using (SqlCommand cmd = new SqlCommand(cmdText,conn))
            {
                cmd.Parameters.AddWithValue("@userName",Textuser.Text);
                cmd.Parameters.AddWithValue("@password",Textpass.Text);
                conn.Open();
                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    if(reader.Read())
                    {
                        Labelmsg.Text = "Login successful";
                    }
                    else
                    {
                        Labelmsg.Text = "Login failed";
                    }
                }

            }
        }
    }
}