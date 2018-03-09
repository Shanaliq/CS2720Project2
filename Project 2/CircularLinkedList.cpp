//
//  CircularLinkedList.cpp
//  Project 2
//
//  Created by Nekosama on 3/9/18.
//  Copyright © 2018 Shan Qamruddin. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include "CircularLinkedList.h"
#include <fstream>
#include <string>
using namespace std;
CircularLinkedList::CircularLinkedList(){
    length = 0;
}

CircularLinkedList::~CircularLinkedList(){
    
}

void CircularLinkedList::insertItem(ItemType &item){
    if (length == 0) {
        NodeType *tempNode = new NodeType;
        tempNode->data = item;
        current = tempNode;
        head = tempNode;
        current->next = head;
        length ++;
        //  std::cout << "handling "<< newNode->item.getValue()<< "\n";
    }
    else if (head->data.getVlue()  > item.getVlue()) {
        NodeType *tempNode = new NodeType;
        tempNode->data = item;
        tempNode->next = head;
        current->next = tempNode;
        head = tempNode;
        length ++;
        //  std::cout << "handling "<< newNode->item.getValue()<< "\n";
    }
    else if (head->data.getVlue() < item.getVlue()) {
        NodeType *iterator = new NodeType;
        iterator = head;
        while (iterator->next != head) {
            if (iterator->next->data.getVlue() < item.getVlue()) {
                iterator = iterator->next;
            }
            else {
                break;
            }
        }
        NodeType *tempNode = new NodeType;
        tempNode->data = item;
        tempNode->next = iterator->next;
        iterator->next = tempNode;
        while(iterator->next != head){
            iterator = iterator -> next;
        }
        current = iterator;
        length ++;
    }
    // std::cout << "handling "<< newNode->item.getValue()<< "\n";
}

void CircularLinkedList::deleteItem(ItemType &item){
    
}

void CircularLinkedList::print(){
    NodeType *tempPtr = new NodeType;
    tempPtr = head;
    while (tempPtr->next != head) {
        std::cout << tempPtr->data.getVlue() << " ";
        tempPtr = tempPtr->next;
    }
    //std::cout <<" Length is= ("<<lengthCount<< ") ";
    std::cout << "\n";
    delete tempPtr;
}
