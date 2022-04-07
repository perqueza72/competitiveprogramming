#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  int n;
  cin >> n;
  int aux[n]; 
  string id[n+1], idCopy[n+1];

  for(int i=1; i<=n; i++) cin >> aux[i];
  for(int i=1; i<=n; i++) cin >> id[i];

  for(int j=0; j<3; j++){
    for(int i=1; i<=n; i++) idCopy[i] = id[aux[i]];
    for(int i=1; i<=n; i++) id[i] = idCopy[i];
  }

  for(int i=1; i<=n; i++){
    cout << id[i] << "\n";
  }

  return 0;
}