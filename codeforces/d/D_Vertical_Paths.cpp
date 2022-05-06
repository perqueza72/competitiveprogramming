#include <bits/stdc++.h>

using namespace std;

vector<int> branch, aux;
vector<vector<int > > grafo, response;
vector<bool> seen;

inline void print(const vector<int> &v){
  cout << v.size() << "\n";
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << "\n";
}

void topo(int i){
  seen[i] = true;

  for(auto u : grafo[i]){
    if(!seen[u]) topo(u);
    seen[i] = true;
  }
  branch.push_back(i);
}

void dfs(int i){
  if(seen[i] == false) return;
  seen[i] = false;
  aux.push_back(i);

  for(auto u: grafo[i]){
    dfs(u);
  }

  if(aux.size()) response.push_back(aux);
  aux.resize(0);
}

int main(){

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int t, n, v;
  cin >> t;
  while(t--){
    cin >>n;
    grafo.assign(n+1, vector<int>(0));
    seen.assign(n+1, false);
    response.resize(0);
    branch.resize(0);

    for(int i=1; i<=n; i++){
      cin >> v;
      grafo[v].push_back(i);
    }

    for(int i=1; i<=n; i++){
      if(!seen[i]) topo(i);
    }

    for(int i=branch.size()-1; i>=0; i--){
      dfs(branch[i]);
    }


    

    // print(branch);
    cout << response.size() << "\n";
    for(int i=0; i<response.size(); i++){
      print(response[i]);
    }
    
    cout << "\n";
  }

  return 0;
}