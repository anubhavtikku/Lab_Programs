package com.course.buildings;
public class House extends Building{
	int bed,bath;
	void setBed(int bed){this.bed=bed;}
	void setBath(int bath){this.bath=bath;}
	int getBath(){return bath;}
	int getBed(){return bed;}
}
