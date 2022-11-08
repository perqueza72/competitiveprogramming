#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo = vector<vector<int> >();
vector<int> seen;
int color;

int DFS(int v){

    if(seen[v]) return 0;
    seen[v] = color;
    int r = 1;
    for(int i=0; i<grafo[v].size(); i++){
        if(!seen[grafo[v][i]]) r+=DFS(grafo[v][i]);
    }

    return r;
}

int main(){

    int n, m,a, b;
    cin >> n >> m;
    grafo.assign(n+1, vector<int>());
    seen.resize(n+1, false);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    long long maxi = 0;
    for(int i=1; i<grafo.size(); i++){
        color = i;
        if(!seen[i])
            maxi = max(maxi,(long long) DFS(i));
    }

    sort(seen.begin(), seen.end());

    long long ant = 0, cont = 0;
    for(long long v : seen){
        if(v != ant){
            cont++;
            ant = v;
        }
    }

    
    cout << (1ll<<(n-cont)) << endl;



    return 0;
}