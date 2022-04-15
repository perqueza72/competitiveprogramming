#include <bits/stdc++.h>

using namespace std;

vector<int> get_primes(int n){

  bool is_prime[n+1];
  for(int i=2; i<=n; i++) is_prime[i] = true;

  is_prime[0] = is_prime[1] = false;
  for(int i=4; i<=n; i+=2){
    is_prime[i] = false;
  }
  for(int i=3; i*i<=n; i+=2){
    if(is_prime[i]){
      // cout << i*i << endl;
      for(int j=i*i; j<=n; j+=i){
        is_prime[j] = false;
      }
    }
  }

  vector<int> res;
  res.push_back(2);
  for(int i=3; i<=n; i+=2){
    if(is_prime[i]) res.push_back(i);
  }

  return res;
}

int main(){

  vector<int> prime = get_primes((int)1e6);
  // for(auto p : prime){
  //   cout << p << endl;
  // }
  long long cont;
  int combinaciones, n, t = 0;
  auto pos = prime.begin();
  while(cin >> n, n){
    cont = 0;
    t++;
    for(int i=0; i<prime.size(); i++){
      pos = lower_bound(prime.begin()+i, prime.end(), n-prime[i]);
      if(*pos+prime[i] > n) --pos;

      combinaciones = pos-(prime.begin()+i);
      combinaciones = max(0, combinaciones);

      if(!combinaciones) break;
      cont += combinaciones;
    }

    printf("Case %d: %lld\n",t, cont);
  }

  

  return 0;
}