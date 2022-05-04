#include <bits/stdc++.h>

using namespace std;

int countA(string s){
  int cont = 0;
  for(int i=0; i<s.length(); i++){
    if(s[i] == 'a') cont++;
  }
  return cont;
}

long long powpicho(long long a, long long b){
  long long c = 1;
  for(int i=0; i<b; i++) c*=a;

  return c;
}

int main(){

  int t, a, b;
  string s, s2;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> s >> s2;

    a = countA(s);
    b = countA(s2);
    if(a && b && s2.length() > 1){
      cout << "-1\n";
    }
    else if(a && b && s2.length() == 1) cout << "1\n";
    else {
      cout << ((long long)powpicho(2,a)) << "\n";
    }
  }

  return 0;
}