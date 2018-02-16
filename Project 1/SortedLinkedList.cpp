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
ListNode * tempPtr;
SortedLinkedList::SortedLinkedList() {
	count = 0;
	currentPos= NULL;
    start = NULL;
    prevPos = NULL;
}

SortedLinkedList::~SortedLinkedList() {
	while (currentPos != NULL) {
		tempPtr = currentPos;
		currentPos = currentPos -> next;
		delete tempPtr;
	}
	count = 0;
    free(tempPtr);
}

int SortedLinkedList::length() const {
	return count;
}

void SortedLinkedList::insertItem(DataType & item) {
    ListNode * input = new ListNode(item); // creating a new node and filling it with the correct int value
    
    //So this currently causes a memory leak or something. the logic is there kinda...
    /* the logic: */
    
    //First if there is no node it will create one.
    if (start == NULL){ //
		currentPos = input;
        start = currentPos;
	}
    /*if there is a node it will check if the starting node is larger or smaller than the input node. if it is smaller than the starting node then there is no need to go further.*/
    else if(start->item.compareTo(item) == DataType::GREATER){
        input->next = start;
        start = input;
    }
    /* here we see that if the input node is larger than the starting node it will begin to iterate though the list of nodes. when it finally finds a node that is greater than the value (ie. no longer less than the input node) then it will come out of the while loop, set the previous node to point to the input node and the input node to point to the one greater than it. it will then free the temporary variables. */
    else if(start->item.compareTo(input->item) == DataType::GREATER){
        ListNode *temp = NULL;
        ListNode *prevTemp = NULL;
        temp = start;
        while(temp->item.compareTo(input->item) == DataType::GREATER){
            prevTemp = temp;
            temp = temp->next;
        }
        prevTemp->next = input;
        input->next = temp;
    }
    
    
}
    
    //ATTEMPT 1, WRONG :(
    /*else if(currentPos->item.getValue() >= input->item.getValue()){
        currentPos->next = input;
        prevPos = currentPos;
        currentPos = input;
    }
    else if(prevPos == NULL&&(currentPos->item.getValue() < input->item.getValue())){
        input->next = currentPos;
        start = input;
        prevPos = NULL;
    }
    else if(currentPos->item.getValue() < input->item.getValue()){
        prevPos -> next = input;
        input -> next = currentPos;
        prevPos = input;
    }*/
//previous code, attempts to make a sortedLinkedList. (didnt work numbers not in order)
    /*  if(head == NULL){
     head = input;
     currentPos = input;
     }
     else{
     currentPos->next = input;
    }
	else{
		currentPos = head;		
		while (input->next != NULL && currentPos->next->item.getValue() < input->item.getValue()) {
			currentPos = currentPos->next;
		}
		input->next = currentPos->next;
		currentPos->next = input;
	}*/


void SortedLinkedList::printList() { // prints out the linked list.
	tempPtr = start;
	while (tempPtr != NULL) {
        std::cout << tempPtr->item.getValue();
        std::cout << " ";
		tempPtr = tempPtr->next;
	}
}




	








