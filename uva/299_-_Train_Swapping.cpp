#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, t, swaps;
  vector<int> v;

  cin >> t;
  while(t--){
    swaps = 0;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i];

    while(v.size()){
      for(int i=0; i<v.size(); i++){
        if(v[i] == v.size()){
          v.erase(v.begin()+i);
          swaps+= v.size()-i;
          break;
        }
      }
    }

    printf("Optimal train swapping takes %d swaps.\n", swaps);
  }

  return 0;
}