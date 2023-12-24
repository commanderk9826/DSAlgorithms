#include <iostream>

#define queueMAXSIZE 7

using namespace std;

template <typename E>
class CircularQueue
{
	E queue[queueMAXSIZE];
	int front, rear, count;
public:
	CircularQueue();//������
	~CircularQueue();//�Ҹ���

	void push(const E& e);//����
	E pop();//����

	E printfront() const;//����Ʈ ���� ���
	E printback() const;	//ť ���� �ڿ� �ִ� �� ��ȯ
	int size() const;//ť�� ũ�� ���
	bool empty() const;	//ť �� ���� Ȯ��
	bool full() const;	//ť ��ȭ ���� Ȯ��
	void printQueue() const;	//ť �迭 ���� ���
};

template <typename E>
CircularQueue <E> ::CircularQueue() : front(0), rear(0), count(0) {}

template <typename E>
CircularQueue<E>::~CircularQueue() {} // �Ҹ���

template <typename E>
void CircularQueue<E>::push(const E& e)
{
	if (full())
	{
		cout << "ť ��ȭ ���·� Ǫ�� �Ұ�" << endl;
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
		cout << "ť�� ��� ���� " << endl;
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
		cout << "ť�� ����ֽ��ϴ�." << endl;
		return 0;
	}
	return queue[front];
}

template<typename E>
E CircularQueue<E>::printback() const
{
	if (empty())
	{
		cout << "ť�� ����ֽ��ϴ�." << endl;
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
		cout << "ť�� ��� �ֽ��ϴ�" << endl;
		return;
	}
	if (full())
	{
		cout << "ť�� �� á���ϴ�" << endl;
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
	CircularQueue<int> q;	//ť Ŭ���� ����
	int menu;

	cout << endl << "### ť ����: 1���� �迭 ###" << endl << endl;

	cout << "1) ������ ����(enQueue):" << endl;
	cout << "2) ������ ����(deQueue):" << endl;
	cout << "3) ��ü ���" << endl;
	cout << "4) ���α׷� ����" << endl << endl;

	while (true)
	{
		cout << "�޴� ����: "; cin >> menu;

		switch (menu)
		{
		case 1:	//1) ������ ����
			int input;
			cout << "������ ������ �Է�: "; cin >> input;
			q.push(input);
			break;
		case 2:	//2) ������ ����
			q.pop();
			break;
		case 3:	//3) ������ ���
			q.printQueue();
			break;
		case 4: //4) ���α׷� ����
			return 0;
		}

		cout << endl;
	}

	return 0;
}

