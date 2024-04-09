<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="AdminDashboard.aspx.cs" Inherits="Default4" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:Label ID="Label1" runat="server" Text="" Font-Size="Large"></asp:Label><br />
    CREATE RESTAURANT:
    <br /><br />
    NAME<asp:TextBox ID="nameText" runat="server"></asp:TextBox><br />
   <br />CUISINE<asp:TextBox ID="cuisineText" runat="server"></asp:TextBox><br />
   <br />LOCATION<asp:TextBox ID="locationText" runat="server"></asp:TextBox><br />
    
   <br /><asp:Button ID="btnAddRestaurant" ValidationGroup="Create" runat="server" Text="Add Restaurant" OnClick="btnAddRestaurant_Click" />
    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" ControlToValidate="nameText" ValidationGroup="Create" runat="server" ErrorMessage="Enter Name Field "></asp:RequiredFieldValidator>
    <br /><asp:RequiredFieldValidator ID="RequiredFieldValidator2" ControlToValidate="cuisineText" ValidationGroup="Create" runat="server" ErrorMessage="Enter Cuisine Field"></asp:RequiredFieldValidator>
    <br /><asp:RequiredFieldValidator ID="RequiredFieldValidator3" ControlToValidate="locationText" ValidationGroup="Create" runat="server" ErrorMessage="Enter Location Field"></asp:RequiredFieldValidator>

    <br /><br/><br />
    COMMENTS <br /><br /><br />
    <asp:GridView ID="commentsGrid" runat="server" OnRowCommand="commentsGrid_RowCommand" AutoGenerateColumns="false">
        <Columns>
            <asp:BoundField DataField="Username" HeaderText="User" ReadOnly="true" />
            <asp:BoundField DataField="Restaurantname" HeaderText="Restaurant" ReadOnly="true" />
            <asp:BoundField DataField="commentText" HeaderText="Comments" ReadOnly="true" />
            <asp:ButtonField CommandName="Accept" Text="Approve" ButtonType="Button" />
            <asp:ButtonField CommandName="Reject" Text="Reject" ButtonType="Button" />

        </Columns>
    </asp:GridView>
    
    <br /><br /><br />
    GET INFORMATION
    <br /><br /><br />
    <asp:DropDownList ID="ddlInfo" runat="server"></asp:DropDownList>
    <asp:Button ID="btnInfo" runat="server" OnClick="btnInfo_Click" Text="Get Information"/>
    <br /><br /><br />
    <asp:Label ID="infoLabel" Text="" runat="server"></asp:Label>
    <br /><br /><br />
    GENERATE REPORT
    <br /><br /><br />
    Cuisine: <asp:CheckBoxList ID="cuisineList" runat="server"></asp:CheckBoxList><br /><br />
    Location: <asp:CheckBoxList ID="locationList" runat="server"></asp:CheckBoxList><br /><br />
    
    Rating: <asp:DropDownList ID="ratingList" runat="server">
        <asp:ListItem>0</asp:ListItem>
        <asp:ListItem>1</asp:ListItem>
        <asp:ListItem>2</asp:ListItem>
        <asp:ListItem>3</asp:ListItem>
        <asp:ListItem>4</asp:ListItem>
        <asp:ListItem>5</asp:ListItem>
            </asp:DropDownList>
    <asp:Button ID="btnReport" OnClick="btnReport_Click" runat="server" Text="Generate" /><br />
    <asp:Label ID="validateCuisineFilter" runat="server" Text=""></asp:Label><br />
    <asp:Label ID="validateLocationFilter" runat="server" Text=""></asp:Label>


</asp:Content>