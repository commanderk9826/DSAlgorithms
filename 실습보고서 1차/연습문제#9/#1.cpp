#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const string& name, int age)
        : name(name), age(age) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }


    void printPerson(){
        cout << "이름: " << name << ", 나이: " << age << endl;
    }

private:
    string name;
    int age;
};

class Student : private Person {
// Person 클래스를 상속 받은 Student 클래스 정의
public:
    Student(const string& name, int age, int admissionYear, int graduationYear)
        : Person(name, age), admissionYear(admissionYear), graduationYear(graduationYear){}
    
    int getad() const {
        return admissionYear;
    }
    int getgY() const {
        return graduationYear;
    }

    void printStudent(){
        cout << "이름: " << getName() << ", 나이: " << getAge() << endl;
        cout << "입학 년도: " << getad() << endl;
        cout << "졸업 년도: " << getgY() << endl;
    }

private:
    int admissionYear;
    int graduationYear;
};

class Worker : private Person {
// Person 클래스를 상속 받은 Worker 클래스 정의
public:
    Worker(const string& name, int age, int workingTime)
        : Person(name, age), workingTime(workingTime) {}

    int getwT() const {
        return workingTime;
    }

    void printWorker() {
        printPerson();
        cout << "작업 시간: " << getwT() << endl;
    }

private:
    int workingTime;
};

class Albamon : private Student, private Worker {
// Person 클래스를 상속 받은 Worker, Student클래스를 상속받은 Albamon 클래스 정의
public:
    Albamon(const string& name, int age, int admissionYear, int graduationYear, int workingTime)
        : Student(name, age, admissionYear, graduationYear), Worker(name, age, workingTime) {}

    void printAlbamon(){
        printStudent();
        cout << "작업 시간: " << getwT() << endl;
    }

};

int main() {
    Person aPerson("단군", 100);
    Student bStudent("이도", 25, 2020, 2024);
    Worker cWorker("이순신", 50, 100);
    Albamon dAlbamon("철수", 20, 2023, 2027, 120);
    //4개의 객체 생성

    aPerson.printPerson();
    bStudent.printStudent();
    cWorker.printWorker();
    dAlbamon.printAlbamon();
    //생성된 객체 값 출력

    return 0;
}
