//
//  SortedLinkedList.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include <iostream>
#include "SortedLinkedList.h"
using namespace std;
int cTest = 0;

SortedLinkedList::SortedLinkedList() {
	count = 0;
	currentPos= NULL;
}

SortedLinkedList::~SortedLinkedList() {
	ListNode * tempPtr;
	while (currentPos != NULL) {
		tempPtr = currentPos;
		currentPos = currentPos -> next;
		delete tempPtr;
	}
	count = 0;
}

int SortedLinkedList::length() const {
	return count;
}

void SortedLinkedList::insertItem(DataType & item) {
    ListNode * input = new ListNode(item); // creating a new node and filling it with the correct int value
    if (currentPos == NULL){
		currentPos = input;
        start = currentPos;
	}
    else{
        currentPos->next = input;
        currentPos = input;
    }
}
//previous code, attempts to make a sortedLinkedList. (didnt work numbers not in order)
    /*  if(head == NULL){
     head = input;
     currentPos = input;
     }
     else{
     currentPos->next = input;
    }
	/*else{
		currentPos = head;		
		while (input->next != NULL && currentPos->next->item.getValue() < input->item.getValue()) {
			currentPos = currentPos->next;
		}
		input->next = currentPos->next;
		currentPos->next = input;

	}*/


void SortedLinkedList::printList() {
	ListNode * tempPtr = start;
	while (tempPtr != NULL) {
        std::cout << tempPtr->item.getValue();
        std::cout << " ";
		tempPtr = tempPtr->next;
	}
}




	








