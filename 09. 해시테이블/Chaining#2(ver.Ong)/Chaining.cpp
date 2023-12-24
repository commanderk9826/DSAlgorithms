#include <iostream>
#include <vector>
#include <list>
using namespace std;

// HashChaining class 
template <typename E>
class HashChaining {
public:
    HashChaining(int num);
    int insert(int num);
    int remove(int num);
    int search(int num);
    void output(void);
private:
    vector<list<E>> __table;  // 각 슬롯에 대한 연결 리스트
    int __count;
    const int DELETED = -54321;
    int __Hash(int num);  // 해시 함수
};

template <typename E>
HashChaining<E>::HashChaining(int num) : __count(0) {
    __table = vector<list<E>>(num);
}

// 데이터 삽입
template <typename E>
int HashChaining<E>::insert(int num) {
    int slot = __Hash(num);
    __table[slot].push_back(num);
    __count++;
    return num;
}

// 데이터 삭제
template <typename E>
int HashChaining<E>::remove(int num) {
    int slot = __Hash(num);
    auto& chain = __table[slot];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (*it == num) {
            chain.erase(it);
            __count--;
            return num;
        }
    }
    return 0;
}

// 데이터 검색
template <typename E>
int HashChaining<E>::search(int num) {
    int slot = __Hash(num);
    for (auto& item : __table[slot]) {
        if (item == num) {
            return item;
        }
    }
    return 0;
}

// 전체 원소 출력
template <typename E>
void HashChaining<E>::output(void) {
    cout << "count(" << __count << "): " << endl;
    for (int i = 0; i < __table.size(); i++) {
        cout << i << ": ";
        if (__table[i].empty()) {
            cout << "EMPTY";
        }
        else {
            for (auto& item : __table[i]) {
                cout << item << " ";
            }
        }
        cout << endl;
    }
}

// 해시 함수(선형 조사)
template <typename E>
int HashChaining<E>::__Hash(int num) {
    return num % __table.size();
}

int main(void) {
    HashChaining<int> h(13);

    while (true) {
        cout << "\n ### 해시 테이블 ###" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "메뉴 선택: ";
        int choice;
        cin >> choice;

        int num;
        if (choice == 1) {
            cout << "삽입 할 데이터 입력: ";
            cin >> num;
            int inserted = h.insert(num);
            cout << "삽입 된 데이터: " << inserted << endl;
        }
        else if (choice == 2) {
            cout << "삭제 할 데이터 입력: ";
            cin >> num;
            int removed = h.remove(num);
            cout << "삭제 된 데이터: " << removed << endl;
        }
        else if (choice == 3) {
            cout << "검색 할 데이터 입력: ";
            cin >> num;
            int searched = h.search(num);
            if (searched != 0)
                cout << "검색된 데이터: " << searched << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;
        }
        else if (choice == 4)   h.output();
        else if (choice == 5) {
            cout << "프로그램 종료!!!" << endl;
            break;
        }
        else {
            cout << "잘못 선택 하셨습니다." << endl;
            break;
        }
    }
    return 0;
}