/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: AdjList.cpp
			- main	: 그래프 생성 및 정점 추가
			클래스	: GraphType
				- 그래프 생성.삭제: GraphType, ~GraphType
				- 그래프 간선 추가: insertEdge
				- 그래프 전체 출력: printAdjList
*/

#include <iostream>
using namespace std;

//GNode class
class GNode {
private:
	int __vertex;//정점
	int __weight;//가중치
	GNode* __link;
	friend class GraphType;
public:
	GNode(int vertex, int weight);
};

//그래프 노드(C): 그래프 노드 생성
GNode::GNode(int vertex, int weight)
	:__vertex(vertex), __weight(weight), __link(nullptr){}

// GraphType class
class GraphType {
private:
	int	__vertex;	// 정점의 개수
	GNode** __adjSList;	// 인접 리스트
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	printAdjList(void) const;
};

//생성자(소멸자)와 메소드 정의
GraphType::GraphType(int vertex) : __vertex(vertex) {
	// 인접 행렬: 2차원 배열 동적 메모리 할당
	__adjSList=new GNode*[vertex + 1];
	memset(__adjSList, 0, sizeof(GNode*) * (vertex + 1));
}

//graphDestroy: 그래프 삭제
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
	delete[]__adjSList;
}

//insertEdge: 그래프 간선 추가
void  GraphType::insertEdge(int  row, int  col, int weight = 1) {
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

//printAdjList: 그래프 전체 출력
void  GraphType::printAdjList(void) const {
	char ch;
	for (int i = 0; i < __vertex; i++) {
		ch = i + 65;
		cout << "\t정점 " << ch << "의 인접 리스트";
		GNode* tNode = __adjSList[i];
		while (tNode){
			cout.width(3);
			ch = tNode->__vertex + 65;
			cout << ch << "->>";
			tNode = tNode->__link;
		}
		cout << " NULL" << endl;
	}
}

int main(void)
{
	// G2 : 무향 그래프
	GraphType	G2 = GraphType(3);

	// 정점: A(0)
	G2.insertEdge(0, 1, 0);	// A(0) - B(1)
	G2.insertEdge(0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	G2.insertEdge(1, 0, 0);	// B(1) - A(0)
	G2.insertEdge(1, 2, 0);	// B(1) - C(2)

	// 정점: C(2)
	G2.insertEdge(2, 1, 0);	// C(2) - B(1)
	G2.insertEdge(2, 0, 0);	// C(2) - A(0)

	cout << "\n##### 그래프(G2): 인접 행렬 #####" << endl;
	G2.printAdjList();

	// G4 : 유향 그래프
	GraphType	G4 = GraphType(3);

	// 정점(A)
	G4.insertEdge(0, 1, 0);	// A(0) - B(1)
	G4.insertEdge(0, 2, 0);	// A(0) - C(2)

	// 정점(B)
	G4.insertEdge(1, 0, 0);	// B(1) - A(0)
	G4.insertEdge(1, 2, 0);	// B(1) - C(2)

	cout << "\n##### 그래프(G4): 인접 행렬 #####" << endl;
	G4.printAdjList();

	return 0;
}
