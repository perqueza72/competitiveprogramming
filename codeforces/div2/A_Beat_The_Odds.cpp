#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int t, n, par, impar, aux;
  cin >> t;
  while(t--){
    cin >> n;
    par = impar = 0;
    for(int i=0; i<n; i++){
      cin >> aux;
      if(aux&1) impar++;
      else par++;
    }
    
    cout << min(impar, par) << "\n";
    }
    
  
  
  return 0;
}