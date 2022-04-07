#include <bits/stdc++.h>

using namespace std;


inline void getDatos(const int *c, int *m1, int *m2){
  int aux = *m1;
  *m1 = max(0, aux+*m2-*c);
  *m2 = min(*c, *m2+aux);
}

int main(){

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  int c[3], m[3];
  for(int i=0; i<3; i++){
    cin >> c[i] >> m[i];
  }

  int a, b, aux;
  for(int i=1; i<101; i++){
    a = (i-1)%3;
    b = i%3;

    getDatos(c+b, m+a, m+b);
  }


  for(int i : m){
    cout << i << endl;
  }


  return 0;
}