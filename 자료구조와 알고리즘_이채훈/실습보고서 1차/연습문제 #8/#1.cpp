#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, const string& gender, const string& tel, const string& addr)
        : name(name), gender(gender), tel(tel), addr(addr) {}

    void showPerson() const {
        cout << "이  름: " << name << endl;
        cout << "성  별: " << gender << endl;
        cout << "연락처: " << tel << endl;
        cout << "주  소: " << addr << endl;
       
    }

private:
    string name;
    string gender;
    string tel;
    string addr;
};

class Student : public Person {//Person 클래스를 상속받은 Student 클래스 정의
public:
    Student(const string& name, const string& gender, const string& tel, const string& addr, int kor, int eng, int math)
        : Person(name, gender, tel, addr), kor(kor), eng(eng), math(math) {
        calculateT_A();
    }

    void showStudent() const {
            Person::showPerson();//Person 클래스의 showPerson함수 선언
            cout << "국  어: " << kor << endl;
            cout << "영  어: " << eng << endl;
            cout << "수  학: " << math << endl;
            cout << "총  점: " << tot << endl;
            cout << "평  균: " << ave << endl;
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
    }//총점, 평균 계산하는 함수
};

int main() {
    string personName, personGender, personTel, personAddr;
    int kor, eng, math;

    cout << "20215229 이채훈" << endl;
    cout << endl;

    cout << "학생의 정보와 성적을 입력하세요..." << endl;
    cout << endl;
    cout << "이  름: "; cin >> personName; 
    cout << "성  별: "; cin >> personGender;
    cout << "연락처: "; cin >> personTel; 
    cout << "주  소: "; getline(cin >> ws, personAddr);//공백 입력을 위한 getline()함수
    cout << "국  어: "; cin >> kor; 
    cout << "영  어: "; cin >> eng; 
    cout << "수  학: "; cin >> math;
    cout << endl;

   
    Student student(personName, personGender, personTel, personAddr, kor, eng, math);
    //입력값을 통해 객체 생성

    cout << " ### 입력 정보 ###" << endl;
    cout << endl;
    student.showStudent();

    return 0;
}
