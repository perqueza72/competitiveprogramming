#include <bits/stdc++.h>

using namespace std;


double distance(int a, int a0, int y, int y0){
  double dato = (a-a0)*(a-a0)+(y-y0)*(y-y0);
  return sqrt(dato);
}

int main(){

  int n;
  double sum = 0, k;
  int a, a0, b, b0;
  cin >> n >> k;
  k/=50.0;
  cin >> a0 >> b0;
  for(int i=1; i<n; i++){
    cin >> a >> b;
    sum+= distance(a, a0, b, b0);
    a0 = a;
    b0 = b;
  }


  cout << fixed << setprecision(8) << (k*sum) << endl;

  return 0;
}