#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  bool left;
  int x,y,a,ant, cont = 0;
  cin >> x >> y;

  ant = x;
  a = 1;

  if(y < x) left = 1;
  else left = 0;

  while(left*(ant > y) + (1-left)*(ant < y)){
    cont += abs(x+a - ant);
    // printf("cont: %d - %d\n", x+a, ant);
    ant = x+a;
    a*=-2;
  }

  cont -= max(0, left*(y - ant) + (1-left)*(ant - y));

  // cout << (x+a) << " " << y << " " << left << endl;

  cout << cont << endl;

  return 0;
}