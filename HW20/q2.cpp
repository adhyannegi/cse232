#include "q2.hpp"

Counter::Counter(){
    val = 0;
    count = 0;
    log_.push_back("Default Constructor called.");
}

Counter::Counter(int num){
    val = num;
    count = 0;
    log_.push_back("Constructor called with a " + std::to_string(num));
}

Counter::Counter(const Counter & C1){
    val = C1.val;
    log_ = C1.log_;
    count = C1.count;
    log_.push_back("Copy Constructor called.");
}

int Counter::Value(){
    log_.push_back("Value called. Returned a " + std::to_string(val - count));
    return val - count++;
}

std::ostream& operator<<(std::ostream & oss, Counter & C1){
    C1.log_.push_back("<< called.");
    oss << "Counter(" << C1.val << ")@" << C1.val - C1.count;
    return oss;
}

Counter Counter::operator+(const Counter & C1){
    int valuee = val + C1.val;
    Counter ans(valuee);
    for (int i = 0; i < (count + C1.count); i++){
        ans.Value();
        ans.log_.pop_back();
    }
    ans.log_.push_back("+ called.");
    return ans;
}

Counter Counter::operator=(const Counter & C1){
    this->count = C1.count;
    this->val = C1.val;
    this->log_ = C1.log_;
    log_.push_back("= called.");
    return *this;
}