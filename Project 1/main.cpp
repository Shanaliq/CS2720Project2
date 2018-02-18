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
int continueLoop;
using namespace std;

SortedLinkedList *list = new SortedLinkedList();

void printCommands(){ // prints out the commands to the screen and waits for user input.
    std::cout << "Commands,\n\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n";
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
    continueLoop = 1;
    list->printList();
    while(continueLoop == 1){
        std::cout << "Enter a command: ";
        cin >> userInputChar;
        switch (userInputChar) {
        case 'i': {
            list->printList();
            std::cout << "What Number would you like to insert: ";
            cin >> userInputNum;
            DataType *itemToMake = new DataType(userInputNum);
            list->insertItem(*itemToMake);
            list->printList();
            printBreakLine();
            delete itemToMake;
            break;
        }
        case 'd': {
            list->printList();
            std::cout << "What Number would you like to delete: ";
            cin >> userInputNum;
            DataType *itemToDelete = new DataType(userInputNum);
            list->deleteItem(*itemToDelete);
            list->printList();
            printBreakLine();
            delete itemToDelete;
            break;
        }
            case 's': {
            list->printList();
            std::cout << "What Number would you like to search for: ";
            cin >> userInputNum;
            DataType *itemToSearch = new DataType(userInputNum);
            std::cout << list->searchItem(*itemToSearch)<< " \n";
            list->printList();
            printBreakLine();
            delete itemToSearch;
            break;
            }
                
            case 'n':   {
            
            break;
            }
          
            case 'r': {
            
            break;
            }
          
            case 'p':{
            
            break;
            }
        
            case 'l':{
                break;
            }
            case 'c': {
                
                break;
            }
            case 'b': {
            
                break;
                }
            case 'q':{
                continueLoop = 0;
                break;
            }
            default:
                std::cout << "That is not a valid Input please try again";
                break;
        }
    }
	exit(0);
}



