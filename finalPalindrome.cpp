#include <iostream>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
 {
  char input[81];
  char input2[81];
  int i = 0;
  int j = 0;
  cout<<"Enter a string: "<<endl;
  cin.get(input, 80);
  cin.get();
  char output[strlen(input)];
  for(int i = 0; i<strlen(input); i++){
    char lowerCase = tolower(input[i]);//changing all the characters to lowercase
    input[i] = lowerCase;
    if(input[i]>=97 && input[i]<=122){//Seeing if the input is a letter using ascii chart.
      output[j] = input[i];//if it is a letter it will beput in the other char array
      j++;//doing j++ moves the place in the char array in output so the chars are placed in different spots
    }else{
      continue;
    }

  }
  strcpy(input2, output);//makes input2 the same as output
  for(int i =0; i<strlen(input2)/2;i++){
    swap(input2[i], input2[strlen(input2)- i - 1]); //makes input2 array backwards
  }
  cout<<output<<endl;
  cout<< input2<<endl;
  if (strcmp(output,input2) == 0){//if output and input2 are the same then it is a palindrome
    cout<<"Palindrome"<<endl;
  }else{
  cout<<"Not a Palindrome"<<endl;
  }
}
