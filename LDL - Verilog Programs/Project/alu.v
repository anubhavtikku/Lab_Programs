module alu(s,A,B,F);
input [2:0]s;
input [3:0]A,B;
output [3:0]F;
output carry;
always@(s)
begin
case (s)
       0:
       begin
        lu st1(A,B,s[0],s[1],F); 
       end
       
       1:
       begin
         lu st2(A,B,s[0],s[1],F);   
       end
       
       2:
       begin
         lu st3(A,B,s[0],s[1],F);         
       end
       
       3:
       begin
          lu st4(A,B,s[0],s[1],F);
       end
       
       4:
       begin
         au au1(A,B,s[0],F,carry);  
       end

       5:
       begin
         au au2(a,b,s[0],F,carry);
       end
       
       6:
       begin
           assign F={4'b0000}
       end
       
       7:
       begin
          assign F={4'b1111}
       end
endcase
endmodule

module au(a,b,s0,o,cout);
input [3:0]a,b;
input s0;
output [3:0]o;
output cout;
wire [3:0]y;
mux2 st1(b[3],~b[3],s0,y[3]);
mux2 st2(b[2],~b[2],s0,y[2]);
mux2 st3(b[1],~b[1],s0,y[1]);
mux2 st4(b[0],~b[0],s0,y[0]);

adder4 st1(s0,a[3],a[2],a[1],a[0],y[3],y[2],y[1],y[0],o[3],o[2],o[1],o[0],cout);
endmodule

module lu(a,b,s0,s1,r);
input [3:0]a,b;
output [3:0]r;
wire [3:0]g,e,l;
assign g={4'b0000};
assign e={4'b0000};
assign l={4'b0000};
comparator4 st1(a,b,g[0],e[0],l[0]);
wire [3:0]t;
and(t,a,b);
mux4 st2({g,e,l,t},{s1,s0},r);
endmodule

module mux2(a,b,s,f);
input a,b;
input s;
output f;
reg f;
always@(a|s)
begin
if(s==0)
f=a;
else
f=b;
end
endmodule
