#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n;
  bool no_repetido;
  int as[256] = {0}, bs[256] = {0}, res[256] = {0};
  string a, b;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    for(int j=0; j<a.length(); j++) as[a[j]]++;
    for(int j=0; j<b.length(); j++) bs[b[j]]++;
    for(int j='a'; j<='z'; j++){
      res[j] += max(as[j], bs[j]);
      as[j] = 0;
      bs[j] = 0;
    }
  }

  for(int i='a'; i<='z'; i++){
    cout << (int)res[i] << "\n";
  }

  return 0;
}