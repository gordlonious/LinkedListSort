#include "nodeT.h"

template<class elemType>
class linkedListSort {
public:
	linkedListSort(int size);

	void push(elemType item);

private:
	int length;
	int maxSize;
	nodeT<elemType> *lastNode;
	nodeT<elemType> *beginningNode;
};

template<class elemType>
linkedListSort<elemType>::linkedListSort(int size) {
	list = new elemType[size];
	maxSize = size;
	length = 0;
	lastNode = NULL;
	beginningNode = NULL;
}

template<class elemType>
void linkedListSort<elemType>::push(elemType item) {
	if (length == 0) {
		lastNode->info = &item;
		beginningNode = &lastNode;
	}

}