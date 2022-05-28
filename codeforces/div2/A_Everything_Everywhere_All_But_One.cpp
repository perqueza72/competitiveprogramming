#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, prom, sum, n;
  bool puede;
  vector<int> v;
  cin >> t;
  while(t--){
    cin >> n;
    v.resize(n);
    sum = 0;
    for(int i=0; i<n; i++){
      cin >> v[i];
      sum+= v[i];
    }
    if(sum%n == 0) prom = sum/n;
    else prom = -1;

    puede = false;
    for(int  i=0; i<n; i++){
      if(prom == v[i]) puede = true;
    }

    if(puede) cout << "YES\n";
    else cout << "NO\n";

  }

  return 0;
}