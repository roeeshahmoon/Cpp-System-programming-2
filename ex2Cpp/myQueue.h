/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/

#ifndef EX2CPP_MYQUEUE_H
#define EX2CPP_MYQUEUE_H
#pragma once
#include <climits>

#include <iostream>
#include <vector>

using namespace std;
class myQueue
{
	vector<int>  Queue;
	int maxQ;
public:
	myQueue(int maxQ = INT_MAX);//we did a fefault INT_MAX for deafult constructor
	myQueue(const myQueue& other);

	const bool enQueue(int val); //return True if the insert succeeded and False otherwise

	const bool deQueue(); //return True if the remove succeeded and False otherwise

	const bool isEmpty() const; //return True if the Queue is enpty and False otherwise
	const int peek() const; // return first element FIFO
	int getSize() const;//to get the size
	friend std::ostream& operator<<(std::ostream& out, const myQueue& myQueue);
	vector<int> getV() const;//get the vector
	~myQueue(){}//default destructor
};

#endif // EX2CPP_MYQUEUE_H