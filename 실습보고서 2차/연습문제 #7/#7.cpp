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

// DNode: �����ڿ� �޼ҵ� ����
DNode::DNode(const int& data) :
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

// DLinkedList class
class DLinkedList {
private:
    DNode* __head;      // ù ��° ���
    DNode* __tail;      // �� ������ ���
    int __count;        // ����� �� ����
public:
    DLinkedList();               // ������
    ~DLinkedList();             // �Ҹ���: ��ü ��� ����
    void addRear(const int& e);     // ����: �� ������ ���
    void removeFront();          // ����: ù ��° ���
    DNode* frontDNode() const;        // Ž��: ù ��° ���
    DNode* rearDNode() const;        // Ž��: �� ������ ���
    bool isEmpty() const;        // �� ����Ʈ ���� �Ǵ�
    int countDNode() const; // Ž��: ����� �� ����(count)
    void printSLinkedList() const;   // ����Ʈ�� ��ü ����(���) ���: ������
    void revPrintSLinkedList() const;   // ����Ʈ�� ��ü ����(���) ���: ������
};

// DLinkedList: ������(�Ҹ���)�� �޼ҵ� ����
DLinkedList::DLinkedList()
    : __head(nullptr), __tail(nullptr), __count(0) { }

DLinkedList::~DLinkedList() {
    while (!isEmpty()) removeFront();
}

// ��� ����: �� ������ ����...
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

// ��� ����: ù ��° ��带...
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

// Ž��: ù ��° ���
DNode* DLinkedList::frontDNode() const {
    return __head;
}

// Ž��: �� ������ ���(tail)
DNode* DLinkedList::rearDNode() const {
    return __tail;
}

// �� ����Ʈ ���� �Ǵ�
bool DLinkedList::isEmpty() const {
    return __head == nullptr;
}

// Ž��: ����� �� ����(count)
int DLinkedList::countDNode() const {
    return __count;
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
    cout << "20215229 ��ä��" << endl;
    cout << endl;
    DLinkedList dList = DLinkedList();
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
    }
    else {
        printf("\n ### �Էµ� ������ ### \n\n");
        dList.printSLinkedList();
        dList.revPrintSLinkedList();
    }
    dList.~DLinkedList();
    return 0;
}