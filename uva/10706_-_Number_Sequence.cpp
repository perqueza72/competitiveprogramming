#include <bits/stdc++.h>

using namespace std;

int main(){

  const unsigned int upperBound = 65536;
  unsigned int dato[upperBound], sum[upperBound];
  unsigned int cont = 10;
  int ceros = 1;
  dato[0] = 0;
  for(int i = 1; i<upperBound; i++){
    if(i/cont){
      cont*=10;
      ceros++;
    }
    dato[i] = dato[i-1]+ceros;
  } 

  int a = 0;
  sum[0] = 0;
  for(int i=1; i<upperBound; i++){
    sum[i]= dato[i-1] + sum[i-1];
  }

  unsigned int n, d, v, pos, aux;
  unsigned int *l, *u;
  string s;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> d;
    l = lower_bound(sum, sum+upperBound, d); // Get cluster
    --l;
    v = d-*l; //Get difference (position of digit needed)
    u = upper_bound(dato, dato+upperBound, v-1); //Get digit K-group
    aux = u-dato;
    s = to_string(aux); //Get number like string

    pos = *u - v; //Get position (front to back) to digit required.
    // cout << *l << " " << *u << " ";
    // cout << s << " " << pos << " ";
    cout << s[s.length() - pos -1] << "\n";
  }

  return 0;
}