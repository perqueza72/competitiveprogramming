#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m, aux;
    pair<int,int> x;
    deque<pair<int,int> > table;
    while (cin >> n >> m, n + m)
    {

        priority_queue<pair<int, int>> pq, pqAux;
        vector<vector<int> > response(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            pq.push({aux, i});
        }

        table.resize(0);
        for (int i = 0; i < m; i++){
            cin >> aux;
            table.push_back({aux, i+1});
        }
        sort(table.begin(), table.end());

        int i = 0;

        while (i < m && pq.size())
        {
            while (pq.size())
            {
                x = pq.top();
                pq.pop();

                if (table[i].first > 0)
                {
                    x.first--;
                    table[i].first--;
                    response[x.second].push_back(table[i].second);
                }

                if (x.first){
                    pqAux.push(x);
                }
            }
            i++;
            pq.swap(pqAux);
        }

        if(i <= m && pq.empty()){
            cout << 1 << "\n";
            for(auto &v : response){
                for(int j=0; j<v.size(); j++){
                    if(j) cout << " ";
                    cout << v[j];
                }
                cout << "\n";
            }
        }else{
            cout << "0\n";
        }
    }

    return 0;
}