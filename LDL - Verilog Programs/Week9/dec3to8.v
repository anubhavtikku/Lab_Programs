module dec3to8(w,en,y);
input [3:0]w;
input en;
output [7:0]y;
reg [7:0]y;
integer i;
always@(w|en)
begin
y={8'b11111111};
if (en==1)
begin
case (w)
       0:
       begin
         y[0]=0;  
       end
       
       1:
       begin
       y[1]=0;  
       end

       2:
       begin
       y[2]=0;  
       end
       
       3:
       begin
       y[3]=0;  
       end
       
       4:
       begin
       y[4]=0;  
       end
       
       5:
       begin
       y[5]=0;  
       end
       
       6:
       begin
       y[6]=0;  
       end
       
       7:
       begin
       y[7]=0;  
       end
endcase
end
end
endmodule
