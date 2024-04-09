module circuit1(a,b,d,f);
input a,b,d;
output f;
not(na,a);
not(nb,b);
not(nd,d);
and(g1,na,b);
and(g2,b,d);
and(g3,nb,nd);
or(f,g1,g2,g3);
endmodule
