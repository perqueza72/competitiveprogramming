#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, m, ans = 0, diff = 0, aux, aux1;
  cin >> n >> m;
  int a[1000001] = {0}, b[1000001] = {0}, sum[1000001] = {0};
  for(int i=0; i<n; i++){
    cin >> aux1;
    a[aux1]++;
  }
  for(int i=0; i<m; i++){
    cin >> aux;
    b[aux]++;
  }
  int antPos = max(aux1,aux);
  aux1 = antPos;
  for(int i=aux1; i>0; i--){
    if(b[i]){
      sum[i] += sum[antPos] + b[i];
      antPos = i;
    }
    diff = a[i] - sum[antPos];
    
    if(diff > 0){
      ans+=diff;
      sum[antPos] = 0;
    }else sum[antPos]-=a[i];
    
  }

  cout << ans << endl;

  return 0;
}