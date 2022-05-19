#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, t, B, x, y, actual;
  long long sum;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> n >> B >> x >> y;
    sum = 0;
    actual = 0;

    for(int j=0; j<n; j++){
      actual+= x;
      if(B < actual){
        actual-=x;
        actual-=y;
      }
      sum+= actual;
    }

    cout << sum << "\n";
  }


  return 0;
}