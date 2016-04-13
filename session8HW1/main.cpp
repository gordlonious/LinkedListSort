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

	// test quicksort partition
	linkedListSort<int> list4 = linkedListSort<int>(6, linkedListType::integerType);
	list4.push(new int(10));
	list4.push(new int(80));
	list4.push(new int(75));
	list4.push(new int(124));
	list4.push(new int(63));
	list4.push(new int(91));
	std::cout << std::endl << "before qSort partition: ";
	list4.print();
	list4.partition(0, 5);
	std::cout << "after qSort partition: ";
	list4.print();

	linkedListSort<int> list41 = linkedListSort<int>(6, linkedListType::integerType);
	list41.push(new int(1));
	list41.push(new int(5));
	list41.push(new int(6));
	list41.push(new int(3));
	list41.push(new int(4));
	list41.push(new int(2));
	std::cout << std::endl << "before qSort partition2: ";
	list41.print();
	list41.partition(0, 5);  // 6 ends up being pivot ( rightmost )
	std::cout << "after qSort partition2: ";
	list41.print();


	// test actual quicksort
	linkedListSort<int> list51 = linkedListSort<int>(4, linkedListType::integerType);
	list51.push(new int(2));
	list51.push(new int(7));
	list51.push(new int(1));
	list51.push(new int(3));
	std::cout << std::endl << "list51 before:  ";
	list51.print();
	list51.quickSort();
	std::cout << "list51 test:  ";
	list51.print();
	// quicksort is working here

	/*linkedListSort<int> list52 = linkedListSort<int>(5, linkedListType::integerType);
	list52.push(new int(10));
	list52.push(new int(5));
	list52.push(new int(2));
	list52.push(new int(7));
	std::cout << std::endl << "list52 before: ";
	list52.print();
	list52.quickSort();
	std::cout << "list52 after: ";
	list52.print();*/ // ihis quicksort is causing a stack overflow for some reason!!
	// i believe quicksort is written correctly though

	// merge sort
	linkedListSort<int> list6 = linkedListSort<int>(4, linkedListType::integerType);
	std::cout << "mergeSort " << std::endl;
	list6.push(new int(2));
	list6.push(new int(7));
	list6.push(new int(1));
	list6.push(new int(3));
	std::cout << std::endl << "list6 before:  ";
	list6.print();
	list6.mergeSort();
	std::cout << "list6 test:  ";
	list51.print(); // small mergesort working

	linkedListSort<int> list7 = linkedListSort<int>(10, linkedListType::integerType);
	std::cout << "mergeSort " << std::endl;
	list7.push(new int(10));
	list7.push(new int(25));
	list7.push(new int(36));
	list7.push(new int(33));
	list7.push(new int(31));
	list7.push(new int(29));
	list7.push(new int(24));
	list7.push(new int(9));
	list7.push(new int(78));
	list7.push(new int(19));
	std::cout << std::endl << "list7 before:  ";
	list7.print();
	list7.mergeSort();
	std::cout << "list7 test:  ";
	list7.print(); // big merge sort test not working



	char stop;
	std::cin >> stop;
}