#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, m, x, mini, maxi, r, aux;
  vector<int> tower, response;
  vector<pair<int,int> > block;

  cin >> t;
  while(t--){
    cin >> n >> m >> x;
    block.resize(n);
    response.resize(n);
    tower.assign(m, 0);
    for(int i=0; i<n; i++){
      cin >> aux;
      block[i] = {aux, i};
    }
    sort(block.begin(), block.begin()+n);

    for(int i=0; i<n; i++){
      tower[i%m]+= block[i].first;
      response[block[i].second] = i%m+1;
    }
    mini = *min_element(tower.begin(), tower.begin()+m);
    maxi = *max_element(tower.begin(), tower.begin()+m);
    r = maxi - mini;
    if(r <= x){
      cout << "YES\n";
      for(int i=0; i<n; i++) cout << response[i] << " ";
    }else cout << "No";
    cout << "\n"; 
  }

  return 0;
}