#include <cstring>
#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;
node *head = NULL;
  //for quit delete head and also make a while loop till userInput equals quit
void add(node *c, node *p, node *&head, student *newStu);
void print(node *head);
void delete1(node *&head, node*current, node *previous, int numDelete);
int studentCounter(node *head);
void average(node *gpaTaker, int number, float average2);
student* studentMaker();
int main(){
  char userInput[20];
  int num = 0;
  int numDelete = 0;
  float average2;

  cout<<"Check"<<endl;
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
    cout<<"Enter the Student's ID"<<endl;
    cin>>numDelete;
    cin.get();
    delete1(head, head, head, numDelete);
    cout<<"Student deleted"<<endl;
  }
  if(strcmp(userInput, "average") == 0){
    if(head == NULL){
      cout<<"no students in list"<<endl;
    }
    else{
      num = studentCounter(head);
      average(head, num, average2);
    }
  }
  }while(strcmp(userInput, "quit") != 0);

}
void add(node *c, node *p, node *&head, student *newStud){

  if(head == NULL){
    head = new node(newStud);//if linked list is empty
    head->setNext(NULL);
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
void delete1(node *&head, node*current, node *previous, int numDelete){

  int num = 0; //for going through the linked list and delete each part.
    if(current->stu->number == numDelete && num == 0){//for the first cycle through the list
      node *removeHead = current;
      previous = current -> nextNode;//Moving up the list
      current = current -> nextNode;//moving up the list
      cout<<current<<endl;
      head = current;
      delete removeHead;//removes the head of the
    }
    else if(current->stu->number == numDelete){
      node *tempHead = current;//making a new node equal to the head of a linked list
      previous->nextNode = current->nextNode;//moving what each node is so I can delete the tempHead node without deleting current
      current = current->nextNode;
      delete tempHead;
    }
    else{
      delete1(head, current,current->nextNode,numDelete);
    }
    num++;


}

int studentCounter(node *head){
  int num = 0;

  node *current = head;

  while(current!=NULL){
    num++;
    if(current->nextNode == NULL){
      return num;
    }
    current = current->nextNode;
  }
  return 0;
}

void average(node *gpaTaker, int number, float average2){

  if(gpaTaker != NULL){
    average2 += gpaTaker->stu->GPA; //add the gpa of the current node to the average function
    average(gpaTaker->getNext(), number, average2);//setting the node to the next node so that I can take the GPA of the next student.
  }
  else{
    average2 = average2/number;//dividing the total of the GPA's by the number of students.
    cout<<"Average GPA's: "<<endl;
  }
}
