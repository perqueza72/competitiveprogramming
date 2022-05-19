#include <bits/stdc++.h>
#define un unsigned

using namespace std;

un short display[1010][2];
un int dp[1010][1010][2];
un int n, m, x, y;

//Si c es true, toma #, de lo contrario toma .
int solve(un int j,un int same, bool c){

  if(j == m){
    if(same < x &&  same <= y) return (int) 600000;
    return 0;
  }
  un int &ans = dp[j][same][c];
  if(ans != -1) return ans;

  
  int sameC = display[j][!c];
  int diffC = display[j][c];

  if(same<x) ans = sameC + solve(j+1, same+1, c);
  else if(same>=y) ans = diffC + solve(j+1, 1, !c);
  else ans = min(sameC + solve(j+1,same+1,c),  diffC + solve(j+1,1,!c));

  return ans;
}

int main(){
  un char aux[1010][1010];
  memset(dp, -1, sizeof(dp));
  memset(display, 0, sizeof(display));
  cin >> n >> m >> x >> y;
  getchar();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      aux[i][j] = getchar();
    }
    getchar();
  }

  for(int j=0; j<m; j++){
    for(int i=0; i<n; i++){
      if(aux[i][j] == '#') display[j][1]++;
      else display[j][0]++;
    }
  }

  

  cout << min(solve(0,0,0),solve(0,0,1)) << endl;

  return 0;
}