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
    int __Hash(int i, int num);  // ù ��° �ؽ� �Լ�
    int __Hash2(int num);       // �� ��° �ؽ� �Լ� (���� �ؽ̿� ���)
};

template <typename E>
HashOpenAddressing<E>::HashOpenAddressing(int num) : __count(0) {
    __table = vector<int>(num, NULL);
}

// ������ ����
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

// ������ ����
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

// ������ �˻�
template <typename E>
int HashOpenAddressing<E>::search(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = (__Hash(i, num) + i * __Hash2(num)) % __table.size();
        if (__table[slot] == NULL) return 0;
        else if (__table[slot] == num) return __table[slot];
    }
    return 0;
}

// ��ü ���� ���
template <typename E>
void HashOpenAddressing<E>::output(void) {
    cout << "count(" << __count << "): ";
    for (int i = 0; i < __table.size(); i++) {
        if (__table[i] == DELETED) cout << ' ' << "DELETED";
        else cout << ' ' << __table[i];
    }
    cout << endl;
}

// ù ��° �ؽ� �Լ� (���� ����)
template <typename E>
int HashOpenAddressing<E>::__Hash(int i, int num) {
    return (num + i) % __table.size();
}

// �� ��° �ؽ� �Լ� (���� �ؽ�)
template <typename E>
int HashOpenAddressing<E>::__Hash2(int num) {
    return 7 - (num % 7); // ���÷� 7�� ���� �������� ���
}

int main(void) {
    HashOpenAddressing<int> h(4);

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
            if (inserted != 0)
                cout << "���� �� ������: " << inserted << std::endl;
            else
                cout << "������ ���Կ� �����Ͽ����ϴ�." << std::endl;
        }
        else if (choice == 2) {
            cout << "���� �� ������ �Է�: ";
            cin >> num;
            int removed = h.remove(num);
            if (removed != 0)
                cout << "���� �� ������: " << removed << endl;
            else
                cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
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
        else cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
    }
    return 0;
}