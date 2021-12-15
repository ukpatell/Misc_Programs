/******************************************************************************
Name: Umangkumar Patel
Date: February 23, 2020
Prof: Fahringer, Daniel
Prog: Double Fibonacci
      Sequence class
      Specification
*******************************************************************************/
#ifndef UPDOUBLEFIBCLASS_H
#define UPDOUBLEFIBCLASS_H
#include<iostream>
using namespace std;

class UPDoubleFibClass 
{
    private:
        struct DoubleNode                   // Struct for Linked-List
        {
            int num;
            struct DoubleNode *preNode;
            struct DoubleNode *nextNode;
        }*begin = NULL;                     // Default Begin
    public:                                 // Functions
        void menu();                        // Menu For The Program
        void create(int);                   // #1 Creates the List
        void display();                     // #2 Displays the List
        void checkCount(int);               // #3 Print Iteration
        void numBefore(int);                // #4 Numbers that calculated
        void numAfter(int);                 // #5 Numbers after the result
        void del(int);                      // #6 Delete Occurances of a Number
                                            // #7 Exit 
};
#endif
