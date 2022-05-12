#include <bits/stdc++.h>

using namespace std;


string aux;
void eval(const char f){
  stack<int> v;
  char c;
  while(getline(cin, aux),c = aux[0], c != f && aux.length()){
    if(v.empty()){
      v.push(c);
    }
    else if(c == '(') v.push(c);
    else if(c == ')'){
      while(v.top() != '('){
        cout << (char)v.top();
        v.pop();
      }
      v.pop();
    }
    else if(c == '+' || c == '-'){
      while(v.size() && v.top() != '('){
        cout << (char)v.top();
        v.pop();
      }
      v.push(c);
    }
    else if(c == '*' || c == '/'){
      while(v.size() && v.top() != '+' && v.top() != '-' && v.top() != '('){
        cout << (char)v.top();
        v.pop();
      }
      v.push(c);
    }else v.push(c);
  }

  while(v.size()){
    cout << (char)v.top();
    v.pop();
  }
}

int main(){

  int t, cont = 0;
  cin >> t;
  getchar();
  getchar();
  while(t--){
    eval('\n');
    cout << "\n";
    if(t) cout << "\n";
  }


  return 0;
}