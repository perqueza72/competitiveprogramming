#include <bits/stdc++.h>

using namespace std;

void printI(int n){
  for(int i=0; i<32; i++){
    if(n & (1<<i)) cout << 1;
    else cout << 0;

    if(i%8 == 7) cout << " ";

  }
  cout << endl;
}

int main(){

  int m, n, aux;

  while(cin >> m){
    n = m;
    // printI(m);;

    aux = 0;
    for(int i=0; i<8; i++){
      if(n & (1 << (i+24))){
        aux|=(1 << i);
      }

      n&= ~(1 << (i+24));
      if(n & (1 << i)){
        n|= (1 << (i+24));
      }

      n&= ~(1 << i);
      if(aux & (1 << i)){
        n|= (1 << i);
      }
    }

    aux = 0;
    for(int i=8; i<16; i++){
      if(n & (1 << (i+8))) aux|=(1 << i);

      n&= ~(1 << (i+8));
      if(n & (1 << i)){
        n|= (1 << (i+8));
      }

      n&= ~(1 << i);
      if(aux & (1 << i)){
        n|= (1 << i);
      }
    }

    // printI(n);


    printf("%d converts to %d\n", m, n);
  }



  


  return 0;
}