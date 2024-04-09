module circuit3(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=((~a)|b)&(b|d)&(a|(~c)|(~d))&(~a|c|~d);
endmodule
