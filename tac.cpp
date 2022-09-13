#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
int xWins;
int oWins;
char letter = 'x';
bool tie  = false;

void drawingBoard(){

  cout<<"    a    b    c \n";
  cout<<"a";
  cout<<"   "<<board[0][0]<<"    "<<board[0][1]<<"    "<< board[0][2]<<"  \n";
  cout<<"b";
  cout<<"   "<<board[1][0]<<"    "<<board[1][1]<<"    "<< board[1][2]<<"  \n";
  cout<<"c";
  cout<<"   "<<board[2][0]<<"    "<<board[2][1]<<"    "<< board[2][2]<<"  \n";

}

void gamePlay(){
  int num;

  if(letter == 'x'){
    cout<<"Please enter a number: ";
    cin>>num;
  }

  if(letter == 'o'){
    cout<<"Please enter a number: ";
    cin>>num;
  }

  if(num == 1){
    row = 0;
    column = 0;
   }
  if(num == 2){
    row = 0;
    column = 1;
   }
  if(num == 3){
    row = 0;
    column = 2;
   }
  if(num == 4){
    row = 1;
    column = 0;
   }
  if(num == 5){
    row = 1;
    column = 1;
   }
   if(num == 6){
    row = 1;
    column = 2;
   }
  if(num == 7){
    row = 2;
    column = 0;
   }
  if(num == 8){
    row = 2;
    column = 1;
   }
  if(num == 9){
    row = 2;
    column = 2;
   }
  if(num<1){
    cout<< "Invalid number entered!"<<endl;
    gamePlay();
  }
  if(num>9){
    cout<< "Invalid number entered!"<<endl;
    gamePlay();
  }

  //replacement
if(letter == 'x' && board[row][column] != 'x' && board[row][column] != 'o')
    {
      board[row][column] = 'x';
      letter ='o'; 
    }
  else if(letter== 'o' && board[row][column] != 'x' && board[row][column] != 'o')
    {
      board[row][column] = 'o';
      letter= 'x';
    }
  else{
    cout<<"There is no empty space there!"<<endl;
    gamePlay();
  }
}

bool winStatment(){
  for(int i=0; i<3; i++)
    {
      if(board[i][0]==board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] &&
         board[0][i] == board[2][i]){
         return true;
      }
    }
if(board[0][0] == board[1][1] && board[1][1]==board[2][2] || board[0][2] == board[1][1] &&
     board[1][1] == board[2][0]){
     return true;
  }

  for(int i=0;i<3;i++)
    {

      for(int j=0;j<3;j++)
        {
          if(board[i][j] != 'x' && board[i][j] != 'o')
            {

              return false;
            }
        }
    }
  tie = true;
  return false;
}

void resetBoard(){
  letter= 'x';

  if(board[0][0] == 'x' || board[0][0] == 'o'){
    board[0][0] = '1';
  }
  if(board[0][1] == 'x' || board[0][1] == 'o'){
    board[0][1] = '2';
  }
if(board[0][2] == 'x' || board[0][2] == 'o'){
    board[0][2] = '3';
  }
  if(board[1][0] == 'x' || board[1][0] == 'o'){
    board[1][0] = '4';
  }
  if(board[1][1] == 'x' || board[1][1] == 'o'){
    board[1][1] = '5';
  }
  if(board[1][2] == 'x' || board[1][2] == 'o'){
    board[1][2] = '6';
  }
  if(board[2][0] == 'x' || board[2][0] == 'o'){
    board[2][0] = '7';
  }
  if(board[2][1] == 'x' || board[2][1] == 'o'){
    board[2][1] = '8';
  }
  if(board[2][2] == 'x' || board[2][2] == 'o'){
    board[2][2] = '9';
  }
}
int main(){
  int rematch;

  while(!winStatment()){
    drawingBoard();
    gamePlay();
    winStatment();
  }
  drawingBoard();
  if(letter== 'x' && tie == false)
    {
      cout<<"O Wins!"<<endl;
      oWins++;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
else if(letter== 'o' && tie == false)
    {
      cout<<"X Wins!"<<endl;
      xWins++;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
  else
    {
      cout<<"It's a draw!"<<endl;
      cout<<"X total wins: "<<xWins<<endl;
      cout<<"O total wins: "<<oWins<<endl;
      cout<<endl;
      cout<<"Do you want to play again?(Type 1 for Yes or 2 for No)"<<endl;
      cin>>rematch;
      if(rematch == 1){
        resetBoard();//call resetboard function, and at the end of the reset board function call main
        main();
      }
      else{
        return 0;
      }
    }
}
