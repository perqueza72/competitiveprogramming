#include <bits/stdc++.h>


using namespace std;

int main(){

  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  string line[n];
  for(int i=0; i<n; i++){
    cin >> line[i];
  }

  string s;
  for(int i=0; i<n; i++){
    s = "";
    for(int j=0; j<m; j++){
      for(int l=0; l<k; l++){
        s+= line[i][j];
      }
    }
    for(int l=0; l<k; l++){
      cout << s << "\n";
    }

  }

  return 0;
}