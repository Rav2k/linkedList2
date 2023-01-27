#include <cstring>
#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;
node *head = NULL;
  //for quit delete head and also make a while loop till userInput equals quit
void add(node *c, node *p, node *&head, student *newStu);
void print(node *head);
student* studentMaker();
int main(){
  char userInput[20];
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
  if(strcmp(userInput, "del")==0){//if they say delete run the delete function
    
  }
  }while(strcmp(userInput, "quit") != 0);

}

void add(node *c, node *p, node *&head, student *newStud){

  if(head == NULL){
    head = new node(newStud);//if linked list is empty 
    return;//if this is true then i don't need to check through more
  }
  else if(newStud->number < head->getStudent()->number){
    node *newNode = new node(newStud);
    newNode -> setNext(head);
    head = newNode;
    return;
  }
  else if(newStud->number < c->getStudent()->number){
    node * newNode2 = new node(newStud);
    p->setNext(newNode2);
    newNode2-> setNext(c);
    return;
  }
  if(c->getNext() == NULL){
    node *newNode3 = new node(newStud);
    c->setNext(newNode3);
    newNode3->setNext(NULL);
    return;
  }

  add(c->getNext(), c, head, newStud);
}

student* studentMaker(){
  char* test = new char[20];
  int numstud;
  float gradepoint;
  cout<<"Name?"<<endl;
  cin>>test;
  
  
  cout<<"number"<<endl;
  cin>>numstud;
  cout<<"GPA"<<endl;
  cin>>gradepoint;

  student *student4 = new student(test, numstud, gradepoint);
  return student4;
}

void print(node *head){
  cout << head->getStudent()->getName()<<endl;
  cout << head->getStudent()->getNumber()<<endl;
  cout << head->getStudent()->getGPA()<<endl;
    if(head -> getNext() != NULL){
      print(head->getNext());
    }
    cout<<"Done!"<<endl;
}

void delete1(){

}

void average(){

}
