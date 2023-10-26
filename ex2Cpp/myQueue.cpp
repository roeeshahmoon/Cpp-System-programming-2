/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/
#include "myQueue.h"

using namespace std;

myQueue::myQueue(int maxQ) {
	Queue = {};
	this->maxQ = maxQ;
	
}
//myQueue Copy Constructor
myQueue::myQueue(const myQueue& other):maxQ(other.maxQ) {
	this->Queue = other.Queue;
}
const bool myQueue::enQueue(int val) {//return True if the insert succeeded and False otherwise
	int a = Queue.size();
	if (Queue.size() >= maxQ) {
		return false;
	}
	else {
		Queue.push_back(val);
		return true;
	}
}
	

const bool myQueue::deQueue() { //return True if the remove succeeded and False otherwise
	if (Queue.size() > 0) {
		Queue.erase(Queue.begin());
		return true;
	}
	return false;
}


const bool myQueue::isEmpty() const {//return True if the Queue is empty and False otherwise
		//std::vector<int>  Queue;
		return Queue.empty();
	}
	const int myQueue::peek() const { // return first element FIFO
		//std::vector<int>  Queue;
		if (this->isEmpty() == 0) {
			return Queue[0];
		}
		return -1;
	}
	int myQueue::getSize() const {
		return Queue.size();
	}
	vector<int>	myQueue::getV() const{
		return Queue;
	}
	std::ostream& operator<<(std::ostream& out, const myQueue& Queue) {//Print myQueue values using << operator
		int i = 0;
		while (i < Queue.getSize()) {
			if (i > 0 && i < Queue.getSize()) {
				out << " <- ";
			}
			out << Queue.getV()[i];
			i++;
		}
		out << endl;
		return out;
	}

	

