#include <bits/stdc++.h>

using namespace std;


const int tMax = 100;
int main(){

  int n, M, cont, acum, v, sum = 0;
  cin >> n >> M;
  int arr[n];
  int hash[tMax+1]{};
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  for(int i=1; i<=n; i++){
    sum+= arr[i];
    // cout << "sum: " << sum << endl;
    cont = 0;
    if(sum > M){
      acum = sum-M;
      // cout << "here" << endl;
      for(int j=tMax; j>0; j--){
        if(!hash[j]) continue;

        v = (acum +j-1)/j; //ceil
        // cout << "v: " << v << " " << sum << endl;
        // cout << v << endl;
        if(v > hash[j]){
          cont+= hash[j];
          acum-= hash[j]*j;
        }
        else{
          cont+= v;
          break;
        }
      }
    }

    hash[arr[i]]++;
    cout << cont << " " ;
    
  }

  return 0;
}