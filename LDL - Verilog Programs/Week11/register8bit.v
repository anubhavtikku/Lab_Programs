module register8bit(a,b,clk);
input [7:0]a;
output [7:0]b;
input clk;
DF1 s0(a[0],clk,b[0]);
DF1 s1(a[1],clk,b[1]);
DF1 s2(a[2],clk,b[2]);
DF1 s3(a[3],clk,b[3]);
DF1 s4(a[4],clk,b[4]);
DF1 s5(a[5],clk,b[5]);
DF1 s6(a[6],clk,b[6]);
DF1 s7(a[7],clk,b[7]);
endmodule

module DF1(d,clock,q);
input d,clock;
output q;
reg q;
always@(posedge clock)
begin
q<=d;
end
endmodule
