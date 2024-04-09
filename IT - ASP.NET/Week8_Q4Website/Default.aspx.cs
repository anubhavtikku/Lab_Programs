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

    protected void Button1_Click(object sender, EventArgs e)
    {
        string connStr = @"Data Source=(localdb)\mssqllocaldb;Initial Catalog=Q4;Integrated Security=True;Pooling=False";
        string cmdInsertText = "INSERT INTO WORKS VALUES (@NAME, @COMPANY, @SALARY)";
        string cmdRetrieveText = "SELECT L.NAME, L.CITY FROM WORKS W, LIVES L WHERE W.COMPANY = @comp AND L.NAME = W.NAME";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(cmdRetrieveText, conn))
            {
                cmd.Parameters.AddWithValue("@comp", TextBox2.Text);
                conn.Open();
                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    while (reader.Read()) {
                        
                    }
                    /*
                    if (reader.Read())
                    {
                        //Labelmsg.Text = "Login successful";
                    }
                    else
                    {
                        Labelmsg.Text = "Login failed";
                    }
                    */
                }
                conn.Close();

            }
        }
    }
}