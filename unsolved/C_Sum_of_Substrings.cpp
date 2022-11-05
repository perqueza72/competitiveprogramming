#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){
    cin >> n >> k;
    cin >> s;
    for(int i=n-1; i>=0; i--){
      if(s[i] == '1'){
        s[i] = '0';
        resta= min(n-1-i, k);
        s[i+resta] = '1';
        k-=resta;
      }
    }

    sum = 0;
    aux = s[0];
    for(int i=1; i<n; i++){
      stoi(aux+s[i]);
    }
  }

  return 0;
}