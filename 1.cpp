#include <iostream>
using namespace std;
class rectage
{
private:
    int len, wid;

public:
    rectage(int a=0,int b=0)
    :len(a),wid(b){}
    inline
    int calarea()const { return len * wid; }
    inline
    int calzhouchang()const { return (len + wid) * 2l; }
    
    void operator()()
    {
        cout << "请输入长和宽" << endl;
        cin >> len >> wid;
    }
};

int main()
{
    rectage rect1;
    int sum1, sum2;
    rect1();
    sum1 = rect1.calarea();
    sum2 = rect1.calzhouchang();
    cout << "面积" << sum1 << endl;
    cout << "周长" << sum2 << endl;
}