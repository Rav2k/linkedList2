#include <cstring>
#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;
node *head = NULL;
  //for quit delete head and also make a while loop till userInput equals quit
void add(node *c, node *p, node *&head, student *newStu);
void print(node *head);
void delete1(node * &head, int numDelete);
int studentCounter(node *head);
void average(node *gpaTaker, int number, float average2);
student* studentMaker();
int main(){
  char userInput[20];
  int num = 0;
  int numDelete = 0;
  do{
    cout<<"Type 'add' to add student;Type 'delete' to delete student;Type 'print' to print all student's info;Type 'quit' to quit; 'Average' for average student GPA."<<endl;
    cin.getline(userInput,20,'\n');//gets the user's request then clears the cin

  if(strcmp(userInput, "add") == 0){//if they say add run the add function
    student* student = studentMaker();
    add(head, head, head, student);
    cout<<"Student Added!"<<endl;
  }
  if(strcmp(userInput, "print")==0){//if they say print run the print functi
    print(head);
  }
  if(strcmp(userInput, "delete")==0){//if they say delete run the delete function
    delete1(head, numDelete);
    cout<<"Student deleted"<<endl;
  }
  if(strcmp(userInput, "average") == 0){
    if(head == NULL){
      cout<<"no students in list"<<endl;
    }
    else{
      num = studentCounter(head);
      average(head, num, 0);
    }
  }
  }while(strcmp(userInput, "quit") != 0);

}

void add(node *c, node *p, node *&head, student *newStud){

  if(head == NULL){
    head = new node(newStud);//if linked list is empty
    return;//if this is true then i don't need to check through more
  }
