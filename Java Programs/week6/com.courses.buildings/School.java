package com.courses.buildings;
import java.io.*;
import java.util.*;

public   class School extends Building
  { int noofclass;
  	String gradelevel;

  	void setPare(int nc,String gl)
  {
  	noofclass=nc;
  	gradelevel=gl;
  }
  
  int getnc()
  {
  	return(noofclass);
  }

  String getgl()
  {
  	return(gradelevel);
  }

  }