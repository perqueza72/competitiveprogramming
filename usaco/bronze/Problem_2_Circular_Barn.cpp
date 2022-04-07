#include <bits/stdc++.h>

using namespace std;

int main(){


  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int mini = 1e8, n, miniS, dist;
  cin >> n;
  int vacas[n]{};
  for(int i=0; i<n; i++) cin >> vacas[i];

  for(int i=0; i<n; i++){
    miniS = 0;
    dist = 0;
    for(int j=i; j<i+n; j++, dist++) miniS+=vacas[j%n]*(dist%n);
    
    mini = min(miniS, mini);
  }

  cout << mini << endl;

  return 0;
}