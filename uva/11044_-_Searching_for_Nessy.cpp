#include <bits/stdc++.h>

using namespace std;

int main(){

  long long t, n, m;
  cin >> t;
  while(t--){
    cin >> n >> m;

    n/=3;
    m/=3;

    cout << (n*m) << "\n";
  }

  return 0;
}