module bcd(x0,x1,x2,x3,y0,y1,y2,y3,s0,s1,s2,s3,cin,cout);
input x0,x1,x2,x3,y0,y1,y2,y3,cin;
output s0,s1,s2,s3,cout;
fulladder stage0(cin,x0,y0,v0,c1);
fulladder stage1(c1,x1,y1,v1,c2);
fulladder stage2(c2,x2,y2,v2,c3);
fulladder stage3(c3,x3,y3,v3,tcout);
assign cout=tcout|(v3&v2)|(v3&v1);
fulladder stage4(0,v0,0,s0,c4);
fulladder stage5(c4,v1,cout,s1,c5);
fulladder stage6(c5,v2,cout,s2,c6);
fulladder stage7(c6,v3,0,s3,c7);
endmodule
