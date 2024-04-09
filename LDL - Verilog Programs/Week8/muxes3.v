module muxes3(a,b,c,f);
input a,b,c;
output f;
mux4 s1({a,1'b1,~a,1'b1},{c,b},f);
endmodule
