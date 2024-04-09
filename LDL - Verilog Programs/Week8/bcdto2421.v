module bcdto2421(b,g);
input [3:0]b;
output [3:0]g;
mux8 m1({5'b11111,b[0],2'b00},b[3:1],g[3]);
mux8 m2({5'b11111,~b[0],2'b00},b[3:1],g[2]);
mux8 m3({3'b111,b[0],b[0],b[0],b[0],b[0]},b[3:1],g[0]);
mux8 m4({5'b11110,b[0],2'b10},b[3:1],g[1]);
endmodule
