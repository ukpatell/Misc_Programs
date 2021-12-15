/**************************
Name:	Umangkumar Patel
Date:	November 24, 2019
Prof:	Fahringer, Daniel
Prog:	Pig-Latin
***************************/
#include<iostream>
#include<cstring>									// C-Strings
#include<vector>									// Use of Vectors
#include<fstream>									// File Output
using namespace std;

string rLine    = "";  								// *	Reverse Line Created
//char* linePtr = 0;								// *	Null Pointer Created
ofstream outFile;									// Output File
													// Function Declaration
void reversal(char*, int);							// *	Conversion 1: Reversal
bool vowel(char*);									// Checks Vowels 
void pigLatin(char*,int);							// Second Conversion(piglatin)

int main()											// Main Function
{
															// Variable Declaration
	char line[]  =
		 "I love Paris in the Spring time.";		// *	Char Line1
	char line2[] =
	 	 "Mary, my friend, had a lamb.";			// *	Char Line2
	char line3[] = "Hello?  Hello?  Are you still there?";	// *	Char Line3
	char line4[] = 
	 	 "John said, “Whoop Dee Doo!”, then skipped, hopped, and twirled."; 	// * Char Line4
	outFile.open("Pig Latin Solution.txt");			// Output File Opened
	outFile << "\nName:\tUmangkumar Patel\n";		// Output Data (Header)
	outFile <<   "Date:\tNovember 24, 2019\n";		// *
	outFile <<   "Prof:\tFahringer, Daniel\n";		// *
	outFile <<   "Prog:\tPig-Latin Strings\n\n";	// *
	
	system("color f1");	system("cls");				// Color Change of Console
	
	int length = sizeof(line);						// * Size of Line to Pass
	int l2 = sizeof(line2);							// * Size of Line to Pass
	int l3 = sizeof(line3);							// * Size of Line to Pass
	int l4 = sizeof(line4);							// * Size of Line to Pass
													// Post Input (Original) to File
	outFile <<   "\n\tInput  \n\t\t" << line 		// *
		<< "\n\t\t" << line2 << "\n\t\t" << line3 	// *
		<<	 "\n\t\t" << line4;						// *
	outFile <<	 "\n\tOutput : ";					// Post Output (Reversed) header to File
	
	reversal(line,length);							// Call the Reversal Function
	reversal(line2,l2);								// Reversals of Line
	reversal(line3,l3);
	reversal(line4,l4);
	outFile << "\n";
	pigLatin(line,length);	
	pigLatin(line2,l2);								// Pig-Latin
	pigLatin(line3,l3);					
	pigLatin(line4,l4);
	
	outFile.close();								// Output File Closed
	cout << "\n\t\tYour Output has been saved as Pig Latin Solution.txt " << endl;
	return 0;
}
void reversal(char* l, int size)					// Calculates a String 
{
	string reverseLine = "";
	
	char alpha = ' ';								// Temp. character for input
	for (int i = 0; i < size; i++) 					// Until the size of the line
	{
		if(!ispunct(l[i])) 							// If Not Punct. then Proceed
		{
			if(isspace(l[i]))						// If Space, Add Space
				rLine += " ";
			else									// Else...
			{
				alpha = l[i];
				alpha = toupper(alpha);				// Convert it to Upper-Case
				rLine = rLine + alpha;				// concatinate
				alpha = ' ';						// Clear temp
			}
        }
		else 
		{
			rLine += " ";			    			// Remove Punct and Add Space
		}
    }
	for(int i=size-1; i>=0; i--)					// Reversal
	{	
		char array[20] = "";						// Word Array to Hold			
		
		int idx = 0;
		while(rLine[i] != ' ' && i>=0 && rLine[i] != '\0')
		{
			array[idx] = rLine[i];
			idx++;
			i--;
		}
		array[idx] = '\0';							
		for(int k=idx-1; k>=0; k--)
			reverseLine += array[k];				// Concatinate Strings
		reverseLine += " ";							// Add Spaces
	}
	while(reverseLine[0] == ' ')					// Removal Of Additional Characters 
	{
		reverseLine.erase(reverseLine.begin());		// Remove 
	}
	outFile << "\n\t\tReversed  : " << reverseLine;	// Display to Output
	rLine = "";
}
bool vowel(char ch)									// Vowels
{
	if(ch == 'a' || ch == 'A' || ch == 'e' || ch=='E' || ch == 'i' || ch == 'I'
	   || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
	{	
		return true;
	}
	else
		return false;

}
void pigLatin(char *sentence, int size)
{

	int temp = 0;									// Temp
	string pig = "";								// Empty String
	
	for(int i=0; i<size; i++)
	{	
		char array[20] = "";
		int idx = 0;
		while(i< size && sentence[i] != ' ')			// Convert to Lower
		{	
			if((sentence[i]<91 && sentence[i]>=65) || (sentence[i]<123 && sentence[i]>=97))
			{
				array[idx] = tolower(sentence[i]);
				idx++;
			}
			i++;
		}
		if(vowel(array[0]))							// Checks if first element is vowel
		{
			pig += array;
			pig += "-way ";
		}
		else
		{
			char array2[20] = "";					// In-arr
			char array3[20] = "";					// IN-Va. arr
			int counter1 = 0;						// In Count
			int counter2 = 0;
			while(!vowel(array[counter1])&&isalpha(array[counter1]))			// Until No-Vowel
			{
				array2[counter1] = array[counter1];
				counter1++;

			}
			while(counter1<idx)						
				array3[counter2++] = array[counter1++];

			if(temp == 0)							// Set-UP For Fst temp
			{
				array3[0] = toupper(array3[0]);
				temp = 1;
			}
			pig += array3;
			pig += "-";
			pig += array2;
			pig += "ay ";
		}
	}
	outFile <<   "\n\t\tPig-Latin : " << pig;			// Post Output(Pig-Latin) header to File
	pig = "";
}
