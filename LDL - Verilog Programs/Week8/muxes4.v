module muxes4(a,b,c,f);
input a,b,c;
output f;
mux4 s1({a,~a,1'b0,1'b1},{c,b},f);
endmodule
