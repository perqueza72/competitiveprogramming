#include <bits/stdc++.h>

using namespace std;

// vector<vector<int> > chess(8, vector<int>());

int n = 8, it;
vector< vector<vector<pair<int, int> > > > chess(8, vector<vector<pair< int, int> > >(8, vector<pair<int, int> >()));
vector<vector<int> > seen(8, vector<int>(8,-1));

int BFS(pair<int,int> a, const pair<int, int> &b)
{
    deque<pair<int,int> > q, qAux;
    pair<int,int> v;
    int cont = 0;

    q.push_back(a);
    while(q.size()){
        while(q.size()){
            v = q.front();
            q.pop_front();
            if(v == b) break;

            if(seen[v.first][v.second] == it) continue;
            seen[v.first][v.second] = it;
            // cout << v.first << " " << v.second << " cont: " << cont << endl;

            for(int i=0; i<chess[v.first][v.second].size(); i++){
                pair<int,int> &aux = chess[v.first][v.second][i];
                if(seen[aux.first][aux.second] != it){
                    // cout << "aux: " << aux.first << " "  << aux.second << endl;
                    qAux.push_back(aux);
                }
            }
        }
        if(v == b) break;
        cont++;
        q.swap(qAux);
    }

    // cout << v.first << " " << v.second << "  " << b.first << " " << b.second << endl;

    return cont;
}

pair<int,int> getPos(const string &s){
    pair<int,int> p;
    p.first = s[0]-'a';
    p.second = s[1]-'1';

    return p;
}

int main()
{

    string s1, s2;

    int equis[] = {-1, -1, +1, +1, -2, +2, -2, +2};
    int yes[] = {-2, +2, -2, +2, +1, +1, -1, -1};
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k <8 ; k++)
            {
                x = i + equis[k];
                y = j + yes[k];
                if (x >= 0 && y >= 0 && x < n && y < n)
                    chess[i][j].push_back({x, y});
            }
        }
    }

    it = 10;
    pair<int, int> a,b;
    while (cin >> s1 >> s2)
    {
        a = getPos(s1);
        b = getPos(s2);
        // cout << a.first << a.second << " " <<b.first << b.second << endl;
        cout << "To get from " << s1 << " to " << s2 << " takes " << BFS(a, b) << " knight moves.\n";
        it++;
    }

    return 0;
}