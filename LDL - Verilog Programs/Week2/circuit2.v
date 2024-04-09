module circuit2(a,b,c,r1,r2);
input a,b,c;
output r1,r2;
and(f1,a,b);
and(f2,b,c);
and(f3,a,c);
or(r1,f1,f2,f3);
nand(g1,a,b);
nand(g2,b,c);
nand(g3,a,c);
nand(r2,g1,g2,g3);
endmodule
