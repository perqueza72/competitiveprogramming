#include <bits/stdc++.h>
#define un unsigned

using namespace std;


int n, m;
char land;
vector<string> grafo(22);

int DFS(char x, char y){
  if(grafo[x][y] != land) return 0;
  grafo[x][y] = !land;

  short value = 1;
  if(x > 0) value+= DFS(x-1, y);
  if(x<n-1) value+= DFS(x+1, y);
  
  if(y>0) value+= DFS(x, y-1);
  else value+= DFS(x, m-1);
  if(y < m-1) value+= DFS(x, y+1);
  else value+= DFS(x, 0);

  return value;
}

int main(){

  int xR, yR, ans;
  while(cin >> n >> m){
    for(int i=0; i<n; i++){
      cin >> grafo[i];
    }
    cin >> xR >> yR;
    land = grafo[xR][yR];
    DFS(xR, yR);

    // for(int i=0; i<n; i++){
    //   cout << grafo[i] <<endl;
    // }

    ans = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grafo[i][j] == land) ans = max(DFS(i, j), ans);
      }
    }

    cout << ans << endl;
  }


  return 0;
}