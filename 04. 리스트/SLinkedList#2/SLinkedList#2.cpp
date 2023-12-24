#include <iostream>

using namespace std;

class SNode {
private:
    int data;
    SNode* link;
    friend class SLinkedList; 
};

class SLinkedList {
private:
    SNode* head;
    SNode* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    //생성
    SNode* makeSNode(const int& e);
    //조사
    bool isEmpty() const;
    int countSNode();
    int searchSNode(const int& e);
    //출력
    void PrintSLinkedList() const;
    //삽입
    void insertFront(const int& e);
    void insertMid(const int& e, SNode* preSNode);
    void insertRear(const int& e);
    //삭제
    void removeFront();
    void removeMid(SNode* preSNode);
    void removeRear();
};

inline void error(const char* message) {
    cout << message;
    exit(100); //exit : 
}

//생성자 & 소멸자
SLinkedList::SLinkedList() {
    head = NULL;
    tail = NULL;
    count = 0;
}
SLinkedList::~SLinkedList() {
    while (!isEmpty()) removeRear();
}

//생성
SNode* SLinkedList::makeSNode(const int& e) {
    SNode* s = new SNode;
    s->data = e;
    s->link = NULL;

    return s;
}

//조사
bool SLinkedList::isEmpty() const {
    return head == NULL;
}
int SLinkedList::countSNode() {
    return count;
}

int SLinkedList::searchSNode(const int& e) {
    SNode* temp = head;
    count = 0;//count 0으로 초기화해두고 시작

    while (temp != NULL) { //마지막 노드 while문 실행
        count++;
        if (temp->data == e) return count;
        else temp = temp->link;
    }//if-else 아니여도 똑같음
    //while의 결과 temp=null

    if (temp == NULL) return 0;
}

//출력
void SLinkedList::PrintSLinkedList() const {
    SNode* temp = head;

    while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->link;
    }

    if (temp == NULL) cout << "NULL";
}

//삽입

//앞부터 삽입
void SLinkedList::insertFront(const int& e) {
    SNode* newSNode = makeSNode(e); //새로운 노드 생성

    //if(isEmpty()) head=newSNode else{}; //없어도 됨

    newSNode->link = head;//head값 물려받음
    head = newSNode;

}
//중간 삽입
void SLinkedList::insertMid(const int& e, SNode* preSNode) {

    SNode* newSNode = makeSNode(e);//새로운 노드 생성

    if (isEmpty()) {
        head = newSNode;
        tail = newSNode;
    }
    else {
        newSNode->link = preSNode->link;
        preSNode->link = newSNode;
    }
}
//뒤부터 삽입
void SLinkedList::insertRear(const int& e) {
    SNode* newSNode = makeSNode(e);//새로운 노드 생성

    if (isEmpty()) {
        head = newSNode;
        tail = newSNode;
    }
    else {
        tail->link = newSNode;
        tail = newSNode;
    }

    count++;
}

//삭제

//앞에서 삭제
void SLinkedList::removeFront() {
    if (isEmpty()) return;

    SNode* old = head;
    head = old->link;
    delete old;

    count--;
}
//중간에서 삭제
void SLinkedList::removeMid(SNode* preSNode) {
    if (isEmpty()) return;

    SNode* old = preSNode->link;
    preSNode->link = old->link;
    delete old;

    count--;
}
//뒤에서 삭제
void SLinkedList::removeRear() {
    SNode* temp = head;

    if (isEmpty()) {
        cout << "빈 리스트입니다 " << endl;
        return;
    }

    if (temp == tail) {//노드 하나일 때
        delete head;

        head = NULL;
        tail = NULL;
        count--;
        return;
    }

    SNode* old = tail;
    count = 1;

    //이전 노드 탐색
    while (temp->link != tail) {
        temp = temp->link;
        count++;
    }//while문 결과 : n-1 노드

    temp->link = NULL;
    tail = temp;
    delete old;
    count--;
}

//메인함수

int main() {
    int num;
    SLinkedList s = SLinkedList();
    while (true) {
        cout << " 임의의 정수 입력(종료 : 0): ";
        cin >> num;
        if (num == 0) break;
        //맨 마지막 노드로 삽입
        s.insertRear(num);
    }

    // 전체 원소 출력
    if (s.isEmpty()) {
        cout << "입력된 데이터가 없습니다..." << endl;
        return 0;
    }

    printf("\n ### 입력된 데이터 ### \n\n ");
    s.PrintSLinkedList();

    printf("\n ### 데이터 갯수 ### \n\n ");
    cout << "총 데이터 갯수 : " << s.countSNode() << endl;

    s.~SLinkedList();

    return 0;
}
