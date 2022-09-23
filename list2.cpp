/* Author: Wade Owojori
   Date:9/15/22
   Purpose: Creating a lists of students and storing their information
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;
struct student {
  char firstName[20];
  char lastName[20];
  int studentID;
  float GPA;
};
void add(vector<student*>& studentInfo);
void print(vector<student*>& studentInfo);
void del(vector<student*>& studentInfo);

int main(){
  vector<student*> studentInfo;
  char userInput[10];
do{
 cout<<"Type 'add' to add student;Type 'del' to delete student;Type 'print' to print all student's info;Type 'quit' to quit"<<endl;

 cin.getline(userInput,10,'\n');
  
  if(strcmp(userInput, "add") == 0){
    add(studentInfo);
  }
  if(strcmp(userInput, "print")==0){
    print(studentInfo);
  }
  if(strcmp(userInput, "del")==0){
    del(studentInfo);
  }
  }while(strcmp(userInput, "quit") != 0);

  return 0;

}

void add(vector<student*>&studentInfo){
    student* info  = new student();
    cout<<"Enter Student's first name"<<endl;
    cin>>info->firstName;
    cout<<"Enter Student's last name"<<endl;
    cin>> info->lastName;
    cout<<"Enter Student's ID number"<<endl;
    cin>>info->studentID;
    cout<<"Enter Student's GPA"<<endl;
    cin>>info->GPA;
    cin.ignore();
    cout<<endl;
    cout<<info->firstName << " "<< info->lastName<<endl;
    cout<<"ID: "<< info->studentID<<endl;
    cout<<setprecision(3)<<"GPA: "<<info->GPA<<endl;
    studentInfo.push_back(info);
}

void print(vector<student*>&studentInfo){
  vector<student*>::iterator ptr;
  cout<<endl;
  for (ptr = studentInfo.begin(); ptr != studentInfo.end(); ptr++){
    cout<<endl;
    cout<<(*ptr)->firstName<<" "<<(*ptr)->lastName<<endl;
    cout<<(*ptr)->studentID<<" "<<(*ptr)->GPA<<endl;
    
  }
}

void del(vector<student*>&studentInfo){
  vector<student*>::iterator ptr;
  int userdel;
  cout<<"Type the Student's ID number: "<<endl;
  cin>>userdel;
  for (ptr = studentInfo.begin(); ptr != studentInfo.end(); ptr++){
    if((*ptr)->studentID == userdel){
      delete *ptr;
      studentInfo.erase(ptr);
      break;
    }
  }

}
  
