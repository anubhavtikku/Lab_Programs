module circuit3(x,y,z,r1,r2);
input x,y,z;
output r1,r2;
nand(nz,z,z);
nand(f1,nz,x);
nand(ny,y,y);
nand(r1,f1,ny);
nor(g1,x,x);
nor(g2,g1,z);
nor(g3,g2,y);
nor(r2,g3,g3);
endmodule
