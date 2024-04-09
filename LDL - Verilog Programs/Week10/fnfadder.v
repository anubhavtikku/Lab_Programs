module fnfadder(x1,x2,en,x3,f,c);
input x1,x2,x3;
input en;
output f,c;
wire [2:0]w;
assign w[0]=x1;
assign w[1]=x2;
assign w[2]=x3;
wire [7:0]y;
dec3to8 st1(w,en,y);
assign f=y[1]|y[2]|y[4]|y[7];
assign c=y[3]|y[5]|y[6]|y[7];
endmodule

