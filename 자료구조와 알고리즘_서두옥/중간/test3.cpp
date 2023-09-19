#include <iostream>

using namespace std;

class SNode {
	int data;
	SNode* link;
	friend class SLinkedList;
};

class SLinkedList {
	SNode* head;
	SNode* tail;
	int count;
public:
	SLinkedList();
	~SLinkedList();

	bool isEmpty() const;
	int countSNode() const;
	SNode* frontSNode() const; //ù ��� Ž��

	SNode* makeSNode(const int& e);
	void addRear(const int& e);
	void removeFront();
	void printSLinkedList();
};
SLinkedList::SLinkedList() {
	head = NULL;
	tail = NULL;
}
SLinkedList::~SLinkedList() {
	while (!isEmpty()) removeFront();
}

bool SLinkedList::isEmpty() const {
	return head == NULL;
}
int SLinkedList::countSNode() const{
	SNode* temp = head;
	int count = 0;

	while (temp != NULL) {
		temp = temp->link;
		count++;
	}//while�� ��� : temp = NULL;

	return count;
}
SNode* SLinkedList::frontSNode() const {
	if (isEmpty()) {
		cout << " �� ����Ʈ�Դϴ�." << endl;
		return NULL;
	}
	return head;
}

SNode* SLinkedList::makeSNode(const int& e) {
	SNode* nNode = new SNode; //SNode�� ������ �޸� ���� �ο�

	nNode->data = e;
	nNode->link = NULL;
	
	return nNode;
}

void SLinkedList::addRear(const int& e) {
	SNode* NewNode = makeSNode(e);

	if (isEmpty()) {
		head = NewNode;
		return;
	}
	//Ž��
	SNode* temp = head;
		
	while (temp->link != NULL) {
		temp = temp->link;
	}//while ��� : ������ ���

	temp->link = NewNode;
}

void SLinkedList::removeFront() {
	SNode* old = head;
	head = old->link;
	delete old;
}
void SLinkedList::printSLinkedList() {
	SNode* temp = head;

	while (temp!= NULL) {
		cout << temp->data << " ->> ";
		temp = temp->link;
	}//temp = NULL

	cout << "NULL" << endl;
}




int main() {
	int x;
	SLinkedList s;

	while (true) {
		cout << "������ ���� �Է�(���� : 0): ";
		cin >> x;

		if (x == 0) break;
		else {
			s.addRear(x);
		}
	}

	cout << "### �Էµ� ������(�� : " << s.countSNode() << " ) ###" << endl;
	s.printSLinkedList();

	return 0;

}