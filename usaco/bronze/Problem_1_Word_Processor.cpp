#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);

  int n, k, cont = 0;
  string word;
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> word;
    cont+=word.length();
    if(cont == word.length()) printf("%s", word.c_str());
    else if(cont <= k) printf(" %s", word.c_str());
    else{
      printf("\n%s", word.c_str());
      cont = word.length();
    }

  }

  return 0;
}