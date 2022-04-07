#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);

  int n, pos, aux, cont = 0;
  bool maxi;
  vector<int> h, copia;
  cin >> n;

  cin >> aux;
  h.push_back(aux);
  for(int i=1; i<n; i++){
    cin >> aux;
    if(h.back() != aux) h.push_back(aux);
  }
  n = h.size();
  

  is_sorted(h.begin(), h.end());

  for(int i=0; i<n; i++){
    if(i == 0 && h[i] > h[i+1] || i == n-1 && h[i-1] < h[i] || i > 0 && i <n-1 && h[i-1] < h[i] && h[i] > h[i+1]){
      // printf("%d",*(h.begin()+i+1));
      copia.reserve(n-1);
      copia.insert(copia.end(), h.begin(), h.begin()+i);
      copia.insert(copia.end(), h.begin()+i+1, h.end());
      if(is_sorted(copia.begin(), copia.end())){
        maxi = true;
        pos = i;
        break;
      }
      else{
        maxi = false;
        pos = i+1;
        break;
      }
    }
  }

  // printf("pos %d: %d\n", pos, h[pos]);
  if(maxi){
    for(int i=pos+1; i<n; i++){
      if(h[pos] > h[i]) cont++;
    }
  }else{
    for(int i=pos-1; i>=0; i--){
      if(h[pos] < h[i]) cont++;
    }
  }

  cout << cont << endl;


  return 0;
}