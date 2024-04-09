module negtflipflop(T,clock,reset,Q);
input T,clock,reset;
output Q;
reg Q;
always@(negedge clock)
begin
if(!reset)
Q<=0;
else if(T)
Q<=~Q;
end
endmodule

