module addsub(carryin,x3,x2,x1,x0,y3,y2,y1,y0,s3,s2,s1,s0,carryout);
input carryin,x3,x2,x1,x0,y3,y2,y1,y0;
output s3,s2,s1,s0,carryout;
fulladder stage0(carryin,y0^carryin,x0,s0,c1);
fulladder stage1(c1,y1^carryin,x1,s1,c2);
fulladder stage2(c2,y2^carryin,x2,s2,c3);
fulladder stage3(c3,y3^carryin,x3,s3,carryout);
endmodule
