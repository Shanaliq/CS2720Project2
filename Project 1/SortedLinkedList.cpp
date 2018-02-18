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
int lengthCount;
SortedLinkedList::SortedLinkedList() {
	lengthCount = 0;
}

SortedLinkedList::~SortedLinkedList() {

}

int SortedLinkedList::length() const {
	return lengthCount;
}

void SortedLinkedList::insertItem(DataType &item) {
	ListNode *newNode = new ListNode(item);
	if (lengthCount == 0) {
		start = newNode;
		iterator = newNode;
		start->next = NULL;
		std::cout << "handling " << newNode->item.getValue() << "\n";
	}
	else if (start->item.compareTo(newNode->item) == 1) {
		newNode->next = start;
		start = newNode;
		std::cout << "handling " << newNode->item.getValue() << "\n";
	}
	else if (start->item.compareTo(newNode->item) == -1) {
		iterator = start;
		while (iterator->next != NULL) {
			if (iterator->next->item.compareTo(newNode->item) == -1) {
				iterator = iterator->next;
			}
			else {
				break;
			}
		}
		ListNode *tempo;
		tempo = iterator->next;
		newNode->next = tempo;
		iterator->next = newNode;
	}
	std::cout << "handling " << newNode->item.getValue() << "\n";
	lengthCount++;
}

void SortedLinkedList::deleteItem(DataType &item) {
	iterator = start;
	int checkLength = 0;
	while (checkLength < lengthCount) {
		if (iterator->item.compareTo(item) == 0) {
			start = iterator->next;
			delete iterator;
			iterator = start;
			lengthCount--;
		}
		else {
			while (iterator->next->item.compareTo(item) != 0) {
				if (iterator->next != NULL) {
					iterator = iterator->next;
				}
				else {
					std::cout << "no such data exists in the list";
				}
			}
			checkLength++;
		}
	}
}

int SortedLinkedList::searchItem(DataType &item) {
	iterator = start;
	int checkLength = 0;
	if (iterator->next == NULL) {
		if (iterator->item.getValue() == item.getValue()) {
			return 0;
		}
		else {
			std::cout << "not found 1 " << endl;
			return -1;
		}
	}
	while (checkLength < lengthCount) {
		if (iterator->item.getValue() == item.getValue()) {
			return checkLength;
		}
		iterator = iterator->next;
		checkLength++;
	}
	return -1;
}

void SortedLinkedList::clear() {
	iterator = start;
	start = NULL;
	ListNode * temp;
	while (iterator != NULL) {
		temp = iterator->next;
		delete[] iterator;
		iterator = temp;
		lengthCount--;
	}
}

void SortedLinkedList::pairwiseSwap() {

}

void SortedLinkedList::printList() { // prints out the linked list.
	ListNode *tempPtr;
	tempPtr = start;
	while (tempPtr != nullptr) {
		std::cout << tempPtr->item.getValue();
		std::cout << " ";
		tempPtr = tempPtr->next;
	}
	std::cout << endl;
	std::cout << " Length is= (" << lengthCount << ") ";
	std::cout << endl;
	free(tempPtr);
}

void SortedLinkedList::resetIterator() { //resets iterator to start
	iterator = start;
}



