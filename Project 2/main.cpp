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
#include <string>
int fileReadingNumber;
char userInputChar;
int userInputNum;
int continueLoop;
using namespace std;

SortedLinkedList *list = new SortedLinkedList();

void printCommands() { // prints out the commands to the screen and waits for user input.
	std::cout << "insert (i), delete (d), Length (l), print (p), quit (q) /n/n";
}


void fileHandler(string file){ // handles the file input.
    ifstream inFile;
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
        inFile.close();
}

void starter() {
	DataType *startData = new DataType(0);
	list->insertItem(*startData);
}

void printBreakLine() {
	std::cout << "-------------------------------- \n";

}

int main(int argc, const char * argv[]) {
	//string file = argv[1];
    //fjdklsa
	fileHandler("/Users/nekosama/Documents/CS2720Project2/input.txt"); // handles opening the file and creating an (unsorted) Linked List
	printCommands(); // prints the commands and wait for user input.
	continueLoop = 1;
	list->printList();
	while (continueLoop == 1) {
		std::cout << "Enter a command: ";
		cin >> userInputChar;
		switch (userInputChar) {
		case 'i': {
			list->printList();
			std::cout << "Enter Number: ";
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
			std::cout << "Enter value to delete: ";
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
			std::cout << "Enter value to search: ";
			cin >> userInputNum;
			DataType *itemToSearch = new DataType(userInputNum);
			std::cout << list->searchItem(*itemToSearch) << " \n";
			list->printList();
			printBreakLine();
			delete itemToSearch;
			break;
		}

		case 'n': {
			std::cout << list->iterateList() << "\n";
			printBreakLine();
			break;
		}
		case 'r': {
			list->resetIterator();
			std::cout << "Iterator reset. \n";
			printBreakLine();
			break;
		}

		case 'p': {
			list->printList();
			printBreakLine();
			break;
		}
		case 'l': {
			std::cout << "List Length is " << list->length() << "\n";
			printBreakLine();
			break;
		}
		case 'c': {
			list->clear();
			std::cout << "List cleared \n";
			printBreakLine();
			break;
		}
		case 'b': {

			break;
		}
		case 'q': {
			std::cout << "Quitting program.. \n";
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







