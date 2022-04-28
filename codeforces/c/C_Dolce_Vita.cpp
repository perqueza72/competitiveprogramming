#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, t, x, days, lastDay;
  long long cont,*r, arr[(int)1e6];
  cin >> t;
  while(t--){
    cin >> n >> x;
    
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=1; i<n; i++){
      arr[i] += arr[i-1];
    }

    cont = 0;
    r = arr+n;
    r = lower_bound(arr, r, x);

    if(r == (arr+n)  || *r > x) r--;
    if(r < arr){
      cout << cont << endl;
      continue;
    }

    cont+= r-arr+1;
    lastDay = 0;
    for(int i=r-arr+1; i> 0; i--){
      days = (x-arr[i-1])/i;
      cont+= (long long)(days-lastDay)*(long long)i;
      lastDay = days;
      // cout << cont << endl;
    }

    cout << cont << "\n";
  }


  return 0;
}