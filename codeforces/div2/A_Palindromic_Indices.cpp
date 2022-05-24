#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, cont;
  string s;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    cin >> s;
    cont = 0;
    for(int i=n/2, j=(n+1)/2; j<n; i--, j++){
      if(s[i] == s[j]){
        if(i != j) cont++;
        cont++;
      }else break;
    }

    cout << (cont+1) << "\n";
  }

  return 0;
}