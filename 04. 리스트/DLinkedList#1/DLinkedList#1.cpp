/*
	���� ���� ����Ʈ: �˰��� ����
		���ϸ�: DLinkedList(head).cpp
			- Ŭ����: DNode
			- Ŭ����: DLinkedList
				�����ڿ� �Ҹ���		: DLinkedList, ~DLinkedList
				��� ����.����		: addRear, removeFront
				��� Ž��		: frontSNode, rearSNode
				��� Ȯ��		: isEmpty, countSNode
				��ü ����(���) ���	: printSLinkedList
*/

#include <iostream>
using namespace std;

// DNode class
class DNode {
private:
	int	__data;
	DNode* __Llink;
	DNode* __Rlink;
	friend class DLinkedList;
public:
	DNode(const int& data);
};

// DNode: �����ڿ� �޼ҵ� ����
DNode::DNode(const int& data) :
	__data(data), __Llink(nullptr), __Rlink(nullptr) {}

// DLinkedList class
class DLinkedList {
private:
	DNode* __head;		// ù ��° ���
	// DNode*	__tail;		// �� ������ ���
	// int		__count;	// ����� �� ����
public:
	DLinkedList();				// ������
	~DLinkedList();				// �Ҹ���: ��ü ��� ����
	void	addRear(const int& e);		// ����: �� ������ ���
	void	removeFront();			// ����: ù ��° ���
	DNode* frontDNode() const;		// Ž��: ù ��° ���
	DNode* rearDNode() const;		// Ž��: �� ������ ���
	bool	isEmpty() const;		// �� ����Ʈ ���� �Ǵ�
	int		countDNode() const;	// Ž��: ����� �� ����(count)
	void	printSLinkedList() const;	// ����Ʈ�� ��ü ����(���) ���: ������
	void	revPrintSLinkedList() const;	// ����Ʈ�� ��ü ����(���) ���: ������
};

// DLinkedList: ������(�Ҹ���)�� �޼ҵ� ����
DLinkedList::DLinkedList()
	: __head(nullptr) { }

DLinkedList::~DLinkedList() {
	// while (!isEmpty()) removeFront();
	DNode* tNode = __head;
	while (tNode) {
		__head = tNode->__Rlink;
		delete tNode;
		tNode = __head;
	}
}

// ��� ����: �� ������ ����...
void DLinkedList::addRear(const int& e) {
	DNode* nNode = new DNode(e);
	if (isEmpty()) __head = nNode;
	else {
		DNode* rNode = rearDNode();
		rNode->__Rlink = nNode;
		nNode->__Llink = rNode;
	}
}

// ��� ����: ù ��° ��带...
void DLinkedList::removeFront() {
	DNode* old;
	while (__head) {
		old = __head;
		__head = old->__Rlink;
		if (__head != nullptr)
			__head->__Llink = nullptr;
		delete old;
	}
}

// Ž��: ù ��° ���
DNode* DLinkedList::frontDNode() const {
	return __head;
}

// Ž��: �� ������ ���(tail)
DNode* DLinkedList::rearDNode() const {
	if (isEmpty()) return nullptr;
	DNode* rNode = __head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return rNode;
}

// �� ����Ʈ ���� �Ǵ�
bool DLinkedList::isEmpty() const {
	return __head == nullptr;
}

// Ž��: ����� �� ����(count)
int	DLinkedList::countDNode() const {
	if (isEmpty()) return 0;
	int		count = 0;
	DNode* rNode = __head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return count;
}

// ����Ʈ�� ��ü ����(���) ���: ������
void DLinkedList::printSLinkedList() const {
	DNode* temp = __head;
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__Rlink;
	}
	cout << " NULL" << endl;
}

// ����Ʈ�� ��ü ����(���) ���: ������
void DLinkedList::revPrintSLinkedList() const {
	DNode* temp = rearDNode();
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__Llink;
	}
	cout << " NULL" << endl;
}

int main(void)
{
	int	num;
	DLinkedList	dList = DLinkedList();
	while (true) {
		cout << "������ ���� �Է�(����: 0): ";
		cin >> num;
		if (num == 0)   break;

		// �� ������ ���� ����
		dList.addRear(num);
	}

	// ��ü ���� ���
	if (dList.isEmpty()) {
		cout << "�Էµ� �����Ͱ� �����ϴ�..." << endl;
		return 0;       // dList.~DLinkedList();
	}
	printf("\n ### �Էµ� ������ ### \n\n");
	dList.printSLinkedList();
	dList.revPrintSLinkedList();

	return 0;			// dList.~DLinkedList();
}