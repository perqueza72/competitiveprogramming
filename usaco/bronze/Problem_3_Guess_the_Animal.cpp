#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  map<string,int> mapita;
  string s;
  int n, t;
  cin >> n;
  vector<vector<string> > v(n);
  for(int i=0; i<n; i++){
    cin >> s >> t;
    for(int j=0; j<t; j++){
      cin >> s;
      v[i].push_back(s);
      if(mapita.find(s) == mapita.end()) mapita.insert(make_pair(s,1));
      else mapita[s]++;
    }
  }

  vector<set<string> > cosaInmunda(n);

  int diferentes = 0, cont;
  for(int i=0; i<n; i++){
    cont = 0;
    for(int j=0; j<v[i].size(); j++){
      if(mapita[v[i][j]] > 1){
        cosaInmunda[i].insert(v[i][j]);
        cont++;
      }
    }
    
  }

  for(int i=0; i<n; i++){
    auto cosa = cosaInmunda[i];
    for(int j=0; j<n; j++){
      if(j == i) continue;
      cont = 0;
      for(auto value : cosa){
        if(cosaInmunda[j].count(value)){
          cont++;
        }
      }
      diferentes = max(diferentes, cont);
    }
  }

  cout << (diferentes+1) << endl;

  return 0;
}