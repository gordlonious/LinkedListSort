#include <iostream>
#include "linkedListSort.h"
#include "nodeT.h"
int main() {
	nodeT<int> node = nodeT<int>();

	int sex = 6;
	nodeT<int> node1 = nodeT<int>(sex);

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

	// test add
	linkedListSort<int> list = linkedListSort<int>(10);
	int listNum = 6;
	list.push(listNum);

	char stop;
	std::cin >> stop;
}