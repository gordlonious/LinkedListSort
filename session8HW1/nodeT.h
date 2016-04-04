template<class elemType>
class nodeT {
public:
	nodeT();
	nodeT(elemType& info);
	nodeT(elemType& info, nodeT<elemType>* link);
	nodeT(nodeT<elemType>& node, bool assignLink = false);
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
	info = node.info;
	if (assignLink)
		link = node.link;
}

