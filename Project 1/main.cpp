//
//  main.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
char x;


void insertValue(){
    std::cout << "insertValue function called \n";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Commands,\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n Enter a command:";
   
    x = getchar();
    if(x == 'i'){
        insertValue();
    }
    return 0;
    
    
}



