/*
    ���� Ž�� Ʈ��(AVL Ʈ��): �˰��� ����
        ���ϸ�: AVLTree.cpp
        Ŭ����: AVLNode
        Ŭ����: AVLTree
            - ������.�Ҹ���		: AVLTree, ~AVLTree
            - ������ ����.����.�˻�	: insert, remove, search
            - ���� ���߱�    		: balance, leftRotate, rightRotate
            - ���� �켱 ��ȸ		: Preorder, Inorder, Postorder
*/

#pragma once
#include <iostream>
#include <algorithm>    // max
using namespace std;

// class AVLNode
class AVLNode {
    int         __data;
    AVLNode* __Llink;
    AVLNode* __Rlink;
    int         __height;
    friend class AVLTree;
public:
    AVLNode(const int& data);
    int     getData(void) const;
    int     getHeight(void) const;
};

// AVLNode: �����ڿ� �޼ҵ�
AVLNode::AVLNode(const int& data) :
    __data(data), __height(1), __Llink(nullptr), __Rlink(nullptr) {}
int     AVLNode::getData(void) const { return __data; }
int     AVLNode::getHeight(void) const { return __height; }

// class AVLTree
class AVLTree {
private:
    AVLNode* __root;
public:
    AVLTree();
    ~AVLTree();
    AVLNode* getRoot(void) const;
    int         getHeight(AVLNode* tNode) const;
    AVLNode* search(const int& data) const;
    void        insert(const int& data);
    void        remove(const int& data);
    AVLNode* transPlant(AVLNode*& root);
    AVLNode* balance(AVLNode* root);
    AVLNode* leftRotate(AVLNode* root);
    AVLNode* rightRotate(AVLNode* root);
    void        Preorder(AVLNode* root) const;
    void        Inorder(AVLNode* root) const;
    void        Postorder(AVLNode* root) const;
};

// AVLTree: �����ڿ� �޼ҵ�
AVLTree::AVLTree() : __root(nullptr) {}
AVLTree::~AVLTree() {}
AVLNode* AVLTree::getRoot(void) const { return __root; }
int AVLTree::getHeight(AVLNode* tNode) const {
    if (tNode == nullptr)
        return 0;
    return tNode->__height;
}

// ������ �˻�
AVLNode* AVLTree::search(const int& data) const {
    AVLNode* tNode = __root;
    while (tNode) {
        if (tNode->__data == data)      return tNode;
        else if (tNode->__data > data)  tNode = tNode->__Llink;
        else                            tNode = tNode->__Rlink;
    }
    return nullptr;
}

// ������ ����
void    AVLTree::insert(const int& data) {
    if (__root == nullptr) {
        __root = new AVLNode(data);
        return;
    }
    else if (__root->__data == data)
        return;

    // ������ ����� �θ� ��� �˻�
    AVLNode* parent = nullptr;
    AVLNode* tNode = __root;
    while (tNode) {
        parent = tNode;
        if (data < parent->__data)  tNode = tNode->__Llink;
        else                        tNode = tNode->__Rlink;
    }
    // ���ο� ��� ���� �� ����
    if (data < parent->__data)      parent->__Llink = new AVLNode(data);
    else if (data > parent->__data) parent->__Rlink = new AVLNode(data);

    // AVLTree: ����(__height)
    parent->__height = 1 + max(getHeight(parent->__Llink), getHeight(parent->__Rlink));
    parent = balance(parent);    // ���� ���߱�
}

// ������ ����
void    AVLTree::remove(const int& data) {
    if (__root == nullptr) {
        return;
    }

    // ������ ����� ��ġ Ž��
    AVLNode* parent = nullptr, * child = nullptr;
    AVLNode* tNode = __root;
    while (tNode->__data != data) {
        parent = tNode;
        if (data < tNode->__data)   tNode = tNode->__Llink;
        else                        tNode = tNode->__Rlink;
    }

    // 1) ������ ��尡 �ܸ� ����� ���
    if ((tNode->__Llink == nullptr) && (tNode->__Rlink == nullptr)) {
        if (parent == nullptr) {
            __root->__height = 0;
            __root = nullptr;
        }
        else {
            if (parent->__Llink == tNode)   parent->__Llink = nullptr;
            else                            parent->__Rlink = nullptr;
            // AVLTree: ����(__height)
            parent->__height = 1 + max(getHeight(parent->__Llink), getHeight(parent->__Rlink));
            parent = balance(parent);    // ���� ���߱�
        }
    }
    // 2) ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else if ((tNode->__Llink == nullptr) || (tNode->__Rlink == nullptr)) {
        if (tNode->__Llink)  child = tNode->__Llink;
        else                child = tNode->__Rlink;
        if (parent == nullptr)  __root = child;
        else {
            if (parent->__Llink == tNode)	parent->__Llink = child;
            else                            parent->__Rlink = child;
            // AVLTree: ����(__height)
            parent->__height = 1 + max(getHeight(parent->__Llink), getHeight(parent->__Rlink));
            parent = balance(parent);    // ���� ���߱�
        }
    }
    // 3) ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else {
        // ���� ���� Ʈ������ �İ��� ã��
        AVLNode* succParent = tNode;
        AVLNode* succ = tNode->__Llink;
        while (succ->__Rlink != nullptr) {
            succParent = succ;
            succ = succ->__Rlink;
        }

        if (succParent->__Llink == succ)
            succParent->__Llink = succ->__Llink;
        else
            succParent->__Rlink = succ->__Llink;
        tNode->__data = succ->__data;
        tNode = succ;

        // AVLTree: ����(__height)
        succParent->__height = 1 + max(getHeight(succParent->__Llink), getHeight(succParent->__Rlink));
        succParent = balance(succParent);    // ���� ���߱�
    }
    delete tNode;
}

AVLNode* AVLTree::transPlant(AVLNode*& root) {
    AVLNode* parent = root;
    AVLNode* RChild = root->__Rlink;

    if (root->__Llink == nullptr)           root = root->__Rlink;
    else if (root->__Rlink == nullptr)      root = root->__Llink;
    else {
        // ������ ���� Ʈ������ ���� ���� ��
        while (RChild->__Llink != nullptr) {
            parent = RChild;
            RChild = RChild->__Llink;
        }
        // root <-- RChild
        root->__data = RChild->__data;
        if (parent == root) root->__Rlink = RChild->__Rlink;
        else                parent->__Llink = RChild->__Rlink;
        root = RChild;
    }
    delete RChild;
    return root;
}

// ���� ���߱�: LL, LR, RR, RL ����
AVLNode* AVLTree::balance(AVLNode* root) {
    if (getHeight(root->__Llink) >= getHeight(root->__Rlink) + 2) {                      // L ����
        if (getHeight(root->__Llink->__Rlink) > getHeight(root->__Llink->__Llink) + 2)
            root->__Llink = leftRotate(root->__Llink);                                  // LR ����
        root = rightRotate(root);                                                       // L ����: LL, LR
    }
    else if (getHeight(root->__Rlink) >= getHeight(root->__Llink) + 2) {                // R ����
        if (getHeight(root->__Rlink->__Llink) > getHeight(root->__Rlink->__Rlink) + 2)
            root->__Rlink = rightRotate(root->__Rlink);                                 // RL ����
        root = leftRotate(root);                                                        // R ����: RR, RL
    }
    return root;
}

// ����(left) ȸ��
AVLNode* AVLTree::leftRotate(AVLNode* root) {
    AVLNode* RChild = root->__Rlink;
    root->__Rlink = RChild->__Llink;
    RChild->__Llink = root;

    // ���� ������: root, RChild
    root->__height = max(getHeight(root->__Llink), getHeight(root->__Rlink)) + 1;
    RChild->__height = max(getHeight(RChild->__Llink), getHeight(RChild->__Rlink)) + 1;
    return RChild;  // root --> RChild
}

// ������(right) ȸ��
AVLNode* AVLTree::rightRotate(AVLNode* root) {
    AVLNode* LChild = root->__Llink;
    root->__Llink = LChild->__Rlink;
    LChild->__Rlink = root;

    // ���� ������: root, LChild
    root->__height = max(root->__Llink->__height, root->__Rlink->__height) + 1;
    LChild->__height = max(LChild->__Llink->__height, LChild->__Rlink->__height) + 1;
    return LChild;  // root --> LChild
}

// ���� �켱 ��ȸ: ���� ��ȸ
void AVLTree::Preorder(AVLNode* root) const {
    if (root == nullptr)
        return;
    cout << root->__data << " ";
    Preorder(root->__Llink);
    Preorder(root->__Rlink);
}

// ���� �켱 ��ȸ: ���� ��ȸ
void AVLTree::Inorder(AVLNode* root) const {
    if (root == nullptr)
        return;
    Inorder(root->__Llink);
    cout << root->__data << " ";
    Inorder(root->__Rlink);
}

// ���� �켱 ��ȸ: ���� ��ȸ
void AVLTree::Postorder(AVLNode* root) const {
    if (root == nullptr)
        return;
    Postorder(root->__Llink);
    Postorder(root->__Rlink);
    cout << root->__data << " ";
}
