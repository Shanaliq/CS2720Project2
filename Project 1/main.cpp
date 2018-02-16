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

SortedLinkedList *list = new SortedLinkedList();

void printCommands(){ // prints out the commands to the screen and waits for user input.
    std::cout << "Commands,\n\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n Enter a command:";
        x = getchar();
}

void fileHandler(){ // handles the file input.
    ifstream inFile;
    inFile.open("/Users/nekosama/Desktop/Project-1-Data-Structures/input.txt");
    if(!inFile){
        cout << "Unable to open file\n";
        exit(1);
    }
    else{
        while (inFile >> x){
            DataType *input = new DataType(x);
            list->insertItem(*input);
        }
    }
        inFile.close();
}


int main(int argc, const char * argv[]) {
    fileHandler(); // handles opening the file and creating an (unsorted) Linked List
    printCommands(); // prints the commands and wait for user input.
    list->printList(); // Prints the list out in its current state.
}



