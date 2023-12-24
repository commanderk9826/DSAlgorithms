#include <iostream>
using namespace std;

// DNode class
class DNode {
private:
    int __data;
    DNode* __Llink;
    DNode* __Rlink;
    friend class DLinkedList;
public:
    DNode(const int& data);
};

// DNode: 생성자와 메소드 정의
DNode::DNode(const int& data) :
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

// DLinkedList class
class DLinkedList {
private:
    DNode* __head;      // 첫 번째 노드
    DNode* __tail;      // 맨 마지막 노드
    int __count;        // 노드의 총 개수
public:
    DLinkedList();               // 생성자
    ~DLinkedList();             // 소멸자: 전체 노드 삭제
    void addRear(const int& e);     // 삽입: 맨 마지막 노드
    void removeFront();          // 삭제: 첫 번째 노드
    DNode* frontDNode() const;        // 탐색: 첫 번째 노드
    DNode* rearDNode() const;        // 탐색: 맨 마지막 노드
    bool isEmpty() const;        // 빈 리스트 여부 판단
    int countDNode() const; // 탐색: 노드의 총 개수(count)
    void printSLinkedList() const;   // 리스트의 전체 원소(노드) 출력: 순방향
    void revPrintSLinkedList() const;   // 리스트의 전체 원소(노드) 출력: 역방향
};

// DLinkedList: 생성자(소멸자)와 메소드 정의
DLinkedList::DLinkedList()
    : __head(nullptr), __tail(nullptr), __count(0) { }

DLinkedList::~DLinkedList() {
    while (!isEmpty()) removeFront();
}

// 노드 삽입: 맨 마지막 노드로...
void DLinkedList::addRear(const int& e) {
    DNode* nNode = new DNode(e);
    if (isEmpty()) {
        __head = nNode;
        __tail = nNode;
    }
    else {
        __tail->__Rlink = nNode;
        nNode->__Llink = __tail;
        __tail = nNode;
    }
    __count++;
}

// 노드 삭제: 첫 번째 노드를...
void DLinkedList::removeFront() {
    if (!isEmpty()) {
        DNode* old = __head;
        __head = old->__Rlink;
        if (__head != nullptr)
            __head->__Llink = nullptr;
        delete old;
        __count--;
        if (isEmpty()) {
            __tail = nullptr;
        }
    }
}

// 탐색: 첫 번째 노드
DNode* DLinkedList::frontDNode() const {
    return __head;
}

// 탐색: 맨 마지막 노드(tail)
DNode* DLinkedList::rearDNode() const {
    return __tail;
}

// 빈 리스트 여부 판단
bool DLinkedList::isEmpty() const {
    return __head == nullptr;
}

// 탐색: 노드의 총 개수(count)
int DLinkedList::countDNode() const {
    return __count;
}

// 리스트의 전체 원소(노드) 출력: 순방향
void DLinkedList::printSLinkedList() const {
    DNode* temp = __head;
    while (temp) {
        cout.width(3);
        cout << temp->__data << " ->>";
        temp = temp->__Rlink;
    }
    cout << " NULL" << endl;
}

// 리스트의 전체 원소(노드) 출력: 역방향
void DLinkedList::revPrintSLinkedList() const {
    DNode* temp = __tail;
    while (temp) {
        cout.width(3);
        cout << temp->__data << " ->>";
        temp = temp->__Llink;
    }
    cout << " NULL" << endl;
}

int main(void) {
    int num;
    cout << "20215229 이채훈" << endl;
    cout << endl;
    DLinkedList dList = DLinkedList();
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)   break;

        // 맨 마지막 노드로 삽입
        dList.addRear(num);
    }

    // 전체 원소 출력
    if (dList.isEmpty()) {
        cout << "입력된 데이터가 없습니다..." << endl;
    }
    else {
        printf("\n ### 입력된 데이터 ### \n\n");
        dList.printSLinkedList();
        dList.revPrintSLinkedList();
    }
    dList.~DLinkedList();
    return 0;
}