<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body >
    <form id="form1" runat="server">
    <div>
        <asp:DropDownList ID="llthemes" runat="server"></asp:DropDownList>
        <asp:Button ID="Button1" runat="server" Text="Trial1" />
        <asp:Button ID="Button2" runat="server" Text="Trial2"/>
        <br />
        <asp:Button ID="Button3" runat="server" Text="Change Theme" OnClick="Button3_Click" />
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    </div>
    </form>
</body>
</html>
