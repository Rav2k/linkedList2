#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class student{
 public:
  
  char *name2;
  int number;
  float GPA;
  char* getName();
  void setNumber(int studentNum);
  int getNumber();
  void setGPA(float grade);
  float getGPA();
  student();
  student(char* name, int id, float GPA);
};
#endif
