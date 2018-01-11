#include<iostream>
#include<string>
using namespace std;

char field[] = {'0','1', '2','3','4','5','6','7','8','9'};
int player1=0, player2=0;

void clearBoard(){
	field[1] = '1';
	field[2] = '2';
	field[3] = '3';
	field[4] = '4';
	field[5] = '5';
	field[6] = '6';
	field[7] = '7';
	field[8] = '8';
	field[9] = '9';
}

void board(){
	  system("clear");		//clears the terminal
	  cout<<"\n==========Tic Tac Toe==========" <<endl;
	  cout<<"\nPlayer 1 (X) vs Player 2 (O)\n\n";

	  cout<<"     |     |     "<< endl;
	  cout<<"  "<<field[1]<<"  |"<<"  "<<field[2]<<"  |"<<"  "<<field[3]<<endl;
	  cout<<"_____|_____|_____"<< endl;
	  cout<<"     |     |     "<< endl;
	  cout<<"  "<<field[4]<<"  |"<<"  "<<field[5]<<"  |"<<"  "<<field[6]<<endl;
	  cout<<"_____|_____|_____"<< endl;
	  cout<<"     |     |     "<< endl;
	  cout<<"  "<<field[7]<<"  |"<<"  "<<field[8]<<"  |"<<"  "<<field[9]<<endl;
	  cout<<string(2,'\n');		//2 blank lines
}

int checkGame(){
	  if(field[1] == field[2] && field[2] == field[3])
		    return 1;
	  else if(field[4] == field[5] && field[5] == field[6])
		    return 1;
	  else if(field[7] == field[8] && field[8] == field[9])
		    return 1;
	  else if(field[1] == field[4] && field[4] == field[7])
		    return 1;
	  else if(field[2] == field[5] && field[5] == field[8])
		    return 1;
	  else if(field[3] == field[6] && field[6] == field[9])
		    return 1;
	  else if(field[1] == field[5] && field[5] == field[9])
		    return 1;
	  else if(field[3] == field[5] && field[5] == field[7])
		    return 1;
	  else if(field[1] != '1'&& field[2] != '2' && field[3] != '3' && field[4] != '4'&&
		  field[5] != '5'&& field[6] != '6' && field[7] != '7' && field[8] != '8'&&
		  field[9] != '9')
		    return 0;
	  else 
		    return -1;
}

void startGame(){
	  int player = 1, check;
	  char choice, mark;

	  do{
		  board();
		  player = (player%2)? 1:2;
		  mark = (player==1)? 'X':'O';
		  cout<<"Player "<< player <<" enter a number"<<endl;
		  cin>>choice;

		  if(choice == '1' && field[1] == '1')
			  field[1] = mark;
		  else if(choice == '2' && field[2] == '2')
			 field[2] = mark;
		  else if(choice == '3' && field[3] == '3')
			 field[3] = mark;
		  else if(choice == '4' && field[4] == '4')
			 field[4] = mark;
		  else if(choice == '5' && field[5] == '5')
			  field[5] = mark;		
		  else if(choice == '6' && field[6] == '6')
			 field[6] = mark;
		  else if(choice == '7' && field[7] == '7')
			 field[7] = mark;
		  else if(choice == '8' && field[8] == '8')
			  field[8] = mark;
		  else if(choice == '9' && field[9] == '9')
			  field[9] = mark;
		  else{ 
			  cout<<"Invalid choice!" << endl;
			  player--;
			  cin.ignore();
			  cin.get();
		  }
		  check= checkGame();
		  player++;
	  }while( check == -1);
	  board();
	  if(check == 1) 
		  cout<<"Player "<<--player<<" Wins!"<< endl;
	  else{
		  player=0;
		  cout<<"The Game is a Draw"<< endl;
	  }
	  (player==1)? player1++:(player==2)? player2++:player=0;
	  cout<<"\n\n===========Score==========\n"<<endl;
	  cout<<"Player 1: "<< player1<<endl;
	  cout<<"Player 2: "<< player2<<endl;

	  cin.ignore();
	  cin.get();
}

int main(){
	char next='y';
	while(next != 'q'){
		clearBoard();
		startGame();
		cout<<"To Exit enter: q  \nTo Continue press any key:\n";
		cin >> next;
	}
	return 0;
}
