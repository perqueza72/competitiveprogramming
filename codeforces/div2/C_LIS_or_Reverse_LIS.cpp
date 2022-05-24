#include <bits/stdc++.h>

using namespace std;

int n;

int lis(vector<int> &X){
  int r = 0;
  int ant = X[0];
  for(int i=1; i<X.size(); i++){
    if(ant < X[i]){
      r++;
    }else break;
  }

  return r;

}

int main(){

  int t, r, juntos, unicos;
  int v;
  map<int,int> mapa;
  cin >> t;
  while(t--){
    mapa = map<int,int>();
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> v;
      if(mapa.count(v)) mapa[v]++;
      else mapa.insert({v, 1});
    }

    juntos = unicos = 0;
    for(auto &u: mapa){
      if(u.second > 1) juntos++;
      else unicos++;
    }

    cout << (juntos+(1+unicos)/2) << "\n";
  }

  return 0;
}