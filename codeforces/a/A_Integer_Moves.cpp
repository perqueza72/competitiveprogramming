#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, y, x, r, ahhhh;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    r = x*x+y*y;
    ahhhh = sqrt(r);

    if(x == 0 && y == 0){
      cout << "0" << endl;
      continue;
    }

    if(ahhhh*ahhhh == r){
      cout << "1" << endl;
      continue;
    }

    cout << "2" << endl;
  }

  return 0;
}