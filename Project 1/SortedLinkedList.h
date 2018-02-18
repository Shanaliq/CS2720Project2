//
//  SortedLinkedList.hpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#ifndef SortedLinkedList_h
#define SortedLinkedList_h
#include <stdio.h>
#endif /* SortedLinkedList_h */
#include "ListNode.h"

class SortedLinkedList{
private:
    int Length; // should contain the length of the list.
    ListNode *start;
    ListNode *iterator;
    ListNode *prevNode;

public:
    SortedLinkedList(); // List is Created
    ~SortedLinkedList(); // All Nodes Are Freed.
    int length() const; // Returns the Length
    void insertItem(DataType &item); //item is inserted into the list in sorted order.
    void deleteItem(DataType &item); //node with that item is removed from the list.
    int searchItem(DataType &item); //position of node that contains the item is returned
    void clear(); // list contains no items, Length is 0, all node pointer memory freed.
    void pairwiseSwap(); // items in the list are sorted before swapping and the adjacent pare nodes are swapped according to their index positions.
	void printList();
    int iterateList();
    void resetIterator();
};




