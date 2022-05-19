#include <bits/stdc++.h>

using namespace std;

int dp[(int)1e4+10];
int n, m;

int main(){

  cin >> n >> m;
  memset(dp, -1, sizeof(dp));

  queue<pair<int,int>> q;
  q.push(make_pair(n, 0));
  pair<int,int> x;

  while(q.size()){
    x = q.front();
    q.pop();
    if(dp[x.first] != -1) continue;
    dp[x.first] = x.second;

    if(x.first*2 <= 10000) q.push(make_pair(x.first*2, x.second+1));
    if(x.first > 1) q.push(make_pair(x.first-1, x.second+1));
  }
  cout << dp[m] << endl;

  return 0;
}