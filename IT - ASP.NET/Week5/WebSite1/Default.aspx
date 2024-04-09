<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
<asp:textbox ID="txtname" runat="server"></asp:textbox>
<asp:button ID="btnSaveCookie" runat="server" text="Save Cookie" OnClick="btnSaveCookie_Click"/>    
    </div>
    </form>
</body>
</html>
