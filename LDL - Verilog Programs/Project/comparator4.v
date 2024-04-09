module comparator4(a,b,g,e,l);
input [3:0]a;
input [3:0]b;
output g,e,l;
xnor(i3,a[3],b[3]),(i2,a[2],b[2]),(i1,a[1],b[1]),(i0,a[0],b[0]);
assign e=i3&i2&i1&i0;
assign g=a[3]&(~b[3])|i3&a[2]&(~b[2])|i3&i2&a[1]&~b[1]|i3&i2&i1&a[0]&(~b[0]);
assign l=~(e|g);
endmodule
