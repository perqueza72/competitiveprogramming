#include <bits/stdc++.h>

using namespace std;

const bool LEFT = 0, RIGTH = 1;

int main(){

  int leave[10100], arr[10100];
  vector<queue<int> > orilla(2);
  int cases, n, t, m, tl, te, space, cont;
  bool dir, siteBoat;
  string site;

  cin >> cases;
  while(cases--){
    cin >> n >> t >> m;
    cont = 0;
    for(int i=0; i<m; i++){
      cin >> te >> site;
      if(site == "left") orilla[LEFT].push(i);
      else orilla[RIGTH].push(i);
      arr[i] = te;
    }


    siteBoat = LEFT;
    while(orilla[LEFT].size() || orilla[RIGTH].size()){

      if(orilla[LEFT].empty())          dir = RIGTH;
      else if(orilla[RIGTH].empty())    dir = LEFT;
      else{
        if(arr[orilla[LEFT].front()] == arr[orilla[RIGTH].front()] || arr[orilla[siteBoat].front()] <= cont){
          dir = siteBoat;
        }
        else if(arr[orilla[LEFT].front()] < arr[orilla[RIGTH].front()]){
          dir = LEFT;
        }else{
          dir = RIGTH;
        }
      }
      tl = arr[orilla[dir].front()];


      space = n;
      if(siteBoat == dir){
        cont = max(cont, tl);
      }else{
        if(tl < cont) cont += t;
        else cont = tl+t;
      }

      while(space && orilla[dir].size() && arr[orilla[dir].front()] <= cont){
        space--;
        leave[orilla[dir].front()] = cont + t;
        orilla[dir].pop();
      }

      cont+=t; //Add time to travel to destination.
      siteBoat = !dir; //Move to car siteBoat needed.
    }

    for(int j=0; j<m; j++) cout << leave[j] << "\n";
    if(cases) cout << endl;
  }
    

  return 0;
}