#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);
  int x1,x2,y1,y2, i=0, j=0, xR, yR;
  string s;
  for(int j=0; j<10; j++){
    cin >> s;
    for(int i=0; i<10; i++){
      if(s[i] == 'B') x1 = i, y1 = j;
      if(s[i] == 'R') xR = i, yR = j;
      if(s[i] == 'L') x2 = i, y2 = j;
    }
  }

  int res = abs(y2-y1) + abs(x2-x1)- 1;
  if(y1 == y2 && y1 == yR){
    if(max(x1,x2) > xR && min(x1,x2) < xR){
      res+=2;
    }
  }
  if(x1 == x2 && x1 == xR){
    if(max(y1,y2) > yR && min(y1,y2) < yR){
      res+=2;
    }
  }
  printf("%d\n", res);


  return 0;
}