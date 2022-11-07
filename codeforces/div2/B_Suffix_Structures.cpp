#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(){
  int sL[26] = {0}, tL[26] ={0};
  cin >> s >> t;
  for(auto &c : s) sL[c-'a']++;
  for(auto &c : t) tL[c-'a']++;

  if(s.size() == t.size()){
    for(int i=0; i<26; i++){
      if(sL[i] != tL[i]){
        cout << "need tree" << endl;
        return 0;
      }
    }

    cout << "array" << endl;
  }
  else{
    if(s.size() < t.size()){
      cout << "need tree" << endl;
      return 0;
    }

    for(int i=0; i<26; i++){
        if(sL[i] < tL[i]){
          cout << "need tree" << endl;
          return 0;
        }
      }
    
    int l = 0;
    for(int i=0; i<s.size() && l < t.size(); i++){
      if(s[i] == t[l]) l++;
    }

    l == t.size() ?
      cout << "automaton" << endl
      :
      cout << "both" << endl;
  }
  return 0;
}