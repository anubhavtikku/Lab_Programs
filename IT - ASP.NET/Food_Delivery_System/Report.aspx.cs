using System;
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default5 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            List<string> cuisines = (List<string>)Session["Cuisine"];
            List<string> locations = (List<string>)Session["Location"];
            int rating = Convert.ToInt32(Request.QueryString["rating"]);
            string reportQuery = "select Name,Cuisine,Location,RATING from Restaurant";
            string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
            DataSet ds = new DataSet();
            using (SqlConnection conn = new SqlConnection(connStr))
            {
                using (SqlCommand cmd = new SqlCommand(reportQuery, conn))
                {
                    
                    conn.Open();
                    using (SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                    {
                        adapter.Fill(ds, "S");
                    }
                }
            }
            DataTable dt = new DataTable();
            dt.Columns.Add("Name");
            dt.Columns.Add("Cuisine");
            dt.Columns.Add("Location");
            dt.Columns.Add("RATING");
            
            foreach (DataRow dr in ds.Tables[0].Rows)
                 {
                     if (cuisines.Contains(dr["Cuisine"]) && locations.Contains(dr["Location"]) && (Convert.ToInt32(dr["RATING"]) >= rating))
                     {
                    
                    dt.ImportRow(dr);

                     }

                 }
                 GridView1.DataSource = dt;
                 GridView1.DataBind();
             
           
        }

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
}