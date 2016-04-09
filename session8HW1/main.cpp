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

	// selection sort
	std::cout << std::endl;
	std::cout << "selection sort" << std::endl;
	list.print();
	list.selectionSort();
	list.print();

	// selection sort 2
	linkedListSort<int> list2 = linkedListSort<int>(10, linkedListType::integerType);
	int l2Num1 = 5;
	int l2Num2 = 100;
	int l2Num3 = 13;
	int l2Num4 = 17;
	int l2Num5 = 25;
	int l2Num6 = 59;
	int l2Num7 = 78;
	int l2Num8 = 56;
	int l2Num9 = 117;
	int l2Num10 = 7; // must be a parameter type that allows for direct integer passing ?
	list2.push(l2Num1);
	list2.push(l2Num2);
	list2.push(l2Num3);
	list2.push(l2Num4);
	list2.push(l2Num5);
	list2.push(l2Num6);
	list2.push(l2Num7);
	list2.push(l2Num8);
	list2.push(l2Num9);
	list2.push(l2Num10);
	std::cout << std::endl;
	std::cout << "selections sort 2" << std::endl;
	list2.print();
	list2.selectionSort();
	list2.print();




	char stop;
	std::cin >> stop;
}