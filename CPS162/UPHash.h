//
//  UPHash.h
//  UPHash
//
//  Created by Umangkumar Patel on 4/11/20.
//  Copyright © 2020 Umangkumar Patel. All rights reserved.
//

#ifndef UPHash_h
#define UPHash_h
using namespace std;

class UPHash
{
private:
    struct Candy
    {
        string  IDcode;          // 4-char alphanumeric code
        string  itemName;        // name/description of the candy
        double quantity;         // quantity on hand, in pounds
        double price;            // price per pound
    };
    struct Node                  // Linked-List Node
    {
        Candy c;                 // Candy Structure
        Node *next;              // To Move to Next Node
    };
    int index(string itemQ);     // Index for Hashing
                        
                                 // Access Private Member Functions
    Node *array[25];             // Array of Linked-Lists
    void insertCandy(Candy,int);

public:
    UPHash()
    {
        for(int i = 0; i < 26; i++)
        { array[i] = NULL;}
    }
                    
    int  calcHash(string);                 // Returns index
    void insert(string,string,double,double); // Insert from File
    void available();                      // #1- Availability and Price
    void purchase();                       // #2- Purchase Function
    void delivery();                       // #3- Delivery Function
    void inventory();                      // #4- Inventory Function
};;
#endif /* UPHash_h */
