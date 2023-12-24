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
    //������, �Ҹ���
    DLinkedList();
    ~DLinkedList();
    //����
    DNode* makeDNode(const int& e);
    //����
    bool isEmpty() const;
    int countDNode();
    //����
    void insertRear(const int& e);
    //����
    void deleteFront();
    void deleteMid(DNode* pre_DNode);
    void deleteRear();
    //���
    void printBy_Rlink() const;
    void printBy_Llink() const;
};

//������ & �Ҹ���
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

//����
DNode* DLinkedList::makeDNode(const int& e) {
    DNode* nNode = new DNode;

    nNode->data = e;
    nNode->Llink = NULL;
    nNode->Rlink = NULL;

    return nNode;
}

//����
bool DLinkedList::isEmpty() const {
    return head == NULL;
}
int DLinkedList::countDNode() {
    return count;
}
//����
void DLinkedList::insertRear(const int& e) {
    DNode* nNode = makeDNode(e); //��� ����

    if (isEmpty()) { //�� ��� Ȯ��
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

//����
void DLinkedList::deleteFront() {

    if (isEmpty()) error("�� ����Ʈ�Դϴ�.");

    DNode* old = head;
    old->Llink = NULL;
    head = old->Rlink;

    delete old;

    count--;
}

void DLinkedList::deleteMid(DNode* pre_DNode) {

    if (isEmpty()) error("�� ����Ʈ�Դϴ�.");

    DNode* old = pre_DNode->Rlink;//������ ���


    pre_DNode->Rlink = old->Rlink;
    old->Rlink->Llink = pre_DNode;

    delete old;

    count--;
}

void DLinkedList::deleteRear() {

    if (isEmpty()) error("�� ����Ʈ�Դϴ�.");

    DNode* old = tail; //������ ���

    //��� �ϳ� ���� ���
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        // n-1 ��� Rlink -> NULL��
        // tail -> n-1��
        old->Llink->Rlink = NULL;
        tail = old->Llink;
    }

    delete old;

    count--;
}

//���
void DLinkedList::printBy_Rlink() const {
    DNode* temp = head;

    while (temp) {
        cout << temp->data << " ->> ";
        temp = temp->Rlink;
    }//������ ��嵵 while�� ����

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

//�����Լ�
int main() {
    int num;
    DLinkedList d = DLinkedList();

    while (true) {
        cout << "������ ���� �Է�(���� : 0) : ";
        cin >> num;

        if (num == 0) break;

        d.insertRear(num);
    }

    if (d.isEmpty()) {
        cout << "�Էµ� �����Ͱ� �����ϴ�..." << endl;
        return 0;
    }

    printf("%c", '\n');
    cout << "### �Էµ� ������ ### " << endl;
    printf("%c", '\n');

    d.printBy_Rlink();
    d.printBy_Llink();

    d.~DLinkedList();

    return 0;
}
