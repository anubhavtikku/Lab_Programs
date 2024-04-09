module circuit4(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
and(g,x1,x2);
or(h,x3,x4);
and(f1,g,h);
not(ng,g);
not(nh,h);
and(f2,ng,nh);
or(f,f1,f2);
endmodule
