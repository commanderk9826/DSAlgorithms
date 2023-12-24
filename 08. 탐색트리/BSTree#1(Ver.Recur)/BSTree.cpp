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

// DNode: ��� �Լ� ����
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

// LinkedBSTree: ��� �Լ� ����
template <typename E>
LinkedBSTree<E>::LinkedBSTree() :
    __root(nullptr) {}

// �Ҹ���: ��� ��� ����
// �ʺ� �켱 ��ȸ: ť ���� Ȱ��
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

// ���� �켱 ��ȸ: ���� ��ȸ(����� ���)
template <typename E>
void   LinkedBSTree<E>::Preorder(DNode<E>* root) const {
    if (root) {
        cout.width(3);    cout << root->__data;
        Preorder(root->__Llink);
        Preorder(root->__Rlink);
    }
}

// ���� �˻� Ʈ��(BST): ������ �˻� -- ����� ���
template <typename E>
DNode<E>* LinkedBSTree<E>::searchBST(DNode<E>* root, const E& data) const {
    if (root == nullptr || data == root->__data)
        return root;

    DNode<E>* tNode = nullptr;
    if (data < root->__data)      tNode = searchBST(root->__Llink, data);
    else if (data > root->__data)   tNode = searchBST(root->__Rlink, data);
    return tNode;
}

// ���� �˻� Ʈ��(BST): ������ ���� -- ����� ���
template <typename E>
DNode<E>* LinkedBSTree<E>::insertBST(DNode<E>* root, const E& data) const {
    // Ž�� ����: ���ο� ��� ����
    DNode<E>* newNode = nullptr;
    if (root == nullptr) {
        newNode = new DNode<E>(data);
        return newNode;
    }

    // �ߺ��� �����Ͱ� ������ ��� ������ ���� �Ұ���!!!
    if (data == root->__data) cout << "�̹� ���� Ű�� �ֽ��ϴ�!!!" << endl;
    else if (data < root->__data)   root->__Llink = insertBST(root->__Llink, data);
    else if (data > root->__data)   root->__Rlink = insertBST(root->__Rlink, data);

    return root;
}

// ���� �˻� Ʈ��(BST): ������ ���� -- ������� ���
template <typename E>
DNode<E>* LinkedBSTree<E>::deleteBST(DNode<E>* root, const E& data) const {
    // ������ ��尡 ���� ���
    if (root == nullptr) {
        cout << "\nŰ�� ã�� ���߽��ϴ�." << endl;
        return root;
    }

    DNode<E>* pParent = nullptr;   // ������ ����� �θ� ���
    DNode<E>* tNode = root;   // ������ ���
    DNode<E>* pChild;      // ������ ����� �ڽ� ���

    // ������ ����� ��ġ Ž��
    while (data != tNode->__data) {
        pParent = tNode;
        if (data < tNode->__data) tNode = tNode->__Llink;
        else tNode = tNode->__Rlink;
    }

    // 1) ������ ��尡 �ܸ� ����� ���
    if ((tNode->__Llink == nullptr) && (tNode->__Rlink == nullptr)) {
        if (pParent == nullptr)   root = nullptr;
        else if (pParent != nullptr) {
            if (pParent->__Llink == tNode)   pParent->__Llink = nullptr;
            else            pParent->__Rlink = nullptr;
        }
    }
    // 2) ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else if ((tNode->__Llink == nullptr) || (tNode->__Rlink == nullptr)) {
        // pChild : (�İ���) ������ ����� �ڽ� ���
        if (tNode->__Llink != nullptr)   pChild = tNode->__Llink;
        else         pChild = tNode->__Rlink;

        if (pParent == nullptr)   root = pChild;
        else {
            if (pParent->__Llink == tNode)   pParent->__Llink = pChild;
            else            pParent->__Rlink = pChild;
        }
    }
    // 3) ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else {
        // ���� ���� Ʈ������ �İ���(�ִ�) ã��
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

// ��ü ���� ���, ������ �˻�, ����, ����
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
        cout << "\n ##### ���� �˻� Ʈ�� ##### \n" << endl;
        cout << "1) ������ ����" << endl;
        cout << "2) ������ ����" << endl;
        cout << "3) ������ �˻�" << endl;
        cout << "4) ��ü ���� ���" << endl;
        cout << "5) ���α׷� ����" << endl;
        cout << "\n�޴� ����: ";
        cin >> num;

        switch (num) {
        case 1: InsertBST(bst);       break;
        case 2: DeleteBST(bst);       break;
        case 3: SearchBST(bst);       break;
        case 4: printBSTAll(bst);   break;
        case 5: cout << "���α׷� ����!!!\n" << endl;
            return 0;
        default: cout << "�޴��� �߸� �����ϼ̽��ϴ�." << endl;
        }
        system("pause");
    }
    return 0;
}

// ���� �˻� Ʈ��(BST): ��ü ��� ���(���� ��ȸ)
template <typename E>
void    printBSTAll(LinkedBSTree<E>& bst) {
    cout << "\n���� �˻� Ʈ��: ��ü ���� ���" << endl;
    bst.Preorder(bst.getRoot());
    cout << "\n" << endl;
}

// ���� �˻� Ʈ��(BST): ������ �˻�
template <typename E>
void   SearchBST(LinkedBSTree<E>& bst) {
    int          num;
    DNode<E>* tNode = nullptr;

    cout << "\n���� �˻� Ʈ��: ������ �˻�" << endl;
    while (true) {
        cout << "������ ���� �Է�(����: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // ������ �˻�
        tNode = bst.searchBST(bst.getRoot(), num);
        if (tNode)   cout << tNode->getData() << " Ű�� ã�ҽ��ϴ�!!!" << endl;
        else      cout << "Ű�� ã�� ���߽��ϴ�." << endl;
    }
}

// ���� �˻� Ʈ��(BST): ������ ����
template <typename E>
void   InsertBST(LinkedBSTree<E>& bst) {
    int           num;
    DNode<E>* root = nullptr;

    cout << "\n���� �˻� Ʈ��: ������ ����" << endl;
    while (true) {
        cout << "������ ���� �Է�(����: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // ������ ����
        root = bst.insertBST(bst.getRoot(), num);
        if (root != bst.getRoot())
            bst.setRoot(root);
    }
}

// ���� �˻� Ʈ��(BST): ������ ����
template <typename E>
void   DeleteBST(LinkedBSTree<E>& bst) {
    int           num;
    DNode<E>* root = nullptr;

    cout << "\n���� �˻� Ʈ��: ������ ����" << endl;
    while (true) {
        cout << "������ ���� �Է�(����: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // ������ ����
        root = bst.deleteBST(bst.getRoot(), num);
        if (root != bst.getRoot())
            bst.setRoot(root);
    }
}