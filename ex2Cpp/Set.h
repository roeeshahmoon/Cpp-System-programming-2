/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/
#ifndef EX2CPP_SET_H
#define EX2CPP_SET_H

#include <iostream>

using namespace std;

class Set {
    int maxSize; // maximal number of elements.
    int currentSize; //current number of elements.
    int *arr;
public:
    Set(int MaxSize = 1000); //Default constructor() Initialize maxSize to 1000 and allocate memory for an integer array with the size
    Set(const Set &other);
    int getCurrentSize() const; //- Return the value of currentSize
    int *getArr() const; //- Return the value of currentSize

    friend std::ostream &operator<<(std::ostream &out, const Set &set);
    const int& operator[](int index) const;
    Set& operator=(Set const &other) ;
    Set operator+=(const int& int_add);
    Set operator+(const int& int_add);
    Set operator+(const Set& set_two);
    bool operator>(const Set& set) const;
    bool search (int* arr, int size, int value) const;
    friend Set operator+(const int num, Set& set);
    Set CheckOverLoadSet(Set &set);
    ~Set();
};


#endif //EX2CPP_SET_H
