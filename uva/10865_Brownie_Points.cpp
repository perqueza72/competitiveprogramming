#include <bits/stdc++.h>

using namespace std;

int main(){


  int n, x, y, datos[200010][2], first, second, xMid, yMid, centerPos;
  while(scanf("%d\n", &n), n){

    first = second = 0;

    for(int i=0; i<n; i++){
      scanf("%d %d\n", &datos[i][0], &datos[i][1]);
    }
    centerPos = n/2;
    xMid = datos[centerPos][0];
    yMid = datos[centerPos][1];

    for(int i=0; i<n; i++){
      if(datos[i][0] > xMid && datos[i][1] > yMid || datos[i][0] < xMid && datos[i][1] < yMid) first++;
      else if(datos[i][0] != xMid && datos[i][1] != yMid) second++;
    }

    printf("%d %d\n", first, second);
  }

  return 0;
}