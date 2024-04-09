module ntogrey(b,g);
parameter n=4;
input [n-1:0]b;
output [n-1:0]g;
reg [n-1:0]g;
integer i;
always@(b)
begin
 for(i=0;i<n-1;i=i+1)
 begin
 g[i]=b[i]^b[i+1];
 end
g[n-1]=b[n-1];
end
endmodule
