#include <bits/stdc++.h>

using namespace std;


struct Dsu{
  vector<int> parents;

  Dsu(int n){
    resize(n);
  }

  Dsu(){}

  void resize(const int &n){
    parents.resize(n+1);
    for(int i=0; i<=n; i++) parents[i] = i;
  }

  int find_parent(int v){
    if(v == parents[v]) return v;
    return parents[v] = find_parent(parents[v]);
  }

  void merge(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a == b) return;

    parents[a] = b;
  }
};

struct Edge{
  int origin;
  int destiny;
  int w;
};

bool operator<(const Edge &a, const Edge &b){
  return a.w < b.w;
}

int n, m;
Dsu *dsu = new Dsu();
vector<Edge> edges;
int mst(int ignore = -1){
  int cost = 0, mst_size = 0;
  dsu->resize(n);

  for(int i=0; mst_size<n-1 && i < m; i++){

    Edge &edge = edges[i];
    if(dsu->find_parent(edge.origin) == dsu->find_parent(edge.destiny))
      continue;

    if(mst_size == ignore){
      ignore--;
      continue;
    }
    mst_size++;
    dsu->merge(edge.origin, edge.destiny);

    cost+= edge.w;
  }

  return mst_size == n-1 ? cost : 1e9;
  
}

int main(){
  int t;
  Edge edge;
  cin >> t;
  while(t--){
    cin >> n >> m;

    edges.resize(0);
    for(int i=0; i<m; i++){
      cin >> edge.origin >> edge.destiny >> edge.w;
      edges.push_back(edge);
    }

    sort(edges.begin(), edges.end());

    int second_const = 1e9+10;

    int cost = mst();
    for(int i=0; i<n-1; i++){
      second_const = min(mst(i), second_const);
    }

    cout << cost << " " << max(cost, second_const) << "\n";

  }

  return 0;
}