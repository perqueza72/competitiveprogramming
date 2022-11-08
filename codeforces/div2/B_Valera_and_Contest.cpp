#include <bits/stdc++.h>

using namespace std;

void printV(int sk, int k){
  if(k == 0) return;
  int add = sk%k;
  int value = sk/k;

  for(int i=0; i<add; i++){
    cout << (value+1) << " ";
  }

  for(int i=add; i<k; i++){
    cout << (value) << " ";
  }
}

int main(){

  int n, k , l, r, sall, sk, srest, rest;
  cin >> n >> k >> l >> r >> sall >> sk;
  srest = sall - sk;
  rest = n - k;

  printV(sk, k);
  printV(srest, rest);

  return 0;
}