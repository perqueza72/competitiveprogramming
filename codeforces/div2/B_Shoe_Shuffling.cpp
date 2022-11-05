#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, t, a, ant, cont;
  bool xd;
  deque<int> v, r, p;
  cin >> t;
  while(t--){
    cin >> n;
    xd = true;
    v.resize(n);
    p = r = deque<int>(0);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    // sort(v.begin(), v.end());

    ant = v[0];
    r.push_back(1);
    for(int i=1; i<n; i++){
      if(v[i] == ant){
        r.push_back(i+1);
      }
      else{
        if(r.size() <= 1){
          xd = false;
          break;
        }

        a = r.front();
        r.pop_front();
        r.push_back(a);

        while(r.size()){
          a = r.front();
          r.pop_front();
          p.push_back(a);
        }

        ant = v[i];
        r.push_back(i+1);

      }
    }

    if(r.size() == 1 || xd == false){
      cout << -1 << "\n";
      r = deque<int>(0);
      continue;
    }

    if(r.size()){
      a = r.front();
      r.pop_front();
      r.push_back(a);
    }

    while(r.size()){
      a = r.front();
      r.pop_front();
      p.push_back(a);
    }

    for(auto &u : p){
      cout << u << " ";
    }
    cout << "\n";

  }

  return 0;
}