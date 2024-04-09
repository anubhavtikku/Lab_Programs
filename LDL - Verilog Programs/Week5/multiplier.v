module multiplier(x0,x1,y0,y1,s0,s1,s2,cout);
input x0,x1,y0,y1;
output s0,s1,s2,cout;
assign s0=x0&y0;
halfadder t1(x1&y0,x0&y1,s1,c);
halfadder t2(x1&y1,c,s2,cout);
endmodule





