#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, a, b ,c , x, y;
  cin >> t;
  while(t--){
    cin >> a >> b >> c >> x >> y;
    
    x = max(x-a, 0);
    y = max(y-b, 0);

    c = max((x+y)-c, 0);

    if(c > 0) cout << "NO\n";
    else cout << "YES\n";
  }


  return 0;
}