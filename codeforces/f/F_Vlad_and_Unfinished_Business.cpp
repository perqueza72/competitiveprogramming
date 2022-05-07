#include <bits/stdc++.h>

using namespace std;

set<int> task;
vector<vector<int> > grafo;
vector<bool> seen;
int y;

int dfsResponse;
int DFS(int node){
  if(seen[node]) return 0;
  seen[node] = true;

  int dist = 0;
  bool leafImportant = false;

  for(auto u : grafo[node]){
    if(!seen[u]){
      dfsResponse = DFS(u);
      dist+= dfsResponse;
      if(dfsResponse) leafImportant = true;
    }
  }

  if(leafImportant || task.count(node)){
    dist+=2;
  }

  return dist;
}

int deep(int node, int d){
  if(node == y) return d;
  if(seen[node] == false) return 0;
  seen[node] = false;
  int ans = 0;

  for(auto u : grafo[node]){
    ans+= deep(u, d+1);
  }

  return ans;
}

int main(){

  int t, n, k, x,a ,b;

  cin >> t;
  while(t--){

    cin >> n >> k;
    cin >> x >> y;

    task = set<int>();
    seen.assign(n+1, false);
    grafo.assign(n+1, vector<int>(0));

    task.insert(y);
    for(int i=0; i<k; i++){
      cin >> a;
      task.insert(a);
    }
    for(int i=1; i<n; i++){
      cin >> a >> b;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }

    cout << (DFS(x)-2-deep(x, 0)) << "\n";
    
  }

  return 0;
}