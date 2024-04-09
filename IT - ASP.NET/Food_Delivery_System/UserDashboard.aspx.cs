using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;

public partial class Default3 : System.Web.UI.Page
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
        Label1.Text = "Welcome " + Session["username"];
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string authText = "select * from Restaurant";


        if(!IsPostBack)
        for(int i = 1; i <= 5;i++)
        {
            ddlRating.Items.Add(i.ToString());
        }
        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {

                conn.Open();

                SqlDataAdapter da = new SqlDataAdapter(authText, conn);


                DataSet ds = new DataSet();

                da.Fill(ds);

                GridView1.DataSource = ds;
                GridView1.DataBind();
                if (!IsPostBack) { 
                foreach(DataRow dr in ds.Tables[0].Rows)
                {
                    ddlNames.Items.Add(dr["Name"].ToString());
                    ddlComments.Items.Add(dr["Name"].ToString());
                }
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
    protected void btnFilter_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string authText;
        string updateText;
        string[] names = { "Name","Cuisine","Location","RATING" };
        if (ddlFilter.SelectedIndex < 3)
        {
            authText = "select * from Restaurant where " + names[ddlFilter.SelectedIndex]+" like" + "'" + nameFilter.Text + "%'";
            updateText = "update Restaurant set Views=Views+1 where " + names[ddlFilter.SelectedIndex] + "=" + "'" + nameFilter.Text + "'";
        }
        else
        {
            authText = "select * from Restaurant where " + names[ddlFilter.SelectedIndex] + ">=" + nameFilter.Text;
            updateText = "update Restaurant set Views=Views+1 where " + names[ddlFilter.SelectedIndex] + "=" + nameFilter.Text;
        }
            using (SqlConnection conn = new SqlConnection(connStr))
        {
            using(SqlCommand cmd = new SqlCommand(updateText, conn))
            {
                conn.Open();
                cmd.ExecuteNonQuery();
                conn.Close();
            }
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {
                
                conn.Open();

                SqlDataAdapter da = new SqlDataAdapter(authText, conn);


                DataSet ds = new DataSet();

                da.Fill(ds);

                GridView1.DataSource = ds;
                GridView1.DataBind();
            }
        }
    }

    protected void btnRate_Click(object sender, EventArgs e)
    {
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        
        string authText = "update Restaurant set RATING=ROUND(0.9*RATING+ @rate,2)  where Name=@resname";
        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {

                cmd.Parameters.AddWithValue("@rate", 0.1 * Convert.ToInt32(ddlRating.SelectedValue));
                cmd.Parameters.AddWithValue("@resname", ddlNames.SelectedValue);
                conn.Open();
                cmd.ExecuteNonQuery();

            }
        }
        ddlNames.Items.Remove(ddlNames.SelectedValue);

        authText = "select * from Restaurant";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(authText, conn))
            {

                conn.Open();

                SqlDataAdapter da = new SqlDataAdapter(authText, conn);


                DataSet ds = new DataSet();

                da.Fill(ds);

                GridView1.DataSource = ds;
                GridView1.DataBind();
                if (!IsPostBack)
                {
                    foreach (DataRow dr in ds.Tables[0].Rows)
                    {
                        ddlNames.Items.Add(dr["Name"].ToString());
                        ddlComments.Items.Add(dr["Name"].ToString());
                    }

                }
            }
        }
    }

    protected void btnComment_Click(object sender, EventArgs e)
    {
        string commentId = Session["username"].ToString() + ":"+comments.Text;
        string connStr = ConfigurationManager.ConnectionStrings["FoodDeliveryConnectionString"].ToString();
        string cmdInsertText = "insert into Comments(Id,Username,Restaurantname,commentText,isApproved) values(@Id,@user,@restname,@CommentText,0)";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            using (SqlCommand cmd = new SqlCommand(cmdInsertText, conn))
            {
                cmd.Parameters.AddWithValue("@Id", commentId);
                cmd.Parameters.AddWithValue("@user", Session["username"].ToString());
                cmd.Parameters.AddWithValue("@restname", ddlComments.SelectedValue);
                cmd.Parameters.AddWithValue("@commentText",comments.Text);
                conn.Open();
                cmd.ExecuteNonQuery();
            }
        }
        ddlComments.Items.Remove(ddlComments.SelectedValue);

    }
}