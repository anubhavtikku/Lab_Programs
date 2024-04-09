module circuit2(a,b,d,f);
input a,b,d;
output f;
nand(nb,b,b);
nand(g1,nb,a);
nand(f,g1,d);
endmodule
