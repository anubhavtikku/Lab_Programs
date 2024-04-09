<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="UserDashboard.aspx.cs" Inherits="Default3" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
   <br />
    <asp:Label ID="Label1" runat="server" Text="" Font-Size="Large"></asp:Label><br /><br />
            <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="Name">
                <Columns>
                    <asp:BoundField DataField="Name" HeaderText="Name" ReadOnly="True" SortExpression="Name" />
                    <asp:BoundField DataField="Cuisine" HeaderText="Cuisine" SortExpression="Cuisine" />
                    <asp:BoundField DataField="Location" HeaderText="Location" SortExpression="Location" />
                    <asp:BoundField DataField="RATING" HeaderText="RATING" SortExpression="RATING" />
                    <asp:BoundField DataField="COMMENTS" HeaderText="COMMENTS" SortExpression="COMMENTS" />
                    <asp:BoundField DataField="Views" HeaderText="Views" SortExpression="COMMENTS" />
                </Columns>
                
            </asp:GridView>
    <asp:DropDownList ID="ddlFilter" runat="server">
                 <asp:ListItem>Name</asp:ListItem>
        <asp:ListItem>Cuisine</asp:ListItem>
        <asp:ListItem>Location</asp:ListItem>
        <asp:ListItem>Rating</asp:ListItem>
                </asp:DropDownList>
    <br />
   <asp:TextBox ID="nameFilter" runat="server"></asp:TextBox>
    
                <asp:Button id="btnFilter" runat="server" ValidationGroup="GG" Text="Filter" OnClick="btnFilter_Click" />
    <br/>
    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" ControlToValidate="nameFilter" ValidationGroup="GG" runat="server" ErrorMessage="Enter Text"></asp:RequiredFieldValidator>
    <br /> <br /><br /><br /><br />RATE RESTAURANT
    <br />
    <asp:DropDownList ID="ddlNames" runat="server"></asp:DropDownList>
    <asp:DropDownList ID="ddlRating" runat="server"></asp:DropDownList>

    <asp:Button ID="btnRate" runat="server" Text="Rate" onClick="btnRate_Click"/>
    <br /><br /><br />
    COMMENTS: <br /><br />
    <asp:DropDownList ID="ddlComments" runat="server"></asp:DropDownList>
    <asp:TextBox ID="comments"  runat="server"></asp:TextBox>
    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" ControlToValidate="comments" ValidationGroup="CC" runat="server" ErrorMessage="Enter Comments"></asp:RequiredFieldValidator>
    <asp:Button ID="btnComment" ValidationGroup="CC" runat="server" Text="Comment" onClick="btnComment_Click"/>
    
</asp:Content>

