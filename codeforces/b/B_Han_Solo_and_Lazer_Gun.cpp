#include <bits/stdc++.h>

using namespace std;

int xo, yo;

pair<int,int> calc(int x, int y){
  double modulo = sqrt((double)((xo-x)*(xo-x)+(y-yo)*(y-yo)));
  return (make_pair((int)abs(10000*((double)(x)/modulo)), (int)abs(10000*((double)(y))/modulo)));
}

int main(){

  set<pair<int,int>> leMape;
  int n, x, y;
  pair<int, int> aux;


  cin >> n >> xo >> yo;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    aux = calc(x,y);
    if(!leMape.count(aux)){
      leMape.insert(aux);
    }
  }

  cout << leMape.size() << endl;


  return 0;
}