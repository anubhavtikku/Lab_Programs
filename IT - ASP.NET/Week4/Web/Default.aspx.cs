using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            foreach (var font in FontFamily.Families)
            {
                ddlfont.Items.Add(font.Name);
            }
        }
    }

    protected void ddlfont_SelectedIndexChanged(object sender, EventArgs e)
    {
        string font =ddlfont.Items[ddlfont.SelectedIndex].ToString();
        lblHeading.Font.Name = font;
    }

    protected void BtnPreview_Click(object sender, EventArgs e)
    {
        string font = ddlfont.Items[ddlfont.SelectedIndex].ToString();
        lblHeading.Font.Name = font;

        //lblHeading.ForeColor =ColorTranslator.FromHtml(Color.Red);
        PnlDisplay.BorderColor = Color.Blue;
        PnlDisplay.BorderColor = Color.FromArgb(100, 100, 100, 100);
    }
}