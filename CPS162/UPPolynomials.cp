/***********************
Name: Umangkumar Patel
Date: February 9, 2020
Prof: Fahringer, Daniel
Prog: Polynomials 
      Specification File
***********************/
#include "UPPolynomials.h"
#include<iostream>
using namespace std;

void UPPolynomials::in1()
{
   int c,e;                         // Local Variables for Coeff, Expo.
   int i = 0;                       // Counter
   Poly *temp = head1;              // Head Track
   
   cout << "\n\tWelcome to Polynomials...!\n\n";
   cout << "\tEnter Two Sets for Polynomials\n";
   cout << "\tTo Perform Actions on them later\n";
   cout<<"\n................Polynomial 1: \n";
  
   while(true)
   {
       cout<<"Coefficient Term # "<<i+1<<": ";
       cin>>c;                      // Input Coefficient
      
       cout<<"Power for Term # "<<i+1<<"(-1 to exit): ";
       cin>>e;                      // Input Exponent
       cout<<endl;
       if(e == -1)                  // Break Statement
           break;
       else
       {
           temp = head1;            // Reassign
           if(temp == NULL)
           {
                                    // empty polynomial
               temp = new Poly;
               temp->co = c;        // Assign to Val.Coefficient
               temp->ex = e;        // Assign to Val.Exponent
               temp->next = NULL;   // Set Null, if n.mre
              
               head1 = temp;
           }
           else
           {
                                    // create a new node and insert at last
               while(temp->next != NULL)
                   temp = temp->next;
                  
               Poly *temp1 = new Poly;
               temp1->co = c;
               temp1->ex = e;
               temp1->next = NULL;
               temp->next = temp1;
           }
       }
       i++;                         // Increment
   }
}
void UPPolynomials::in2()
{
   int c, e;                        // Local V.
   int i = 0;                       // Counter
   Poly *temp = head2;              // Assign to 2nd Head
   cout<<"\n................Polynomial 2: \n";
  
   while(true)                      // Loop until Counter
   {
       cout<<"Coefficient # "<<i+1<<": ";
       cin>>c;
      
       cout<<"Power for term # "<<i+1<<"(-1 to exit): ";
       cin>>e;
       cout<<endl;
      
       if(e == -1)
           break;
       else
       {
           temp = head2;
           if(temp == NULL)
           {
               // empty polynomial
               temp = new Poly;
               temp->co = c;
               temp->ex = e;
               temp->next = NULL;
              
               head2 = temp;
           }
           else
           {
               // create a new node and insert at last
               while(temp->next != NULL)
                   temp = temp->next;
                  
               Poly *temp1 = new Poly;
               temp1->co = c;
               temp1->ex = e;
               temp1->next = NULL;
               temp->next = temp1;
           }
       }
       i++;
   }  
}
void UPPolynomials::showPoly(int n)         // Poly Display
{
    Poly *temp;                 // Pointer to Head, to display
    if(n == 1)
    { 
        temp = head1;           // ASsisgns the HEad based on INT
        cout<<"Polynomial #1: ";
    }
    else 
    { 
        temp = head2;
        cout << "Polynomial #2: ";
    }
    while(temp != NULL)         // Until it reached End
    {
       if(temp->next != NULL)
           cout<<temp->co<<"x^"<<temp->ex<<" + ";
       else
           cout<<temp->co<<"x^"<<temp->ex<<endl;
      
       temp=temp->next;
    }
}
void UPPolynomials::addPoly(int n)  // ADDITION
{
    int c, e;                       // Local V.
    int i = 0;                      // Counter
    Poly *temp;                     // Temp Ptr.
    
    if(n == 1)
    { 
        temp = head1;               // Assigns accordingly
        cout<<"ADD TO Polynomial #1: ";
    }
    else 
    { 
        temp = head2;
        cout << "ADD TO Polynomial #2: ";
    }
    
   while(true)                      // While Condition is Met
   {
       cout<<"Coefficient for Term # "<<i+1<<": ";
       cin>>c;
      
       cout<<"Power for Term # "<<i+1<<"(-1 to exit): ";
       cin>>e;
       cout<<endl;
       if(e == -1)                  // Break Statement
           break;
       else
       {
           temp = head1;
           if(temp == NULL)
           {
               // empty polynomial
               temp = new Poly;
               temp->co = c;
               temp->ex = e;
               temp->next = NULL;
               head1 = temp;
           }
           else
           {
               // create a new node and insert at last
               while(temp->next != NULL)
                   temp = temp->next;
                  
               Poly *temp1 = new Poly;
               temp1->co = c;
               temp1->ex = e;
               temp1->next = NULL;
               temp->next = temp1;
           }
       }
       i++;
   }

}
void UPPolynomials::menu()
{
    system("CLS");
    cout << "\n\tWelcome to Polynomials...!\n\n";
    cout << "\tChoose from the menu to perform action...\n";
    cout << "1. Display     Polynomial #1\t2. Display     Polynomial #2\n";
    cout << "3. Add Term To Polynomial #1\t4. Add Term To Polynomial #2\n";
    cout << "5. Addition of Polynomials  \t6. Subtraction(#1 - #2)     \n";
    cout << "7. Multiplication to #1     \t8. Exit the Menu\n\n";
}
void UPPolynomials::multiply()
{
   int c,e;                     // Input for Multiplication
   cout<<"Enter Coefficient for Multiplication: ";
   cin>>c;
   cout<<"Power: ";
   cin>>e;
  
   Poly* temp1 = head1;         // Head 1 Multiplication
  
   while(temp1 != NULL)         // Complete till END
   {
       if(temp1->next != NULL)
       {
           if(c > 0)
           {cout<<temp1->co * c<<"x^"<<temp1->ex*e<<" + ";}
           else
           {cout<<temp1->co * c<<"x^"<<temp1->ex*e<<" ";}
       }
       else
       {
           if(c > 0)
           { cout<<temp1->co* c<<"x^"<<temp1->ex*e<<endl;}
           else
           { cout<<temp1->co * c<<"x^"<<temp1->ex*e<<" ";}
       }
       temp1 = temp1 -> next;
   }
}
