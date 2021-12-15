//
//  main.cpp
//  UPHeapify
//
//  Created by Umangkumar Patel on 4/23/20.
//  Copyright © 2020 Umangkumar Patel. All rights reserved.
//  Professor: Fahringer, Daniel
//  Program  : Heap Sort Assignment #9

#include <iostream>
#include <fstream>
#include <cmath>
//using namespace std;                    // Has been neglected due to array
                                          // *                     ambigious

const int SIZE = 25;                      //  Size
int array[SIZE];                          //  array

void heapify(int);                        //  List to Heap w. Heapify Algorithm
void heap();                              //  Recursive Func. For each parents
void heap_sort();                         //  Sort
void print(int []);                       //  Prints in order
void displayArr();                        //  Display Array
void finalPrint();                        //  Ascending Order Array
// ***        Nyoff Book 13.1      ***    //  Reference
void displayTree();                       //  Display using Binary Tree
void displayLevel(int [],int,int,int,int);//  Display Levels

int main()
{
    std::ifstream inFile;                 // Input File  Object

    int num,s=0;                          // Num from file & array location
    
                                          // Attempt to open file
    inFile.open("/Users/jayswaminarayan/Desktop/xCPP/xCode/UPHeapify/UPHeapify/text.txt");
    
    if (!inFile)                          // If Not Open throw Error
    {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);                          // Terminate
    }
    
    while(inFile >> num)                  // Post-File Open Successful
    {
        array[s] = num;                   // Fill Array
        s++;                              // Increment Location
    }
    
    std::cout << "Initial Array ~ \n";
    displayArr();
    displayTree();
    
    heap();                               // Call for Heap_Recursive
    std::cout << "\nPost-Heapify  ~ \n";
    displayArr();
    displayTree();
    
    std::cout << "\nPost-Heapsort ~ \n";
    heap_sort();                          // Call for Heap_Sort
    displayArr();
    return 0;
}
void heap()
{
    for (int i = SIZE / 2 - 1; i >= 0; i--) // Build heap
        heapify(i);
}
void heapify(int l)
{
     int max   = l;                         // l is the largest element
     int left  = 2*l + 1;                   // Left = 2*l + 1
     int right = 2*l + 2;                   // Right = 2*l + 2
    
                                            // If Left child >  than max
     if (left < SIZE && array[left] > array[max])
         max = left;
                                            // If Right child is > largest so far
     if (right < SIZE && array[right] > array[max])
         max = right;
    
     if (max != l)                          // If largest is not max
     {
        std::swap(array[l], array[max]);    // Swap l and largest
        heapify(max);                       // Recursively heapify the sub-tree
     }
}
void heap_sort()
{
    for (int i=SIZE-1; i>=0; i--)
     {
        std::swap(array[0], array[i]);      // Move current root to end
        heapify(i);                         // again call max heapify on the reduced heap
     }
}
// **************************************************************** //
// Display Functions
// 1. Display Using For Loop(Array)
// 2. Display Trace Execution
// **************************************************************** //

void displayArr()
{
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << " " << array[i] << " ~";
    }
    std::cout << std::endl;
}
void displayTree()                          // ** FOLLOWING HAS BE REFERENCED FROM NYOFF TEXTBOOK **
{
    int beginIndex = 0,                     // Index of first node on some level
        endIndex = 0,                       // " "1ast node on this 1evel
        rowLength,                          // length of current row
        numLevels = int(ceil(log(float(SIZE))/log(2.0))); // Number of levels
   
    for (int level = 0; level < numLevels; level++)
    {
        displayLevel(array, numLevels, level, beginIndex, endIndex);
        rowLength = endIndex - beginIndex + 1;
        beginIndex = endIndex + 1;
        endIndex = std::min(endIndex + 2*rowLength,SIZE-1);
    }
                       }
void displayLevel(int x[],int numRows,int level, int beginIndex, int endIndex)
{
    int skip = int(pow(2.0, numRows - level) - 1);
    for (int i = beginIndex; i <= endIndex; i++)
    {
        std::cout << std::setw(skip) << " ";
        std::cout << std::setw(2) << x[i];
        std::cout << std::setw(skip) << " ";
    }
    std::cout << "\n\n";
}
