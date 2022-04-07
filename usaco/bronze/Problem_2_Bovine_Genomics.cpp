#include <bits/stdc++.h>

using namespace std;


void printBits(char xd){
  for(int i=0; i<8; i++){
    if(xd & (1<<i)) cout << 1;
    else cout << 0;
  }
  cout << endl;
}


int main(){

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m, cont=0;
  cin >> n >> m;
  string genome[(2*n)];
  for(int i=0; i<2*n; i++){
    cin >> genome[i];
  }

  char a, spotty, plain;
  string letter = "ATCG";
  for(int i=0; i<m; i++){
    spotty = 0;
    plain = 0;

    for(int j=0; j<n; j++){
      for(int k=0; k<4; k++){
        if(genome[j][i] == letter[k]) spotty |= (1<<k);
      }
    }

    for(int j=n; j<2*n; j++){
      for(int k=0; k<4; k++) if(genome[j][i] == letter[k]) plain |= (1<<k);      
    }

    if(!(spotty & plain)) cont++;
  }

  cout << cont << endl;


  return 0;
}