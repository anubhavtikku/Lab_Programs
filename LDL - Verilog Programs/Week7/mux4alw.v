module mux4alw(a,s,f);
input [3:0]a;
input [1:0]s;
output f;
reg f;
always@(a or s)
begin
assign f=s[1]?(s[0]?a[3]:a[2]):(s[0]?a[1]:a[0]);
end
endmodule
