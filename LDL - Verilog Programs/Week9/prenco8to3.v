module prenco8to3(w,y,en);
input [7:0]w;
output [3:0]y;
output en;
reg [3:0]y;
reg en;
integer i;
always@(w)
begin
y=0;
en=0;
for(i=0;i<8;i=i+1)
if(w[i]==1)
begin
y=i;
en=1;
end
end
endmodule


