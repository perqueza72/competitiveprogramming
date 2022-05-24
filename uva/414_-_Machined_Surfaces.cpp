#include <bits/stdc++.h>

using namespace std;

int main(){

  string s;
  vector<int> v;
  int maxi, n, cont, r;
  while(cin >> n, n){
    getchar();
    v.resize(0);
    maxi = 0;
    r = 0;
    for(int i=0; i<n; i++){
      getline(cin, s);
      cont = 0;
      for(auto c : s){
        if(c == 'X') cont++;
      }
      
      v.push_back(cont);
    }

    maxi = *max_element(v.begin(), v.end());
    // printf("maxi: %d\n", maxi);
    for(auto u : v){
      // printf("maxi %d - u %d: %d\n", maxi, u, maxi-u);
      r+= maxi-u;
    }

    cout << r << "\n";
    


  }


  return 0;
}