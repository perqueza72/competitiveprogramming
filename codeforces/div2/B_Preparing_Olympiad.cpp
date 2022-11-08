#include <bits/stdc++.h>

using namespace std;

int l, r;
bool inRange(int value){
  if(l <= value && value <= r) return true;
  return false;
}

int main(){
  vector<int> v;
  int n, x;
  cin >> n >> l >> r >> x;
  v.resize(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  int sum = 0, r = 0, maxi = 0, mini = 1e9+10;
  for(int i=0; i<(1<<n); i++){
    sum = maxi = 0;
    mini = 1e9+10;
    for(int j=0; j<n; j++){
      if(i&(1<<j)){
        sum+= v[j];
        maxi = max(maxi, v[j]);
        mini = min(mini, v[j]);
      }
    }


    if(maxi-mini >= x && inRange(sum)){
      r++;
    }
  }

  cout << r << endl;

  return 0;
}