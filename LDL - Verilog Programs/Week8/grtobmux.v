module grtobmux(b,g);
input [3:0]b;
output [3:0]g;
mux8 m1({8'b00111100},b[3:1],g[2]);
mux8 m2({8'b01100110},b[3:1],g[1]);
mux8 m3({~b[0],b[0],~b[0],b[0],~b[0],b[0],~b[0],b[0]},b[3:1],g[0]);
assign g[3]=b[3];
endmodule




