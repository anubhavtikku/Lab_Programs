<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Panel ID="PnlSettings" runat="server" style="float:left">
        <asp:DropDownList ID="ddlfont" runat="server" OnSelectedIndexChanged="ddlfont_SelectedIndexChanged"></asp:DropDownList><br />
        <asp:DropDownList ID="ddlcolor" runat="server">
        <asp:ListItem>Red</asp:ListItem>
        <asp:ListItem>Yellow</asp:ListItem>
        </asp:DropDownList>
            <asp:Button ID="lblHeading" runat="server" Text="Preview" OnClick="BtnPreview_Click" />
        </asp:Panel>
        <asp:Panel ID="PnlDisplay" runat="server" border>
        <asp:Label ID="Label1" runat="server" Text="Default"></asp:Label>
        </asp:Panel>
    </div>
    </form>
</body>
</html>
