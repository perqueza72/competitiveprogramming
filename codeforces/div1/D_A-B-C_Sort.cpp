#include <bits/stdc++.h>

using namespace std;

int main(){

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  int t, n, a, b;
  vector<int> q1, q2, r, v;
  cin >> t;
  while(t--){
    cin >> n;
    v.resize(n);
    r.resize(0);
    for(int i=0; i<n; i++) cin >> v[i];

    while(v.size() > 1){
      a = v.back();
      v.pop_back();
      b = v.back();
      v.pop_back();

      if(a < b){
        q1.push_back(a);
        q2.push_back(b);
      }else{
        q1.push_back(b);
        q2.push_back(a);
      }
    }

    if(v.size() == 1){
      r.push_back(v.back());
      v.pop_back();
    }

    while(q1.size() || q2.size()){

      if(q1.size()) a = q1.back();
      else a = 1e8;
      if(q2.size()) b = q2.back();
      else b = 1e8;

      if(a < b){
        q1.pop_back();
        r.push_back(a);
        q2.pop_back();
        r.push_back(b);
      }else{
        q2.pop_back();
        r.push_back(b);
        q1.pop_back();
        r.push_back(a);
      }
    }

    if(is_sorted(r.begin(), r.begin()+n)){
      cout << "YES\n";
    }else cout << "NO\n";

    // for(int i=0; i<n; i++){
    //   cout << r[i] << " ";
    // }
    // cout << endl;
  }

  return 0;
}