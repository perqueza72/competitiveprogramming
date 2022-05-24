#include <bits/stdc++.h>

using namespace std;

const bool VERBOUS = true, CONSONANT = false;

bool is_verbous(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

long long pow(long long a, long long b){
  long long r = 1;
  for(int i=0; i<b; i++){
    r+=a;
  }
  return r;
}

int main(){

  int t, n;
  bool expected = true, puede, start;
  long long letters[2], r;
  string s;
  cin >> t;
  for(int j=0; j<t; j++){
    cin >> s;
    n = s.length();
    puede = true;
    start = false;
    letters[0] = letters[1] = 0;
    for(int i=0; i<n; i++){
      expected = !expected;
      // cout << s[i] << " " << expected << " " << letters[0] <<  " "<< letters[1] << endl;
      if(s[i] != '?'){
        if(!start){
          start = true;
          expected = is_verbous(s[i]);

          bool calc = expected;
          if(i%2) calc = !expected;
          letters[calc]+=(i+1)/2;
          letters[!calc]+=(i)/2;
        }else{ //If proccess has been started.
          if(is_verbous(s[i]) != expected){
            puede = false;
            break;
          }
        }
      }else if(start) letters[expected]++;
    }
    // cout << endl;

    // cout << "puede: " << puede << " " <<start << endl;

    if(puede){
      if(start) r = (pow(6, letters[VERBOUS])*pow(20, letters[CONSONANT]) );
      else r = (pow(20, (n+1)/2) * pow(6, n/2) + pow(20, n/2) * pow(6, (n+1)/2));
      printf("String #%d: %lld\n\n", j+1, r);
    }
    else printf("String #%d: 0\n\n", j+1);
  }

  return 0;
}