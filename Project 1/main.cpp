//
//  main.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright Â© 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
#include "SortedLinkedList.h"
#include <fstream>
#include <string>
int x;
using namespace std;

SortedLinkedList *list = new SortedLinkedList();

void printCommands() { // prints out the commands to the screen and waits for user input.
	std::cout << "Commands,\n\n \t(i) - Insert value \n \t(d) - Delete value \n \t(f) - Search value \n \t(n) - Print iterator's next value \n \t(r) - Reset iterator \n \t(p) - Print list \n \t(l) - Print length \n \t(s) - Parewise Swap \n \t(c) - Clear List \n \t(q) - Quit Program \n\n Enter a command: ";
	x = getchar();
}


void fileHandler(string file) { // handles the file input.
	ifstream inFile;
	inFile.open(file);
	if (!inFile) {
		cout << "Unable to open file\n";
		exit(1);
	}
	else {
		while (inFile >> x) {
			DataType *input = new DataType(x);
			std::cout << x;
			list->insertItem(*input);
		}
	}
	inFile.close();
}

void starter() {
	DataType *startData = new DataType(0);
	list->insertItem(*startData);
}

int main(int argc, const char * argv[]) {
	//starter();
	string file = argv[1];
	fileHandler(file); // handles opening the file and creating an (unsorted) Linked List
	printCommands(); // prints the commands and wait for user input.
	list->printList(); // Prints the list out in its current state.
	DataType *deleteItemTest = new DataType(9);
	DataType *searchItemTest = new DataType(1);
	int pos = list->searchItem(*searchItemTest);
	std::cout << "Position of 1 is : " << pos << endl;
	list->deleteItem(*deleteItemTest);
	list->printList();
	std::cout << "test clear list " << endl;
	list->clear();
	list->printList();
}



