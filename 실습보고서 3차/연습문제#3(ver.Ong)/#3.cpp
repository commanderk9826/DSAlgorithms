#include <iostream>

#define queueMAXSIZE 7

using namespace std;

template <typename E>
class CircularQueue
{
	E queue[queueMAXSIZE];
	int front, rear, count;
public:
	CircularQueue();//생성자
	~CircularQueue();//소멸자

	void push(const E& e);//삽입
	E pop();//삭제

	E printfront() const;//프론트 원소 출력
	E printback() const;	//큐 제일 뒤에 있는 값 반환
	int size() const;//큐의 크기 출력
	bool empty() const;	//큐 빈 여부 확인
	bool full() const;	//큐 포화 여부 확인
	void printQueue() const;	//큐 배열 원소 출력
};

template <typename E>
CircularQueue <E> ::CircularQueue() : front(0), rear(0), count(0) {}

template <typename E>
CircularQueue<E>::~CircularQueue() {} // 소멸자

template <typename E>
void CircularQueue<E>::push(const E& e)
{
	if (full())
	{
		cout << "큐 포화 상태로 푸쉬 불가" << endl;
		return;
	}
	queue[rear] = e;
	rear = (rear + 1) % queueMAXSIZE;
	++count;
}

template<typename E>
E CircularQueue<E>::pop()
{
	if (empty())
	{
		cout << "큐가 비어 있음 " << endl;
		return 0;
	}

	E pop_data = queue[front];
	front = (front + 1) % queueMAXSIZE;
	--count;
	return pop_data;
}

template<typename E>
E CircularQueue<E>::printfront() const
{
	if (empty())
	{
		cout << "큐가 비어있습니다." << endl;
		return 0;
	}
	return queue[front];
}

template<typename E>
E CircularQueue<E>::printback() const
{
	if (empty())
	{
		cout << "큐가 비어있습니다." << endl;
		return 0;
	}
	return queue[(rear - 1 + queueMAXSIZE) % queueMAXSIZE];
}

template<typename E>
int CircularQueue<E>::size() const
{
	return count;
}

template<typename E>
bool CircularQueue<E>::empty() const
{
	return (count == 0);
}

template<typename E>
bool CircularQueue<E>::full() const
{
	return (count == queueMAXSIZE);
}

template<typename E>
void CircularQueue<E>::printQueue() const
{
	if (empty())
	{
		cout << "큐가 비어 있습니다" << endl;
		return;
	}
	if (full())
	{
		cout << "큐가 꽉 찼습니다" << endl;
		return;
	}

	int i = front;
	for (int j = 0; j < count; j++)
	{
		cout << queue[i] << " ";
		i = (i + 1) % queueMAXSIZE;
	}
	cout << endl;
}

int main()
{
	CircularQueue<int> q;	//큐 클래스 선언
	int menu;

	cout << endl << "### 큐 구현: 1차원 배열 ###" << endl << endl;

	cout << "1) 데이터 삽입(enQueue):" << endl;
	cout << "2) 데이터 삭제(deQueue):" << endl;
	cout << "3) 전체 출력" << endl;
	cout << "4) 프로그램 종료" << endl << endl;

	while (true)
	{
		cout << "메뉴 선택: "; cin >> menu;

		switch (menu)
		{
		case 1:	//1) 데이터 삽입
			int input;
			cout << "삽입할 데이터 입력: "; cin >> input;
			q.push(input);
			break;
		case 2:	//2) 데이터 삭제
			q.pop();
			break;
		case 3:	//3) 데이터 출력
			q.printQueue();
			break;
		case 4: //4) 프로그램 종료
			return 0;
		}

		cout << endl;
	}

	return 0;
}

