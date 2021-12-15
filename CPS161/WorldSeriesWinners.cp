/*************************
Name: Umangkumar Patel
Date: November 6, 2019
Prof: Fahringer, Daniel
Prog: World Series #8
	  Write A Program To 
	  Enter # Of Games
	  Won For The Team(s)
*************************/
#include<iostream>
#include<fstream>
#include<vector>	
#include<string>	
#include<iomanip>		
using namespace std;

vector<string> iTeam;								// Vector to Store String
vector<string> wTeam;								// Vector to Store Winning Team
void fillVectors();									// File(Strings) to Vectors
void intro();										// Introduction: Display teams to Choose
void stat(string);									// Calculates Statistics for the Team
int main()
{
	fillVectors();
	intro();
}
void fillVectors()
{
	ifstream teams ("Teams.txt");					// Declare&Open input File object(Teams)
	ifstream wteam ("WorldSeriesWinners.txt");		// Declare&Open input File object(Winners)
	string   line;									// Line of String
	while(getline(teams, line))						// File to Vector (Display Teams)
	{
		iTeam.push_back(line);
	}
	teams.close();
	while(getline(wteam, line))						// File to Vector (Winning Teams)
	{
		wTeam.push_back(line);
	}
	wteam.close();
}
void intro()
{
	string str;										// Line for Team Input
	for(int i = 0; i < iTeam.size(); i++)			
	{
		if(i%2 == 0)
			cout << " * " << iTeam[i];
		else
			cout << right << setw(20) << " * " << iTeam[i] << endl;
	}
	cout << "\n\nEnter A Team\nTo Find Out\nWinning Statistics\n(Case-Sensitive)): ";
	getline(cin,str);
	stat(str);										// Sends the Selection of Team
				 
}
void stat(string str)
{
	int countYears = 1903;							// The year from which my file starts it is 1903
	int count = 0;									// Counts Wins
	for(int i = 0; i < wTeam.size(); i++)
	{
		if(wTeam[i] == str)							// Wins Comparison
		{
			cout << str << " : " <<  countYears << endl;
			count++;
		}
		countYears++;											// Increases Year after loop
		if(countYears == 1904 || countYears == 1994)			// Avoid these years
			countYears++;		
	}
	cout << "\n\nThis Team Has Won: " << count << " Times....!" << endl;
}
