#include <bits/stdc++.h>

using namespace std;

const int dd = (int)1e6+1;


vector<int> get_primes(int n){
  vector<bool> primes(n+1, true);
  vector<int> res;
  int nsqr = sqrt(n)+1;

  primes[0] = primes[1] = false;
  for(int i=4; i<=nsqr; i+=2){
    primes[i] = false;
  }

  for(int i=3; i<=nsqr; i+=2){
    if(primes[i]){
      for(int j=i*i; j<=n; j+=i){
        primes[j] = false;
      }
    }
  }

  res.push_back(2);
  for(int i=3; i<=nsqr; i+=2){
    if(primes[i]) res.push_back(i);
  }

  return res;
}

vector<int> primes = get_primes(11255840);

long long get_divisors(int n){
  long long ans = 1, cont;
  for(int i=0; i<primes.size() && i*i<=n; i++){
    cont = 1;
    while(n%primes[i] == 0){
      n/= primes[i];
      cont++;
    }
    ans*=cont;
  }
  if(n != 1) ans*=2;
  return ans;
}

int main(){
  
  int divisors[dd];
  divisors[0] = 1;
  for(int i=1; i<dd; i++){
    divisors[i] = divisors[i-1]+get_divisors(divisors[i-1]);
  }

  int n, A, B, ans;

  int *lower, *upper;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d\n", &A, &B);
    lower = lower_bound(divisors, divisors+dd, A);
    upper = lower_bound(divisors, divisors+dd, B);
    if(*lower < A) lower++;
    if(*upper > B) upper--;

    printf("Case %d: %ld\n", i+1, upper-lower+1);
  }


  // long long ans=1;
  // for(int i=0; i<1e6+1; i++){
  //   ans += divisors(ans);
  // }
  // cout << ans << endl;

  return 0;
}