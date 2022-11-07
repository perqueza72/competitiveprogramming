#include <bits/stdc++.h>

using namespace std;

const int SIZE = 26;

int main(){

  string s;
  cin >> s;
  if(s.size() < SIZE){
    cout << -1 << endl;
    return 0;
  }

  int arr[SIZE] = {0};
  int letters = 0, unk = 0;
  int c, prevC;

  for(int i=0; i<SIZE; i++){
    if(s[i] == '?'){
      unk++;
    }
    else{
      c = s[i]-'A';
      if(!arr[c]){
        letters++;
      }
      arr[c]++;
    }
  }

  int pos = 0;
  bool puede = false;

  if(letters+unk == SIZE)
      puede = true;

  for(int i=SIZE; i<s.size(); i++){
    if(s[i-SIZE] == '?') unk--;
    else{
      prevC = s[i-SIZE]-'A';
      arr[prevC]--;
      if(!arr[prevC]) letters--;
    }

    if(s[i] == '?'){
      unk++;
    }
    else{
      c = s[i]-'A';
      if(!arr[c]){
        letters++;
      }
      arr[c]++;
    }

    if(letters+unk == SIZE){
      puede = true;
      pos = i+1-SIZE;
      break;
    }
  }

  if(!puede){
    cout << -1 << endl;
    return 0;
  }

  int arrPos = 0;
  for(int i=pos; i<SIZE+pos; i++){
    if(s[i] == '?'){
      for(int j=arrPos; j<SIZE; j++){
        if(!arr[j]){
          arrPos = j+1;
          s[i] = (char)(j+'A');
          arr[j]++;
          break;
        }
      }
    }
  }

  cout << endl;
  for(int i=0; i<s.size(); i++){
    if(s[i] == '?') s[i] = 'A';
  }

  cout << s << endl;
  return 0;
}