#include <bits/stdc++.h>

using namespace std;

int main(){

  int P, n, sum, ans=0;
  cin >> n;
  int petals[n];
  for(int i=0; i<n; i++) cin >> petals[i];

  for(int i=0; i<n; i++){
    sum = 0;
    for(int j=i; j<n; j++){
      sum+=petals[j];
      if(sum%(1+j-i) == 0){
        P = sum/(1+j-i);
        for(int k=i; k<=j; k++){
          if(P == petals[k]){
            ans++;
            break;
          }
        }
      }
    }
  }

  cout << ans;
  

  return 0;
}