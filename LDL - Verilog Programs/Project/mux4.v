module mux4(a,s,f);
input [3:0]a;
input [1:0]s;
output f;
reg f;
always@(a or s)
begin
if (s==0)
  begin
    f=a[0];
  end
else if (s==1)
  begin
   f=a[1];
  end
else if (s==2)
  begin
    f=a[2];
  end
else if(s==3)
  begin
    f=a[3];
  end
end
endmodule
