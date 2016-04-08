#ifndef generalNode_H
#define generalNode_H

#include <vector>
#include "nodeT.h"

// Trying to solve implicit conversion problem
// goal:  cause compiler to call a series of constructors instead of.... something else???
//  create node types on the fly (ish)??>
template<class elemType>
class generalNode { // basically tuple
public:
	generalNode(std::vector<elemType>&);
	~generalNode();

private:  // privatize specific types??
	std::vector<elemType> *infoList = NULL;
	void generateIntegerNodeList(std::vector<nodeT<int>>&);
};

template <class elemType>
generalNode<elemType>::generalNode(std::vector<elemType>& listOfInfo) {
	infoList = listOfInfo;
}

template<class elemType>
generalNode<elemType>::~generalNode() {
	delete infoList;
}

template<>
void generalNode<int>::generateIntegerNodeList(std::vector<nodeT<int>>&) {
	//for (nodeT<int>) testing git repo
}

#endif