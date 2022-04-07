#include <bits/stdc++.h>

using namespace std;

int is_prime[(int)1e5];
vector<int> is_primev;

void primes(){
  int maxi = (int) 1e9+10;
  memset(is_prime, -1, sizeof(is_prime));

  is_prime[0] = 0;
  is_prime[1] = 0;
  is_prime[2] = 1;
  is_primev.push_back(2);
  for(int i=4; i*i<maxi; i+=2){
    is_prime[i] = 0;
  }

  for(int i=3; i*i<maxi; i+=2){

    if(is_prime[i] == -1){
      is_primev.push_back(i);
      for(int j=i; j*j<maxi; j+=i){
        is_prime[i] = 0;
      }
      is_prime[i] = 1;
    }
  }

}


int main(){

  primes(); //SACAR PRIMOS
  string s;
  vector<string> cosas;
  long long number;
  while(cin >> s){
    cosas.push_back(s);
  }
  if(cosas.size() != 3){ //NUMEROS DIFERENTES A 3
    cout << 0 << endl;
    return 0;
  }

  for(int k=0; k<cosas.size(); k++){
    s = cosas[k];
    if(s.length() > 10){ //MENOR A 9e9
      cout << 0 << endl;
      return 0;
    }
    
    if(s[0] == '0'){ //NO LEADING ZEROS
      cout << 0 << endl;
      return 0;
    }

    for(int i=0; i<s.length(); i++){
      if(s[i] < '0' || s[i] > '9'){ //DIGITOS
        cout << 0 << endl;
        return 0;
      }
    }

    if(s.length() == 10 && s[0] > '1'){ //NO SE DESBORDE
      cout << 0 << endl;
      return 0;
    }
    number = stoi(s);

    if(k == 0){ //FIRST NUMBER
      if(number <= 3 ||  number > (int)1e9 || number%2){
        cout << 0 << endl;
        return 0;
      }
    }else if(number <= (int)1e9){
      if(number < (int)1e5){
        if(!is_prime[number]){
          cout << 0 << endl;
          return 0;
        }
      }else{
        for(int i=0; i<is_primev.size(); i++){
          if(number%is_primev[i] == 0){
            cout << 0 << endl;
            return 0;
          }
        }
      }
    }else{
      cout << 0 << endl;
      return 0;
    }

  }
  int a = stoi(cosas[0]);
  int b = stoi(cosas[1]);
  int c = stoi(cosas[2]);

  if(a == (b+c)) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}