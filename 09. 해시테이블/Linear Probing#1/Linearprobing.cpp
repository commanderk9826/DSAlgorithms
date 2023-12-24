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
    int __Hash(int i, int num) {    // �ؽ� �Լ�
        return (num + i) % __table.size();       // ���� ����
        //return (num + i*i) % __table.size();     // ���� ����
    }
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
            int slot = __Hash(i, num);
            if (__table[slot] == NULL || __table[slot] == DELETED) {
                __table[slot] = num;
                __count++;
                return num;
            }
        }
    }
    return NULL;
}

// ������ ����
template <typename E>
int HashOpenAddressing<E>::remove(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = __Hash(i, num);
        if (__table[slot] == NULL)
            return NULL;
        else if (__table[slot] == num) {
            __table[slot] = DELETED;
            __count--;
            return num;
        }
    }
    return NULL;
}

// ������ �˻�
template <typename E>
int HashOpenAddressing<E>::search(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = __Hash(i, num);
        if (__table[slot] == NULL)      return NULL;
        else if (__table[slot] == num)  return __table[slot];
    }
    return NULL;
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

int main(void) {
    HashOpenAddressing<int>   h(13);

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
            if (inserted != NULL)
                cout << "���� �� ������: " << inserted << std::endl;
            else
                cout << "������ ���Կ� �����Ͽ����ϴ�." << std::endl;
        }
        else if (choice == 2) {
            cout << "���� �� ������ �Է�: ";
            cin >> num;
            int removed = h.remove(num);
            if (removed != NULL)
                cout << "���� �� ������: " << removed << endl;
            else
                cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
        }
        else if (choice == 3) {
            cout << "�˻� �� ������ �Է�: ";
            cin >> num;
            int searched = h.search(num);
            if (searched != NULL)
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