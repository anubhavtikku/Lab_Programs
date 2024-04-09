package com.course.buildings;
public class School extends Building{
	int rooms;
	String grade;
	public void setRooms(int rooms){this.rooms=rooms;}
	public void setGrade(String grade){this.grade=grade;}
	public int getRooms(){return rooms;}
	public String getGrade(){return grade;}
}