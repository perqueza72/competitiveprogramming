#include <bits/stdc++.h>

using namespace std;

pair<int,int> e;
vector<vector<bool> > grafo;

int n, m;

queue<pair<int, int> > q;

void positions(int &i, int &j, vector<pair<int, int> > &v){
  v.resize(0);
  if(i > 0 && grafo[i-1][j] == false)    v.push_back({i-1,j});
  if(i < n-1 && grafo[i+1][j] == false) v.push_back({i+1,j});
  if(j < m-1 && grafo[i][j+1] == false)    v.push_back({i,j+1});
  if(j > 0 && grafo[i][j-1] == false)    v.push_back({i,j-1});

}

int BFS(){

  int total = 0;
  pair<int,int> v;
  vector<pair<int, int> > a;
  queue<pair<int, int> > qAux;


  while(++total){
    while(q.size()){
      v = q.front();
      q.pop();
      if(v == e) return total-1; 
      if(grafo[v.first][v.second]) continue;
      grafo[v.first][v.second] = 1;

       
      positions(v.first, v.second, a);
      for(auto u : a){
        if(grafo[u.first][u.second]) continue;
        qAux.push(u);
      }
    }
    q.swap(qAux);

  }

  return total;
}


int main(){
  pair<int, int> ini;
  int i, j, t, colboms;

  while(cin >> n >> m, n + m){
    grafo.assign(n, vector<bool>(m, false));
    cin >> colboms;
    while(colboms--){
      cin >> i >> t;
      while(t--){
        cin >> j;
        grafo[i][j] = true;
      }
    }
    cin >> ini.first >> ini.second;
    cin >> e.first >> e.second;

    q = queue<pair<int,int> >();
    q.push(ini);
    cout << BFS() << "\n";

  }


  return 0;
}