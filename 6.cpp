// #include <iostream>
// #include <array>
// #include <vector>
// #include <math.h>
// #include <algorithm>
// #include <functional>

// using namespace std;
// void DC(const vector<vector<bool>>::iterator &b, const vector<vector<bool>>::iterator &e, size_t n, size_t N);
// void fun(size_t n, vector<bool> &node);
// int count1 = 0;
// int count2 = 0;
// int main(int argc, char *argv[])
// {
//     size_t n;
//     cin >> n;
//     vector<vector<bool>> gary(pow(2, n), vector<bool>(n, 0));
//     DC(gary.begin(), gary.end(), n, n);
//     for (auto i : gary)
//     {
//         cout << "(";
//         for (auto j : i)
//         {
//             cout << j ;
//         }
//         cout << ")" << endl;
//     }
//     return 0;
// }

// void DC(const vector<vector<bool>>::iterator &b, const vector<vector<bool>>::iterator &e, size_t n, size_t N)
// {
//     if (n != 0)
//     {
//         vector<vector<bool>>::iterator mid = b + pow(2, n - 1);
//         if (::count2++ % 2==0)
//         {
//             for_each(mid, e, [&](vector<bool> &node)
//                      { node[::count1] = 1; });
//         }
//         else
//         {
//             for_each(b, mid, [&](vector<bool> &node)
//                      { node[::count1] = 1; });
//         }
//         ++count1;
//         DC(b, mid, n - 1, N);
//         DC(mid, e, n - 1, N);
//         --count1;
//         if (::count2++ % (int) pow(2,n)==0)
//             count2 =0;
//     }
// }
// void fun(size_t n, vector<bool> &node)
// {
//     node[n] = true;
// }

#include "iostream"
#include "cmath"
using namespace std;

int arr[1024][1024];

void gray(int a, int b)
{
    if (b == 1)
    {
        arr[0][0] = 0;
        arr[1][0] = 1;
        return;
    }
    for (int i = 0; i < a / 2; i++)
    {
        arr[i][b - 1] = 0;
        arr[a - i - 1][b - 1] = 1;
    }
    gray(a / 2, b - 1);
    for (int i = a / 2; i < a; i++)
        for (int j = 0; j < b - 1; j++)
            arr[i][j] = arr[a - i - 1][j];
}

int main()
{
    int b;
    cout << "输入格雷码位数：";
    cin >> b;
    int a = pow(2, b);
    gray(a, b);
    cout << "格雷码为：\n";
    for (int i = 0; i < a; i++)
    {
        cout << "(";
        for (int j = 0; j < b; j++)
            cout<< arr[i][j];
        cout << ")" << endl;
    }
    return 0;
}