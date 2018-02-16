//
//  main.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
#include "SortedLinkedList.h"
#include <fstream>
int x;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Commands,\n\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n Enter a command:";
   
    x = getchar();
    ifstream inFile;
    inFile.open(argv[2]);
    if(!inFile){
        cout << "Unable to open file";
        exit(1);
    }
    while (inFile >> x){
        std::cout << x;
        std::cout << " ";
    }
    inFile.close();
}



