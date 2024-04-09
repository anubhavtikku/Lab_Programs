module prenco8to3case(w,y,en);
input [7:0]y;
output [2:0]w;
output en;
reg [2:0]w;
reg en;
integer i;
always@(y)
begin
w=0;
en=1;
casex(y)
       {8'b00000000}:
       begin
             w={8'bxxxxxxxx};
             en=0;
       end
   
       {8'b00000001}:
       begin
             w=0;
       end

       {8'b0000001x}:
       begin
               w=1;
       end
       
       {8'b000001xx}:
       begin
               w=2;
       end
      
       {8'b00001xxx}:
       begin
               w=3;
       end
       
       {8'b0001xxxx}:
       begin
               w=4;
       end
       
      {8'b001xxxxx}:
       begin
               w=5;
       end

      {8'b01xxxxxx}:
       begin
               w=6;
       end
       
      {8'b1xxxxxx}:
       begin
               w=7;
       end

endcase
end
endmodule
