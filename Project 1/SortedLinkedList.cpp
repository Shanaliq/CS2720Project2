//
//  SortedLinkedList.cpp
//  Project 1
//
//  Created by Shan Qamruddin on 2/12/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//

#include "SortedLinkedList.h"


SortedLinkedList::SortedLinkedList() {
	count = 0;
	head = NULL;
}

SortedLinkedList::~SortedLinkedList() {
	ListNode * tempPtr;
	while (head != NULL) {
		tempPtr = head;
		head = head -> next;
		delete tempPtr;
	}
	count = 0;
}

int SortedLinkedList::length() const {
	return count;
}

void SortedLinkedList::insertItem(DataType & item) {
	ListNode * input = new ListNode(item);
	ListNode * currentPos;
	if (head == NULL || head->item.getValue() >= input ->item.getValue()) {
		input->next = head;
		head = input;
	}
	else{
		currentPos = head;		
		while (input->next != NULL && currentPos->next->item.getValue() < input->item.getValue()) {
			currentPos = currentPos->next;
		}
		input->next = currentPos->next;
		currentPos->next = input;

	}
}




	








