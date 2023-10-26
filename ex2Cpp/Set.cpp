/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/

#include "Set.h"
#include <iostream>

using namespace std;

Set::Set(int MaxSize) { //Set constructor
    maxSize = MaxSize;
    currentSize = 0;
    arr = new int[MaxSize]; //arr dynamic memory allocation
}
//Set Copy Constructor
Set::Set(const Set &other){
    *this = other;
}

int Set::getCurrentSize() const { return currentSize; }  //return the currentSize
int *Set::getArr() const { return arr; }  //return the arr

std::ostream &operator<<(std::ostream &out, const Set &set) {//Print Set values using << operator
    out << "{";
    for (int i = 0; i < set.getCurrentSize(); i++) {
        if (i>0){
            out<< ", ";}
        out << set.getArr()[i];
    }
    out << "}";
    return out;
}

Set &Set::operator=(const Set &other) {//Set opertor =
        this->maxSize = other.maxSize;
        this->currentSize = other.currentSize;
        this->arr = new int [other.maxSize];
        for(int i = 0; i <currentSize; i++){
            this->arr[i] =other.arr[i];
        }
    return *this;
}

Set Set::operator+=(const int &int_add) {//Adding int to set
    CheckOverLoadSet(*this);
    bool exist_bool = this->search(this->arr, this->currentSize, int_add);
    if (!exist_bool) {
        this->arr[this->currentSize] = int_add;
        this->currentSize++;
        return *this;
    }
    return *this;
}
Set operator+(const int num, Set& set) { //making operator + be symmetric
    return set + num;
}



Set Set::operator+(const int &int_add) {//Adding int to a set create new set
    Set set;
    set = *this;
    CheckOverLoadSet(*this);
    bool exist_bool = set.search(set.arr, set.currentSize, int_add);
    if (!exist_bool) {
        set.arr[set.currentSize] = int_add;
        set.currentSize++;
        return set;
    }
    return set;
}

Set Set::operator+(const Set &set_two) { //Adding set to a set create new union set
    Set set_union;
    set_union.currentSize = this->currentSize + set_two.currentSize; //update set union size
    bool exist_bool;
    int new_int = 0, idx = 0;
    int cnt_exist = 0;
    CheckOverLoadSet(*this);
    for (int k = 0; k < set_union.currentSize; k++) {
        if (k >= this->currentSize) {
            idx = k - (this->currentSize);
            new_int = set_two.arr[idx];
            exist_bool = this->search(this->arr, this->currentSize, new_int);
            if (!exist_bool) {
                set_union.arr[k- cnt_exist] = new_int;
            }
            else{cnt_exist++;}
        } else {
            set_union.arr[k] = this->arr[k];
        }
    }
    set_union.currentSize -= cnt_exist; //update set union size without duplicates
    return set_union;
}

bool Set::operator>(const Set &set) const { //check which group is bigger by > operator
    if ((this->currentSize) > (set.currentSize))
        return true;
    else
        return false;
}

const int& Set:: operator[](int index) const { //return a member of  set, in index given by operator[]
    return this->arr[index];
}

bool Set::search(int *arr, int size, int value) const {//Assistance function to check if a member already exists in the Set
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
Set Set::CheckOverLoadSet(Set &set){ //check if current size == maxSize if True return new memory allocated
    if ((this->currentSize + 1) == this->maxSize){
        this->maxSize = 2*(this->maxSize);
        int *p = new int[(this->maxSize)];
        for(int i = 0; i <currentSize; i++){
            p[i] = this->arr[i];
        }
        delete []this->arr;
        this->arr = p;
    }
    return *this;
}

Set::~Set() {    //destructor
    delete[]this-> arr; // Freeing The Memory Allocated For arr
}
