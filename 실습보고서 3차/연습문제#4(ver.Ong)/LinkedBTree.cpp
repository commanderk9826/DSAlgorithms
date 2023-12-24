#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

template <typename E>
class LinkedBTree;

// Ŭ���� DNode
template <typename E>
class DNode {
public:
	DNode(const E& data);
private:
	E         __data;
	DNode<E>* __Llink;
	DNode<E>* __Rlink;
	template <typename T> friend class LinkedBTree;
};

template <typename E>
DNode<E>::DNode(const E& data) :
	__data(data), __Llink(nullptr), __Rlink(nullptr) {}

//Ŭ���� LinkedBTree
template <typename E>
class LinkedBTree {
public:
	LinkedBTree();
	~LinkedBTree();
	DNode<E>* makeLinkedBTree(const string str);
	void	Preorder(DNode<E>* root) const;
	void	Inorder(DNode<E>* root) const;
	void	Postorder(DNode<E>* root) const;
	void	Levelorder(DNode<E>* root) const;
private:
	DNode<E>* __root;
};

//������
template <typename E>
LinkedBTree<E>::LinkedBTree() 
	: __root(nullptr){}

//�Ҹ���
template <typename E>
LinkedBTree<E>::~LinkedBTree()
{
	if (__root == nullptr)
		return;

	DNode<E>* tNode = nullptr;
	queue<DNode<E>*>	Q;
	Q.push(__root);
	while (!Q.empty()) {
		tNode = Q.front();
		Q.pop();
		if (tNode->__Llink) Q.push(tNode->__Llink);
		if (tNode->__Rlink) Q.push(tNode->__Rlink);
		delete tNode;
	}
}

//���� ���� �Ǵ�
int  isOperator(int  op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

//����Ʈ�� ����
template <typename E>
DNode<E>* LinkedBTree<E>::makeLinkedBTree(const string str)
{
	stack<DNode<E>*>	S;
	DNode<E>* tNode;
	for (int i = 0; i < str.length(); i++)
	{
		while (str[i] == ' ')
			i++;

		tNode = new DNode<E>(str[i]);

		if (isOperator(str[i])) {
			tNode->__Rlink = S.top();    S.pop();
			tNode->__Llink = S.top();    S.pop();
		}
		S.push(tNode);
	}
	tNode = S.top();
	S.pop();

	// ��Ʈ ��� ����
	__root = tNode;
	return  tNode;
}

// ���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Preorder(DNode<E>* root) const
{
	if (root == nullptr) return;

	stack<DNode<E>*> S;
	S.push(root);

	while (!S.empty())
	{
		DNode<E>* tNode = S.top();
		S.pop();
		cout.width(3); cout << tNode->__data;

		if (tNode->__Rlink) S.push(tNode->__Rlink);
		if (tNode->__Llink) S.push(tNode->__Llink);
	}
	cout << endl;
}

// ���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Inorder(DNode<E>* root) const
{
	if (root == nullptr) return;

	stack<DNode<E>*> S;
	DNode<E>* ptr = root;

	while (ptr != nullptr || !S.empty())
	{
		while (ptr != nullptr)
		{
			S.push(ptr);
			ptr = ptr->__Llink;
		}

		ptr = S.top();
		S.pop();
		cout.width(3); cout << ptr->__data;
		ptr = ptr->__Rlink;
	}
	cout << endl;
}

// ���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Postorder(DNode<E>* root) const
{
	if (root == nullptr) return;

	stack<DNode<E>*> S1, S2;
	S1.push(root);

	while (!S1.empty())
	{
		DNode<E>* tNode = S1.top();
		S1.pop();
		S2.push(tNode);

		if (tNode->__Llink) S1.push(tNode->__Llink);
		if (tNode->__Rlink) S1.push(tNode->__Rlink);
	}

	while (!S2.empty())
	{
		DNode<E>* tNode = S2.top();
		S2.pop();
		cout.width(3); cout << tNode->__data;
	}

	cout << endl;
}

// �ʺ� �켱 ��ȸ: ������� ���(ť ���� Ȱ��)
template <typename E>
void LinkedBTree<E>::Levelorder(DNode<E>* root) const
{
	if (root == nullptr)
		return;

	queue<DNode<E>*>	Q;
	Q.push(root);
	while (!Q.empty()) {
		DNode<E>* tNode = Q.front();
		Q.pop();
		cout.width(3);
		cout << tNode->__data;
		if (tNode->__Llink) Q.push(tNode->__Llink);
		if (tNode->__Rlink) Q.push(tNode->__Rlink);
	}
	cout << endl;
}

int main(void)
{
	string	postfix;

	cout << "Ʈ���� ������ ���� ����: ";
	getline(cin, postfix);

	// ���� Ʈ�� ���� �� ����
	LinkedBTree<char>	BT;
	DNode<char>* root = BT.makeLinkedBTree(postfix);

	// ���� �켱 ��ȸ: ����.����.���� ��ȸ
	cout << "\nPreorder  : ";	BT.Preorder(root);	// ���� ��ȸ
	cout << "Inorder   : ";	BT.Inorder(root);	// ���� ��ȸ
	cout << "Postorder : ";	BT.Postorder(root);	// ���� ��ȸ

	// �ʺ� �켱 ��ȸ
	cout << "Levelorder : ";	BT.Levelorder(root);

	return 0;
}
