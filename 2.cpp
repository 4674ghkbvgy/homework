#include <iostream>
#include <vector>
using namespace std;
class Min
{
public:
    inline int operator()(vector<int> ai)
    {
        int mmin;
        for (mmin = *ai.begin(); int i : ai)
            mmin = min(i, mmin);
        return mmin;
    }
    inline double operator()(vector<double> ai)
    {
        double mmin;
        for (mmin = *ai.begin(); auto i : ai)
            mmin = min(i, mmin);
        return mmin;
    }
}m;

int main()
{
    vector<int> a;
    vector<double> b;    
    for (int i : {5, 4, 3, 2, 1})
        a.push_back(i);
    for (double i : {5.1, 4.2, 3.3, 2.4, 1.5})
        b.push_back(i);
    cout<<m(a)<<endl;
    cout<<m(b)<<endl;
}