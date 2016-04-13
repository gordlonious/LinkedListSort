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
	void push(int*);
	//void push(const int&& item); // push hard-coded integer

	void swap(int, int);  // swaps two integer values (only for linkedListSort<int>)
	void swapAt(int, int);  //  swap at index
	void  linearSearch(elemType, nodeT<elemType>&);
	void  linearSearchJoke(const int, nodeT<int>*&); // how do i get rid of this -- solving incorrect constructors from being called

	void selectionSort();
	void linkedInsertionSort();
	void quickSort();
	nodeT<elemType>* mergeList(nodeT<elemType>*, nodeT<elemType>*);
	void divideList(nodeT<elemType>*, nodeT<elemType>* &node);
	void recMergeSort(nodeT<elemType>* &head);
	void mergeSort();
	int partition(int, int);
	void recQuickSort(int first, int last);



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


template<>
void linkedListSort<int>::push(int* item) {
	if (length == 0) {
		*(lastNode->info) = *item; // copy item info
		beginningNode = lastNode; //  update beginning pointer
	}
	else if (length >= 1 && length < maxSize) {
		lastNode->link = new nodeT<int>(*item);
		lastNode = lastNode->link;
	}
	else {
		std::cerr << "push() length not correct or list is full" << std::endl;
	}
	length++;
}

// hmm
//template<>
//void linkedListSort<int>::push(const int && item) {
//	if (length == 0) {  // first item case
//		*(lastNode->info) = item; // copy item info
//		beginningNode = lastNode; //  update beginning pointer
//	}
//	else if (length >= 1 && length < maxSize) {
//		lastNode->link = nodeT<int>::nodeIntegerConstructor(item);
//		lastNode = lastNode->link;
//	}
//	else {
//		std::cerr << "push() length not correct or list is full" << std::endl;
//	}
//	length++;
//}

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

template<>
void linkedListSort<int>::linearSearchJoke(int item, nodeT<int>*& node) {
	nodeT<int> *temp = beginningNode;
	while (temp != NULL) {
		if (*(temp->info) == item) {
			node = temp; // ref shouldn't be destroyed after function call..
			break;
		}
		else {
			temp = temp->link;
		}
	}
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
template<>
void linkedListSort<int>::swap(int item1, int item2) {
	nodeT<int> *temp = beginningNode;

	// search for reach node integer value
	nodeT<int> *lItem1 = NULL;
	linearSearchJoke(item1, lItem1);
	nodeT<int> *lItem2 = NULL;
	linearSearchJoke(item2, lItem2);

	// swap each node info value
	if (lItem1 != NULL && lItem2 != NULL) {
		int tempInfo = *(lItem1->info);
		*(lItem1->info) = *(lItem2->info);
		*(lItem2->info) = tempInfo;
	}
	else {
		std::cerr << "swap() failed -- items not found" << std::endl;
	}
}

template<class elemType>
void linkedListSort<elemType>::swapAt(int first, int last) {

	nodeT<elemType> *firstN = beginningNode;
	for (int i = first; i > 0; i--) // go to first node
		firstN = firstN->link;

	nodeT<elemType> *lastN = beginningNode;
	for (int i = last; i > 0; i--)
		lastN = lastN->link;

	if (firstN != NULL && lastN != NULL) {
		elemType temp;
		temp = *(firstN->info);
		*(firstN->info) = *(lastN->info);
		*(lastN->info) = temp;
	}
	else {
		std::cerr << "swap() first or last nodes were not found " << std::endl;
	}
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

template<class elemType>
void linkedListSort<elemType>::linkedInsertionSort()
{
	nodeT<elemType> *first = beginningNode;
	nodeT<elemType> *lastInOrder;
	nodeT<elemType> *firstOutOfOrder;
	nodeT<elemType> *current;
	nodeT<elemType> *trailCurrent;
	lastInOrder = first;
	if (first == NULL)
		std::cerr << "Cannot sort an empty list." << std::endl;
	else if (first->link == NULL)
		std::cout << "The list is of length 1. "
		<< "It is already in order." << std::endl;
	else
		while (lastInOrder->link != NULL)
		{
			firstOutOfOrder = lastInOrder->link;
			if (*(firstOutOfOrder->info) < *(first->info))
			{
				lastInOrder->link = firstOutOfOrder->link;
				firstOutOfOrder->link = first;
				first = firstOutOfOrder;
			}
			else
			{
				trailCurrent = first;
				current = first->link;
				while (*(current->info) < *(firstOutOfOrder->info))
				{
					trailCurrent = current;
					current = current->link;
				}
				if (current != firstOutOfOrder)
				{
					lastInOrder->link = firstOutOfOrder->link;
					firstOutOfOrder->link = current;
					trailCurrent->link = firstOutOfOrder;
				}
				else
					lastInOrder = lastInOrder->link;
			}
		}
}

template<class elemType>
int linkedListSort<elemType>::partition(int first, int last) {
	elemType pivot;
	int index, smallIndex;
	swapAt(first, (first + last) / 2);

	nodeT<elemType> *ptrPiv = beginningNode;
	for (int i = first; i > 0; i--)
		ptrPiv = ptrPiv->link;

	pivot = *(ptrPiv->info);
	smallIndex = first;
	smallIndex = 0;
	nodeT<elemType> *temp = beginningNode->link; // start one after pivot
	for (index = first + 1; index <= last; index++) {
		if (*(temp->info) < pivot) {
			smallIndex++;
			swapAt(smallIndex, index);
		}
		temp = temp->link;
	}
	swapAt(first, smallIndex);

	//std::cout << "part sIndex: " << smallIndex<< std::endl;
	return smallIndex;
}

template <class elemType>
void linkedListSort<elemType>::recQuickSort(int first, int last)
{
	int pivotLocation;
	//std::cout << "first: " << first << " last: " << last << std::endl;
	if (first < last)
	{
		pivotLocation = partition(first, last);
		//std::cout << "pivot: " << pivotLocation << std::endl;
		recQuickSort(first, pivotLocation - 1);
		recQuickSort(pivotLocation + 1, last);
	}
}

template <class elemType>
void linkedListSort<elemType>::quickSort()
{
	recQuickSort(0, length - 1);
}

template <class elemType>
void linkedListSort<elemType>::divideList(nodeT<elemType>* first1,
	nodeT<elemType>* &first2) {
	nodeT<elemType>* middle;
	nodeT<elemType>* current;
	if (first1 == NULL) //list is empty
		first2 = NULL;
	else if (first1->link == NULL) //list has only one node
		first2 = NULL;
	else
	{
		middle = first1;
		current = first1->link;
		if (current != NULL) //list has more than two nodes
			current = current->link;
		while (current != NULL)
		{
			middle = middle->link;
			current = current->link;
			if (current != NULL)
				current = current->link;
		} //end while
		first2 = middle->link; //first2 points to the first
							   //node of the second sublist
		middle->link = NULL; //set the link of the last node
							 //of the first sublist to NULL
	} //end else
}

template <class elemType>
nodeT<elemType>* linkedListSort<elemType>::
mergeList(nodeT<elemType>* first1,
	nodeT<elemType>* first2)
{
	nodeT<elemType> *lastSmall; //pointer to the last node of
							   //the merged list
	nodeT<elemType> *newHead; //pointer to the merged list
	if (first1 == NULL) //the first sublist is empty
		return first2;
	else if (first2 == NULL) //the second sublist is empty
		return first1;
	else
	{
		if (first1->info < first2->info) //compare the first nodes
		{
			newHead = first1;
			first1 = first1->link;
			lastSmall = newHead;
		}
		else
		{
			newHead = first2;
			first2 = first2->link;
			lastSmall = newHead;
		}
		while (first1 != NULL && first2 != NULL)
		{
			if (first1->info < first2->info)
			{
				lastSmall->link = first1;
				lastSmall = lastSmall->link;
				first1 = first1->link;
			}
			else
			{
				lastSmall->link = first2;
				lastSmall = lastSmall->link;
				first2 = first2->link;
			}
		} //end while
		if (first1 == NULL) //first sublist is exhausted first
			lastSmall->link = first2;
		else //second sublist is exhausted first
			lastSmall->link = first1;
		return newHead;
	}
}//end mergeList

template <class elemType>
void linkedListSort<elemType>::recMergeSort(nodeT<elemType>* &head)
{
	nodeT<elemType> *otherHead;
	if (head != NULL) //if the list is not empty
		if (head->link != NULL) //if the list has more than one node
		{
			divideList(head, otherHead);
			recMergeSort(head);
			recMergeSort(otherHead);
			head = mergeList(head, otherHead);
		}
} //end recMergeSort

template<class elemType>
void linkedListSort<elemType>::mergeSort()
{
	nodeT<elemType>* first = beginningNode;
	nodeT<elemType>* last = lastNode;
	recMergeSort(first);
	if (first == NULL)
		last = NULL;
	else
	{
		last = first;
		while (last->link != NULL)
			last = last->link;
	}
} //end mergeSort

#endif