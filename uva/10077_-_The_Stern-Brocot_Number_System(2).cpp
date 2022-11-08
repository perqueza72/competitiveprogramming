#include <bits/stdc++.h>

using namespace std;

pair<int, int> sum(const pair<int, int> &a, const pair<int, int> &b)
{
    pair<int, int> r;

    r.first = a.first + b.first;
    r.second = a.second + b.second;

    return r;
}

int main()
{

    int n, m;
    pair<int, int> root, R, L;
    double v, rValue;
    int cont = 0;
    while (cin >> n >> m, n != 1 || m != 1)
    {
        R.first = 1;
        R.second = 0;
        L.first = 0;
        L.second = 1;

        root = sum(R, L);
        v = (double)n / (double)m;
        while (root.first != n || root.second != m)
        {
            rValue = (double)root.first / (double)root.second;
            if (rValue > v)
            {
                R = root;
                root = sum(root, L);
                cout << "L";
            }
            else
            {
                L = root;
                root = sum(root, R);
                cout << "R";
            }
        }
        cout << "\n";
    }
}