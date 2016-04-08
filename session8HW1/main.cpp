#include <iostream>
#include "linkedListSort.h"
int main() {
	nodeT<int> node = nodeT<int>();

	int أخرجه= 6;
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
	std::cout << std::endl  << "Test linear Search:  " << *(testNode1->info) << std::endl;

	 //test add
	std::cout << std::endl;
	std::cout << "linkedListSort" << std::endl;
	linkedListSort<int> list = linkedListSort<int>(10, linkedListType::integerType);
	int listNum = 6;
	list.push(listNum);
	int lType = 7;
	list.push(lType);

	// add random numbers / test swap
	int lNum1 = 5;
	int lNum2 = 11;
	int lNum3 = 16;
	int lNum4 = 20;
	list.push(lNum1);
	list.push(lNum2);
	list.push(lNum3);
	list.push(lNum4);
	std::cout << "before swap:  ";
	list.print();
	list.swap(5, 20);
	std::cout << "after swap:  ";
	list.print();


	char stop;
	std::cin >> stop;
}