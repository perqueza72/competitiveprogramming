#include <bits/stdc++.h>

using namespace std;

int n;
int OO = -1;
int dp[(int)1e5+10][3];
int tree[(int)1e5+10], heigth[(int)1e5+10];

int solve(int i, int side){

  if(i == n+1) return 0;
  int &ans = dp[i][side];
  if(ans != OO) return ans;

  if(side == 2){ //rigth

    if(tree[i-1] + heigth[i-1] >= tree[i]){
      //cout << "arbol que intentan estripar: " <<  tree[i] << endl;
      //cout << "i: " << i << endl << endl;
      ans = -(int)1e9; //No se puede tirar porque tiene uno encima.
      return ans;
    }
    else if(tree[i-1] + heigth[i-1] < tree[i] - heigth[i])
      ans = max( 1 + solve(i+1, 1), 1 + solve(i+1,2));
    else ans = 1 + solve(i+1,2);
    ans = max(solve(i+1, 0), ans);

  }else if(side == 1){ //left
    if(tree[i-1] < tree[i] - heigth[i])
      ans = 1 + max(solve(i+1, 1), solve(i+1,2));
    else ans = 1 + solve(i+1,2);
      ans = max(solve(i+1, 0), ans);
    
  }else{ //Dont fell
    if(tree[i-1] < tree[i] - heigth[i])
      ans = 1 + max(solve(i+1, 1), solve(i+1,2));
    else ans = 1 + solve(i+1,2);
      ans = max(solve(i+1, 0), ans);
  }

  return ans;
}

int main(){

  memset(dp, OO, sizeof(dp));
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> tree[i] >> heigth[i];
  }
  tree[0] = tree[1] - heigth[1] - 100;
  heigth[0] = 0;
  cout << solve(1,0) << endl;

  return 0;
}