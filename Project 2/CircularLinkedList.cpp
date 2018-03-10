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
    while (head->next != NULL) {
        NodeType* temp = head->next;
        delete head;
        head = temp;
    }
    length = 0;
}

int CircularLinkedList::lengthIs() const{
    return length;
}

void CircularLinkedList::insertItem(ItemType &item){
    if (length == 0) {
        NodeType *tempNode = new NodeType;
        tempNode->data = item;
        current = tempNode;
        head = tempNode;
        current->next = head;
        //  std::cout << "handling "<< newNode->item.getValue()<< "\n";
    }
    else if (head->data.getValue()  >= item.getValue()) {
        NodeType *tempNode = new NodeType;
        tempNode->data = item;
        tempNode->next = head;
        current->next = tempNode;
        head = tempNode;
        //  std::cout << "handling "<< newNode->item.getValue()<< "\n";
    }
    else if (head->data.getValue() < item.getValue()) {
        NodeType *iterator = new NodeType;
        iterator = head;
        while (iterator->next != head) {
            if (iterator->next->data.getValue() < item.getValue()) {
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
    }
    length++;
    // std::cout << "handling "<< newNode->item.getValue()<< "\n";
}

void CircularLinkedList::deleteItem(ItemType &item){
    NodeType *iterator = new NodeType;
    int counter = 0;
    iterator = head;
    int deletedSomething = 0;
    while(counter < length){
        if(iterator->next->data.getValue() == item.getValue()){
            NodeType *tempNode = new NodeType;
            if(iterator->next == head){
                tempNode = iterator->next;
                iterator->next = iterator->next->next;
                head = iterator->next;
                length --;
                counter--;
                deletedSomething++;
            }
            else if(iterator->next == current){
                tempNode = iterator->next;
                iterator->next = iterator->next->next;
                current = iterator->next;
                length --;
                counter --;
                deletedSomething++;
            }
            else{
                tempNode = iterator->next;
                iterator->next = iterator->next->next;
                length--;
                counter--;
                deletedSomething++;
            }
        }
        else{
         iterator = iterator->next;
        }
        counter++;
    }
    if(deletedSomething==0){
        std::cout<<"Item not in list!\n";
    }
}

void CircularLinkedList::print(){
    NodeType *tempPtr;
    tempPtr = head;
    int counter = 0;
    while (counter < length) {
        std::cout << tempPtr->data.getValue() << " ";
        tempPtr = tempPtr->next;
        counter++;
    }
    //std::cout <<" Length is= ("<<lengthCount<< ") ";
    std::cout << "\n";
}
