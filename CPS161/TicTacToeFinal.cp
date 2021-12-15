/*************
Name : Umangkumar Patel
	   Husna
	   Vadym
	   Daniel
	   Kyle
Date : October 3, 2019
Proff: Daniel, Fahringer
Class: CPS I 161
Progr: Tic-Tac-Toe 
*************/

#include<iostream>

using namespace std;

string player1;																	// Input Player One's Name
string player2;																	// Input Player Two's Name

int exitValue = 0;																// Sentinel Value to exit game

const int ticRow = 3;															// Constant Row    Size
const int ticCol = 3;															// Constant Column Size
char board[ticRow][ticCol] = {'1', '2', '3','4','5','6','7','8','9'};
int    position;																// Position for Input 
int    tieCheck = 0;															// Counts Entry, if no win and count reaches 9, display message
string winner   = "";
void   intro();																	// Introduction
void   displayBoard();															// Displays Board
void   getPlayers();															// Fetches Player(s) Name
void   getInput(string);														// Input Position Based on Player
void   updateBoard(int , string);
int    check4Win(string,int);													// Checks if either player won
void   endDisplay();
void   checkInput(int, string);															// display end results

int main()
{
	intro();																	// Introduction of the Game
	displayBoard();																// Displays Board
	getPlayers();																// Fetches Player's Name
	
	while(exitValue != -1)														// Sentinel Value for Escape
	{
		do
		{
			getInput(player1);													// Gets Input for PLAYER
		}while(position < 1 ||  position > 9);
		
		if(exitValue != -1)														// If (Not) Exit-Value then Proceed for 2nd Player's Input
		{
			do
			{
				getInput(player2);												// **
			}while(position < 1 ||  position > 9);
	    }
	}
	return 0;
	
}

void intro()
{
	system("color 3");
	system("cls");
	cout<<"\tWelcome To Tic-Tac-Toe\n\n----------------------------------------------\n";
	cout<<"\tInstructions\n\nSystem Will Tell the User to input the number \non empty(numbered) locations\n\n";	
}
void displayBoard()
{
	for(int r = 0; r < ticRow; r++)
	{
		for(int c = 0; c < ticCol; c++)
		{
			cout  << "\t"<< board[r][c] << "  ";
		}
		cout  << "\n\t- - - - - - - - -\n";
	}
}

//Asks each user for their name
void getPlayers()
{
	cout << "\n----------------------------------------------\n\t Players \n\n";
	cout<<"Player1 (O): ";
	cin >> player1;
	cout<<"Player2 (X): ";
	cin >> player2;
	cout << "----------------------------------------------\n";
}

//Asks user for what position on the board they want
void getInput(string name)
{
	cout << name << "\n\t Please Enter #: ";
	cin  >> position;
	checkInput(position, name);
}

//Updates positions on board that are taken to two dimensional array
void updateBoard(int position, string player)
{
	
	//determines which player updated board
	char status;
	if(player == player1)
		status = 'O';
	else
		status = 'X';
	
	//filling array
	switch(position)
	{
		case 1:
			board[0][0] = status;
			break;
		case 2: 
			board[0][1] = status;
			break;
		case 3: 
			board[0][2] = status;
			break;
		case 4: 
			board[1][0] = status;
			break;
		case 5: 
			board[1][1] = status;
			break;
		case 6: 
			board[1][2] = status;
			break;
		case 7: 
			board[2][0] = status;
			break;
		case 8: 
			board[2][1] = status;
			break;
		case 9: 
			board[2][2] = status;
			break;
	}
}

void checkInput(int position, string player)
{
	
	char status;
	if(player == player1)
		status = 'O';
	else
		status = 'X';
	switch(position)
	{
		case 1:
			if(board[0][0] == 'O' || board[0][0] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}			
			break;
		case 2: 
			if(board[0][1] == 'O' || board[0][1] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 3: 
			if(board[0][2] == 'O' || board[0][2] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 4: 
			if(board[1][0] == 'O' || board[1][0] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 5: 
			if(board[1][1] == 'O' || board[1][1] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 6: 
			if(board[1][2] == 'O' || board[1][2] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 7: 
			if(board[2][0] == 'O' || board[2][0] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 8: 
			if(board[2][1] == 'O' || board[2][1] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
		case 9: 
			if(board[2][2] == 'O' || board[2][2] == 'X')
			{
				getInput(player);
			}
			else
			{
				tieCheck++;																// Keeps Track of Input for Tie Check
				updateBoard(position,player);											// Updates the Board with given location and assigned Player's Symbol
				system("cls");															// Clears the Screen for Readibility/User-Friendly
				displayBoard();															// Displays Updated Board
				check4Win(player,tieCheck);											// Checks for Win along with Tie Count
			}
			break;
	}
}


int check4Win(string player, int count)
{
	//checking if player1 has 3 in a row
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')			//
		winner = player;														//
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')	//	Horizontal wins player 1
		winner = player;														//
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')	//
		winner = player;
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')	//
		winner = player;														//
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')	//	Vertical wins player 1
		winner = player;														//
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')	//
		winner = player;
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')	//
		winner = player;														//	Diagonal wins player 1
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')	//
		winner = player;
	
	//checking if player2 has 3 in a row
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')			//
		winner = player;														//
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')	//	Horizontal wins player 2
		winner = player;														//
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')	//
		winner = player;
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')	//
		winner = player;														//
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')	//	Vertical wins player 2
		winner = player;														//
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')	//
		winner = player;
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')	//
		winner = player;														//	Diagonal wins player 2
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')	//
		winner = player;

	if (winner == player)
	{
		system("color b1");
		cout << "\t" << player << " is the winner!" << endl;
		return exitValue = -1;
	}
	if (count == 9)
	{
		cout << "\tIts a Tie!\n";
		return exitValue = -1;
	}
}
