#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  long long ans = 1e10, a, b;
  int num[n];
  for(int i=0; i<n; i++){
    cin >> num[i];
  }

  for(long long i=0; i<=(1 << n); i++){
    a = b = 0;
    for(int j=0; j<n; j++){
      if((1 << j) & i) a+= num[j];
      else b+= num[j];
    }
    ans = min(ans, abs(a-b));
  }

  cout << ans << endl;

  return 0;
}