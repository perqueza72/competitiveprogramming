#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, bit, x, cont;
  vector<int> sol, v, copyV;
  cin >> t;
  while(t--){
    x = 0;
    cin >> n;
    v.resize(n);
    copyV.resize(n);
    sol.resize(0);
    bit = 19;
    for(int i=0; i<n; i++){
      cin >> v[i];
      copyV[i] = v[i];
    }
    sort(copyV.begin(), copyV.end());
    for(int i=0; i<n; i++){
      if(v[i] != copyV[i]) sol.push_back(v[i]);
    }
    sol.swap(v);
    sol.resize(0);
    cont = 0;

    while(bit >= 0){
      for(int i=0; i<v.size(); i++){
        if(v[i] & (1<<bit)){
          cont++;
        }
      }

      // cout << sol.size() << endl;
      if(cont == v.size())
        x+=(1<<bit);
        // cout << bit << endl; 
      cont = 0;
      bit--;
    }

    // cout << v.size() << endl;
    // cout << v.size() << endl;
    // for(auto u: v) cout << u << " ";
    // cout << endl;
    cout << x << "\n";
  }

  return 0;
}