#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  if(n == 1){
    cin >> n;
    if(n == 1) cout << 2;
    else cout << 1;
    return 0;
  }

  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);

  int maxi = 1;

  bool change = false;
  for(int i=0; i<n-1; i++){
    if(maxi < arr[i] && !change){
      change = true;
      cout << maxi << " ";
    }
    cout << arr[i] << " ";
  }
  if(arr[n-1] == 1 && !change) cout << 2;
  else if(arr[n-1] != 1 && !change) cout << 1;
  
  return 0;
}