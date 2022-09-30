#include <bits/stdc++.h>

using namespace std;

vector<int> d;

bool is_possible(int k)
{
    int site = 0;
    // 1 6 7 11 13
    for (int &v : d)
    {
        if (k+site < v)
            return false;
        if (k+site == v)
            k--;
        site= v;
    }

    return true;
}

int binary_search(int &l, int &r)
{
    int mid, sum = 0, it = 20;

    while(l != r)
    {
        mid = (l + r) / 2;

        if (is_possible(mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{

    int t, cont = 0, r, n;
    cin >> t;
    while (cont, cont++ < t)
    {
        cin >> n;
        d.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        int maxi = *max_element(d.begin(), d.end());
        int mini = *min_element(d.begin(), d.end());

        r = binary_search(mini, maxi);
        printf("Case %d: %d\n", cont, r);
    }

    return 0;
}