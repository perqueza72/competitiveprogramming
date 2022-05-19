#include <bits/stdc++.h>

using namespace std;

struct Dsu{
  vector<int> p;

  void set(int n){
    p.resize(n+1);
    for(int i=0; i<=n; i++) p[i] = i;
  };

  void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(p[a] == p[b]) return;
    p[a] = b;
  };

  int find(int x){
    if(p[x] != x) return p[x] = find(p[x]);
    return x;
  };

  bool are_connected(const int &a, const int &b){
    return find(a) == find(b);
  }
};

int main(){

  int t, n, q, s;
  string op;
  int a , b;
  Dsu *dsu = new Dsu();
  cin >> t;
  cin >> n;
  while(t--){
    int cont = 0;
    dsu->set(n);
    q = s = 0;
    while(cin >> op, cin.good() && (op == "c" || op == "q")){
      cin >> a >> b;
      if(op == "c") dsu->merge(a,b);
      else{
        q++;
        s+=dsu->are_connected(a, b);
      }
    }


    printf("%d,%d\n", s, q-s);
    if(t) cout << "\n";
    if(cin.good()) n = stoi(op);
    else break;


  }


  return 0;
}