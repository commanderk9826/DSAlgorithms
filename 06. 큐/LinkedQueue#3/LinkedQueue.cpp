#include <iostream>
using namespace std;

inline void error(const char* message);

template<typename E>
class QueueNode {
    E data;
    QueueNode<E>* link;
    template<typename E> friend class LinkedQueue;
};

inline void error(const char* message) {
    cout << message;
    exit(100); //exit : 
}

template<typename E>
class LinkedQueue {
    QueueNode<E>* front, * rear; //E�� ������� front,rear;
public:
    //������ & �Ҹ���
    LinkedQueue();
    ~LinkedQueue();
    //����
    QueueNode<E>* makeQueueNode(const E& e);
    //����
    bool isEmpty() const;
    //���
    void printQueue() const;
    //����,����,peek
    void enQueue(const E& e);
    E deQueue();
    E peek() const;
};


//������ & �Ҹ���
template<typename E>
LinkedQueue<E>::LinkedQueue() {
    front = NULL;
    rear = NULL;
}
template<typename E>
LinkedQueue<E>::~LinkedQueue() {}

//����
template<typename E>
QueueNode<E>* LinkedQueue<E>::makeQueueNode(const E& e) {
    QueueNode<E>* nNode = new QueueNode<E>;
    nNode->data = e;
    nNode->link = NULL;

    return nNode;
}

//����
template<typename E>
bool LinkedQueue<E>::isEmpty() const {
    return front == NULL;
}

//���
template<typename E>
void LinkedQueue<E>::printQueue() const {

    if (isEmpty()) {
        cout << " Queue is Empty " << endl;
        return;
    }

    QueueNode<E>* temp = front; // ù ������

    while (temp) {
        cout.width(3);
        cout << temp->data;
        temp = temp->link;
    }//while���� ��� : NULL 
    cout << '\n';
}

template<typename E>
void LinkedQueue<E>::enQueue(const E& e) {
    QueueNode<E>* nNode = makeQueueNode(e); //���ο� ��� ����

    if (isEmpty()) { //����ִ� ����Ʈ���
        front = nNode;
        rear = nNode;
    }
    else {
        rear->link = nNode; // n��° ��尡 new ��带 ����Ű���� ��
        rear = nNode; // rear�� new ��� ����
    }
}

template<typename E>
E LinkedQueue<E>::deQueue() {
    if (isEmpty()) error("ť ���� ����");

    QueueNode<E>* old = front; //���� front
    E data = old->data; // data �츮��
    front = old->link; // front ����
    free(old);

    return data;
}

template<typename E>
E LinkedQueue<E>::peek() const {
    if (isEmpty()) {
        error("ť ���� ����");
        return;
    }
    else return front->data;
}

int main(void)
{

    cout << "20215229 ��ä��\n" << endl;

    int   num, choice;
    LinkedQueue<int>	s;

    while (true) {
        system("cls");
        cout << "\n ### ť ����: �ܼ� ���� ����Ʈ ### \n" << endl;
        cout << "1) ������ ����: enQueue" << endl;
        cout << "2) ������ ����: deQueue" << endl;
        cout << "3) ��ü ���" << endl;
        cout << "4) ���α׷� ���� \n" << endl;
        cout << "�޴� ���� : ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "\n���� �� ������ �Է�: ";
            cin >> num;
            s.enQueue(num);
            break;
        case 2: cout << "���� �� ������: " << s.deQueue() << endl;
            break;
        case 3: s.printQueue();
            break;
        case 4: cout << "���α׷� ����..." << endl;
            return 0;
        default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
        }
        system("pause");
    }

    return 0;
}