#include <bits/stdc++.h>

using namespace std;



int main(){

  int a, x, y, cell;
  cin >> a >> x >> y;
  if(y%a == 0){
    cout << -1 << endl;
    return 0;
  }

  cell = y/a;

  if(cell == 0){
    x*=2;
  }else{
    if(cell % 2){
      x*=2;
    cell+= cell/2;

    }else{

    cell+= cell/2;
      if(x == 0){
      cout << -1 << endl;
      return 0;
      }else if(x < 0){
        cell--;
      }
    }
  }

  cout << ((-a < x && x < a) ? cell+1 : -1) << endl;

  return 0;
}