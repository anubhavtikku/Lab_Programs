<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    UserName:<asp:TextBox ID="Textuser" runat="server"></asp:TextBox>
    Password<asp:TextBox ID="Textpass" runat="server"></asp:TextBox>
    <br />
    <asp:Button ID="Buttonlogin" runat="server" Text="LOGIN" OnClick="Buttonlogin_Click"/>
    <asp:Label ID="Labelmsg" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>
