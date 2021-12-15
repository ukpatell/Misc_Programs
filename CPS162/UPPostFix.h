/*************************
Name: Umangkumar Patel
Date: February 16, 2020
Prof: Fahringer, Daniel
Prog: Post-Fix Evaluate
**************************/
#ifndef UPPOSTFIX_H
#define UPPOSTFIX_H

class UPPostFix
{
    public:
        int stack[100];     // Initial Start
        int top = -1;       // Initial Val
        void push(int x)    // Push Function
        {
            ++top;
            stack[top]=x;
        }
        int pop()           // Pop Function
        {
            return stack[top--];  
        }   
};

#endif



