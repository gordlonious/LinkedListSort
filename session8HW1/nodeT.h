#ifndef NodeT_H
#define NodeT_H

template<class elemType>
class nodeT {
public:
	nodeT();
	nodeT(elemType& info);
	nodeT(elemType& info, nodeT<elemType>* link);
	nodeT(nodeT<elemType>& node, bool assignLink = true);
	nodeT(int&&);
	static nodeT<int>* nodeIntegerConstructor(int);
	static nodeT<elemType>* sCopyArg(nodeT<elemType>&);
	static nodeT<int>* sIntCopyArg(nodeT<int>&);
	//nodeT<elemType> operator=(nodeT<elemType>&);

	// converts the node to an integer node if and only if its info member is of integer type
	// link is set to NULL
	// true is returned if info is an integer
	// false is returned if info is else
	//bool convertToIntegerNode(nodeT<int>&);

	//nodeT<elemType> copyIntNode(nodeT<elemType>*, bool assignLink); // integer node copy constructor ( see error )??

	elemType* info;
	nodeT<elemType>* link;

};

template<class elemType>
nodeT<elemType>::nodeT() {
	info = NULL;
	link = NULL;
}

template<class elemType>
nodeT<elemType>::nodeT(elemType& infoItem) {
	info = &infoItem;
	link = NULL;
}

template<class elemType>
nodeT<elemType>::nodeT(elemType& infoItem, nodeT<elemType>* linkItem) {
	info = &infoItem;
	link = linkItem;
}

template<class elemType>
nodeT<elemType>::nodeT(nodeT<elemType>& node, bool assignLink) {
	info = new int();
	*info = *(node.info);
	if (assignLink)
		link = node.link;
}

template<class elemType>
static nodeT<elemType>* sCopyNode(nodeT<elemType>& node) {
	return new nodeT<elemType>(node);
}

template<>
nodeT<int>::nodeT(int && item) {  // not helpful -- create customConstructor
	*info = item;
	link = NULL;
}

template<>
static nodeT<int>* nodeT<int>::sIntCopyArg(nodeT<int>& node) {  // why did i need to make this? -- proof would be good
	return new nodeT<int>(node);
}

template<>
static nodeT<int>* nodeT<int>::nodeIntegerConstructor(int item) {
	return new nodeT<int>(item);
}

//template<class elemType>
//nodeT<elemType> nodeT<elemType>::operator=(nodeT<elemType>& node) {  // return constructor call??
//	nodeT<elemType> *ptrN = &node;  // why is this pointer needed to compile??
//	nodeT<elemType> nNode = nodeT<elemType>(*ptrN, ptrN->link);
//	return nNode;
//}

//template<class elemType>
//bool nodeT<elemType>::convertToIntegerNode(nodeT<int>& node) {
//	int *testInfo = NULL;
//	testInfo = info;
//	if (testInfo != NULL) {
//		node = new nodeT<int>(info, false);
//	}
//	else
//		node = NULL;
//}

// How do I copy an int data type ( trying to solve an implicit conversion problem )
//template<class elemType>
//nodeT<elemType> nodeT<elemType>::copyIntNode(nodeT<elemType>* node, bool assignLink) {
//	info = node.info;
//	if (assignLink)
//		link = node.link;
//	return new nodeT<elemType>(*this);
//}

#endif