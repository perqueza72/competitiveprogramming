#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m, size, maxspeed, pos = 0, ans = 0;
  cin >> n >> m;
  int limit[100], bessie[100];
  for(int i=0; i<n; i++){
    cin >> size >> maxspeed;
    for(int j=0; j<size; j++){
      limit[pos+j] = maxspeed;
    }
    pos += size;
  }

  pos = 0;
  for(int i=0; i<m; i++){
    cin >> size >> maxspeed;
    for(int j=0; j<size; j++){
      bessie[pos+j] = maxspeed;
    }
    pos += size;
  }

  ans = 0;
  int diff;
  for(int i=0; i<100; i++){
    diff = bessie[i] - limit[i];
    ans = max(diff, ans);
  }

  cout << ans << endl;

  return 0;
}