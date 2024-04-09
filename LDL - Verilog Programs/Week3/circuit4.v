module circuit4(x1,x2,x3,f);
input x1,x2,x3;
output f;
and(g1,x1,x2);
and(g2,x2,x3);
and(g3,x1,x3);
or(f,g1,g2,g3);
endmodule
