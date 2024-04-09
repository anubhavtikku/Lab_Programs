module dec3to8(w,en,y);
input [2:0]w;
input en;
output [7:0]y;
reg [7:0]y;
integer i;
always@(w|en)
begin
y={8'b0000000};
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
       
       4:
       begin
       y[4]=1;  
       end
       
       5:
       begin
       y[5]=1;  
       end
       
       6:
       begin
       y[6]=1;  
       end
       
       7:
       begin
       y[7]=1;  
       end
endcase
end
end
endmodule
