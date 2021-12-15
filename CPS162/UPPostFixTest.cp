/*************************
Name: Umangkumar Patel
Date: February 16, 2020
Prof: Fahringer, Daniel
Prog: Post-Fix Evaluate
	  .cpp file
**************************/
#include<iostream>
#include<ctype.h>
#include<string.h>
#include "UPPostFix.h"
using namespace std;

int main()
{
    UPPostFix obj;                // Create an Object
    char exp[25];               // Storage  
    char *e;                    // Pointer
    int n1,n2,n3,num;

    cout<<"\n**** Post-Fix Evaluation  ***"<<endl;
    cout<<"\nEnter An Expression: "<<endl;
    cin>>exp;                   // input
    
    e = exp;                    // set it equal
    
    while(*e != '\0')           // Loop until end
    {
        if(isdigit(*e))         // If Digit then Push
        {
            num=*e-48;          // ASCII Comparison
            obj.push(num);
        }
        else
        {
            n1=obj.pop();       // Pass to Local then Pop
            n2=obj.pop();       // Pass to Local then Pop
            
            switch(*e)          // Different Cases
            {
                case '+':
                    n3=n1+n2;
                    break;
                case '-':
                    n3=n2-n1;
                    break;
                case '*':   
                    n3=n1*n2;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
            }
            obj.push(n3);       // Push the New Number
        }
        e++;                    // Move On
    }
    cout<<"\nResult "<<exp<<" in Postfix is: "<<obj.pop()<<endl;
                                // Pop the Last One
    return 0;
}
