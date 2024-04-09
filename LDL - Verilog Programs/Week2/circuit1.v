module circuit1(x,y,z,a,l1,r1,l2,r2,l3,r3);
input x,y,z,a;
output l1,r1,l2,r2,l3,r3;
assign l1=(x&(y|z));
assign r1=((x&y)|(x&z));
assign l2=(x|(y&z));
assign r2=((x|y)&(x|z));
assign l3=a;
assign r3=~(~a);
endmodule
