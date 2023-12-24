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
    //����
    SNode* makeSNode(const int& e);
    //����
    bool isEmpty() const;
    int countSNode();
    int searchSNode(const int& e);
    //���
    void PrintSLinkedList() const;
    //����
    void insertFront(const int& e);
    void insertMid(const int& e, SNode* preSNode);
    void insertRear(const int& e);
    //����
    void removeFront();
    void removeMid(SNode* preSNode);
    void removeRear();
};

inline void error(const char* message) {
    cout << message;
    exit(100); //exit : 
}

//������ & �Ҹ���
SLinkedList::SLinkedList() {
    head = NULL;
    tail = NULL;
    count = 0;
}
SLinkedList::~SLinkedList() {
    while (!isEmpty()) removeRear();
}

//����
SNode* SLinkedList::makeSNode(const int& e) {
    SNode* s = new SNode;
    s->data = e;
    s->link = NULL;

    return s;
}

//����
bool SLinkedList::isEmpty() const {
    return head == NULL;
}
int SLinkedList::countSNode() {
    return count;
}

int SLinkedList::searchSNode(const int& e) {
    SNode* temp = head;
    count = 0;//count 0���� �ʱ�ȭ�صΰ� ����

    while (temp != NULL) { //������ ��� while�� ����
        count++;
        if (temp->data == e) return count;
        else temp = temp->link;
    }//if-else �ƴϿ��� �Ȱ���
    //while�� ��� temp=null

    if (temp == NULL) return 0;
}

//���
void SLinkedList::PrintSLinkedList() const {
    SNode* temp = head;

    while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->link;
    }

    if (temp == NULL) cout << "NULL";
}

//����

//�պ��� ����
void SLinkedList::insertFront(const int& e) {
    SNode* newSNode = makeSNode(e); //���ο� ��� ����

    //if(isEmpty()) head=newSNode else{}; //��� ��

    newSNode->link = head;//head�� ��������
    head = newSNode;

}
//�߰� ����
void SLinkedList::insertMid(const int& e, SNode* preSNode) {

    SNode* newSNode = makeSNode(e);//���ο� ��� ����

    if (isEmpty()) {
        head = newSNode;
        tail = newSNode;
    }
    else {
        newSNode->link = preSNode->link;
        preSNode->link = newSNode;
    }
}
//�ں��� ����
void SLinkedList::insertRear(const int& e) {
    SNode* newSNode = makeSNode(e);//���ο� ��� ����

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

//����

//�տ��� ����
void SLinkedList::removeFront() {
    if (isEmpty()) return;

    SNode* old = head;
    head = old->link;
    delete old;

    count--;
}
//�߰����� ����
void SLinkedList::removeMid(SNode* preSNode) {
    if (isEmpty()) return;

    SNode* old = preSNode->link;
    preSNode->link = old->link;
    delete old;

    count--;
}
//�ڿ��� ����
void SLinkedList::removeRear() {
    SNode* temp = head;

    if (isEmpty()) {
        cout << "�� ����Ʈ�Դϴ� " << endl;
        return;
    }

    if (temp == tail) {//��� �ϳ��� ��
        delete head;

        head = NULL;
        tail = NULL;
        count--;
        return;
    }

    SNode* old = tail;
    count = 1;

    //���� ��� Ž��
    while (temp->link != tail) {
        temp = temp->link;
        count++;
    }//while�� ��� : n-1 ���

    temp->link = NULL;
    tail = temp;
    delete old;
    count--;
}

//�����Լ�

int main() {
    int num;
    SLinkedList s = SLinkedList();
    while (true) {
        cout << " ������ ���� �Է�(���� : 0): ";
        cin >> num;
        if (num == 0) break;
        //�� ������ ���� ����
        s.insertRear(num);
    }

    // ��ü ���� ���
    if (s.isEmpty()) {
        cout << "�Էµ� �����Ͱ� �����ϴ�..." << endl;
        return 0;
    }

    printf("\n ### �Էµ� ������ ### \n\n ");
    s.PrintSLinkedList();

    printf("\n ### ������ ���� ### \n\n ");
    cout << "�� ������ ���� : " << s.countSNode() << endl;

    s.~SLinkedList();

    return 0;
}
