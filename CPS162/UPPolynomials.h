/***********************
Name: Umangkumar Patel
Date: February 9, 2020
Prof: Fahringer, Daniel
Prog: Polynomials 
      Class File
***********************/
#ifndef UPPOLYNOMIALS_H
#define UPPOLYNOMIALS_H

class UPPolynomials
{
	private:                        // Private Variables
		struct Poly                 // struct   
		{
			double co;              // Private Members Variables
			double ex;  
			struct Poly *next;      // Next Ptr
		};
		Poly *head1 = 0;            // Initialize to nullptr
		Poly *head2 = 0;
    public:
       	void in1();                 // Function for #1 Input    
       	void in2();                 // ************ #2 Input
       	void addPoly(int);          // Function for Apprehend
       	void showPoly(int);;        // Function for Display
       	void sum();                 // Function for SUM
       	void diff();                // Function for DIFFERENCE
       	void multiply();            // Function for MULTIPLY
       	void menu();                // Function for Menu Display
};
#endif
