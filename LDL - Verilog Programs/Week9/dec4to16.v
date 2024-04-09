module dec4to16(w,en,y);
input [3:0]w;
input en;
output [15:0]y;
dec3to8 st0(w[2:0],~w[3]&en,y[7:0]);
dec3to8 st1(w[2:0],w[3]&en,y[15:8]);
endmodule

