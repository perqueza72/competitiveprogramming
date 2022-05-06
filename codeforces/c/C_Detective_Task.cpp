#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  string s;
  bool cero;
  int finalPos, pos;

  cin >> t;
  while(t--){
    cin >> s;
    finalPos = pos = -1;
    cero = false;
    for(int i=0; i<s.size(); i++){
      if(s[i] == '1' && !cero){
        pos = i;
      }
      if(s[i] == '0' && finalPos == -1){
        finalPos = i;
        cero = true;
      }
    }

    if(pos == -1 && finalPos == -1){
      cout << s.size() << "\n";
      continue;
    }
    if(finalPos == -1){
      cout << (s.size()-pos) << "\n";
      continue;
    }
    pos = max(pos, 0);
    finalPos = max(finalPos, 0);
    // cout << pos << " " << finalPos << endl;

    cout << (finalPos-pos+1) << "\n";
  }

  

  return 0;
}