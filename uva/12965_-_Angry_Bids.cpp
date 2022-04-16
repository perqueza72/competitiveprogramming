#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, aux, psize, csize, dir, angryC, angryP, angries, elputas;
  pair<int, int> mini;
  cin >> n;
  for(int i=0; i<n; i++){
    mini = {(int)1e9, (int)1e9};
    priority_queue<int> p,c;

    cin >> psize >> csize;
    for(int j=0; j<psize; j++){
      cin >> aux; p.push(aux);
    }
    for(int j=0; j<csize; j++){
      cin >> aux; c.push(aux);
    }

    if(!p.size()){
      cout << 0 << " " << 0 << "\n";
      continue;
    }
    if(!c.size()){
      cout << p.top() << " " << 0 << "\n";
      continue;
    }

    angryP = 0;
    angryC = csize-1;
    elputas = p.top();
    while(c.size()){
      if(p.top() <= c.top()){
        angries = angryP+angryC--;
        if(mini.first >= angries){
          mini.first = angries;
          mini.second = p.top();
        }
        c.pop();
      }else{
        p.pop();
        angryP++;
        if(!p.size()) break;
      }
    }
    
    if(mini.first >= psize){
      mini.first = psize;
      mini.second = 0;
    }
    if(mini.first > csize){
      mini.first = csize;
      mini.second = elputas;
    }

    cout << mini.second << " " << mini.first << "\n";
  }

  return 0;
}