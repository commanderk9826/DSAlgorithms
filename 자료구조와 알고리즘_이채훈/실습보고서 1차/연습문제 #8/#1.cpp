#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, const string& gender, const string& tel, const string& addr)
        : name(name), gender(gender), tel(tel), addr(addr) {}

    void showPerson() const {
        cout << "��  ��: " << name << endl;
        cout << "��  ��: " << gender << endl;
        cout << "����ó: " << tel << endl;
        cout << "��  ��: " << addr << endl;
       
    }

private:
    string name;
    string gender;
    string tel;
    string addr;
};

class Student : public Person {//Person Ŭ������ ��ӹ��� Student Ŭ���� ����
public:
    Student(const string& name, const string& gender, const string& tel, const string& addr, int kor, int eng, int math)
        : Person(name, gender, tel, addr), kor(kor), eng(eng), math(math) {
        calculateT_A();
    }

    void showStudent() const {
            Person::showPerson();//Person Ŭ������ showPerson�Լ� ����
            cout << "��  ��: " << kor << endl;
            cout << "��  ��: " << eng << endl;
            cout << "��  ��: " << math << endl;
            cout << "��  ��: " << tot << endl;
            cout << "��  ��: " << ave << endl;
    }

private:
    int kor;
    int eng;
    int math;
    int tot;
    double ave;

    void calculateT_A() {
        tot = kor + eng + math;
        ave = static_cast<double>(tot) / 3.0;
    }//����, ��� ����ϴ� �Լ�
};

int main() {
    string personName, personGender, personTel, personAddr;
    int kor, eng, math;

    cout << "20215229 ��ä��" << endl;
    cout << endl;

    cout << "�л��� ������ ������ �Է��ϼ���..." << endl;
    cout << endl;
    cout << "��  ��: "; cin >> personName; 
    cout << "��  ��: "; cin >> personGender;
    cout << "����ó: "; cin >> personTel; 
    cout << "��  ��: "; getline(cin >> ws, personAddr);//���� �Է��� ���� getline()�Լ�
    cout << "��  ��: "; cin >> kor; 
    cout << "��  ��: "; cin >> eng; 
    cout << "��  ��: "; cin >> math;
    cout << endl;

   
    Student student(personName, personGender, personTel, personAddr, kor, eng, math);
    //�Է°��� ���� ��ü ����

    cout << " ### �Է� ���� ###" << endl;
    cout << endl;
    student.showStudent();

    return 0;
}
