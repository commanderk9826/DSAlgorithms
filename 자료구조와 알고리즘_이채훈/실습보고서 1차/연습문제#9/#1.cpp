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
        cout << "�̸�: " << name << ", ����: " << age << endl;
    }

private:
    string name;
    int age;
};

class Student : private Person {
// Person Ŭ������ ��� ���� Student Ŭ���� ����
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
        cout << "�̸�: " << getName() << ", ����: " << getAge() << endl;
        cout << "���� �⵵: " << getad() << endl;
        cout << "���� �⵵: " << getgY() << endl;
    }

private:
    int admissionYear;
    int graduationYear;
};

class Worker : private Person {
// Person Ŭ������ ��� ���� Worker Ŭ���� ����
public:
    Worker(const string& name, int age, int workingTime)
        : Person(name, age), workingTime(workingTime) {}

    int getwT() const {
        return workingTime;
    }

    void printWorker() {
        printPerson();
        cout << "�۾� �ð�: " << getwT() << endl;
    }

private:
    int workingTime;
};

class Albamon : private Student, private Worker {
// Person Ŭ������ ��� ���� Worker, StudentŬ������ ��ӹ��� Albamon Ŭ���� ����
public:
    Albamon(const string& name, int age, int admissionYear, int graduationYear, int workingTime)
        : Student(name, age, admissionYear, graduationYear), Worker(name, age, workingTime) {}

    void printAlbamon(){
        printStudent();
        cout << "�۾� �ð�: " << getwT() << endl;
    }

};

int main() {
    Person aPerson("�ܱ�", 100);
    Student bStudent("�̵�", 25, 2020, 2024);
    Worker cWorker("�̼���", 50, 100);
    Albamon dAlbamon("ö��", 20, 2023, 2027, 120);
    //4���� ��ü ����

    aPerson.printPerson();
    bStudent.printStudent();
    cWorker.printWorker();
    dAlbamon.printAlbamon();
    //������ ��ü �� ���

    return 0;
}
