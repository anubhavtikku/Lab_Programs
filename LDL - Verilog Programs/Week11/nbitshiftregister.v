module nbitshiftregister(k,b,clk);
parameter n=4;
input k,clk;
output [n-1:0]b;
integer i;
reg [n-1:0]b;
always@(posedge clk)
begin
for(i=n-1;i>0;i=i-1)
b[i]=b[i-1];
b[0]=k;
end
endmodule
