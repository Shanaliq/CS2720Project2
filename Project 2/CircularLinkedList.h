//
//  CircularLinkedList.hpp
//  Project 2
//
//  Created by Nekosama on 3/9/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#endif /* CircularLinkedList_hpp */

#include "ItemType.h"

struct NodeType{
    ItemType data;
    NodeType *next;
};

class CircularLinkedList {
private:
    int length; // should contain the length of the list.
    NodeType *head;
    NodeType *current;
    
public:
    CircularLinkedList(); // List is Created
    ~CircularLinkedList(); // All Nodes Are Freed.
    void insertItem(ItemType &item); //item is inserted into the list in sorted order.
    void deleteItem(ItemType &item); //node with that item is removed from the list.
    void print();
};
