#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, x, y;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> x >> y;

    if(y%x == 0) cout << "1 " << (y/x) << "\n";
    else cout << "0 0\n";
  }

  return 0;
}