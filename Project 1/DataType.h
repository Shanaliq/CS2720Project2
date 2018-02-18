//
//  DataType.h
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#ifndef DataType_h
#define DataType_h
#include <stdio.h>
#endif /* DataType_h */
enum Comparison {LESS = -1, GREATER = 1, EQUAL = 0};

class DataType{
public:
    explicit DataType(int val); // DataType Object is Created
    Comparison compareTo(DataType &item); // returns an Enum that indicates weather the calling object is Greater, Less or Equal to the item.
    int getValue() const; // return the value instance variable.

private:
    int value;
};












