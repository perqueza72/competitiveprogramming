#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n, b,s,t;

  cin >> n;
  int times[1001]{};
  for(int i=0; i<n; i++){
    cin >> s >> t >> b;
    for(int j=s; j<t; j++){
      times[j]+= b;
    }
  }

  cout << *max_element(times, times+1001);

  return 0;
}