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

	void selectionSort();
	void insertionSort();


	// places item in the correct place of the linked list

	void print(); // prints the whole list

private:
	int length;
	int maxSize;
	nodeT<elemType> *lastNode;
	nodeT<elemType> *beginningNode;
	linkedListType ListType;

	int minLocation(int, int);
	int minIntValue(int, int);

	// breakdown of insertion sort
	void traverseSorted(nodeT<int>&);

	// case 1: find item greater than and item less than ( insert in between )
	bool insertionCase1(nodeT<int>&, nodeT<int>&, nodeT<int>&);

	void insertionSearch(int);
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
		lastNode = lastNode->link;
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
			std::cout << " ";
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
			if (itemNode != NULL) {
				node = *itemNode;
				break;
			}
			else
				std::cerr << "linearSearch itemNode was null" << std::endl;
			temp = temp->link;
		}
		else {
			temp = temp->link;
		}
	}
}

// 2n
// swap integer values
template<class elemType>
void linkedListSort<elemType>::swap(int item1, int item2) {
	nodeT<int> *temp = beginningNode;

	// search for reach node integer value
	nodeT<elemType> lItem1;
	linearSearch(item1, lItem1);
	nodeT<elemType> lItem2;
	linearSearch(item2, lItem2);

	// swap each node info value
	int tempInfo = *(lItem1.info);
	*(lItem1.info) = *(lItem2.info);
	*(lItem2.info) = tempInfo;
}

template<class elemType>
void linkedListSort<elemType>::selectionSort() {
	nodeT<int> *temp = beginningNode;
	int count = 0;
	while (temp != NULL) {
		int minValue = minIntValue(count, length);
		swap(*(temp->info), minValue);
		temp = temp->link;
		count++;
	}
}

template<>
int linkedListSort<int>::minLocation(int first, int last) {
	int minIndex = first;
	return -1;
}

// n
// only 1 param needed for selections sort use case?
// not using minLoc because returning item value instead of index
template<>
int linkedListSort<int>::minIntValue(int first, int last) {
	nodeT<int> *firstN = beginningNode;
	for (int i = first; i > 0; i--) // get to starting point
		firstN = firstN->link;


	nodeT<int> *temp = firstN;
	int minItem = *(firstN->info);
	if (temp != NULL) { // last item will be in order ( do not do any comparisons )
		minItem = *(temp->info);
		for (int i = first; i < length; i++) { // find min value
			if (*(temp->info) < *(firstN->info)) {
				minItem = *(temp->info);
				temp = temp->link;
			}
			else {
				temp = temp->link;
			}
		}
	}
	return minItem;
}

template<>
bool linkedListSort<int>::insertionCase1(nodeT<int>& cur, nodeT<int>& trail, nodeT<int>& addCur) {

	return true;
}

// O(n)
template<>
void linkedListSort<int>::traverseSorted(nodeT<int>& nodeToInsert) {
	nodeT<int> *current = beginningNode->link;  // use enumerator to compare two items
	nodeT<int> *trailCurrent = beginningNode;
	nodeT<int> *addCurrent = beginningNode->link->link;

	// case -1: current does not exist ( list has 1 item )
	// case 0:  2 items. add current does not exist ( current is less than first item )
	// case 1: find item greater than and item less than ( insert in between ) ( two closest items ) ( sorted portion )
	// case 2: find item equal to and item greater than or less than ( insert )
	// case 3: else ( output error )
	while (current != NULL) {
		if (current == NULL) { // unnecessary?
			break;
		}
		else if (*(current->info) < *(trailCurrent->info)) {
			swap(*(current->info), *(trailCurrent->info));
		}
		else if (insertionCase1(nodeT<int>(*current), nodeT<int>(*trailCurrent), nodeT<int>(*addCurrent))) { // copy pointers and return case 1
			// move everything down except less than
			// insert
			for (int i = 0; i < length; i++) {
				nodeT<int> *tCopy = new nodeT<int>(*beginningNode);
				nodeT<int> *tCopy2 = new nodeT<int>(*beginningNode->link);
				nodeT<int> *moveNodeTemp = beginningNode;
				while (moveNodeTemp != NULL) {
					moveNodeTemp->link = tCopy;
					tCopy = moveNodeTemp;
				}
			}
		}
	}
}


// O(n)
template<>
void linkedListSort<int>::insertionSort() {
	nodeT<int> *firstOutOfOrder = beginningNode->link;
	nodeT<int> *sortedTraversal = beginningNode;  // initialize node that traverses sorted portion of the list
	for (int i = 0; i < length; i++) {
		traverseSorted(*firstOutOfOrder);
	}
}

#endif