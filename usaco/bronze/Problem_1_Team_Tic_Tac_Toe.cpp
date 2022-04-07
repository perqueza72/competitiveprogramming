#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  vector<string> s(3, "000");
  int individual = 0, dual = 0;
  set<string> xd;
  for(int i=0; i<3; i++){
    cin >> s[i];
  }

  vector<string> v(8, "");
  for(int i=0; i<3; i++){
    for(int j=0, k=3; j<3; j++, k++){
      if(v[j].find(s[i][j])  == string::npos) v[j].push_back(s[i][j]);
      if(v[k].find(s[j][i])  == string::npos) v[k].push_back(s[j][i]);
    }
  }

  for(int i=0, j=i, k=2-i; i<3; i++, j++, k--){
    if(v[6].find(s[i][j])  == string::npos) v[6].push_back(s[i][j]);
    if(v[7].find(s[i][k])  == string::npos) v[7].push_back(s[i][k]);
  }

  for(int i=0; i<8; i++) sort(v[i].begin(), v[i].end());
  for(int i=0; i<8; i++) xd.insert(v[i]);
  for(auto dato : xd){
    if(dato.length() == 1) individual++;
    if(dato.length() == 2) dual++;
  }
  cout << individual << endl << dual << endl;

  return 0;
}