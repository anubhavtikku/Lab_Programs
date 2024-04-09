module negdflipflop(D,clock,reset,Q);
input D,clock,reset;
output Q;
reg Q;
always@(negedge clock)
if(!reset)
Q<=0;
else
Q<=D;
endmodule
