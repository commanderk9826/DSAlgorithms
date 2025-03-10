#include <iostream>
#include <queue>
#include <algorithm>    // max

using namespace std;

template <typename E>
class LinkedBSTree;

// class DNode
template <typename E>
class DNode {
public:
    DNode(const E& data);
    E           getData(void) const;
    DNode<E>* getLlink(void) const;
    DNode<E>* getRlink(void) const;
private:
    E              __data;
    DNode<E>* __Llink;
    DNode<E>* __Rlink;
    template <typename T> friend class LinkedBSTree;
};

// DNode: 멤버 함수 정의
template <typename E>
DNode<E>::DNode(const E& data) :
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

template <typename E>
E   DNode<E>::getData(void) const { return __data; }

template <typename E>
DNode<E>* DNode<E>::getLlink(void) const { return __Llink; }

template <typename E>
DNode<E>* DNode<E>::getRlink(void) const { return __Rlink; }

// class LinkedBSTree
template <typename E>
class LinkedBSTree {
public:
    LinkedBSTree();
    ~LinkedBSTree();
    DNode<E>* getRoot(void) const;
    void      setRoot(DNode<E>* root);
    DNode<E>* insertBST(DNode<E>* root, const E& data) const;
    DNode<E>* deleteBST(DNode<E>* root, const E& data) const;
    DNode<E>* searchBST(DNode<E>* root, const E& data) const;
    void      Preorder(DNode<E>* root) const;
private:
    DNode<E>* __root;
};

// LinkedBSTree: 멤버 함수 정의
template <typename E>
LinkedBSTree<E>::LinkedBSTree() :
    __root(nullptr) {}

// 소멸자: 모든 노드 삭제
// 너비 우선 순회: 큐 구조 활용
template <typename E>
LinkedBSTree<E>::~LinkedBSTree() {
    if (__root == nullptr)
        return;

    DNode<E>* tNode = nullptr;
    queue<DNode<E>*>   Q;
    Q.push(__root);
    while (!Q.empty()) {
        tNode = Q.front();
        Q.pop();
        if (tNode->__Llink) Q.push(tNode->__Llink);
        if (tNode->__Rlink) Q.push(tNode->__Rlink);
        delete tNode;
    }
}

template <typename E>
void        LinkedBSTree<E>::setRoot(DNode<E>* root) {
    __root = root;
}

template <typename E>
DNode<E>* LinkedBSTree<E>::getRoot(void) const {
    return __root;
}

// 깊이 우선 순회: 전위 순회(재귀적 용법)
template <typename E>
void   LinkedBSTree<E>::Preorder(DNode<E>* root) const {
    if (root) {
        cout.width(3);    cout << root->__data;
        Preorder(root->__Llink);
        Preorder(root->__Rlink);
    }
}

// 이진 검색 트리(BST): 데이터 검색 -- 재귀적 용법
template <typename E>
DNode<E>* LinkedBSTree<E>::searchBST(DNode<E>* root, const E& data) const {
    DNode<E>* tNode = root;
    while (tNode) {
        if (data == tNode->__data) return tNode;
        else if (data < root->__data) tNode = tNode->__Llink;
        else if (data > root->__data) tNode = tNode->__Llink;
    }
    return nullptr;
}

// 이진 검색 트리(BST): 데이터 삽입 -- 재귀적 용법
template <typename E>
DNode<E>* LinkedBSTree<E>::insertBST(DNode<E>* root, const E& data) const {
    //삽입할 노드의 부모 노드 검색
    DNode<E>* pParent = nullptr;
    DNode<E>* tNode = root;
    while (tNode) {
        pParent = tNode;
        if (data == tNode->__data) {
            cout << "이미 같은 키가 있습니다!!" << endl;
            return root;
        }
        else if (data < tNode->__data) tNode = tNode->__Llink;
        else if (data > root->__data) tNode = tNode->__Rlink;
    }

    //탐색 실패: 새로운 노드 생성
    if (pParent == nullptr) root = new DNode<int>(data);
    else if (data < pParent->__data) pParent->__Llink = new DNode<int>(data);
    else if (data > pParent->__data) pParent->__Rlink = new DNode<int>(data);

    return root;
}

// 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
template <typename E>
DNode<E>* LinkedBSTree<E>::deleteBST(DNode<E>* root, const E& data) const {
    // 삭제할 노드가 없는 경우
    if (root == nullptr) {
        cout << "\n키를 찾지 못했습니다." << endl;
        return root;
    }

    DNode<E>* pParent = nullptr;   // 삭제할 노드의 부모 노드
    DNode<E>* tNode = root;   // 삭제할 노드
    DNode<E>* pChild;      // 삭제할 노드의 자식 노드

    // 삭제할 노드의 위치 탐색
    while (data != tNode->__data) {
        pParent = tNode;
        if (data < tNode->__data) tNode = tNode->__Llink;
        else tNode = tNode->__Rlink;
    }

    // 1) 삭제할 노드가 단말 노드인 경우
    if ((tNode->__Llink == nullptr) && (tNode->__Rlink == nullptr)) {
        if (pParent == nullptr)   root = nullptr;
        else if (pParent != nullptr) {
            if (pParent->__Llink == tNode)   pParent->__Llink = nullptr;
            else            pParent->__Rlink = nullptr;
        }
    }
    // 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((tNode->__Llink == nullptr) || (tNode->__Rlink == nullptr)) {
        // pChild : (후계자) 삭제할 노드의 자식 노드
        if (tNode->__Llink != nullptr)   pChild = tNode->__Llink;
        else         pChild = tNode->__Rlink;

        if (pParent == nullptr)   root = pChild;
        else {
            if (pParent->__Llink == tNode)   pParent->__Llink = pChild;
            else            pParent->__Rlink = pChild;
        }
    }
    // 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        // 왼쪽 서브 트리에서 후계자(최댓값) 찾기
        DNode<E>* sParent = tNode;
        DNode<E>* sNode = tNode->__Llink;
        while (sNode->__Rlink != nullptr) {
            sParent = sNode;
            sNode = sNode->__Rlink;
        }

        if (sParent->__Llink == sNode)
            sParent->__Llink = sNode->__Llink;
        else
            sParent->__Rlink = sNode->__Llink;

        tNode->__data = sNode->__data;
        tNode = sNode;
    }
    delete tNode;

    return root;
}

// 전체 원소 출력, 데이터 검색, 삽입, 삭제
template <typename E>   void    printBSTAll(LinkedBSTree<E>& bst);
template <typename E>   void   SearchBST(LinkedBSTree<E>& bst);
template <typename E>   void   InsertBST(LinkedBSTree<E>& bst);
template <typename E>   void   DeleteBST(LinkedBSTree<E>& bst);

int main(void)
{
    int                  num;
    LinkedBSTree<int>    bst;

    while (true) {
        system("cls");
        cout << "\n ##### 이진 검색 트리 ##### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 원소 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> num;

        switch (num) {
        case 1: InsertBST(bst);       break;
        case 2: DeleteBST(bst);       break;
        case 3: SearchBST(bst);       break;
        case 4: printBSTAll(bst);   break;
        case 5: cout << "프로그램 종료!!!\n" << endl;
            return 0;
        default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}

// 이진 검색 트리(BST): 전체 노드 출력(전위 순회)
template <typename E>
void    printBSTAll(LinkedBSTree<E>& bst) {
    cout << "\n이진 검색 트리: 전체 원소 출력" << endl;
    bst.Preorder(bst.getRoot());
    cout << "\n" << endl;
}

// 이진 검색 트리(BST): 데이터 검색
template <typename E>
void   SearchBST(LinkedBSTree<E>& bst) {
    int          num;
    DNode<E>* tNode = nullptr;

    cout << "\n이진 검색 트리: 데이터 검색" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 검색
        tNode = bst.searchBST(bst.getRoot(), num);
        if (tNode)   cout << tNode->getData() << " 키를 찾았습니다!!!" << endl;
        else      cout << "키를 찾지 못했습니다." << endl;
    }
}

// 이진 검색 트리(BST): 데이터 삽입
template <typename E>
void   InsertBST(LinkedBSTree<E>& bst) {
    int           num;
    DNode<E>* root = nullptr;

    cout << "\n이진 검색 트리: 데이터 삽입" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삽입
        root = bst.insertBST(bst.getRoot(), num);
        if (root != bst.getRoot())
            bst.setRoot(root);
    }
}

// 이진 검색 트리(BST): 데이터 삭제
template <typename E>
void   DeleteBST(LinkedBSTree<E>& bst) {
    int           num;
    DNode<E>* root = nullptr;

    cout << "\n이진 검색 트리: 데이터 삭제" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삭제
        root = bst.deleteBST(bst.getRoot(), num);
        if (root != bst.getRoot())
            bst.setRoot(root);
    }
}