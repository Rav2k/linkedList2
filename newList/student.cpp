#include "student.h"
#include <cstring>

student::student(char* name, int number, float GPA){
  char* name2 = new char[20];
  strcpy(name2, name);
  this -> number = number;
  this -> GPA = GPA;
}

student::student(){
  //default constructor
}

char* student::getName(){
  return name2;
}

void student::setNumber(int studentNum){
  number = studentNum;
}

int student::getNumber(){
  return number;
}

void student::setGPA(float grade){
  GPA = grade;
}

float student::getGPA(){
  return GPA;
}
