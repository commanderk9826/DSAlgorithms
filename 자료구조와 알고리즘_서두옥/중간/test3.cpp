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
	SNode* frontSNode() const; //첫 노드 탐색

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
	}//while의 결과 : temp = NULL;

	return count;
}
SNode* SLinkedList::frontSNode() const {
	if (isEmpty()) {
		cout << " 빈 리스트입니다." << endl;
		return NULL;
	}
	return head;
}

SNode* SLinkedList::makeSNode(const int& e) {
	SNode* nNode = new SNode; //SNode를 저장할 메모리 공간 부여

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
	//탐색
	SNode* temp = head;
		
	while (temp->link != NULL) {
		temp = temp->link;
	}//while 결과 : 마지막 노드

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
		cout << "임의의 정수 입력(종료 : 0): ";
		cin >> x;

		if (x == 0) break;
		else {
			s.addRear(x);
		}
	}

	cout << "### 입력된 데이터(총 : " << s.countSNode() << " ) ###" << endl;
	s.printSLinkedList();

	return 0;

}