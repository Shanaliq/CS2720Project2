//
//  main.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
#include "CircularLinkedList.h"
#include <fstream>
#include <string>
using namespace std;
CircularLinkedList list;
ItemType item;
int continueLoop;
char userInputChar;
int userInputNum;
void printCommands() { // prints out the commands to the screen and waits for user input.
	std::cout << "insert (i), delete (d), Length (l), print (p), quit (q) \n\n";
}


void fileHandler(string file){ // handles the file input.
   //THE REQUESTED FILE HANDLER FROM ASSIGNMENT 2 INSTRUCTIONS
    int input;
    std::fstream fs;
    fs.open(file);
    if(fs.is_open())
    {
        fs >> input;
        while(!fs.eof())
        {
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }
    }
    else{
        std::cout<<"Failed to open the input file"<<std::endl;
        exit(0);
    }
    //FILE HANDLER USED IN MY LAST PROGRAM
    /* ifstream inFile;
    inFile.open(file);
    if(!inFile){
        cout << "Unable to open file\n";
        exit(1);
    }
    else{
        while (inFile >> fileReadingNumber){
            DataType *input = new DataType(fileReadingNumber);
            list->insertItem(*input);
            delete input;
        }
    }
        inFile.close();*/
}


void printBreakLine() {
	std::cout << "-------------------------------- \n";

}

int main(int argc, const char * argv[]) {
	//string file = argv[1];
    
	fileHandler("/Users/nekosama/Documents/CS2720Project2/input.txt"); // handles opening the andcreati(unsorted) Linked List
   
    

	printCommands(); // prints the commands and wait for user input.
	continueLoop = 1;
    list.print();
    while (continueLoop == 1) {
        std::cout << "Enter a command: ";
        cin >> userInputChar;
        switch (userInputChar) {
        case 'i': {
            std::cout << "Number to insert: ";
            cin >> userInputNum;
            item.initialize(userInputNum);
            list.insertItem(item);
            list.print();
            printBreakLine();
            break;
           }
        case 'd': {
            std::cout << "Number to delete: ";
            cin >> userInputNum;
            item.initialize(userInputNum);
            list.deleteItem(item);
            list.print();
            printBreakLine();
            break;
        }
        case 'l': {
            std::cout << "List Length is " << list.lengthIs() << "\n";
            printBreakLine();
            break;
        }
        case 'p': {
            list.print();
            printBreakLine();
            break;
        }
        case 'q': {
            std::cout << "Quitting program.. \n";
            exit(0);
            break;
        }
        default:{
                std::cout<<"Command not recognized. Try again\n";
                break;
            }
        }
    }
}







