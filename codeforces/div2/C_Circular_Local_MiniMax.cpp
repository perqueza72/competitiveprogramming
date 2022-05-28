#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, next, ant;
  bool puede;
  vector<int> v, r;
  cin >> t;
  while(t--){
    cin >> n;
    v.resize(n);
    r.resize(0);

    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    if(n&1){
      cout << "NO\n";
      continue;
    }
    for(int i=0, j=n/2; j<n; i++, j++){
      r.push_back(v[i]);
      r.push_back(v[j]);
    }

    puede = true;
    for(int i=0; i<n; i++){
      ant = i == 0 ? n-1 : i-1;
      next = i == n-1 ? 0 : i+1;
      if((r[ant] < r[i] && r[i] > r[next]) || (r[ant] > r[i] && r[i] < r[next])){}
      else{
        puede = false;
        break;
      }
    }

    if(puede){
    cout << "YES\n";
      for(int i=0; i<n; i++){
        cout << r[i] << " ";
      }
    }else cout << "NO";
    cout << "\n";
  }

  return 0;
}