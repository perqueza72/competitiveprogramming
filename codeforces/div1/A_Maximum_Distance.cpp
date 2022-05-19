#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  int x[n], y[n];
  for(int i=0; i<n; i++) cin >> x[i];
  for(int i=0; i<n; i++) cin >> y[i];

  int maxi = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      maxi = max((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]), maxi); 
    }
  }

  cout << maxi << endl;
  

  return 0;
}