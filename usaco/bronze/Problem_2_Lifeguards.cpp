#include <bits/stdc++.h>

using namespace std;

int n, h[1000]{}, hashAux[1000]{};
int countHash(){
  int cont=0;
  for(int i=0; i<1000; i++) if(hashAux[i]) cont++;

  // cout << cont << endl;
  return cont;
}

int main(){

  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out","w",stdout);

  cin >> n;
  int init[n], ending[n];
  for(int i=0; i<n; i++){
    cin >> init[i] >> ending[i];
    for(int j=init[i]; j<ending[i]; j++) h[j]++;
  }

  int maxi = 0;
  for(int i=0; i<n; i++){
    copy(begin(h), end(h), begin(hashAux));
    for(int j=init[i]; j<ending[i]; j++) hashAux[j]--;
    maxi = max(countHash(), maxi);
  }

  cout << maxi << endl;

  return 0;
}