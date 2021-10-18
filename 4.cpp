#include <iostream>
using namespace std;
class Date
{
    int year, month, day;

public:
    Date(int y = 1, int m = 1, int d = 1)
        : year(y), month(m), day(d) {}
    inline void print();
    inline bool operator>(Date);
};
bool Date::operator>(Date n)
{
    if (year >= n.year && month >= n.month && day >= n.day)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Date::print()
{
    cout << year << "年" << month << "月" << day << "日" << endl;
}
int main()
{
    Date jianguo(1949, 10, 1);
    jianguo.print();
    Date yuannian;
    jianguo > yuannian ? yuannian.print() : jianguo.print();
    return 0;
}
