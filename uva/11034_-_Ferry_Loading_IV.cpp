#include <bits/stdc++.h>

using namespace std;

const bool RIGTH = 1, LEFT = 0;
int main(){

  int t, a, n, tam;
  int veces[2], car[2];
  bool dir;
  string dirInput;
  cin >> t;
  while(t--){
    cin >> tam >> n;
    tam*=100;
    // cout << tam << endl;
    veces[LEFT] = 0;
    veces[RIGTH] = 0;
    car[1] = car[0] = 0;
    // cout << "card: \n";
    for(int i=0; i<n; i++){
      cin >> a >> dirInput;

      dir = dirInput == "right";
      if(car[dir]+a > tam){
        veces[dir]++;
        car[dir] = 0;
      }
      car[dir]+=a;
      // cout << car[dir] << endl;
    }

    cout << max(veces[0]*2+1, veces[1]*2+2) << "\n";


  }
  return 0;
}