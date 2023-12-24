#include <iostream>
using namespace std;

inline void error(const char* message) {
    cout << message << endl;
    exit(100);
}
using namespace std;

class DNode {
    int data;
    DNode* Llink;
    DNode* Rlink;
    friend class DLinkedList;
};

class DLinkedList {
    DNode* head;
    DNode* tail;
    int count;
public:
    //생성자, 소멸자
    DLinkedList();
    ~DLinkedList();
    //생성
    DNode* makeDNode(const int& e);
    //조사
    bool isEmpty() const;
    int countDNode();
    //삽입
    void insertRear(const int& e);
    //삭제
    void deleteFront();
    void deleteMid(DNode* pre_DNode);
    void deleteRear();
    //출력
    void printBy_Rlink() const;
    void printBy_Llink() const;
};

//생성자 & 소멸자
DLinkedList::DLinkedList() {
    head = NULL;
    tail = NULL;
    count = 0;
}
DLinkedList::~DLinkedList() {
    while (!isEmpty()) deleteRear();
    //while(!isEmpty()) deleteFront();
    if (isEmpty()) cout << "NULL";

    exit(0);
}

//생성
DNode* DLinkedList::makeDNode(const int& e) {
    DNode* nNode = new DNode;

    nNode->data = e;
    nNode->Llink = NULL;
    nNode->Rlink = NULL;

    return nNode;
}

//조사
bool DLinkedList::isEmpty() const {
    return head == NULL;
}
int DLinkedList::countDNode() {
    return count;
}
//삽입
void DLinkedList::insertRear(const int& e) {
    DNode* nNode = makeDNode(e); //노드 생성

    if (isEmpty()) { //빈 노드 확인
        head = nNode;
        tail = nNode;
    }
    else {
        tail->Rlink = nNode;
        nNode->Llink = tail;
        tail = nNode;
    }
    count++;
}

//삭제
void DLinkedList::deleteFront() {

    if (isEmpty()) error("빈 리스트입니다.");

    DNode* old = head;
    old->Llink = NULL;
    head = old->Rlink;

    delete old;

    count--;
}

void DLinkedList::deleteMid(DNode* pre_DNode) {

    if (isEmpty()) error("빈 리스트입니다.");

    DNode* old = pre_DNode->Rlink;//삭제할 노드


    pre_DNode->Rlink = old->Rlink;
    old->Rlink->Llink = pre_DNode;

    delete old;

    count--;
}

void DLinkedList::deleteRear() {

    if (isEmpty()) error("빈 리스트입니다.");

    DNode* old = tail; //삭제할 노드

    //노드 하나 남은 경우
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        // n-1 노드 Rlink -> NULL로
        // tail -> n-1로
        old->Llink->Rlink = NULL;
        tail = old->Llink;
    }

    delete old;

    count--;
}

//출력
void DLinkedList::printBy_Rlink() const {
    DNode* temp = head;

    while (temp) {
        cout << temp->data << " ->> ";
        temp = temp->Rlink;
    }//마지막 노드도 while문 실행

    cout << "NULL" << endl;
}

void DLinkedList::printBy_Llink() const {
    DNode* temp = tail;

    while (temp) {
        cout << temp->data << " ->> ";
        temp = temp->Llink;
    }

    cout << "NULL" << endl;
}

//메인함수
int main() {
    int num;
    DLinkedList d = DLinkedList();

    while (true) {
        cout << "임의의 정수 입력(종료 : 0) : ";
        cin >> num;

        if (num == 0) break;

        d.insertRear(num);
    }

    if (d.isEmpty()) {
        cout << "입력된 데이터가 없습니다..." << endl;
        return 0;
    }

    printf("%c", '\n');
    cout << "### 입력된 데이터 ### " << endl;
    printf("%c", '\n');

    d.printBy_Rlink();
    d.printBy_Llink();

    d.~DLinkedList();

    return 0;
}
