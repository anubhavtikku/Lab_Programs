<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        Company Search: <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <br />
        NEW NAME<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <br />
        NEW COMPANY <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
        <br />
        NEW SAL <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
        <br />
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" />
    </div>
    </form>
</body>
</html>
