#include <bits/stdc++.h>

using namespace std;

bool check(const string &s){
  vector<char> v;
  for(auto c : s){
    if(c == '(' || c == '[') 
      v.push_back(c);
    else if(c == ')' && v.size()){
        if(v.back() != '(') return false;
        v.pop_back();
    }
    else if(c == ']' && v.size()){
      if(v.back() != '[') return false;
      v.pop_back();
    }else return false;
  }

  return v.empty();
}

int main(){

  int n;
  string s, r;
  cin >> n;
  getchar();
  for(int i=0; i<n; i++){
    getline(cin, s);
    r = check(s) ? "Yes" : "No";
    cout << r << "\n";
  }


  return 0;
}