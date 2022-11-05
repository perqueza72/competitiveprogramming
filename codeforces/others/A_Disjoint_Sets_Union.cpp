#include <bits/stdc++.h>

using namespace std;

struct Dsu{
  vector<int> p;

  int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void set(int n){
    p.resize(n+1);
    for(int i=0; i<=n; i++) p[i]  = i;
  }

  void joint(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
     p[a] = b;
  }
};


int main(){

  Dsu *dsu = new Dsu();
  int n, m, a, b;
  string query;
  cin >> n >> m;
  // cout << n;
  dsu->set(n);
  for(int i=0; i<m; i++){
    cin >> query >> a >> b;
    if(query == "union"){
      dsu->joint(a, b);
    }else if(query == "get"){
      if(dsu->find(a) == dsu->find(b)) cout << "YES";
      else cout << "NO";
      cout << "\n";
    }
  }

  return 0;
}