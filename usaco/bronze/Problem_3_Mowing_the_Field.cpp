#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  
  short field[2100][2100];
  memset(field, 0, sizeof(field));
  int posX = 1049, posY = 1049;
  int ans = 1e8, steps, distY, distX, cont, n;
  char dir;

  field[1049][1049] = cont = 0;

  cin >> n;
  for(int i=0; i<n; i++){
    distX = distY = 0;
    cin >> dir >> steps;
    if(dir == 'N') distY = 1;
    if(dir == 'S') distY = -1;
    if(dir == 'E') distX = 1;
    if(dir == 'W') distX = -1;
    for(int j=0; j<steps; j++){
      posX+=distX;
      posY+=distY;
      cont++;

      if(field[posX][posY]){
        ans = min(ans, cont - field[posX][posY]);
      }
      field[posX][posY] = cont;
      
    }

  }
  ans = ans == 100000000 ? -1 : ans;
  cout << ans << endl;

  return 0;
}