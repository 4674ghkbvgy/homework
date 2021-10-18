#include <iostream>
using namespace std;

const int Max =INT16_MAX;
long long sum;
int alt[Max];

void merge(int a[], int l, int r)
{
    for(int i= l; i <= r; i ++)
    {
        alt[i] = a[i];
    }
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    for (int pos = l; pos != r+1; pos++)
    {
        if (i == mid + 1)
        {   
            a[pos] = alt[j];
            j++;
        }
        else if (j == r + 1)
        {
            a[pos] = alt[i];
            i++;
        }
        else if (alt[i] > alt[j])
        {
            a[pos] = alt[j];
            j++;
            sum += mid - i + 1;
        }
        else
        {
            a[pos] = alt[i];
            i++;
        }
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, r);
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);
    printf("%lld\n", sum);
}
