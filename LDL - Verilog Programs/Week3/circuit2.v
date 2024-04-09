module circuit2(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=c&(~d)|(~b)&(~d)|(a&b&(~c)&d);
endmodule
