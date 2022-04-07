#include <bits/stdc++.h>

using namespace std;

int x,y;
int milkdp[1000];
int milk(int m){
  if(m < x && m < y) return 0;
  if(milkdp[m] != -1) return milkdp[m];

  if(m < x) milkdp[m] = y+milk(m-y);
  else if(m < y) milkdp[m] = x+milk(m-x);
  else milkdp[m] = max(x+milk(m-x), y+milk(m-y));

  return milkdp[m];
}

int main(){


  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int m;
  memset(milkdp, -1, sizeof(milkdp));
  cin >> x >> y >> m;

  cout << milk(m) << endl;


  return 0;
}