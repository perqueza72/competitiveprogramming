#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, pos, maxL, n, k;
  vector<int> s;
  char aux;
  cin >> t;
  while(t--){


    scanf("%d %d\n", &n, &k);

    maxL = 0;
    pos = n;
    s.resize(n);

    for(int i=0; i<n; i++){
      aux = getchar();
      s[i] = aux-'a';
    }

    for(int i=0; i<n; i++){
      if(s[i] <= k){
        maxL = max(s[i], maxL);
        s[i] = 0;
      }else{
        pos = i;
        break;
      }
    }

    for(int i=pos; i<n; i++) if(s[i] <= maxL) s[i] = 0;
    k = k-maxL;

    int l = 0, inflection = -1;
    if(pos < n){
      l = s[pos]-k;
      inflection = s[pos];
    }
    for(int i=pos; i<n; i++){
      if(s[i] <= inflection) s[i] = min(s[i], l);
    }

    for(int i=0; i<n; i++){
      printf("%c", s[i]+'a');
    }
    printf("\n");
    

  }

  return 0;
}