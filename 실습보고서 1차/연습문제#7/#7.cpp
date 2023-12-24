#include <iostream>

using namespace std;

class Point {
private:
    const int x;
    const int y;

public:
    Point(int x=0, int y=0) : x(x), y(y) {}

    void showPosition() {
        cout << "("<<x<<", "<<y<<")" << endl; 
    }

    Point operator+(const Point& obj1) const {
        return Point(x + obj1.x, y + obj1.y);
    }//연산자+ 함수

    friend Point operator-(const Point& obj2, const Point& obj3) {
        return Point(obj2.x - obj3.x, obj2.y - obj3.y);
    }//friend를 활용한 다중 정의 함수(연산자- 함수)
};

int main() {
    cout << "20215229 이채훈" << endl;
    cout << endl;
    /*
    Point p1; Point p2;
    객체 매개변수 초기값 0확인
    */

    Point p1(10, 20);
    Point p2(30, 40);
    //p1, p2 객체 생성

    cout << "p1: ";
    p1.showPosition();

    cout << "p2: ";
    p2.showPosition();
    cout << endl;

    Point p3 = p1 + p2;
    cout << "p3 = p1 + p2" << endl;
    cout << "p3: ";p3.showPosition();
    cout << endl;

    Point p4 = p1 - p2;
    cout << "p4 = p1 - p2" << endl;
    cout << "p4: ";p4.showPosition();

    return 0;
}
