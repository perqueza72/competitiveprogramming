#include <bits/stdc++.h>

using namespace std;

int main(){

  int k, pos;
  string n, newN;
  char maxi;
  cin >> n >> k;
  
  while(k > 0 && n.length() > 0){

    maxi = 0;
    for(int i=0; i<n.length() && i<=k; i++){
      if(n[i] > maxi){
        maxi = n[i];
        pos = i;
      }
    }
    k-=pos;
    newN+= maxi;
    n.erase(n.begin()+pos);
  }

  cout << newN << n << endl;


  return 0;
}