#include <bits/stdc++.h>

using namespace std;

int main(){
  int sum[3], tablero[3][3], maxi=0;
  memset(sum, 0, sizeof(sum));

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> tablero[i][j];
      sum[i]+=tablero[i][j];
    }
    maxi = max(maxi, sum[i]);
  }

  int calc = *min_element(sum, sum+3);
  

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(tablero[i][j])
        cout << tablero[i][j] << " ";
      else{
        switch(i){
          case 0:
            cout << (tablero[2][1]+tablero[1][2])/2;
          break;
          case 1:
            cout << (tablero[2][0]+tablero[0][2])/2;
          break;
          case 2:
            cout << (tablero[0][1]+tablero[1][0])/2;
          break;
        }
        cout << " ";
      }
    }
    cout << "\n";
  }


  return 0;
}