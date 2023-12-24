/*
	�ܼ� ���� ����Ʈ: �˰��� ����
		���ϸ�: SLinkedList(head).cpp
			- Ŭ����: SNode
			- Ŭ����: SLinkedList
				�����ڿ� �Ҹ���		: SLinkedList, ~SLinkedList
				��� ����.����		: addRear, removeFront
				��� Ž��		: frontSNode, rearSNode
				��� Ȯ��		: isEmpty, countSNode
				��ü ����(���) ���	: printSLinkedList
*/

#include <iostream>
using namespace std;

// SNode class
class SNode {
private:
	int	__data;
	SNode* __link;
	friend class SLinkedList;
public:
	SNode(const int& data);
};

// SNode: �����ڿ� �޼ҵ� ����
SNode::SNode(const int& data) :
	__data(data), __link(nullptr) {}

// SLinkedList class
class SLinkedList {
private:
	SNode* __head;		// ù ��° ���
	//SNode*	__tail;		// �� ������ ���
	//int	  	__count;	// ����� �� ����
public:
	SLinkedList();					// ������
	~SLinkedList();					// �Ҹ���: ��ü ��� ����
	void	addRear(const int& e);			// ����: �� ������ ���
	void	removeFront();				// ����: ù ��° ���
	SNode* frontSNode() const;			// Ž��: ù ��° ���
	SNode* rearSNode() const;			// Ž��: �� ������ ���
	bool	isEmpty() const;			// �� ����Ʈ ���� �Ǵ�
	int	countSNode() const;			// Ž��: ����� �� ����(count)
	void	printSLinkedList() const;		// ����Ʈ�� ��ü ����(���) ���
};

// LinkedStack: ������(�Ҹ���)�� �޼ҵ� ����
SLinkedList::SLinkedList()
	: __head(nullptr) { }

SLinkedList::~SLinkedList() {
	// while (!isEmpty()) removeFront();	
	SNode* tNode = __head;
	while (tNode) {
		__head = tNode->__link;
		delete tNode;
		tNode = __head;
	}
}

// ����: �� ������ ���
void SLinkedList::addRear(const int& e) {
	SNode* nNode = new SNode(e);
	if (isEmpty()) __head = nNode;
	else {
		SNode* rNode = rearSNode();
		rNode->__link = nNode;
	}
}

// ����: ù ��° ���
void SLinkedList::removeFront() {
	if (isEmpty()) return;
	SNode* old = __head;
	__head = old->__link;
	delete old;
}

// Ž��: ù ��° ���
SNode* SLinkedList::frontSNode() const {
	return __head;
}

// Ž��: �� ������ ���
SNode* SLinkedList::rearSNode() const {
	if (isEmpty()) return nullptr;
	SNode* rNode = __head;
	while (rNode->__link)
		rNode = rNode->__link;
	return rNode;
}

// �� ����Ʈ ���� �Ǵ�
bool SLinkedList::isEmpty() const {
	return __head == nullptr;
}

// Ž��: ����� �� ����(count)
int	SLinkedList::countSNode() const {
	if (isEmpty()) return 0;
	int	count = 0;
	SNode* rNode = __head;
	while (rNode->__link) {
		count++;
		rNode = rNode->__link;
	}
	return count;
}

// ����Ʈ�� ��ü ����(���) ���
void SLinkedList::printSLinkedList() const {
	if (isEmpty()) {
		cout << "�Էµ� �����Ͱ� �����ϴ�..." << endl;
		return;
	}

	cout << "\n ### �Էµ� ������ ### \n" << endl;
	SNode* temp = __head;
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__link;
	}
	cout << " NULL" << endl;
}

int main(void)
{
	int		num;
	SLinkedList	sList = SLinkedList();
	while (true) {
		cout << "������ ���� �Է�(����: 0): ";
		cin >> num;
		if (num == 0)	break;
		sList.addRear(num); 	// �� ������ ���� ����
	}
	sList.printSLinkedList();
	return 0;			// sList.~SLinkedList();
}