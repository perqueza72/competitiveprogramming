#include <bits/stdc++.h>

using namespace std;

int main(){

  int k, n, capacidad, resto;
  cin >> n >> k;
  
  capacidad = n/k;
  if(capacidad >= 3){
    for(int i=1; i<=k; i++){
      for(int j=1; j<capacidad; j++){
        cout << i << " ";
      }
    }
    for(int i=1; i<=k; i++) cout << i << " ";
    resto = n - capacidad*k;
    for(int i=0; i<resto; i++){
      cout << k << " ";
    }
  }else cout << -1 << endl;
}