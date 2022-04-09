#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  vector<string> v(n);
  char chars[256] = {0};
  for(int i=0; i<n; i++){
    cin >> v[i];
    chars[v[i][0]] = 1;
  }

  bool puede;
  for(int i=0; i<n; i++){
    puede = true;
    for(int j=0; j<v[i].length(); j++){
      if(chars[v[i][j]] == 0){
        puede = false;
        break;
      }
    }

    if(puede) break;
  }

  if(puede) cout << "Y";
  else cout << "N";

  cout << endl;



  return 0;
}