#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, aux, dist;
  vector<int> v;
  cin >> t;
  while(t--){
    dist = 1e9;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    int a = *min_element(v.begin(), v.end());
    int b = *max_element(v.begin(), v.end());
    cout << ((b-a)*2) << endl;

  }

  return 0;
}