module muxes2(a,b,c,f);
input a,b,c;
output f;
mux4 s1({~a,1'b0,1'b1,~a},{c,b},f);
endmodule
