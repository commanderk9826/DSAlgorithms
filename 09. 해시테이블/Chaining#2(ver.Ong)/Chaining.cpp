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
    vector<list<E>> __table;  // �� ���Կ� ���� ���� ����Ʈ
    int __count;
    const int DELETED = -54321;
    int __Hash(int num);  // �ؽ� �Լ�
};

template <typename E>
HashChaining<E>::HashChaining(int num) : __count(0) {
    __table = vector<list<E>>(num);
}

// ������ ����
template <typename E>
int HashChaining<E>::insert(int num) {
    int slot = __Hash(num);
    __table[slot].push_back(num);
    __count++;
    return num;
}

// ������ ����
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

// ������ �˻�
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

// ��ü ���� ���
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

// �ؽ� �Լ�(���� ����)
template <typename E>
int HashChaining<E>::__Hash(int num) {
    return num % __table.size();
}

int main(void) {
    HashChaining<int> h(13);

    while (true) {
        cout << "\n ### �ؽ� ���̺� ###" << endl;
        cout << "1) ������ ����" << endl;
        cout << "2) ������ ����" << endl;
        cout << "3) ������ �˻�" << endl;
        cout << "4) ��ü ���" << endl;
        cout << "5) ���α׷� ����" << endl;
        cout << "�޴� ����: ";
        int choice;
        cin >> choice;

        int num;
        if (choice == 1) {
            cout << "���� �� ������ �Է�: ";
            cin >> num;
            int inserted = h.insert(num);
            cout << "���� �� ������: " << inserted << endl;
        }
        else if (choice == 2) {
            cout << "���� �� ������ �Է�: ";
            cin >> num;
            int removed = h.remove(num);
            cout << "���� �� ������: " << removed << endl;
        }
        else if (choice == 3) {
            cout << "�˻� �� ������ �Է�: ";
            cin >> num;
            int searched = h.search(num);
            if (searched != 0)
                cout << "�˻��� ������: " << searched << endl;
            else
                cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
        }
        else if (choice == 4)   h.output();
        else if (choice == 5) {
            cout << "���α׷� ����!!!" << endl;
            break;
        }
        else {
            cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
            break;
        }
    }
    return 0;
}