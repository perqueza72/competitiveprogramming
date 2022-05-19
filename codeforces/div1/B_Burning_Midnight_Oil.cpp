#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

int n, k;

int calcN(long long v){
  long long cont = 1;
  int r, sum=v;
  do{
    cont*=k;
    r = v/cont;
    sum+= r;
  }while(r);

  return sum;
}

int bs(int lower, int upper){
  int mid = (upper+lower)/2;

  int nC = calcN(mid);
  if(n == nC) return mid;
  if(lower+1 == upper){
    int a = calcN(upper);
    int b = calcN(lower);
    
    if(b >= n) return lower;
    return upper;
  }
  if(n < nC) return bs(lower, mid);
  if(n>nC) return bs(mid+1, upper);

  return 0;
}

int main(){

  cin >> n >> k;
  cout << bs(1, MAX) << endl;
  // cout << calcN(4) << endl;

  return 0;
}