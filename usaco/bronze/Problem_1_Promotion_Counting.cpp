#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int a[4], b[4], r[4] = {0};
  for(int i=0; i<4; i++){
    cin >> a[i] >> b[i];
  }

  for(int i=2; i>=0; i--){
    r[i] = r[i+1] + b[i+1] - a[i+1];
  }

  printf("%d\n%d\n%d\n", r[0], r[1], r[2]);


  return 0;
}