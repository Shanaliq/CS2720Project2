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

class DataType{
public:
    enum Comparison{
        GREATER = 1,
        LESS = -1,
        EQUAL = 0
    };
    
    explicit DataType(int value);
    Comparison compareTo(DataType &item);
    int getValue() const;

private:
    int value;

    
};
