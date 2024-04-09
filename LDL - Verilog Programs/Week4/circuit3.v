module circuit3(x1,x2,x3,x4,f,g);
input x1,x2,x3,x4;
output f,g;
assign f=(~x1)&(~x3)&(~x4)|(~x2)&x3&(~x4)|x1&(~x2)&(~x3)&x4|(~x1)&x2&x3;
assign g=(~x1)&(~x3)&(~x4)|(~x2)&x3&(~x4)|x1&(~x2)&(~x3)&x4|x1&x2&x3;
endmodule
