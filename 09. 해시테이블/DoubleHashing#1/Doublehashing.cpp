#include <iostream>
#include <vector>
using namespace std;

// HashOpenAddressed class 
template <typename E>
class HashOpenAddressing {
public:
    HashOpenAddressing(int num);
    int     insert(int num);
    int     remove(int num);
    int     search(int num);
    void    output(void);
private:
    vector<E>   __table;
    int         __count;
    const int   DELETED = -54321;
    int __Hash(int i, int num);  // 첫 번째 해시 함수
    int __Hash2(int num);       // 두 번째 해시 함수 (이중 해싱에 사용)
};

template <typename E>
HashOpenAddressing<E>::HashOpenAddressing(int num) : __count(0) {
    __table = vector<int>(num, NULL);
}

// 데이터 삽입
template <typename E>
int HashOpenAddressing<E>::insert(int num) {
    if (__count < __table.size()) {
        for (int i = 0; i < __table.size(); i++) {
            int slot = (__Hash(i, num) + i * __Hash2(num)) % __table.size();
            if (__table[slot] == NULL || __table[slot] == DELETED) {
                __table[slot] = num;
                __count++;
                return num;
            }
        }
    }
    return 0;
}

// 데이터 삭제
template <typename E>
int HashOpenAddressing<E>::remove(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = (__Hash(i, num) + i * __Hash2(num)) % __table.size();
        if (__table[slot] == NULL)
            return 0;
        else if (__table[slot] == num) {
            __table[slot] = DELETED;
            __count--;
            return num;
        }
    }
    return 0;
}

// 데이터 검색
template <typename E>
int HashOpenAddressing<E>::search(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = (__Hash(i, num) + i * __Hash2(num)) % __table.size();
        if (__table[slot] == NULL) return 0;
        else if (__table[slot] == num) return __table[slot];
    }
    return 0;
}

// 전체 원소 출력
template <typename E>
void HashOpenAddressing<E>::output(void) {
    cout << "count(" << __count << "): ";
    for (int i = 0; i < __table.size(); i++) {
        if (__table[i] == DELETED) cout << ' ' << "DELETED";
        else cout << ' ' << __table[i];
    }
    cout << endl;
}

// 첫 번째 해시 함수 (선형 조사)
template <typename E>
int HashOpenAddressing<E>::__Hash(int i, int num) {
    return (num + i) % __table.size();
}

// 두 번째 해시 함수 (이중 해싱)
template <typename E>
int HashOpenAddressing<E>::__Hash2(int num) {
    return 7 - (num % 7); // 예시로 7로 나눈 나머지를 사용
}

int main(void) {
    HashOpenAddressing<int> h(4);

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
            if (inserted != 0)
                cout << "삽입 된 데이터: " << inserted << std::endl;
            else
                cout << "데이터 삽입에 실패하였습니다." << std::endl;
        }
        else if (choice == 2) {
            cout << "삭제 할 데이터 입력: ";
            cin >> num;
            int removed = h.remove(num);
            if (removed != 0)
                cout << "삭제 된 데이터: " << removed << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;
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
        else cout << "잘못 선택 하셨습니다." << endl;
    }
    return 0;
}