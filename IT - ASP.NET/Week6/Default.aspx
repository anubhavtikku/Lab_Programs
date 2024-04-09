<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:DropDownList ID="DropDownList1" runat="server"></asp:DropDownList>
        <asp:RadioButtonList ID="RadioButtonList1" runat="server"></asp:RadioButtonList>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click"/>
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        <asp:RequiredFieldValidator ControlToValidate="DropDownList1" ID="RequiredFieldValidator1" runat="server" ErrorMessage="RequiredFieldValidator"></asp:RequiredFieldValidator>
        <asp:RequiredFieldValidator ControlToValidate="RadioButtonList1" ID="RequiredFieldValidator2" runat="server" ErrorMessage="RequiredFieldValidator"></asp:RequiredFieldValidator>
        <asp:RequiredFieldValidator  ControlToValidate="TextBox1" ID="RequiredFieldValidator3" runat="server" ErrorMessage="RequiredFieldValidator"></asp:RequiredFieldValidator>
        <asp:RequiredFieldValidator ControlToValidate="TextBox3" ID="RequiredFieldValidator4" runat="server" ErrorMessage="RequiredFieldValidator"></asp:RequiredFieldValidator>
        <asp:RangeValidator MinimumValue="6" MaximumValue="12" ControlToValidate="TextBox1" ID="RangeValidator1" runat="server" ErrorMessage="RangeValidator"></asp:RangeValidator>
        <asp:RegularExpressionValidator ValidationExpression=".+@.+" ControlToValidate="TextBox2" ID="RegularExpressionValidator1" runat="server" ErrorMessage="RegularExpressionValidator"></asp:RegularExpressionValidator>
        <asp:CustomValidator OnServerValidate="CustomValidator1_ServerValidate" ControlToValidate="TextBox3" ID="CustomValidator1" runat="server" ErrorMessage="CustomValidator"></asp:CustomValidator>
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
    </div>
    </form>
</body>
</html>
