#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  short a, b, c, d;
  cin >> a >> b >> c >> d;
  bool arr[100] = {0};
  for(int i=c; i<d; i++){
    arr[i] = 1;
  }
  for(int i=a; i<b; i++){
    arr[i] = 1;
  }

  short cont = 0;
  for(int i=0; i<100; i++){
    if(arr[i]) cont++;
  }

  cout << cont << endl;

  return 0;
}