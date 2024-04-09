<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Select Background Color"></asp:Label>
            <asp:DropDownList ID="DropDownList1" runat="server"></asp:DropDownList>
       
        <asp:Label ID="message" runat="server" Text="Message"></asp:Label>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Generate" OnClick="generate_cover" />
         </div>
        <asp:Panel ID="Panel1" runat="server"></asp:Panel>
    </form>
</body>
</html>
