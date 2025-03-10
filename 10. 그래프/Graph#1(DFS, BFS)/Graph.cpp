#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// GNode class
class GNode {
private:
	int	__vertex;	// 정점
	int	__weight;	// 가중치
	GNode* __link;
	friend class GraphType;
public:
	GNode(int vertex, int weight);
};

// 그래프 노드(C): 그래프 노드 생성
GNode::GNode(int vertex = 0, int weight = 0)
	: __vertex(vertex), __weight(weight), __link(nullptr) {}

// GraphType class
class GraphType {
private:
	int	  __vertex;		// 정점의 개수
	GNode** __adjSList;		// 인접 리스트
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	DFSAdjSList(int  vertex);
	void	BFSAdjSList(int  vertex);
	void	printAdjSList(void) const;
};

// GraphType: 생성자(소멸자)와 메소드 정의
GraphType::GraphType(int vertex) : __vertex(vertex) {
	__adjSList = new GNode * [vertex + 1];
	memset(__adjSList, 0, sizeof(GNode*) * (vertex + 1));
}

// graphDestroy : 그래프 삭제
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

// insertEdge : 간선 추가
void  GraphType::insertEdge(int  row, int  col, int weight) {
	if (row >= __vertex || col >= __vertex) {
		// cout << "그래프에 없는 정점입니다!!!" << endl;
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

// printAdjMatrix : 그래프 전체 출력
void  GraphType::printAdjSList(void) const {
	char	ch;
	for (int i = 0; i < __vertex; i++) {
		ch = i + 65;
		cout << "\t정점 " << ch << "의 인접 리스트";
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

//그래프 순회: 깊이 우선 탐색(DFS)
void GraphType::DFSAdjSList(int vertex){
	//각 정점의 방문(Visited) 여부: true, false
	int* pVisited = new int[__vertex];
	memset(pVisited, 0, sizeof(int) * __vertex);
	stack<int> S;
	S.push(vertex);// Start Vertex
	pVisited[vertex] = true; //정점 방문
	char ch = vertex + 65;
	cout.width(3); cout << ch;

	int v = vertex;
	GNode* w;
	while (!S.empty()) {
		w = __adjSList[v];
		while (w){//인접한 정점이 있는 동안...
			// 방문 안한 인접 정점에 대해서 수행
			if (!pVisited[w->__vertex]) { 
				S.push(w->__vertex); 
				pVisited[w->__vertex]=true;//정점 방문
				ch = w->__vertex + 65;
				cout.width(3); cout << ch;
				v = w->__vertex;
				w = __adjSList[v];
			}
			else w = w->__link;
		}
		//방문안한 인접 정점이 없으면 스택 pop
		v = S.top(); S.pop();
	}
	cout << endl;
	delete[] pVisited;
}

//그래프 순회: 너비 우선 탐색(BFS)
void GraphType::BFSAdjSList(int vertex) {
	// 각 정점의 방문(Visited) 여부 : true, false
	int* pVisited = new int[__vertex];
	memset(pVisited, 0, sizeof(int) * __vertex);

	queue<int> Q;
	Q.push(vertex);// Start Vertex
	pVisited[vertex] = true;// 정점 방문
	char ch = vertex + 65;
	cout.width(3); cout << ch;

	int v = vertex;
	GNode* w;
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		w = __adjSList[v];
		while (w){//인접한 정점이 있는 동안..
			//방문 안한 인접 정점에 대해서 수행
			if (!pVisited[w->__vertex]) {
				Q.push(w->__vertex);
				pVisited[w->__vertex] = true;//정점 방문
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
	// G9 : 무향 그래프
	GraphType	G9 = GraphType(7);

	// 정점: A(0)
	G9.insertEdge(0, 1, 0);	// A(0) - B(1)
	G9.insertEdge(0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	G9.insertEdge(1, 0, 0);	// B(1) - A(0)
	G9.insertEdge(1, 3, 0);	// B(1) - D(3)
	G9.insertEdge(1, 4, 0);	// B(1) - E(4)

	// 정점: C(2)
	G9.insertEdge(2, 0, 0);	// C(2) - A(0)
	G9.insertEdge(2, 4, 0);	// C(2) - E(4)

	// 정점: D(3)
	G9.insertEdge(3, 1, 0);	// D(3) - B(6)
	G9.insertEdge(3, 6, 0);	// D(3) - G(6)

	// 정점: E(4)
	G9.insertEdge(4, 1, 0);	// E(4) - B(1)
	G9.insertEdge(4, 2, 0);	// E(4) - C(2)
	G9.insertEdge(4, 6, 0);	// E(4) - G(6)

	// 정점: F(5)
	G9.insertEdge(5, 6, 0);	// F(5) - G(6)

	// 정점: G(6)
	G9.insertEdge(6, 5, 0);	// G(6) - F(5)
	G9.insertEdge(6, 4, 0);	// G(6) - E(4)
	G9.insertEdge(6, 3, 0);	// G(6) - D(3)

	cout << "\n##### 그래프(G9): 인접 리스트 #####\n" << endl;
	G9.printAdjSList();

	printf("\n##### 그래프(G9): 깊이 우선 탐색(DFS) #####\n\n");
	G9.DFSAdjSList(0);

	printf("\n##### 그래프(G9): 너비 우선 탐색(BFS) #####\n\n");
	G9.BFSAdjSList(0);

	return 0;
}
