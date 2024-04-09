package com.course.buildings;
class School extends Building{
	int rooms;
	String grade;
	void setRooms(int rooms){this.rooms=rooms;}
	void setGrade(String grade){this.grade=grade;}
	int getRooms(){return rooms;}
	String grade(){return grade;}
}