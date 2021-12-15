/*************************
Name:	Umangkumar Patel
Date:	November 17, 2019
Prof:	Fahringer, Daniel
Prog:	Pointers #9
		Use it to compare
		Source/charSet
**************************/
#include<iostream>
using namespace std;

char *searcher (char*, char*);								// Searcher Function returning char
int main()
{
    char source[100], charSet[100]; 						// Hold Char-String Values
    char *sourcePtr  = nullptr;								// Pointers
	char *charSetPtr = nullptr;								// ********
	char rerun;												// Rerun Value
	
	while(true)
    {
    	system("cls");										// Clear Screen
    	cout<<"\n\t* * * Details * * * \n\n";
        cout<<"Enter Source  String  : "; 					// Input Source String
		gets(source); 										// *******************
		sourcePtr = source;									// Pass it to the Pointer

        cout<<"Enter Charset String  : "; 					// Input Source String
		gets(charSet);										// *******************
		charSetPtr = charSet;								// Pass it to the Pointer
		
		system("cls");										// Clear Screen
		system("color b4");									// Color Change
		cout<<"\t\t* * * Information * * *\n";
        cout<<"\nSource  String	       :\t"<<source; 		// Print Source
		cout<<"\nCharset String         :\t"<<charSet;		// Print charSet

		cout<<"\nSource  String(Address):\t"<<&sourcePtr<<endl; // Print Address(Source)
    
        char *c = searcher(sourcePtr,charSetPtr);				// Call Searcher

        if(c == NULL)							     		 // Print Unsuccesfull Message
        	cout << "\nSearch was Unsuccessful......\n";
    	else												 // Print Substring
			cout<<"Subtring               :\t"<< c <<endl;
		
		cout <<"\nRerun the Program(Y/N) :\t"; 				 // Rerun Input(user)
        cin  >> rerun; 
		
		if(rerun =='n'||rerun =='N')						 // Rerun Handler
			break;
	    cin.ignore();										 // Remove Carriage Return from Buffer
    }
	return 0;
}

char *searcher (char *source, char *charSet)
{
	while(*source!='\0')									 // Parse Till The End
    {
		char *temp = charSet; 								 // Temp. Pointer
        while(*temp!='\0')									 // source.compare(temp) 
        {
			if(*temp==*source)								 // Return to Pointer, if Found
                return source;
            temp++;											 // Next Char
        }
        source++; 											 // Next Char(Source)
    }
	return NULL; 											 // Default Return for No Found
}
