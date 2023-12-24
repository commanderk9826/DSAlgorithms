#pragma once
#include <iostream>
#include <queue>
using namespace std;

class DNode {
public:
    int     __data;
    DNode* __Llink;
    DNode* __Rlink;
    DNode(const int& data);
};

// 새로운 노드(data, link) 생성
DNode::DNode(const int& data) :
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

class BinarySearchTree {
private:
    DNode* __root;
    DNode* __search(DNode* root, const int& data) {
    }

    void __insert(DNode* root, const int& data) {
    }
public:
    DNode* getRoot(void) const { return __root; }
    DNode* search(const int& data);
    void    insert(const int& data);
    void    remove(const int& data);
    void    printBSTAll(DNode* root) const;
};

// 전체 노드 출력 -- 중위 순회
void BinarySearchTree::printBSTAll(DNode* root) const {
    if (root) {
        printBSTAll(root->__Llink);
        cout << root->__data << " ";
        printBSTAll(root->__Rlink);
    }
}

// 데이터 검색
DNode* BinarySearchTree::search(const int& data) {
}

// 데이터 삽입
void BinarySearchTree::insert(const int& data) {
}

// 데이터 삭제
void    BinarySearchTree::remove(const int& data) {
}