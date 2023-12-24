#pragma once
//Chaining Class
template<typename E>
class Chaining {
public:
	Chaining(int num);
	~Chaining(void);
	E insert(E num);
	E remove(E num);
	E search(E num);
	void output(void);
private:
	class SNode {
	public:
		E data;
		SNode* link;
		SNode(E data)
			: data(data), link(nullptr){}
	};
	vector<SNode*> __table;
	int __Hash(int num){//해시 함수
		return num % __table.size();
	}
};

template<typename E>
Chaining<E>::Chaining(int num)
	: __table(num, nullptr){}

template<typename E>
Chaining<E>::~Chaining(void) {
	for (auto tNode : __table) {
		while (tNode) {
			SNode* pTemp = tNode;
			tNode = tNode->link;
			delete pTemp;
		}
	}
}

//데이터 삽입
template<typename E>
E Chaining<E>::insert(E num) {
	int slot = __Hash(num);
	if (__table[slot] == nullptr)
		__table[slot] = new SNode(num);
	else {
		SNode* tNode = __table[slot];
		whiile(tNode->link)
			tNode = tNode->link;
		tNode->link = new SNode(num);
	}
	return num;
}

//데이터 삭제
template<typename E>
E Chaining<E>::remove(E num) {
	int slot = __Hash(num);
	SNode* tNode = __table[slot];
	if(tNode == nullptr)
		return NULL:

	SNode * pre = nullptr;
	while (tNode && tNode->data != num) {
		pre = tNode;
		tNode = tNode->link;
	}
	if (pre == nullptr)
		__talbe[slot] = tNode->link;
	else
		pre->link = tNode->link;

	E data = tNode->data;
	delete tNode;
	return data;
}

//데이터 검색
template<typename E>
E Chaining<E>::search(E num) {
	int slot = __Hash(num);
	SNode* tNode = __table[slot];
	while (tNode) {
		if (tNode->data == num)
			return tNode->data;
		tNode = tNode->link;
	}
	return NULL;
}

//전체 원소 출력
template<typename E>
void Chaining<E>::output(void) {
	for (int i = 0; i < __table.size(); i++) {
		cout << i << " ";
		SNode* tNode = __table[i];
		while (tNode) {
			cout << "--> " << tNode->data;
			tNode = tNode->link;
		}
		cout << endl;
	}
}