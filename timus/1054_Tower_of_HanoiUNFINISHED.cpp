#include <bits/stdc++.h>

using namespace std;


int dp[31][3][3], D[31];
int secondDp[31][3];
int n, maxi = -1;

bool calc(int i, int moves){
  for(int j=0; j<n; j++){
    if(secondDp[j][D[j]] != -1) continue;
    return false;
  }
   
  maxi = max(moves, maxi);
  //printf("respuesta obtenida en: %d movimientos.\n i: %d\n", moves, i);
  return true;
}

int Hanoi(int i,int From,int To_, int Temp){
  if (i < 0) return 0;

  int &moves = dp[i][From][To_];
  if(moves != -1){
    secondDp[i][From] = -1;
    secondDp[i][To_] = moves;
    return moves;
  }
  
  moves+= 1 + Hanoi(i - 1, From, Temp, To_);
  secondDp[i][From] = -1;
  secondDp[i][Temp] = moves;
  moves+= 1 + Hanoi(i - 1, Temp, To_, From);
  secondDp[i][Temp] = -1;
  secondDp[i][To_] = moves;


  if(secondDp[i][D[i]] != -1) calc(i, moves);
  return moves;
}

int main(){

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> D[i];
    D[i]--;
  }

  Hanoi(n-1, 0, 1, 2);
  cout << maxi << endl;
  return 0;
}