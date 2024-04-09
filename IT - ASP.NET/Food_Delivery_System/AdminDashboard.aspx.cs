using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default4 : System.Web.UI.Page
{
    string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
    string viewText = "select * from Comments";
    string authText = "select * from Restaurant";
    protected void Page_Load(object sender, EventArgs e)
    {
        Label1.Text = "Welcome " + Session["username"];
        if (!IsPostBack)
        {
            using (SqlConnection conn = new SqlConnection(connStr))
            {
                using (SqlCommand cmd = new SqlCommand(viewText, conn))
                {

                    conn.Open();

                    SqlDataAdapter da = new SqlDataAdapter(viewText, conn);


                    DataSet ds = new DataSet();

                    da.Fill(ds);

                    commentsGrid.DataSource = ds;
                    commentsGrid.DataBind();
                }
            }

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                using (SqlCommand cmd = new SqlCommand(authText, conn))
                {

                    conn.Open();

                    SqlDataAdapter da = new SqlDataAdapter(authText, conn);


                    DataSet ds = new DataSet();

                    da.Fill(ds);


                    List<string> cuisines = new List<string>();
                    List<string> locations = new List<string>();
                    foreach (DataRow dr in ds.Tables[0].Rows)
                    {
                        ddlInfo.Items.Add(dr["Name"].ToString());
                        if (!cuisines.Contains(dr["Cuisine"]))
                        {
                            cuisines.Add(dr["Cuisine"].ToString());
                        }
                        if (!locations.Contains(dr["Location"]))
                        {
                            locations.Add(dr["Location"].ToString());
                        }
                    }
                    cuisineList.DataSource = cuisines;
                    locationList.DataSource = locations;
                    this.DataBind();



                }
            }
            




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
    protected void btnAddRestaurant_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string cmdInsertText = "insert into Restaurant(Name,Cuisine,Location,RATING,COMMENTS,Views) values(@name,@cuisine,@location,0,' ',0)";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(cmdInsertText, conn))
            {
                cmd.Parameters.AddWithValue("@name", nameText.Text);
                cmd.Parameters.AddWithValue("@cuisine", cuisineText.Text);
                cmd.Parameters.AddWithValue("@location", locationText.Text);
                conn.Open();
                cmd.ExecuteNonQuery();
            }
        }
            }

    protected void commentsGrid_RowCommand(object sender, GridViewCommandEventArgs e)
    {
        if (e.CommandName == "Accept")
        {
            int index = Convert.ToInt32(e.CommandArgument);
            GridViewRow row = commentsGrid.Rows[index];
            commentsGrid.Rows[index].Enabled =false;
            string restname= row.Cells[1].Text;
            string commentText = row.Cells[2].Text;
            string username = row.Cells[0].Text;
            
            string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
            string cmdInsertText = "update Restaurant set COMMENTS=COMMENTS+@comment where Name=@resname";
            string delText = "delete from Comments where Restaurantname=@rn and Username=@un and commentText=@ct";
            using (SqlConnection conn = new SqlConnection(connStr))
            {
                using (SqlCommand cmd = new SqlCommand(cmdInsertText, conn))
                {
                    cmd.Parameters.AddWithValue("@comment", username + ":"+commentText+" ");
                    cmd.Parameters.AddWithValue("@resname", restname);
                    
                    conn.Open();
                    cmd.ExecuteNonQuery();
                }
                using(SqlCommand cmd = new SqlCommand(delText, conn))
                {
                    cmd.Parameters.AddWithValue("@rn",restname);
                    cmd.Parameters.AddWithValue("@un",username);
                    cmd.Parameters.AddWithValue("@ct",commentText);
                    
                    cmd.ExecuteNonQuery();
                }
            }

        }
        else if (e.CommandName == "Reject")
        {
            int index = Convert.ToInt32(e.CommandArgument);
            GridViewRow row = commentsGrid.Rows[index];
            string restname = row.Cells[1].Text;
            string commentText = row.Cells[2].Text;
            string username = row.Cells[0].Text;
            commentsGrid.Rows[index].Enabled = false;
            
            string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
            string delText = "delete from Comments where Restaurantname=@rn and Username=@un and commentText=@ct";
            using (SqlConnection conn = new SqlConnection(connStr))
            {
                
                using (SqlCommand cmd = new SqlCommand(delText, conn))
                {
                    cmd.Parameters.AddWithValue("@rn", restname);
                    cmd.Parameters.AddWithValue("@un", username);
                    cmd.Parameters.AddWithValue("@ct", commentText);
                    conn.Open();
                    cmd.ExecuteNonQuery();
                }
            }
        }
    }

    protected void btnInfo_Click(object sender, EventArgs e)
    {
        string authText = "select * from Restaurant where Name=@resname";
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        DataSet ds = new DataSet();
        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {
                cmd.Parameters.AddWithValue("@resname",ddlInfo.SelectedValue);
                conn.Open();
                using(SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                {
                    adapter.Fill(ds, "S");
                }
            }
        }
       
        DataRow dr =ds.Tables[0].Rows[0];
      
        infoLabel.Text = "The restaurant "+dr["Name"].ToString()+" has "+ dr["Cuisine"].ToString()+" cuisine.<br/>It is located in " + dr["Location"].ToString()+ ".<br/>It's overall rating is  " + dr["RATING"].ToString() + ".<br/>COMMENTS <br/><br/>" + dr["COMMENTS"].ToString();
     

    }

    protected void btnReport_Click(object sender, EventArgs e)
    {
        List<string> cuisines = new List<string>();
        List<string> locations = new List<string>();
        int clCount = 0, lCount = 0;
        for(int i = 0; i < cuisineList.Items.Count; i++)
        {
            if (cuisineList.Items[i].Selected)
            {
                cuisines.Add(cuisineList.Items[i].Text);
                clCount++;
            }
        }
        
        for (int i = 0; i < locationList.Items.Count; i++)
        {
            if (locationList.Items[i].Selected)
            {
                lCount++;
                locations.Add(locationList.Items[i].Text);
            }
        }
        if (clCount == 0)
        {
            validateCuisineFilter.Text = "Please Select atleast one cuisine ";
        }
        if (lCount == 0)
        {
            validateCuisineFilter.Text = "Please Select atleast one location";
        }
        if ((clCount!=0) && (lCount!=0))
        {
            Session["Cuisine"] = cuisines;
            Session["Location"] = locations;
            string queryUrl = "Report.aspx?";
            queryUrl += "rating=" + ratingList.SelectedValue;
            Response.Redirect(queryUrl);
        }
    }
}