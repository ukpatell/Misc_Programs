//
//  main.cpp
//  UPDigitCount
//
//  Created by Umangkumar Patel on 4/23/20.
//  Copyright © 2020 Umangkumar Patel. All rights reserved.
//  Professor  : Fahringer, Daniel
//  Description: Extra Credit-Digit Count

#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

void searchNum(int,int);
void countDigit(int);
vector<int> numbers;

int main()
{
    // Variables
    int a,b,k;
    
    
    
    // Input
    cout << "Enter Prime(a): ";
    cin  >> a;
    
    cout << "Enter Prime(b): ";
    cin  >> b;
    
    cout << "Enter Digit(k): ";
    cin  >> k;
    
    searchNum(a,b);
    countDigit(k);
    return 0;
}
void searchNum(int num1, int num2)
{
    int exit = 0;
    int power = 2;

    int r1, r2, result;
    int b1, b2, result1,result2;
    cout << "\n\tSearching Numbers...\n";
    
    do
    {
        r1 = pow(num1,power);
        r2 = pow(num2,power);
        b1 = pow(num1,power-1);
        b2 = pow(num2,power-1);
        result  = r1*r2;
        result1 = r1*b1;
        result2 = r1*b2;
        if(result >= 10000 && result <= 99999)
            numbers.push_back(result);
        if(result1 >= 10000 && result1 <= 99999)
            numbers.push_back(result1);
        if(result2 >= 10000 && result2 <= 99999)
            numbers.push_back(result2);
        if(result > 99999)
            exit = 1;
        
        power++;
    }while(exit == 0);
}
void countDigit(int n)
{
    cout << "\tCounting Digits...\n\n";
    for(int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
        
    }
}
