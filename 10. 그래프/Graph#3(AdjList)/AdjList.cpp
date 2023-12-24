/*
	�׷��� ǥ��(���� ����Ʈ): �˰��� ����
		���ϸ�: AdjList.cpp
			- main	: �׷��� ���� �� ���� �߰�
			Ŭ����	: GraphType
				- �׷��� ����.����: GraphType, ~GraphType
				- �׷��� ���� �߰�: insertEdge
				- �׷��� ��ü ���: printAdjList
*/

#include <iostream>
using namespace std;

//GNode class
class GNode {
private:
	int __vertex;//����
	int __weight;//����ġ
	GNode* __link;
	friend class GraphType;
public:
	GNode(int vertex, int weight);
};

//�׷��� ���(C): �׷��� ��� ����
GNode::GNode(int vertex, int weight)
	:__vertex(vertex), __weight(weight), __link(nullptr){}

// GraphType class
class GraphType {
private:
	int	__vertex;	// ������ ����
	GNode** __adjSList;	// ���� ����Ʈ
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	printAdjList(void) const;
};

//������(�Ҹ���)�� �޼ҵ� ����
GraphType::GraphType(int vertex) : __vertex(vertex) {
	// ���� ���: 2���� �迭 ���� �޸� �Ҵ�
	__adjSList=new GNode*[vertex + 1];
	memset(__adjSList, 0, sizeof(GNode*) * (vertex + 1));
}

//graphDestroy: �׷��� ����
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

//insertEdge: �׷��� ���� �߰�
void  GraphType::insertEdge(int  row, int  col, int weight = 1) {
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

//printAdjList: �׷��� ��ü ���
void  GraphType::printAdjList(void) const {
	char ch;
	for (int i = 0; i < __vertex; i++) {
		ch = i + 65;
		cout << "\t���� " << ch << "�� ���� ����Ʈ";
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
	// G2 : ���� �׷���
	GraphType	G2 = GraphType(3);

	// ����: A(0)
	G2.insertEdge(0, 1, 0);	// A(0) - B(1)
	G2.insertEdge(0, 2, 0);	// A(0) - C(2)

	// ����: B(1)
	G2.insertEdge(1, 0, 0);	// B(1) - A(0)
	G2.insertEdge(1, 2, 0);	// B(1) - C(2)

	// ����: C(2)
	G2.insertEdge(2, 1, 0);	// C(2) - B(1)
	G2.insertEdge(2, 0, 0);	// C(2) - A(0)

	cout << "\n##### �׷���(G2): ���� ��� #####" << endl;
	G2.printAdjList();

	// G4 : ���� �׷���
	GraphType	G4 = GraphType(3);

	// ����(A)
	G4.insertEdge(0, 1, 0);	// A(0) - B(1)
	G4.insertEdge(0, 2, 0);	// A(0) - C(2)

	// ����(B)
	G4.insertEdge(1, 0, 0);	// B(1) - A(0)
	G4.insertEdge(1, 2, 0);	// B(1) - C(2)

	cout << "\n##### �׷���(G4): ���� ��� #####" << endl;
	G4.printAdjList();

	return 0;
}
