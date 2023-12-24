#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

template <typename E>
class LinkedBTree;

// 클래스 DNode
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

//클래스 LinkedBTree
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

//생성자
template <typename E>
LinkedBTree<E>::LinkedBTree() 
	: __root(nullptr){}

//소멸자
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

//공백 여부 판단
int  isOperator(int  op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

//이진트리 생성
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

	// 루트 노드 설정
	__root = tNode;
	return  tNode;
}

// 깊이 우선 순회: 전위 순회
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

// 깊이 우선 순회: 중위 순회
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

// 깊이 우선 순회: 후위 순회
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

// 너비 우선 순회: 비재귀적 용법(큐 구조 활용)
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

	cout << "트리를 구성할 후위 수식: ";
	getline(cin, postfix);

	// 이진 트리 생성 및 구성
	LinkedBTree<char>	BT;
	DNode<char>* root = BT.makeLinkedBTree(postfix);

	// 깊이 우선 순회: 전위.중위.후위 순회
	cout << "\nPreorder  : ";	BT.Preorder(root);	// 전위 순회
	cout << "Inorder   : ";	BT.Inorder(root);	// 중위 순회
	cout << "Postorder : ";	BT.Postorder(root);	// 후위 순회

	// 너비 우선 순회
	cout << "Levelorder : ";	BT.Levelorder(root);

	return 0;
}
