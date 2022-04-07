#include <bits/stdc++.h>

using namespace std;

void getbits(int number){
  for(int i=0; i<21; i++)
    if((number & 1 << i)) cout << 1;
    else cout << 0;
  cout << endl;
}

int main(){

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int n, k, dato, cont = 0;
  cin >> k >> n;
  int arr[k][n];
  for(int i=0; i<k; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }

  int numbers[n+1]{}, aux;
  for(int i=0; i<n; i++){
    dato = arr[0][i];
    for(int j=i+1; j<n; j++) numbers[dato] |= (1<<arr[0][j]);
    // getbits(numbers[dato]);
    for(int group=1; group<k; group++){
      aux = 0;
      for(int cow=0; cow<n; cow++){
        if(arr[group][cow] == dato){
          for(int j=cow+1; j<n; j++) aux |= (1<<arr[group][j]);
          break;
        }
      }
      numbers[dato] &= aux;
    }
    for(int i=1; i<=n; i++) if((numbers[dato] & (1<<i))) cont++;
    

  }

  cout << cont << endl;

  // cout << numbers[dato] << endl;


  return 0;
}