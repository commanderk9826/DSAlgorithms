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
    QueueNode<E>* front, * rear; //E로 만들어진 front,rear;
public:
    //생성자 & 소멸자
    LinkedQueue();
    ~LinkedQueue();
    //생성
    QueueNode<E>* makeQueueNode(const E& e);
    //조사
    bool isEmpty() const;
    //출력
    void printQueue() const;
    //삽입,삭제,peek
    void enQueue(const E& e);
    E deQueue();
    E peek() const;
};


//생성자 & 소멸자
template<typename E>
LinkedQueue<E>::LinkedQueue() {
    front = NULL;
    rear = NULL;
}
template<typename E>
LinkedQueue<E>::~LinkedQueue() {}

//생성
template<typename E>
QueueNode<E>* LinkedQueue<E>::makeQueueNode(const E& e) {
    QueueNode<E>* nNode = new QueueNode<E>;
    nNode->data = e;
    nNode->link = NULL;

    return nNode;
}

//조사
template<typename E>
bool LinkedQueue<E>::isEmpty() const {
    return front == NULL;
}

//출력
template<typename E>
void LinkedQueue<E>::printQueue() const {

    if (isEmpty()) {
        cout << " Queue is Empty " << endl;
        return;
    }

    QueueNode<E>* temp = front; // 첫 노드부터

    while (temp) {
        cout.width(3);
        cout << temp->data;
        temp = temp->link;
    }//while문의 결과 : NULL 
    cout << '\n';
}

template<typename E>
void LinkedQueue<E>::enQueue(const E& e) {
    QueueNode<E>* nNode = makeQueueNode(e); //새로운 노드 생성

    if (isEmpty()) { //비어있는 리스트라면
        front = nNode;
        rear = nNode;
    }
    else {
        rear->link = nNode; // n번째 노드가 new 노드를 가리키도록 함
        rear = nNode; // rear에 new 노드 저장
    }
}

template<typename E>
E LinkedQueue<E>::deQueue() {
    if (isEmpty()) error("큐 공백 에러");

    QueueNode<E>* old = front; //기존 front
    E data = old->data; // data 살리고
    front = old->link; // front 갱신
    free(old);

    return data;
}

template<typename E>
E LinkedQueue<E>::peek() const {
    if (isEmpty()) {
        error("큐 공백 에러");
        return;
    }
    else return front->data;
}

int main(void)
{

    cout << "20215229 이채훈\n" << endl;

    int   num, choice;
    LinkedQueue<int>	s;

    while (true) {
        system("cls");
        cout << "\n ### 큐 구현: 단순 연결 리스트 ### \n" << endl;
        cout << "1) 데이터 삽입: enQueue" << endl;
        cout << "2) 데이터 삭제: deQueue" << endl;
        cout << "3) 전체 출력" << endl;
        cout << "4) 프로그램 종료 \n" << endl;
        cout << "메뉴 선택 : ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "\n삽입 할 데이터 입력: ";
            cin >> num;
            s.enQueue(num);
            break;
        case 2: cout << "삭제 된 데이터: " << s.deQueue() << endl;
            break;
        case 3: s.printQueue();
            break;
        case 4: cout << "프로그램 종료..." << endl;
            return 0;
        default: cout << "잘못 선택 하셨습니다." << endl;
        }
        system("pause");
    }

    return 0;
}