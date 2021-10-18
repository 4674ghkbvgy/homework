#include <concepts>
#include <iostream>
using namespace std;

class Shape
{
private:
    int length,breadth;
public:
    Shape(int l,int b)
        :length(l),breadth(b){}
    virtual inline int area()const = 0;
    inline int get_l() const{ return length; }
    inline int get_b() const{ return breadth; }
};

class Rectangle :public Shape
{
public:
    Rectangle(int l=0,int b=0)
        :Shape(l,b){}
    int area() const override { return get_l() * get_b(); }
};

template <derived_from<Shape> T>
int get_area(const T &t)
{
    return t.area();
}

inline ostream& operator << (ostream& out,Rectangle r)
{
    out << "Rectangle：\n\t"
        << "length:" << r.get_l() << "\n\t"
        << "breadth:" << r.get_b() << "\n\t"
        << "area:" << get_area(r) << "\n\t";
    return out;
}
int main()
{
    Rectangle r(3,5);
    cout << r;
    return 0;
}