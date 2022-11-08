#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
vector<int> seen;
int DFS(int v){
  if(seen[v]) return 0;
  seen[v] = 1;

  int nodes = 1;
  for(int i=0; i<grafo[v].size(); i++){
    if(!seen[grafo[v][i]]) nodes +=DFS(grafo[v][i]);
  }


  return nodes;
}


int componentes;
bool Conexo(int v){
  if(seen[v] == 2) return true;
  seen[v] = 2;

  bool puede = true;
  if(componentes-1 != grafo[v].size()) return false;
  for(int i=0; i<grafo[v].size(); i++){
    if(seen[grafo[v][i]] == 1) puede &= Conexo(grafo[v][i]);
  }

  return puede;

}

int main(){

  int n, m, a, b;
  cin >> n >> m;
  grafo.assign(n+1, vector<int>());
  seen.assign(n+1, false);

  for(int i=0; i<m; i++){
    cin >> a >> b;
    grafo[a].push_back(b);
    grafo[b].push_back(a);
  }

  bool puede = true;
  for(int i=1; i<grafo.size(); i++){
    if(!seen[i]){
      componentes = DFS(i);
      puede &= Conexo(i);
    }
  }
  cout << (puede ? "YES" : "NO") << endl;

  return 0;
}