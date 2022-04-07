#include <bits/stdc++.h>


using namespace std;

int main(){

  int TAM = 50010;
  int t,q,lady[TAM], pos = 1, n, aux=0;

  cin >> t;
  cin >> lady[aux];
  for(int i=1; i<t; i++){
    cin >> aux;
    if(aux == lady[pos-1]) continue;
    lady[pos] = aux;
    pos++;
  }

  cin >> q;
  string s1, s2;
  for(int i=0; i<q; i++){
    cin >> n;
    int *dato = upper_bound(lady,lady+pos, n);
    if(lady+pos == dato) s2 = "X\n";
    else s2 = to_string(*dato) + "\n";
    do{
      dato--;
    }while(dato>=lady && *dato == n);

    if(dato < lady) s1 = "X ";
    else s1 = to_string(*dato) + " ";
    cout << s1 << s2;
  }

  return 0;
}