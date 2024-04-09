module mux8(a,w,s);
input [7:0]a;
input [2:0]w;
output s;
reg s;
always@(a|w)
begin
case(w)
      
         0:
         begin
           assign s=a[0];
         end

         1:
         begin
          assign   s=a[1];
         end
          
         2:
         begin
           assign  s=a[2];
         end
         
         3:
         begin
           assign  s=a[3];
         end
 
         4:
         begin
           assign  s=a[4];
         end
        
         5:
         begin
           assign  s=a[5];
         end
         
         6:
         begin
           assign  s=a[6];
         end
          
         7:
         begin
           assign  s=a[7];
         end
endcase
end
endmodule
