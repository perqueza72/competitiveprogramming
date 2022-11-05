#include <bits/stdc++.h>

using namespace std;

struct Dsu{
  vector<int> p, maxi, mini, length;

  int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void get(int x){
    x = find(x);
    cout << mini[x] << " " << maxi[x] << " " << length[x] << "\n";
  }

  void set(int n){
    p.resize(n+1);
    maxi.resize(n+1);
    mini.resize(n+1);
    length.assign(n+1,1);
    for(int i=0; i<=n; i++) p[i] = mini[i] = maxi[i] = i;
  }

  void joint(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    maxi[b] = max(maxi[a], maxi[b]);
    mini[b] = min(mini[a], mini[b]); 
    length[b] += length[a];
    p[a] = b;
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b;
  string q;
  Dsu *dsu = new Dsu();
  cin >> n >> m;
  dsu->set(n);
  for(int i=0; i<m; i++){
    cin >> q;
    if(q == "union"){
      cin >> a >> b;
      dsu->joint(a, b);
    }else{
      cin >> a;
      dsu->get(a);
    }
  }
  



  return 0;
}