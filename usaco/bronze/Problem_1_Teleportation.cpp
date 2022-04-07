#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int a,b,c,d;
  cin >> a >> b >> c >> d;

  cout << min(abs(a-b), min(abs(a-c), abs(a-d)) + min(abs(c-b), abs(d-b))) << endl;

  return 0;
}