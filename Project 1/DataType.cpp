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

int value;
 DataType::DataType(int value){
    this->value = value;
}

DataType::Comparison DataType::compareTo(DataType &item){
    if(item.value < this->value){
        return GREATER;
    }
    else if(item.value > this -> value){
        return LESS;
    }
    else if(item.value == this -> value){
        return EQUAL;
    }
    else{
        std::cout << "Error";
        return EQUAL;
    }
}

int DataType::getValue() const{
    return value;
}






