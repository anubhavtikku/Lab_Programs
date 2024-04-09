module posedgejk(j,k,Q,reset,clock);
input clock,j,k,reset;
output Q;
reg Q;
always@(posedge clock)
begin
if(j==0&& k==1)
Q<=0;
if(j==1&&k==0)
Q<=1;
if(j==1&&k==1)
Q<=~Q;
if(!reset)
Q<=0;
end
endmodule
