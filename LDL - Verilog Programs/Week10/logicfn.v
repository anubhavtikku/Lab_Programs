module logicfn(w,en,f);
input [2:0]w;
input en;
output f;
wire [7:0]y;
dec3to8 st1(w,en,y);
assign f=y[0]|y[2]|y[3]|y[4]|y[5]|y[7];
endmodule
