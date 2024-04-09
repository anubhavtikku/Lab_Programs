package com.course.buildings;
public class House extends Building{
	int bed,bath;
	public void setBed(int bed){this.bed=bed;}
	public void setBath(int bath){this.bath=bath;}
	public int getBath(){return bath;}
	public int getBed(){return bed;}
}
