#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, first, second;
  string s;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s;
    first = (s[0]-'a')*25;
    second = (s[1]-'a')+1;
    if(s[1] > s[0]) second--;
    // if(first == )
    cout << (first+second) << "\n";
  }

  return 0;
}