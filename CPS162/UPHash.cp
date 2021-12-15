//
//  UPHash.cpp
//  UPHash
//
//  Created by Umangkumar Patel on 4/11/20.
//  Copyright © 2020 Umangkumar Patel. All rights reserved.
//

#include <string>
#include<iostream>
#include "UPHash.h"
using namespace std;


// Functions for the Program
int UPHash::calcHash(string id)
{
    int hash = id.at(0);                                        // First Alpha
                                                                // Generates Location 0-25 using ASCII
      if(hash>=97)
          hash=hash-97;
      else
          hash=hash-65;
      return hash;                                              // Returns Location for Array
}
void UPHash::insert(string id, string name, double q, double p)
{
    Candy c;                                                    // Create Candy Structure
    int location;                                               // Create Location Variable
    c.IDcode   = id;                                            // Pass Candy Data in Structure
    c.itemName = name;                                          // *
    c.quantity = q;                                             // *
    c.price    = p;                                             // *
    
    location = calcHash(id);                                    // Compute Array Location
    insertCandy(c,location);                              // Pass to Candy Insertion in Array Function
}
void UPHash::insertCandy(Candy cand, int i)
{
    Node* p=new Node;
    p->c=cand;
    p->next=NULL;

    Node *ptr= array[i];
    if(ptr!=NULL)
    {
        p->next=ptr; //moves head to next
    }
    ptr=p;
    array[i]=ptr;
}





