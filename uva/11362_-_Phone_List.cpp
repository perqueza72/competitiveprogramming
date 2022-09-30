#include <bits/stdc++.h>

using namespace std;

const int MAX = (int)1e6 + 20;

struct Trim
{
    int nodes[MAX][10];
    vector<bool> fin = vector<bool>(MAX, false);
    int last = 1;

    Trim()
    {
        memset(nodes, -1, sizeof(nodes));
    }

    void reset(){
        for(int i=0; i<last; i++){
            fin[i] = false;
            for(int j=0; j<10; j++){
                nodes[i][j] = -1;
            }
        }
        last = 1;
    }

    bool add(const string &s)
    {
        int now = 0, x;
        for (int i = 0; i < s.size(); i++)
        {
            x = s[i]-'0';
            if (nodes[now][x] == -1)
            {
                now = nodes[now][x] = last++;
                continue;
            }

            now = nodes[now][x]; 

            if (fin[now])
                return false;

            if(i == s.size() - 1)
                return false;
        }

        fin[now] = true;
        return true;
    }
};

int main()
{

    string s;
    int k, n;
    bool puede;
    cin >> k;
    Trim *trim = new Trim();
    while (k--)
    {
        puede = true;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (trim->add(s) == false)
                puede = false;
        }

        cout << (puede ? "YES" : "NO") << "\n";
        if(k) trim->reset();
    }

    return 0;
}