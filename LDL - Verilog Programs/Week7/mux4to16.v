module mux4t(a,s,f);
input [3:0]a;
input [1:0]s;
output f;
reg f;
always@(a or s)
begin
assign f=s[1]?(s[0]?a[3]:a[2]):(s[0]?a[1]:a[0]);
end
endmodule

module mux4to16(a,s,f);
input [15:0]a;
input [3:0]s;
output f;
wire [3:0]g;
mux4t st1(a[3:0],s[1:0],g[0]);
mux4t st2(a[7:4],s[1:0],g[1]);
mux4t st3(a[11:8],s[1:0],g[2]);
mux4t st4(a[15:12],s[1:0],g[3]);
mux4t st5(g,s[3:2],f);
endmodule


