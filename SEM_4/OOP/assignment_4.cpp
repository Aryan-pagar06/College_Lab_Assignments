#include <iostream>
using namespace std;

class Point {
    public : 
    int x,y;
    Point(int a=0, int b=0) {
        x=a;
        y=b;
    }

int add (int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}
Point add (Point p1, Point p2) {
    return Point (p1.x + p2.x, p1.y + p2.y);
}
Point sub (Point p1, Point p2) {
    return Point (p1.x - p2.x, p1.y - p2.y);
}
Point mul (Point p1, Point p2) {
    return Point (p1.x * p2.x, p1.y * p2.y);
}
void display (Point p){
    cout<<"Point coordinate : ("<<p.x<<","<<p.y<<"'";
}
};

int main () 
{
    int x,y;
    cin>>x>>y;
    Point call;
    cout<<call.add(x,y)<<endl;
    cout<<call.sub(x,y)<<endl;
    cout<<call.mul(x,y)<<endl;
    Point a(4,5);
    Point b(2,3);
    Point c = call.add(a,b);
    call.display (c);
    Point d= call.sub(a,b);
    call.display (d);
    Point e = call.mul(a,b);
    call.display (e);
    
}
