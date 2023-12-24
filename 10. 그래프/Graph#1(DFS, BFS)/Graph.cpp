#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// GNode class
class GNode {
private:
	int	__vertex;	// ����
	int	__weight;	// ����ġ
	GNode* __link;
	friend class GraphType;
public:
	GNode(int vertex, int weight);
};

// �׷��� ���(C): �׷��� ��� ����
GNode::GNode(int vertex = 0, int weight = 0)
	: __vertex(vertex), __weight(weight), __link(nullptr) {}

// GraphType class
class GraphType {
private:
	int	  __vertex;		// ������ ����
	GNode** __adjSList;		// ���� ����Ʈ
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	DFSAdjSList(int  vertex);
	void	BFSAdjSList(int  vertex);
	void	printAdjSList(void) const;
};

// GraphType: ������(�Ҹ���)�� �޼ҵ� ����
GraphType::GraphType(int vertex) : __vertex(vertex) {
	__adjSList = new GNode * [vertex + 1];
	memset(__adjSList, 0, sizeof(GNode*) * (vertex + 1));
}

// graphDestroy : �׷��� ����
GraphType::~GraphType(void) {
	GNode* old;
	for (int i = 0; i < __vertex; i++) {
		old = __adjSList[i];
		while (old) {
			__adjSList[i] = old->__link;
			delete old;
			old = __adjSList[i];
		}
	}
	delete[] __adjSList;
}

// insertEdge : ���� �߰�
void  GraphType::insertEdge(int  row, int  col, int weight) {
	if (row >= __vertex || col >= __vertex) {
		// cout << "�׷����� ���� �����Դϴ�!!!" << endl;
		return;
	}
	GNode* newGNode = new GNode(col, weight);
	if (__adjSList[row] == nullptr)
		__adjSList[row] = newGNode;
	else {
		GNode* rNode = __adjSList[row];
		while (rNode->__link)
			rNode = rNode->__link;
		rNode->__link = newGNode;
	}
}

// printAdjMatrix : �׷��� ��ü ���
void  GraphType::printAdjSList(void) const {
	char	ch;
	for (int i = 0; i < __vertex; i++) {
		ch = i + 65;
		cout << "\t���� " << ch << "�� ���� ����Ʈ";
		GNode* tNode = __adjSList[i];
		while (tNode) {
			cout.width(3);
			ch = tNode->__vertex + 65;
			cout << ch << " ->>";
			tNode = tNode->__link;
		}
		cout << " NULL" << endl;
	}
}

//�׷��� ��ȸ: ���� �켱 Ž��(DFS)
void GraphType::DFSAdjSList(int vertex){
	//�� ������ �湮(Visited) ����: true, false
	int* pVisited = new int[__vertex];
	memset(pVisited, 0, sizeof(int) * __vertex);
	stack<int> S;
	S.push(vertex);// Start Vertex
	pVisited[vertex] = true; //���� �湮
	char ch = vertex + 65;
	cout.width(3); cout << ch;

	int v = vertex;
	GNode* w;
	while (!S.empty()) {
		w = __adjSList[v];
		while (w){//������ ������ �ִ� ����...
			// �湮 ���� ���� ������ ���ؼ� ����
			if (!pVisited[w->__vertex]) { 
				S.push(w->__vertex); 
				pVisited[w->__vertex]=true;//���� �湮
				ch = w->__vertex + 65;
				cout.width(3); cout << ch;
				v = w->__vertex;
				w = __adjSList[v];
			}
			else w = w->__link;
		}
		//�湮���� ���� ������ ������ ���� pop
		v = S.top(); S.pop();
	}
	cout << endl;
	delete[] pVisited;
}

//�׷��� ��ȸ: �ʺ� �켱 Ž��(BFS)
void GraphType::BFSAdjSList(int vertex) {
	// �� ������ �湮(Visited) ���� : true, false
	int* pVisited = new int[__vertex];
	memset(pVisited, 0, sizeof(int) * __vertex);

	queue<int> Q;
	Q.push(vertex);// Start Vertex
	pVisited[vertex] = true;// ���� �湮
	char ch = vertex + 65;
	cout.width(3); cout << ch;

	int v = vertex;
	GNode* w;
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		w = __adjSList[v];
		while (w){//������ ������ �ִ� ����..
			//�湮 ���� ���� ������ ���ؼ� ����
			if (!pVisited[w->__vertex]) {
				Q.push(w->__vertex);
				pVisited[w->__vertex] = true;//���� �湮
				ch = w->__vertex + 65;
				cout.width(3); cout << ch;
			}
			w = w->__link;
		}
	}
	cout << endl;
	delete[] pVisited;
}

int main(void) {
	// G9 : ���� �׷���
	GraphType	G9 = GraphType(7);

	// ����: A(0)
	G9.insertEdge(0, 1, 0);	// A(0) - B(1)
	G9.insertEdge(0, 2, 0);	// A(0) - C(2)

	// ����: B(1)
	G9.insertEdge(1, 0, 0);	// B(1) - A(0)
	G9.insertEdge(1, 3, 0);	// B(1) - D(3)
	G9.insertEdge(1, 4, 0);	// B(1) - E(4)

	// ����: C(2)
	G9.insertEdge(2, 0, 0);	// C(2) - A(0)
	G9.insertEdge(2, 4, 0);	// C(2) - E(4)

	// ����: D(3)
	G9.insertEdge(3, 1, 0);	// D(3) - B(6)
	G9.insertEdge(3, 6, 0);	// D(3) - G(6)

	// ����: E(4)
	G9.insertEdge(4, 1, 0);	// E(4) - B(1)
	G9.insertEdge(4, 2, 0);	// E(4) - C(2)
	G9.insertEdge(4, 6, 0);	// E(4) - G(6)

	// ����: F(5)
	G9.insertEdge(5, 6, 0);	// F(5) - G(6)

	// ����: G(6)
	G9.insertEdge(6, 5, 0);	// G(6) - F(5)
	G9.insertEdge(6, 4, 0);	// G(6) - E(4)
	G9.insertEdge(6, 3, 0);	// G(6) - D(3)

	cout << "\n##### �׷���(G9): ���� ����Ʈ #####\n" << endl;
	G9.printAdjSList();

	printf("\n##### �׷���(G9): ���� �켱 Ž��(DFS) #####\n\n");
	G9.DFSAdjSList(0);

	printf("\n##### �׷���(G9): �ʺ� �켱 Ž��(BFS) #####\n\n");
	G9.BFSAdjSList(0);

	return 0;
}
