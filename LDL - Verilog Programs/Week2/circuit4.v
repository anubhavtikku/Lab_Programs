module circuit4(x1,x2,x3,r1,r2);
input x1,x2,x3;
output r1,r2;
nand(n1,x1,x1);
nand(n2,x2,x2);
nand(n3,x3,x3);
nand(f1,x1,n3);
nand(f2,n1,x2);
nand(f3,n3,x2);
nand(r1,f1,f2,f3);
nor(m1,x1);
nor(m2,x2);
nor(g1,x1,m2);
nor(g2,x3,m1);
nor(g3,g1,g2);
nor(r2,g3);
endmodule

