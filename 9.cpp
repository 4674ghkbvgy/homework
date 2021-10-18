#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10;
int a[maxn] = {2, 5, 8, 13, 17, 25, 35, 36, 47, 50};

int lower_bound(int *a, int x, int y, int key)
{
    int m;
    while (x < y)
    {
        m = x + (y - x) / 2;
        if (a[m] >= key)
            y = m;
        else
            x = m + 1;
    }
    return x;
}

int upper_bound(int *a, int x, int y, int key)
{
    int m;
    while (x < y)
    {
        m = x + (y - x) / 2;
        if (a[m] <= key)
            x = m + 1;
        else
            y = m;
    }
    return x;
}

int main()
{
    int key1, key2;
    cin >> key1 >> key2;

    for (int i = lower_bound(a, 0, maxn, key1);
         i < upper_bound(a, 0, maxn, key2);
         i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
