#include <bits/stdc++.h>

using namespace std; 


void search(int x, int y){
  if(x == 8) return;
  if(grafo[x][y] == '*' || grafo[x])
  for(int j=0; j<8; j++){
    search(i, j);
  }

  search(x+1);
}

int main(){

  for(int i=0; i<8; i++){
    cin >> grafo[i];
  }



  return 0;
}