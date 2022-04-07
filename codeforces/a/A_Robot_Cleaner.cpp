#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, m, rb, cb, rd, cd, t, dr=1, dc=1;
  int cell[100][100];
  int move;
  cin >> t;
  for(int i=0; i<t; i++){
    dr=1, dc=1;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    rb--;
    n--;
    m--;
    rd--;
    cd--;
    cb--;
    move = 0;
    while(rb != rd && cd != cb){
      if(rb == n) dr*=-1;
      if(cb == m) dc*=-1;
      if(rb == 0) dr = 1;
      if(cb == 0) dc = 1;
      rb+=dr;
      cb+=dc;
      move++;
    }

    cout << move << endl;


  }


  return 0;
}