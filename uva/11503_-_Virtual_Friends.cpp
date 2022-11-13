#include <bits/stdc++.h>

using namespace std;

struct Dsu{
  vector<int> rank;
  vector<int> parent;

  int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }

  Dsu(){
    init();
  }

  void init(){
    rank.resize(0);
    parent.resize(0);
  }

  void push(int v){
    parent.push_back(v);
    rank.push_back(1);
  }

  int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return rank[a];

    if(rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    rank[a] += rank[b];
    return rank[a];
  }
};

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, t;
  string s, w;
  Dsu dsu;
  cin >> t;
  while(t--){
    cin >> n;
    map<string, int> persons;
    dsu.init();

    for(int i = 0; i<n; i++){
      cin >> s >> w;

      if(!persons.count(s)){
        dsu.push((int)persons.size());
        persons.insert({s, persons.size()});
      }
      if(!persons.count(w)){
        dsu.push((int)persons.size());
        persons.insert({w, persons.size()});
      }
      int a = persons[s];
      int b = persons[w];
      // cout << a << " " << b << endl;
      cout << dsu.merge(a, b) << "\n";
    }
  }

  return 0;
}