
<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ValidationGroup="CheckUsername"   Display="Dynamic" ControlToValidate="TextBox1" ID="RequiredFieldValidator1" Text="*" ForeColor="Red" runat="server" ErrorMessage="Invalid Text"></asp:RequiredFieldValidator>
        <asp:Button ID="Button1" runat="server" ValidationGroup="CheckUsername" Text="Button" OnClick="Button1_Click"/>
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <asp:CompareValidator Enabled="false" ID="CompareValidator1" ControlToValidate="TextBox2" runat="server" ErrorMessage="Values don't match" ControlToCompare="TextBox1" ></asp:CompareValidator>
        <asp:RegularExpressionValidator Enabled="false" ID="RegularExpressionValidator1" runat="server" ErrorMessage="RegularExpressionValidator" ControlToValidate="TextBox2" ValidationExpression="\d{4}"></asp:RegularExpressionValidator>    
        <asp:CustomValidator ID="CustomValidator1" runat="server" OnServerValidate="CustomValidator1_ServerValidate" ErrorMessage="CustomValidator"></asp:CustomValidator>
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
        <asp:Button ID="Button2" runat="server" Text="Button" CausesValidation="false" />
    </div>
    </form>
</body>
</html>
