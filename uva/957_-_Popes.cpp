#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, y, aux, year, maxi, a, b;
  bool first;
  vector<int> v;
  int arr[1000001];

  while(cin >> y){
    cin >> n;
    v.assign(1000001,0);
    for(int i=0; i<n; i++){
      cin >> aux;
      v[aux]++;
    }

    arr[1] = 0;
    for(int i=1; i<=y; i++) arr[1]+=v[i];
    
    maxi = arr[1];
    for(int i=2; i<=aux+1-y; i++){
      arr[i] = arr[i-1] - v[i-1] + v[i+y-1];
      if(maxi < arr[i]){
        maxi = arr[i];
        year = i;
      }
    }

    first = true;
    a = b = 0;
    for(int i=year; i<year+y; i++){
      if(v[i] != 0){
        if(first){
          first = false;
          a = i;
        }else b = i;
      }
    }
    if(b == 0 && a != 0) b = a;

    cout << maxi << " " << a << " " << b << "\n";

  }

  return 0;
}