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
        cout << "이  름: " << getName() << endl;
        cout << "계좌번호: " << getAccount() << endl;
        cout << "패스워드: " << getPass() << endl;
        cout << "현재잔액: " << getBalance() << endl;
    };//계좌관련 정보 출력하는 함수
};

int main(void) {
    cout << "20215229 이채훈" << endl;
    cout << endl;
    Account AC("홍길동", "111-2222-3333", "12345", 100000);
    //임의 객체 생성(과제물의 실행결과와 동일하게 설정함)

    AC.showAccount();
    cout << endl;

    string inAccount, inPass;
    int amount, lbalance;
    cout << "##### 은행 계좌 인증 #####" << endl;
    cout << "계좌번호 입력: "; cin >> inAccount;
    cout << "비밀번호 입력: "; cin >> inPass;

    try
    {
        if (inAccount != AC.getAccount() || inPass != AC.getPass())
        {
            throw 1;//int throw
        }
        else
        {
            cout << "출금액 입력: "; cin >> amount;

            if (amount > AC.getBalance())
            {
                cout << "현재 잔액: " << AC.getBalance() << endl;
                throw 'e';
                //char throw
                return 0;
            }
            else
            {
                lbalance = AC.getBalance() - amount;
                cout << "현재 잔액: " << lbalance << endl;
                cout << AC.getName() << "님의 현재 잔액은: " << lbalance << "입니다." << endl;
            }
            return 0;
        }
    }

    catch (int exception)
    {
        cout << "\n다음 입력을 다시 한 번 확인하세요!!!" << endl;
        Account AC("", inAccount, inPass, 0);
        //입력받은 계좌번호와 비밀번호로 객체 생성
        
        AC.showAccount();
        return 0;
    }
    //계좌번호와 비밀번호가 다를 경우의 예외처리

    catch (char exception)
    {
        cout << "희망 출금액: (" << amount << ")이 너무 많네요." << endl;
        return 0;
    }
    //희망출금액이 잔액보다 적을 경우의 예외처리
}


 
   










