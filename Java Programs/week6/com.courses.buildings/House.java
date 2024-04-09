package com.courses.buildings;
import java.io.*;
import java.util.*;

public class House extends Building
 { int bed;
 	int bath;
     
  void setP(int be,int ba)
  {
  	bed=be;
  	bath=ba;
  }
  
  int getbe()
  {
  	return(bed);
  }

  int getba()
  {
  	return(bath);
  }

 }