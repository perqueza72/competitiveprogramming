#include <bits/stdc++.h>

using namespace std;

int R, G, B;
int dp[201][201][201];
vector<int> r, g, b;

int solve(short x, short y, short z){

  int maxi = 0;
  if((x < 0 && y < 0) || (x < 0 && z < 0) || (y < 0 && z < 0)) return 0;
  if(dp[x+1][y+1][z+1] != -1) return dp[x+1][y+1][z+1];

  if(x >= 0 && y >= 0) maxi = max(maxi, r[x]*g[y] + solve(x-1, y-1, z  ));
  if(x >= 0 && z >= 0) maxi = max(maxi, r[x]*b[z] + solve(x-1, y  , z-1));
  if(y >= 0 && z >= 0) maxi = max(maxi, g[y]*b[z] + solve(x  , y-1, z-1));


  return dp[x+1][y+1][z+1] = maxi;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> G >> B;

  r.resize(R);
  g.resize(G);
  b.resize(B);

  for(unsigned char i=0; i<R; i++) cin >> r[i];
  for(unsigned char i=0; i<G; i++) cin >> g[i];
  for(unsigned char i=0; i<B; i++) cin >> b[i];

  sort(r.begin(), r.begin()+R);
  sort(g.begin(), g.begin()+G);
  sort(b.begin(), b.begin()+B);

  memset(dp, -1, sizeof(dp));
  cout << solve(R-1,G-1,B-1) << endl;

  return 0;
}