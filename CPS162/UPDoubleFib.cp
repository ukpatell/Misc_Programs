/******************************************************************************
Name: Umangkumar Patel
Date: February 23, 2020
Prof: Fahringer, Daniel
Prog: Double Fibonacci
      Sequence Class 
      Implementation
*******************************************************************************/
#include "UPDoubleFibClass.h"
#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

int run = 1;
// Menu Function For Display
void UPDoubleFibClass::menu()
{
    cout << "\n\n\t\tWelcome to Fahrinacci Sequence\n";
    cout <<  "\t\t------------------------------\n\n";
    cout << "Information:    This Programs Asks The User To.\n";
    cout << "                Enter 2 #'s, Then The Program..\n";
    cout << "                Generates the Sequence From....\n";
    cout << "                Formula: Number = (#1 * 3) = #2\n\n";
    cout << "Operations :    1. Enter Two Numbers & Terms...\n";
    cout << "                2. Displays the Sequence.......\n";
    cout << "                3. Displays the Iterations.....\n";
    cout << "                4. Displays the two previous #.\n";
    cout << "                5. Displays the two after #'s..\n";
    cout << "                6. Deletes All Occurance(s)....\n";
    cout << "                7. Exit........................\n";
}
// #1 Creates the Sequence
void UPDoubleFibClass::create(int n)
{
    struct DoubleNode *b = (struct DoubleNode*) malloc(sizeof(struct DoubleNode));        // Create T Variable
    struct DoubleNode *temp;
    // temp = new(struct DoubleNode);      // New Struct Defined
    //NEW CODE
    b->num = n;
    if(begin ==NULL)
    {
        b->nextNode = NULL;
        b->preNode  = NULL;
        begin = b;
    }
    else
    {
        temp = begin;
        while(temp->nextNode != NULL)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = b;
        b->preNode     = temp;
        b->nextNode    = NULL;
    }
}
// #2 Displays the Sequence
void UPDoubleFibClass::display()        // Displays
{
    struct DoubleNode *p;
    if(begin == NULL)                   // If Start is Null, CERROR
    {
        cerr << "ERROR: List Is Empty" << endl;
        return;
    }
    p = begin;
    cout << "\t\tSequence : " << endl;
    cout << "\t\t\t\t";
    while(p != NULL)
    {
        cout << p->num << " . ";
        p = p->nextNode;
    }
}
// #3 Displays # of Iterations
void UPDoubleFibClass::checkCount(int n)
{
    struct DoubleNode *l;
    int count = 0;                      // Count Variables
    if(begin == NULL)
    {
        cerr << "ERROR: List Is Empty. Can't Process This Request!" << endl;
    }
    else
    {
        l = begin;
        while(l != NULL)
        {
            if(l->num == n)
                count++;
            l = l->nextNode;
        }
        if(count == 0)
            cerr << "ERROR: Number Not Found!" << endl;
        else
        {
            cout << "\n\t\tNumber was Found " << count << " time(s)" << endl;
        }
    }
}
// #4 Displays Two Previous Numbers
void UPDoubleFibClass::numBefore(int n)
{
    struct DoubleNode *pre, *prepre, *now;      // Pointer (s) for track&compare
    
    pre = begin->nextNode;
    prepre = begin;
    now = pre->nextNode;
    
    cout << "\n\t";
    while(now != NULL)                          // Traverse till End
    {
        if(now->num == n)                       // If Match Found
        {
            cout << "Number(s) Are : " << prepre->num << "..." << pre->num << endl;
        }
    }
}
// #5 Displays After Two Numbers
void UPDoubleFibClass::numAfter(int n)
{
    struct DoubleNode *pre, *prepre, *now;
    pre    = begin->nextNode;
    prepre = begin;
    now    = pre->nextNode;
    cout<<"\n";
    
    while(now!=NULL)
    {
        if(now->num == n)
        {
            cout<<"( "<<prepre->num<<"..."<<pre->num;
            return;
        }
    }
}
// #6 Delete Occurance of Number Entered
void UPDoubleFibClass::del(int n)
{
    struct DoubleNode *tempo, *q;
    if(begin->num == n)                     // Deletes the First Element
    {
        tempo = begin;
        begin = begin->nextNode;
        begin->preNode = NULL;
        cout << "\n\tDeleted Successfully....";
        free(tempo);
    }
    q = begin;
    while(q->nextNode->nextNode != NULL)
    {
        if(q->nextNode->num == n) // In Between Elements Deleted 
        {
            tempo = q->nextNode;
            q->nextNode = tempo->nextNode;
            cout << "\n\tDeleted Successfully....";
            free(tempo);
        }
        q = q->nextNode;
    }
    if(q->nextNode->num == n)
    {
        tempo = q->nextNode;
        free(tempo);                        // Malloc Free
        q->nextNode = NULL;
        cout << "\n\tDeleted Successfully....";
    }
}
