#include <bits/stdc++.h>

using namespace std;


vector<vector<vector<int> > > multigrafo(101, vector<vector<int> >(101, vector<int>()));

int a, b;
bool BFS(vector<vector<int> > &grafo){
    deque<int> q;
    q.push_back(a);
    int v;
    vector<bool> seen(101, false);

    while(q.size()){
        v = q.front();
        q.pop_front();

        if(seen[v]) continue;
        if(v == b) return true;
        seen[v] = true;

        for(int i=0; i<grafo[v].size(); i++){
            if(seen[grafo[v][i]]) continue;
            q.push_back(grafo[v][i]);
        }
    }

    return false;
}


int main(){

    int n, m, color;


    cin >> n>> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> color;

        multigrafo[color][a].push_back(b);
        multigrafo[color][b].push_back(a);
    }

    int q, cont;
    cin >> q;
    for(int i=0; i<q; i++){
        cont = 0;
        cin >> a >> b;

        for(auto &grafo : multigrafo){
            if(BFS(grafo))cont++;
        }

        cout << cont << "\n";
    }

    return 0;
}