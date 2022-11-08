#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, k;
  cin >> n >> k;
  if(k > ((n*n+1)/2)){
    cout << "NO\n";
    return 0;
  }

  bool show = 1;
  int islands = 0;
  cout << "YES\n";
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << (show && islands<k ? "L" : "S");
      if(show) islands++;
      show = !show;
    }
    if((n&1) == 0) show = !show;
    cout << "\n";
  }

  return 0;
}