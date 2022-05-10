#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, m;
  vector<string> v, sorted;
  vector<pair<int, int> > cont;
  cin >> t;
  while(t--){
    cin >> n >> m;

    v.resize(m);
    sorted.resize(m);
    cont.assign(m, {0,0});
    for(int i=0; i<m; i++){
      cin >> v[i];
      sorted[i] = v[i];

      cont[i].second = i;
    }    

    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        for(int k=j+1; k<n; k++){
          if(v[i][j] > v[i][k]) cont[i].first++;
        }
      }
    }

    sort(cont.begin(), cont.end());

    for(int i=0; i<m; i++){
      cout << v[cont[i].second] << "\n";
    }

    if(t) cout << "\n";
  }

  return 0;
}