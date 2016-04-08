#ifndef LinkedListSort_H
#define LinkedListSort_H

#include "nodeT.h"

enum class linkedListType { integerType = 1, stringType };

template<class elemType>
class linkedListSort {
public:
	linkedListSort(int size, linkedListType);

	void push(elemType& item);
	void push(nodeT<elemType>& node);

	void swap(int, int);  // swaps two integer values (only for linkedListSort<int>)
	void swapAt(int, int, bool);  //  swap at index
	void  linearSearch(elemType, nodeT<elemType>&);


	void print(); // prints the whole list

private:
	int length;
	int maxSize;
	nodeT<elemType> *lastNode;
	nodeT<elemType> *beginningNode;
	linkedListType ListType;
};

template<class elemType>
linkedListSort<elemType>::linkedListSort(int size, linkedListType type) {
	maxSize = size;
	length = 0;
	lastNode = new nodeT<elemType>();
	beginningNode = new nodeT<elemType>();
	ListType = type;
}

template<class elemType>
void linkedListSort<elemType>::push(elemType& item) {
	if (length == 0) {  // first item case
		lastNode->info = &item; // copy item info
		beginningNode = lastNode; //  update beginning pointer
	}
	else if (length >= 1 && length < maxSize) {
		lastNode->link = new nodeT<elemType>(item);
	}
	else {
		std::cerr << "push() length not correct or list is full" << std::endl;
	}
	length++;
}

template<class elemType>
void linkedListSort<elemType>::push(nodeT<elemType>& node) {
	if (length == 0) {
		lastNode = new nodeT<elemType>(node);
		beginningNode = lastNode;
	}
	else if (length > 1 && length < maxSize) {
		lastNode.link = node; // attach to the end of the list
		lastNode = node; // update last node
	}
	else {
		std::cerr << "push() length not correct or list is full" << std::endl;
	}
	length++;
}

template<class elemType>
void linkedListSort<elemType>::print() {
	nodeT<elemType> *temp = beginningNode;
	if (length == 1)
		std::cout << *(temp->info) << std::endl;
	else if (length > 1) {
		while (temp != NULL) {
			std::cout << *(temp->info);
			temp = temp->link; // advance through list by 1
		}
	}
	else {
		std::cout << "list is empty";
	}
	std::cout << std::endl;
}

template<class elemType>
void linkedListSort<elemType>::linearSearch(elemType item, nodeT<elemType>& node) {
	nodeT<elemType> *temp = beginningNode;
	nodeT<elemType> *itemNode = NULL;
	while (temp != NULL) {
		if (*(temp->info) == item) {
			nodeT<elemType> *itemNode = new nodeT<elemType>(*temp, true);
			if (itemNode != NULL)
				node = *itemNode;
			else
				std::cerr << "linearSearch itemNode was null" << std::endl;
			temp = temp->link;
		}
		else {
			temp = temp->link;
		}
	}
}

// swap was hard as linked list -- SAVE CODE!!! -- gLibrary
// swap integer values
template<>
void linkedListSort<int>::swap(int item1, int item2) {
	if (ListType == linkedListType::integerType) {
		nodeT<int> *temp = beginningNode; // not sure if casting works here? be safe and pass enum-taped-type
		nodeT<int> *lItem1 = new nodeT<int>();
		//linearSearch(item1, &*lItem1);
	}
	else {
		std::cerr << "swap() detected incorrect type" << std::endl;
	}
};

#endif