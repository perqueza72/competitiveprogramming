#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, aux, maxi;
  vector<int> arr;
  while(cin >> n, n){
    maxi = 0;
    arr.assign(101, 0);
    for(int i=0; i<n; i++){
      cin >> aux;
      maxi = max(aux, maxi);
      arr[aux]++;
    }

    for(int i=1; i<=100; i++){
      for(; arr[i]>0; arr[i]--){
        cout << i;
        if(i != maxi) cout << " ";
        else{
          if(arr[i] != 1) cout << " ";
        }
      }
    }
    cout << "\n";
  }

  return 0;
}