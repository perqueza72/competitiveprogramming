#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, aux;
  cin >> s;
  
  
  vector<int> permutation;
  for (int i = 0; i < s.length(); i++) {
  permutation.push_back(i);
  }

  set<string> se;
  do {
    aux = "";
    for(int i=0; i<permutation.size(); i++){
      aux += s[permutation[i]];
    }
    se.insert(aux);
  } while (next_permutation(permutation.begin(),permutation.end()));

  cout << se.size() << "\n";
  for(auto dato: se){
    cout << dato << "\n";
  }  


  return 0;
}