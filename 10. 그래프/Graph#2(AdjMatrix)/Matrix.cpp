/*
	�׷��� ǥ��(���� ���): �˰��� ����
		���ϸ�: GraphAdjMatrix.cpp
			- main	: �׷��� ���� �� ���� �߰�
			Ŭ����	: GraphType
				- �׷��� ����.����: GraphType, ~GraphType
				- �׷��� ���� �߰�: insertEdge
				- �׷��� ��ü ���: printAdjMatrix
*/

#include <iostream>
using namespace std;

// GraphType class
class GraphType {
private:
	int	__vertex;	// ������ ����
	int** __adjMatrix;	// ���� ���
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	printAdjMatrix(void) const;
};

// ������: �׷��� ����
GraphType::GraphType(int vertex) : __vertex(vertex) {
	// ���� ���: 2���� �迭 ���� �޸� �Ҵ�
	__adjMatrix = new int* [vertex + 1];
	for (int i = 0; i < vertex; i++) {
		__adjMatrix[i] = new int[vertex];
		memset(__adjMatrix[i], 0, sizeof(int) * vertex);
	}
	__adjMatrix[vertex] = nullptr;
}

// �Ҹ���: �׷��� ����
GraphType::~GraphType(void) {
	for (int i = 0; i < __vertex; i++)
		delete[] __adjMatrix[i];
	delete[] __adjMatrix;
	__vertex = 0;
}

// �׷��� ���� �߰�
void  GraphType::insertEdge(int  row, int  col, int weight = 1) {
	if (row >= __vertex || col >= __vertex) {
		// cout << "�׷����� ���� �����Դϴ�!!!" << endl;
		return;
	}
	__adjMatrix[row][col] = weight;
}

// �׷��� ��ü ���
void  GraphType::printAdjMatrix(void) const {
	for (int i = 0; i < __vertex; i++) {
		cout << "\n\t";
		for (int j = 0; j < __vertex; j++) {
			cout.width(3);
			cout << __adjMatrix[i][j];
		}
	}
	cout << endl;
}

int main(void)
{
	// G2 : ���� �׷���
	GraphType	G2 = GraphType(3);

	// ����: A(0)
	G2.insertEdge(0, 1, 1);	// A(0) - B(1)
	G2.insertEdge(0, 2, 1);	// A(0) - C(2)

	// ����: B(1)
	G2.insertEdge(1, 0, 1);	// B(1) - A(0)
	G2.insertEdge(1, 2, 1);	// B(1) - C(2)

	// ����: C(2)
	G2.insertEdge(2, 1, 1);	// C(2) - B(1)
	G2.insertEdge(2, 0, 1);	// C(2) - A(0)

	cout << "\n##### �׷���(G2): ���� ��� #####" << endl;
	G2.printAdjMatrix();

	// G4 : ���� �׷���
	GraphType	G4 = GraphType(3);

	// ����(A)
	G4.insertEdge(0, 1, 1);	// A(0) - B(1)
	G4.insertEdge(0, 2, 1);	// A(0) - C(2)

	// ����(B)
	G4.insertEdge(1, 0, 1);	// B(1) - A(0)
	G4.insertEdge(1, 2, 1);	// B(1) - C(2)

	cout << "\n##### �׷���(G4): ���� ��� #####" << endl;
	G4.printAdjMatrix();

	return 0;
}