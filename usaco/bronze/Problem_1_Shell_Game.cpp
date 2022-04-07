#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int a,b,r,n, temp;
  cin >> n;
  array<int,3> arr = {0,1,2}, ans{};
  for(int i=0; i<n; i++){
    cin >> a >> b >> r;
    a--;
    b--;
    r--;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    ans[arr[r]]++;
  }

  cout << *max_element(ans.begin(), ans.end()) << endl;

  return 0;
}