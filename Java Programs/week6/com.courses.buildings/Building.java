package com.courses.buildings;
import java.io.*;
import java.util.*;

public class Building
{int sqfoot;
 int stories;
   
  public void setPar(int sf,int s)
  {
  	sqfoot=sf;
  	stories=s;
  }
  
  public int getsq()
  {
  	return(sqfoot);
  }

  public int getst()
  {
  	return(stories);
  }

 }

public class House extends Building
 { int bed;
 	int bath;
     
 public void setP(int be,int ba)
  {
  	bed=be;
  	bath=ba;
  }
  
  public int getbe()
  {
  	return(bed);
  }

  public int getba()
  {
  	return(bath);
  }

 }

  public class School extends Building
  { int noofclass;
  	String gradelevel;

   public	void setPare(int nc,String gl)
  {
  	noofclass=nc;
  	gradelevel=gl;
  }
  
  public int getnc()
  {
  	return(noofclass);
  }

  public String getgl()
  {
  	return(gradelevel);
  }

  }