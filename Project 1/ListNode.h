//
//  ListNode.hpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>

#include "DataType.h"
#endif /* ListNode_h */


struct ListNode{
    DataType item;
    ListNode *next;
    explicit ListNode(DataType &item):item(item){}
    
};

