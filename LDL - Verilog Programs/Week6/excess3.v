module excess3(b,s,c);
input [3:0]b;
output [3:0]s;
output c;
adder4 st1(0,0,0,1,1,b[3],b[2],b[1],b[0],s[3],s[2],s[1],s[0],c);
endmodule
