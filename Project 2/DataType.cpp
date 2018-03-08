//
//  DataType.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
#include "DataType.h"
#include <stdio.h>

 DataType::DataType(int val){
     value = val;
}

Comparison DataType::compareTo(DataType &item){
    if(value < item.value){
        return LESS;
    }
    else if(value > item.value){
        return GREATER;
    }
    else {
        return EQUAL;
    }
}

int DataType::getValue() const{
    return this->value;
}




