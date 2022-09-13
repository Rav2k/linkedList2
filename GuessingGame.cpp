#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
  srand (time(NULL));
  //generates random number
  int randomNum = rand() % 100 + 1;
  //initalizes the variable for the input from the user
  int input = 0;
  //keeps track of the amount of guesses the user has taken
  int guesses = 0;
  //yes or no to restart
  char restart = ' ';
  //do-while loop for the user to continually guess.
  do{
    //tells the user what to do
    cout<<"Guess the number between 1-100"<<endl;
    //gets the input from the user and stores it in the variable 'input'
    cin>>input;
    //tells the user if the number is higher or lower so they can make a closer guess.
    if(input>randomNum){
      cout<<"The number is lower"<< endl;
    }else if(input<randomNum){
      cout<<"The number is higher"<<endl;
    }
    //adds one to the guesses count because if the user didn't guess correctly it counts as a guess
    guesses++;
    //parameter for the do while loop
  }while(input!=randomNum);
  //it exits the loop if the person guesses correctly so this is the end message
  cout<< "You guessed correctly!"<< endl;
  //prints out the amount of guesses.
  cout<< "You guessed: "<< guesses<< " times!"<< endl;
  cout<<"Do you want to play again?('y' for yes and 'n' for no)"<< endl;
  cin>>restart;
  if(restart == 'y'){
    main();
  }
  //just in case of bad input.
  return 0;

}
