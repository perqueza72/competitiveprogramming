#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, n, cont, newValue, lValue;
  cin >> t;
  while(t--){
    cin >> n;

    newValue = lValue = cont = 0;
    cin >> lValue; 
    for(int i=1; i<n; i++){
      cin >> newValue;
      if(lValue > newValue){
        cont++;
        lValue = -1;
      }
      else lValue = newValue;
    }

    cout << cont << "\n";

  }

  return 0;
}