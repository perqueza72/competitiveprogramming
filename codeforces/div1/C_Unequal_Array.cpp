#include <bits/stdc++.h>

using namespace std;

int main(){

  int n,m;
  cin >> n;
  int dato[(int) 1e6];
  int mini = 1e8, maxi = 0;

  for(int i=0; i<n; i++){
    cin >> m;
    for(int j=0; j<m; j++){
      cin >> dato[j];
    }

    mini = 1e8, maxi = 0;
    for(int j=0; j<m-1; j++){
      if(dato[j] == dato[j+1]){
        mini = min(j+1, mini);
        maxi = max(j, maxi);
      }
    }

    if(maxi - mini == 0) cout << 1 << "\n";
    else if(mini == 1e8 || maxi-mini == -1) cout << 0 << "\n";
    else cout << (maxi-mini) << "\n";

  }


  return 0;
}