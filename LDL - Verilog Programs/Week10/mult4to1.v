module mult4to1(s,w,f,en);
input [1:0]s;
input [3:0]w;
wire [3:0]y;
input en;
output f;
dec2to4 st1(s,en,y); 
and (g0,y[0],w[0]);
and(g1,y[1],w[1]);
and(g2,y[2],w[2]);
and(g3,y[3],w[3]);
assign f=g0|g1|g2|g3;
endmodule


module dec2to4(w,en,y);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
integer i;
always@(w|en)
begin
y={4'b0000};
if (en==1)
begin
case (w)
       0:
       begin
         y[0]=1;  
       end
       
       1:
       begin
       y[1]=1;  
       end

       2:
       begin
       y[2]=1;  
       end
       
       3:
       begin
       y[3]=1;  
       end
       
endcase
end
end
endmodule

