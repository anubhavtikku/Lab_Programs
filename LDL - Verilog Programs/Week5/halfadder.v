module halfadder(x,y,f,c);
input x,y;
output f,c;
assign f=x^y;
assign c=x&y;
endmodule
