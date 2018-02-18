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
        if(lengthCount == 0){
            start = newNode;
            iterator = newNode;
            start->next = NULL;
            std::cout << "handling "<< newNode->item.getValue()<< "\n";
        }
        else if(start->item.compareTo(newNode->item) == 1){
            newNode->next =start;
            start=newNode;
            std::cout << "handling "<< newNode->item.getValue()<< "\n";
        }
        else if(start->item.compareTo(newNode->item) == -1){
            iterator = start;
            while(iterator->next != NULL){
                if(iterator->next->item.compareTo(newNode->item) == -1){
                    iterator = iterator->next;
                }
                else{
                    break;
                }
            }
            ListNode *tempo;
            tempo = iterator->next;
            newNode -> next = tempo;
            iterator->next =newNode;
        }
        std::cout << "handling "<< newNode->item.getValue()<< "\n";
        lengthCount++;
    }

    void SortedLinkedList::deleteItem(DataType &item){
        iterator = start;
        ListNode *prevNode;
        prevNode = start;
        int checkLength = 0;
        while(checkLength < lengthCount){
            if(start->item.compareTo(item) == 0){
                start= iterator->next;
                delete iterator;
                iterator = start;
                lengthCount --;
        }
        else{
            while (iterator -> next != NULL) {
                if(iterator->next->item.compareTo(item) == 0){
                    prevNode = iterator;
                    iterator = iterator->next;
                    prevNode->next = iterator->next;
                    delete iterator;
                    lengthCount--;
                    iterator =prevNode;
                }
                else{
                    iterator = iterator->next;
                    checkLength++;
                }
                checkLength++;
            }
        }
    }
}


    int SortedLinkedList::searchItem(DataType &item){
        return 0;
    }

    void SortedLinkedList::clear(){
    
    }

    void SortedLinkedList::pairwiseSwap(){
    
    }

void SortedLinkedList::printList() { // prints out the linked list.
    ListNode *tempPtr;
    tempPtr = start;
    while (tempPtr != nullptr) {
        std::cout << tempPtr->item.getValue();
        std::cout << " ";
        tempPtr = tempPtr->next;
    }
    std::cout <<" Length is= ("<<lengthCount<< ") ";
    std::cout << "\n";
    free(tempPtr);
	}


    
