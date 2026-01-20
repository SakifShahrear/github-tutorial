#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;

    int x;
    int count = 0;
    for (int j = 1; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            int other_divisor = n / j;
            if (j * j != n)
            {
                a.push_back(j);
                a.push_back(other_divisor);
            }
            else if (j * j == n)
            {
                a.push_back(j);
            }
        }
    }
    sort(a.begin(), a.end());
    if (k > a.size())
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << a[k - 1] << endl;
    }

    return 0;
}