#include <bits/stdc++.h>

using namespace std;

string reduce(string &s)
{
    string r = "", b = "";
    for(auto &c : s)
        if (c != 'B' && (c == 'A' || c == 'C'))
            r.push_back(c);

    if (r.empty())
        return r;

    b.push_back(r[0]);
    for (int i = 1; i < r.length(); i++)
    {
        while (b.size() && i < r.length() && b.back() == r[i])
        {
            b.pop_back();
            i++;
        }
        if(i < r.length()) b.push_back(r[i]);
    }

    return b;
}

int main()
{

    int n;
    string s, w;
    cin >> n;
    while (n--)
    {
        cin >> s >> w;

        if (s.size() % 2 != w.size() % 2)
        {
            cout << "NO\n";
            continue;
        }
        s = reduce(s);
        w = reduce(w);

        // cout << "s y w " <<  s << "..." << w << endl;
        cout << (s == w ? "YES" : "NO") << "\n";
    }

    return 0;
}