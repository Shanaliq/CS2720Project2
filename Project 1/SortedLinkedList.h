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
    int count;
    ListNode *head;
    
public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(DataType &item);
    void deleteItem(DataType &item);
    int searchItem(DataType &item);
    void clear();
    void pairwiseSwap();
    
    
};




