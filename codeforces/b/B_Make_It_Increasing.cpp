#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, cont, d, n;
  vector<int> v;
  bool puede;
  cin >> t;
  while(t--){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }

    puede = true;
    cont = 0;
    d = v.back();
    for(int i=n-2; i>=0; i--){
      if(d == 0){
        puede = false;
        break;
      }
      while(d <= v[i]){
        v[i]/=2;
        cont++;
      }
      d = v[i];
    }

    if(puede) cout << cont;
    else cout  << -1;
    cout << "\n";
  }



  return 0;
}