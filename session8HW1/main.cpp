#include <iostream>
#include "linkedListSort.h"
int main() {
	nodeT<int> node = nodeT<int>();

	int أخرجه = 6;
	nodeT<int> node1 = nodeT<int>(أخرجه);

	int test = 5;
	nodeT<int> node2 = nodeT<int>(test);
	std::cout << *(node2.info);

	std::cout << std::endl;
	nodeT<int>* node2Ptr = &node2;
	int test2 = 5;
	nodeT<int> node3 = nodeT<int>(test2, node2Ptr);
	std::cout << *(node3.info) << *(node3.link->info);

	//copy construtor test
	std::cout << std::endl << "copy constr" << std::endl;
	nodeT<int> node4 = nodeT<int>(node3, true);
	std::cout << *(node4.info) << *(node4.link->info);

	// test linear search()
	linkedListSort<int> testList = linkedListSort<int>(5, linkedListType::integerType);
	int testItem1 = 10;
	testList.push(testItem1);
	nodeT<int>* testNode1 = new nodeT<int>();
	testList.linearSearch(10, *testNode1);
	std::cout << std::endl << "Test linear Search:  " << *(testNode1->info) << std::endl;

	//test add
	std::cout << std::endl;
	std::cout << "linkedListSort" << std::endl;
	linkedListSort<int> list = linkedListSort<int>(10, linkedListType::integerType);
	int listNum = 6;
	list.push(listNum);
	int lType = 7;
	list.push(lType);

	// add random numbers / test swap
	list.push(new int(5));
	list.push(new int(11));
	list.push(new int(16));
	list.push(new int(20));
	std::cout << "before swap:  ";
	list.print();
	list.swap(5, 20);
	std::cout << "after swap:  ";
	list.print();

	// selection sort
	std::cout << std::endl;
	std::cout << "selection sort" << std::endl;
	list.print();
	list.selectionSort();
	list.print();

	// selection sort 2
	linkedListSort<int> list2 = linkedListSort<int>(10, linkedListType::integerType);
	list2.push(new int(5));
	list2.push(new int(100));
	list2.push(new int(13));
	list2.push(new int(17));
	list2.push(new int(25));
	list2.push(new int(59));
	list2.push(new int(78));
	list2.push(new int(56));
	list2.push(new int(117));
	list2.push(new int(7));
	std::cout << std::endl;
	std::cout << "selections sort 2" << std::endl;
	list2.print();
	list2.selectionSort();
	list2.print();

	// insertion sort
	linkedListSort<int> list3 = linkedListSort<int>(6, linkedListType::integerType);
	list3.push(new int(10));
	list3.push(new int(80));
	list3.push(new int(105));
	list3.push(new int(124));
	list3.push(new int(90));
	list3.push(new int(91));
	std::cout << std::endl;
	std::cout << "insertion sort before:  ";
	list3.print();
	list3.linkedInsertionSort();
	std::cout << "insertion sort after:  ";
	list3.print();



	char stop;
	std::cin >> stop;
}