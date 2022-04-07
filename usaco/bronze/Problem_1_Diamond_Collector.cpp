#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k, antDiamond, diamond, cont, maxi;
  cin >> n >> k;

  int d[n];
  for(int i=0; i<n; i++) cin >> d[i];

  sort(d, d+n);
  maxi = 0;
  for(int i=0; i<n; i++){
    antDiamond = d[i];
    cont = 1;
    for(int j=i+1; j<n; j++){
      diamond = d[j];
      if(abs(antDiamond-diamond) <= k) cont++;
    }
    maxi = max(maxi, cont);
  }

  cout << maxi;

  return 0;
}