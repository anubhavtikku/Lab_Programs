module muxes1(a,b,c,d,f);
input a,b,c,d;
output f;
mux4 s1({1'b0,a,a^b,a},{d,c},f);
endmodule
