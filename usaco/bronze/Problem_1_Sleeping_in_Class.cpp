#include <bits/stdc++.h>

using namespace std;

int v[(int)1e5];

vector<int> get_values(int n){
  vector<int> factorization;
  if(n == 0){
    factorization.push_back(0);
    return factorization;
  }

  for(int i=1; i*2<=n; i++){
    if(n%i == 0) factorization.push_back(i);
  }

  return factorization;
}

int main(){

  int t, n, cambios, sum, total, mini = 1e8;
  bool puede;
  vector<int> primes;
  cin >> t;

  while(t--){

    mini = 1e8;
    total = 0;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> v[i];
      total+=v[i];
    }


    primes = get_values(total);
    for(int value : primes){
      puede = true;
      cambios = 0;
      sum = 0;

      for(int i=0; i<n; i++){
        sum+= v[i];
        cambios++;

        if(value == sum){
          // cout << "cambio-- " << i << endl;
          cambios--;
          sum = 0;
        }else if(value < sum){
          // cout << "exit " << sum << endl;
          puede = false;
          break;
        }

      }

      if(sum == 0 && puede){
        mini = min(cambios, mini);
      }
    }
    mini = min(mini, n-1);
    cout << mini << endl;
    
  }

  return 0;
}