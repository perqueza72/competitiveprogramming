#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, k, value;
  long long cont;
  multiset<long long> m;
  auto a = m.begin(), b = m.begin();
  while(cin >> n, n){
    cont = 0;
    m = multiset<long long>();
    for(int i=0; i<n; i++){
      cin >> k;
      while(k--){
        cin >> value;
        m.insert(value);
      }
      a = m.begin();
      b = --(m.end());
      cont+= (*b)-(*a);
      m.erase(b);
      m.erase(a);
    }
    cout << cont << "\n";

  }
  return 0;
}