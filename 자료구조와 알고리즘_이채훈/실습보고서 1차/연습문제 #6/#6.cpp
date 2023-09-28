#include <iostream>
#include <stdexcept>

using namespace std;

class Account {
private:
    const string name; 
    const string account;
    string pass;
    int balance;

public:
    Account(string name, string account, string pass = "11111", int balance = 1)
        : name(name), account(account), pass(pass), balance(balance) {}

    string getName(void) const {
        return name;
    };

    string getAccount(void) const {
        return account;
    };

    string getPass(void) const {
        return pass;
    };

    int getBalance(void) const {
        return balance;
    };

    void showAccount(void)const {
        cout << "��  ��: " << getName() << endl;
        cout << "���¹�ȣ: " << getAccount() << endl;
        cout << "�н�����: " << getPass() << endl;
        cout << "�����ܾ�: " << getBalance() << endl;
    };//���°��� ���� ����ϴ� �Լ�
};

int main(void) {
    cout << "20215229 ��ä��" << endl;
    cout << endl;
    Account AC("ȫ�浿", "111-2222-3333", "12345", 100000);
    //���� ��ü ����(�������� �������� �����ϰ� ������)

    AC.showAccount();
    cout << endl;

    string inAccount, inPass;
    int amount, lbalance;
    cout << "##### ���� ���� ���� #####" << endl;
    cout << "���¹�ȣ �Է�: "; cin >> inAccount;
    cout << "��й�ȣ �Է�: "; cin >> inPass;

    try
    {
        if (inAccount != AC.getAccount() || inPass != AC.getPass())
        {
            throw 1;//int throw
        }
        else
        {
            cout << "��ݾ� �Է�: "; cin >> amount;

            if (amount > AC.getBalance())
            {
                cout << "���� �ܾ�: " << AC.getBalance() << endl;
                throw 'e';
                //char throw
                return 0;
            }
            else
            {
                lbalance = AC.getBalance() - amount;
                cout << "���� �ܾ�: " << lbalance << endl;
                cout << AC.getName() << "���� ���� �ܾ���: " << lbalance << "�Դϴ�." << endl;
            }
            return 0;
        }
    }

    catch (int exception)
    {
        cout << "\n���� �Է��� �ٽ� �� �� Ȯ���ϼ���!!!" << endl;
        Account AC("", inAccount, inPass, 0);
        //�Է¹��� ���¹�ȣ�� ��й�ȣ�� ��ü ����
        
        AC.showAccount();
        return 0;
    }
    //���¹�ȣ�� ��й�ȣ�� �ٸ� ����� ����ó��

    catch (char exception)
    {
        cout << "��� ��ݾ�: (" << amount << ")�� �ʹ� ���׿�." << endl;
        return 0;
    }
    //�����ݾ��� �ܾ׺��� ���� ����� ����ó��
}


 
   










