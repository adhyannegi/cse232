#include<iostream>
#include<sstream>
#include<stdexcept>
#include<string>
#include <algorithm>

#include "singlelink.hpp"

SingleLink::SingleLink(){
    head_ = new Node();
    tail_ = head_;
    head_->next_ = nullptr;
}

SingleLink::SingleLink(int dat){
    Node *New_Node = new Node(dat);
    head_ = New_Node;
    tail_ = New_Node;
}

void SingleLink::append_back(int dat){
    Node *New_Node = new Node(dat);
    if (tail_ == nullptr || head_ == nullptr){
        head_ = New_Node;
        tail_ = New_Node;
    }
    else {
        tail_->next_ = New_Node;
        tail_ = New_Node;
    }
}

std::ostream & operator<<(std::ostream &out, const SingleLink &s){
    if (s.head_ == nullptr){
        out << " ";
    }
    else{
        Node* current = s.head_;
        while (current->next_ != nullptr){
            out << current->data_ << ", ";
            current = current->next_;
        }
        out << current->data_;
    }
    return out;
}

bool SingleLink::del(int val){
    //empty list
    if (head_ == nullptr){
        return false;
    }

    Node* current = head_;
    Node* previous = nullptr;

    while ((current != nullptr) && (current->data_ != val)){
        previous = current;
        current = current->next_;
    }

    //element not present in list
    if (current == nullptr){
        return false;
    }

    //element present at head
    if (current == head_){
        head_ = current->next_;
    }

    //element present at tail
    if (current == tail_){
        tail_ = previous;
        tail_->next_ = nullptr;
    }

    //value is in the middle of list
    previous->next_ = current->next_;

    delete current;
    return true;
}

Node & SingleLink::operator[](size_t index){
    Node * current = head_;
    size_t count = -1;
    while ((current != nullptr)){
        count++;
        if (count == index){
            return *current;
        }
        current = current->next_;
    } 
    throw std::out_of_range("Error");
}