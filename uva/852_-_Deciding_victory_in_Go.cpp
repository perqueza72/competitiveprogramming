#include <bits/stdc++.h>

using namespace std;

vector<string> grafo(9);
bool bordes[2];

bool no_visto(const char &v){
  return v == 'O' || v == 'X' || v == '.';
}

int DFS(int i, int j, const char &v){
  if(grafo[i][j] != v){
    if(v == '.'){
      bordes[0]|= (grafo[i][j] == 'P' || grafo[i][j] == 'O');
      bordes[1]|= (grafo[i][j] == 'Y' || grafo[i][j] == 'X');
    }
    return 0;
  }
  if(!no_visto(grafo[i][j])) return 0;
  grafo[i][j]++;

  int r = 1;
  if(i > 0) r+= DFS(i-1, j, v); 
  if(i < 8) r+= DFS(i+1, j, v);
  if(j > 0) r+= DFS(i, j-1, v);
  if(j < 8) r+= DFS(i, j+1, v);

  return r;
}

int main(){

  int t, v, r;
  int ans[2];
  cin >> t;
  while(t--){
    ans[0] = ans[1] = 0;
    for(int i=0; i<9; i++){
      cin >> grafo[i];
    }

    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){ 
        v = grafo[i][j];
        if(no_visto(v)){
          r = DFS(i, j, v);
          // cout << "r: " << r << " " << bordes[0] << " " << bordes[1] << endl;
          if(bordes[0] && bordes[1]){
            bordes[0] = bordes[1] = false;
            // cout << "r: " << r << endl;
            continue;
          }
          if(bordes[0] == bordes[1] && bordes[1] == false){
            if(v == 'O') ans[0]+=r;
            else if(v == 'X') ans[1]+=r;
            continue;
          }
          ans[0]+= r*bordes[0];
          ans[1]+= r*bordes[1];
          bordes[0] = bordes[1] = false;
        }
      }
    }

    printf("Black %d White %d\n", ans[1], ans[0]);
  }

  return 0;
}