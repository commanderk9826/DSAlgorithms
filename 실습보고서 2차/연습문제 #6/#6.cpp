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
	SNode*	__tail;		// �� ������ ���
	int	  	__count;	// ����� �� ����
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
	: __head(nullptr), __tail(nullptr), __count(0){ }

SLinkedList::~SLinkedList() {
	while (!isEmpty()) 
		removeFront();	
}

// ����: �� ������ ���
void SLinkedList::addRear(const int& e) {
	SNode* nNode = new SNode(e);
	if (isEmpty()) {
		__head = nNode;
		__tail = nNode;
	}
	else {
		__tail->__link = nNode;
		__tail = nNode;
	}
	__count++;
}

// ����: ù ��° ���
void SLinkedList::removeFront() {
	if (isEmpty()) 
		return;
	SNode* old = __head;
	__head = old->__link;
	delete old;
	if (__head == nullptr) {
		__tail = nullptr;
	}
	__count--;
}

// Ž��: ù ��° ���
SNode* SLinkedList::frontSNode() const {
	return __head;
}

// Ž��: �� ������ ���
SNode* SLinkedList::rearSNode() const {
	return __tail;
}

// �� ����Ʈ ���� �Ǵ�
bool SLinkedList::isEmpty() const {
	return __head == nullptr;
}

// Ž��: ����� �� ����(count)
int	SLinkedList::countSNode() const {
	return __count;
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
	cout << "20215229 ��ä��" << endl;
	cout << endl;
	SLinkedList	sList = SLinkedList();
	while (true) {
		cout << "������ ���� �Է�(����: 0): ";
		cin >> num;
		if (num == 0)	break;
		sList.addRear(num); 	// �� ������ ���� ����
	}
	sList.printSLinkedList();
	sList.~SLinkedList();
	return 0;	
}