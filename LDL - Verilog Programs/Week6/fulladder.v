module fulladder(x,y,z,f,c);
input x,y,z;
output f,c;
assign f=x^y^z;
assign c=x&y|y&z|x&z;
endmodule
