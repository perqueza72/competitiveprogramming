#include <bits/stdc++.h>

using namespace std;

int main(){

  string s;
  char var;
  vector<char> q;
  cin >> s;
  for(int i=0; i<s.length(); i++){
    var = i;
    if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
      if(q.empty()) break;
      if(s[i] == '}'){
        if(q.back() != '{') break;
        q.pop_back();
      }else if(s[i] == ']'){
        if(q.back() != '[') break;
        q.pop_back();
      }else if(s[i] == ')'){
        if(q.back() != '(') break;
        q.pop_back();
      }
    }else q.push_back(s[i]);
  }

  if(q.size() || var != (s.length()-1)) cout << "false" << endl;
  else cout << "true" << endl;


  return 0;
}