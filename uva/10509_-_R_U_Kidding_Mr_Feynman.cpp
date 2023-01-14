#include <bits/stdc++.h>

using namespace std;

long double n;

bool calc(long long v)
{
    return (v * v * v) <= n;
}

long double bs(int l, int r)
{
    int mid, ans;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (calc(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    cout.precision(4);
    while (cin >> n, n)
    {
        long double a = bs(0, 1000001);

        long double r = a + (n - a * a * a)/(3 * a * a);

        cout << fixed << r << "\n";
    }

    return 0;
}