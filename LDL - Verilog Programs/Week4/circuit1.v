module circuit1(a,b,d,f);
input a,b,d;
output f;
nor(g1,b,d);
nor(nd,d,d);
nor(g2,nd,a);
nor(g3,g1,g2);
nor(f,g3,g3);
endmodule
