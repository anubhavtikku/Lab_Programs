module greytob(b,g);
parameter n=4;
input [n-1:0]g;
output [n-1:0]b;
reg [n-1:0]b;
integer i;
always@(b)
begin
 b[n-1]=g[n-1];
 for(i=n-2;i>=0;i=i-1)
 begin
 b[i]=b[i+1]^g[i];
 end
end
endmodule

