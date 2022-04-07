#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string subString, s, add;
  int ssize;
  queue<char> q;
  
  cin >> s >> subString;
  for(int i=0; i<s.length(); i++) q.push(s[i]);
  s = "";
   
  ssize = subString.length()-1;
  while(q.size()){
    s.push_back(q.front());
    q.pop();
    for(int i=0; i<=ssize; i++){
      if(s.empty() || s.back() != subString[ssize-i]){
        while(add.size()){
          s.push_back(add.back());
          add.pop_back();
        }
        break;
      }
      else{
        add.push_back(s.back());
        s.pop_back();
      }
    }
    add.clear();
  }

  cout << s << endl;

  return 0;
}