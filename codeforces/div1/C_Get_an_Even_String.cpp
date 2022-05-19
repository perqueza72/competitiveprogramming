#include <bits/stdc++.h>

using namespace std;


int main(){

  int n, index, cont;
  bool arr[26]{};
  string s;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> s;

    for(int i=0; i<26; i++) arr[i] = false;
    cont = 0;
    for(int j=0; j<s.length(); j++){
      index = s[j]-'a';
      if(arr[index]){
        // cout << index << ": " << s[j] << endl;
        cont+=2;
        for(int i=0; i<26; i++) arr[i] = false;
      }else{
        arr[index] = true;
      }
    }
    cout << (s.length()-cont) << "\n";
  }

  return 0;
}