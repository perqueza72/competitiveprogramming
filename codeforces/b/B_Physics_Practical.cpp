#include <bits/stdc++.h>

using namespace std;


deque<pair<int, int> > dq;
int dp[5010][5010];
int n;

int solve(int posMax, int posMin){

  int mini = dq[posMin].first;
  int maxi = dq[posMax].first;
  if(mini*2 >= maxi) return 0;

  int &ans = dp[mini][maxi];
  if(ans != -1) return ans;

  ans = min(dq[posMin].second + solve(posMax, posMin+1), dq[posMax].second + solve(posMax-1, posMin));
  return ans;
}

int main(){

  ifstream cin;
  cin.open("input.txt");
  ofstream cout("output.txt");
  int datoSize = 5010, aux;
  int dato[datoSize];
  memset(dato, 0, sizeof(dato));
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> aux;
    dato[aux]++;
  }

  for(short i=0; i<datoSize; i++){
    if(dato[i]) dq.push_back(make_pair(i, dato[i]));
  }

  cout << solve(dq.size()-1,0) << endl;

  return 0;
}