#include <iostream>

using namespace std;
int myMin(int x, int y, int z);
int minCash(int **a, int *b, int N, int M);
int main()
{
    int m, n;
    cin >> m;
    int *b = new int[m]();
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    while (cin >> n, n != 0)
    {
        int **a = new int *[m];
        for (int i = 0; i < m; i++)
        {
            a[i] = new int[n + 1]();
        }
        cout << minCash(a, b, n, m);
    }
}
int minCash(int **a, int *b, int N, int M)
{
    int m = 0;
    for (int i = N; i >= 0; i--)
    {
        if (i % b[m] == 0)
        {
            a[m][i] = i / b[m];
        }
    }
    ++m;
    for (int i = 0; i <= N && m <= M; i++, m++)
    {
        if (a[m - 1][i])
        {
            a[m][i] = a[m - 1][i];
        }
        else if (i - b[m] >= 0 && a[m][i - b[m]])
        {
            a[m][i] = a[m][i - b[m]] + 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    return a[M - 1][N];
}
// int myMin(int x, int y, int z)
// {
//     int a, b, c;
//     if (x > y)
//     {
//         a = y;
//         b = x;
//     }
//     else
//     {
//         a = x;
//         b = y;
//     }
//     if (z < a)
//     {
//         c = b;
//         b = a;
//         a = z;
//     }
//     else if (z > b)
//         c = z;
//     else
//     {
//         c = b;
//         b = z;
//     }

//     if (b == 0)
//         return c;
//     else if (a == 0)
//         return b;
//     else
//         return a;
// }

// int minCash(int **a, int *b, int N, int M)
// {
//     int m = 0;
//     for (int i = N, j = 0; i >= 0; i -= b[m], j++)
//     {
//         a[m][i] = j;
//     }
//     ++m;
//     for (; m < M; m++)
//     {
//         for (int i = N - b[m]; i >= 0; i--)
//         {

//             if (i + b[m] == N)
//             {
//                 a[m][i] = 1;
//             }
//             else if (a[m - 1][i] != 0 || a[m - 1][i + b[m]] != 0 || a[m][i + b[m]] != 0)
//                 a[m][i] = myMin(a[m - 1][i], a[m - 1][i + b[m]] + 1, a[m][i + b[m]] + 1);
//             else
//             {
//                 a[m][i] = 0;
//             }
//         }
//     }
//     for (int i = 0; i < M; i++)
//     {
//         for (int j = 0; j < N + 1; j++)
//         {
//             cout << a[i][j] << '\t';
//         }
//         cout << endl;
//     }
//     return a[M - 1][0];
// }