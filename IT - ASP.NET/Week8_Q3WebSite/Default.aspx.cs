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

        string connStr = @"Data Source=(localdb)\mssqllocaldb;Initial Catalog=Products;Integrated Security=True;Pooling=False";
        string cmdText = "UPDATE [ITEMS] SET PRICE=@price WHERE FLAVOR='Vanilla' ;";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(cmdText, conn))
            {
                cmd.Parameters.AddWithValue("@price", TextBox1.Text);

                conn.Open();
                /*using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        Label1.Text = "Updated";
                    }
  
                }*/
                int res = cmd.ExecuteNonQuery();
                TextBox1.Text = res.ToString();
                if (res >= 1)
                    Label1.Text = "Updated Successfully";
                else
                    Label1.Text = "Update Failed";
                conn.Close();

            }
        }
    }
}