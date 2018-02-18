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
int fileReadingNumber;
char userInputChar ;
int userInputNum;
using namespace std;

SortedLinkedList *list = new SortedLinkedList();

void printCommands(){ // prints out the commands to the screen and waits for user input.
    std::cout << "Commands,\n\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n Enter a command:";
        userInputChar = getchar();
}


void fileHandler(){ // handles the file input.
    ifstream inFile;
    inFile.open("/Users/Home/Desktop/Project 1/input.txt");
    if(!inFile){
        cout << "Unable to open file\n";
        exit(1);
    }
    else{
        while (inFile >> fileReadingNumber){
            DataType *input = new DataType(fileReadingNumber);
            list->insertItem(*input);
        }
    }
        inFile.close();
}

void starter(){
    DataType *startData = new DataType(0);
    list->insertItem(*startData);
}

void printBreakLine(){
    std::cout<<"-------------------------------- \n";
    
}

int main(int argc, const char * argv[]) {
    fileHandler(); // handles opening the file and creating an (unsorted) Linked List
    printCommands(); // prints the commands and wait for user input.
    switch (userInputChar) {
        case 'i':
            list->printList();
            std::cout << "What Number would you like to delete: ";
            cin >> userInputNum;
            DataType *itemToMake = new DataType(userInputNum);
            list->deleteItem(*itemToMake);
            list->printList();
            delete itemToMake;
        case 'd':
            list->printList();
            std::cout << "What Number would you like to delete: ";
            cin >> userInputNum;
            DataType *itemToDelete = new DataType(userInputNum);
            list->deleteItem(*itemToDelete);
            delete itemToDelete;
            break;
            
        case 's':
            <#statements#>
            break;
            
        case 'n':
            <#statements#>
            break;
            
        case 'r':
            <#statements#>
            break;
            
        case 'p':
            <#statements#>
            break;
            
        case 'l':
            <#statements#>
            break;
            
        case 'c':
            <#statements#>
            break;
            
        case 'b':
            <#statements#>
            break;
            
        case 'q':
            <#statements#>
            break;
            
        default:
            break;
    }
    
    if(userInputChar == 'd'){
        list->printList();
        std::cout << "What Number would you like to delete: ";
        cin >> userInputNum;
        DataType *itemToDelete = new DataType(userInputNum);
        list->deleteItem(*itemToDelete);
        list->printList();
        delete itemToDelete;
    }
}



