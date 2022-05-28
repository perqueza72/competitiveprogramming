#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, a, b, aux, cont = 0;
  while(cin >> n, n){
    cont ++;
    a = b = 0;
    for(int i=0; i<n; i++){
      cin >> aux;
      a+= aux == 0;
      b+= aux != 0;
    }

    printf("Case %d: %d\n", cont, b-a);
  }

  
  return 0;
}