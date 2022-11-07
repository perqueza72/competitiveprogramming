#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9+7;
long long pow(long long b, long long e){
  long long r = 1;
  b%=MOD;
  for(long long i=0; i<64; i++){
    if(e&(1ll<<i)){
      r=(r*b)%MOD;
    }
    b=(b*b)%MOD;
  }

  return r%MOD;
}

int main(){

  long long n;
  cin >> n;
  long long r = (pow(3ll, 3ll*n)-pow(7ll, n)+MOD)%MOD;
  cout << r << endl;

  return 0;
}