module fn3(w,f,en);
input [0:2]w;
output [2:0]f;
wire [7:0]y;
wire [7:0]z;
wire [7:0]a;
input en;
dec3t8 st1(w,en,y);
assign f[0]=y[0]|y[7]|y[5];
dec3t8 st2(w,en,z);
assign f[1]=z[4]|z[3]|z[2];
dec3t8 st3(w,en,a);
assign f[2]=a[1]|a[6]|a[7];
endmodule

module dec3t8(w,en,y);
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

       if(w==0)
       begin
         y[0]=1;  
       end
       
       if(w==1)
       begin
       y[1]=1;  
       end

       if(w==2)
       begin
       y[2]=1;  
       end
       
       if(w==3)
       begin
       y[3]=1;  
       end
       
       if(w==4)
       begin
       y[4]=1;  
       end
       
       if(w==5)
       begin
       y[5]=1;  
       end
       
       if(w==6)
       begin
       y[6]=1;  
       end
       
       if(w==7)
       begin
       y[7]=1;  
       end
end
end
endmodule

