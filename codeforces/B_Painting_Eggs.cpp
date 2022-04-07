#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, a, g, aC=0, gC=0;
  cin >> n;

  for(int i=0; i<n; i++){
    scanf("%i", &a);
    scanf("%i", &g);
    if(0 < g-a + 2*(gC-aC)){
      aC+= a;
      putchar('A');
    }else{
      gC+= g;
      putchar('G');
    }
  }
  cout << endl;

  return 0;
}