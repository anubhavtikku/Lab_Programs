<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Report.aspx.cs" Inherits="Default5" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
                                            REPORT<br /><br />
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="false">
        <Columns>
        <asp:BoundField DataField="Name" HeaderText="Restaurant Name" ReadOnly="True" SortExpression="Name" />
        <asp:BoundField DataField="Cuisine" HeaderText="Cuisine" SortExpression="Cuisine" />
        <asp:BoundField DataField="Location" HeaderText="Location" SortExpression="Location" />
        <asp:BoundField DataField="RATING" HeaderText="RATING" SortExpression="RATING" />
    </Columns>
            </asp:GridView>
   

</asp:Content>

