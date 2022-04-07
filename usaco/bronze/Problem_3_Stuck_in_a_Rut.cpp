#include <bits/stdc++.h>

using namespace std;

int OO = (int)1e9+10;

struct Cow{
  bool dir;
  int x, y;
  priority_queue<pair<int, int>> nodes;

  void print(){
    if(nodes.empty()) cout << "Infinity" << endl;
    else cout << (-1*nodes.top().first) << endl;
  };
};

inline void printQ(priority_queue<pair<int,int> > q, int i = -1){
  cout << "Contenido en cola " << i << ":\n";
  while(q.size()){
    cout << "nodo identificado con: " << q.top().second << " choca en el tiempo: " << (-q.top().first) << endl;
    q.pop();
  }
  cout << endl;
}

inline void calcT(Cow *vaca, Cow *interferencia, priority_queue<pair<int,int> > *qAux, pair<int,int> newNode){


  int tMax = -1*newNode.first;
  int interferenciatMax = interferencia->nodes.size() ? -1*interferencia->nodes.top().first : OO;
  bool choca = false;
  int t = 0;

  t = vaca->dir ? interferencia->y - vaca->y : interferencia->x - vaca->x;
  if(vaca->dir != interferencia->dir){ //Diferente orientación.
    newNode.first = -t;
    if(interferenciatMax != -OO) t = min(t, interferenciatMax);
    if(t == tMax) choca = true;
    else if(vaca->dir && t > 0 && interferencia->x+t > vaca->x && vaca->x > interferencia->x){
      choca = true;
    }
    else if(!vaca->dir && t > 0 && interferencia->y+t > vaca->y && vaca->y > interferencia->y){
      choca = true;
    }
  }
  
  if(choca) qAux->push(newNode);
  return;
}

int main(){

  int n, x, y, qsize;
  bool cambioIter, cambioGlobal;
  char dir;
  Cow vaca, interferencia;

  cin >> n;
  Cow vacas[n];
  for(int i=0; i<n; i++){
    cin >> dir >> vaca.x >> vaca.y;
    vaca.dir = dir == 'N';
    vacas[i] = vaca;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) if(j != i) vacas[i].nodes.push({OO ,j});
  }

  int contAux = 0;
  priority_queue<pair<int, int>> qAux;
  pair<int,int> node;
  do{
    cambioGlobal = false;
    contAux++;
    for(int i=0; i<n; i++){      
      qsize = vacas[i].nodes.size();
      while(vacas[i].nodes.size()){
        node = vacas[i].nodes.top(); //Nodo con menor peso.
        vacas[i].nodes.pop();

        interferencia = vacas[node.second];
        calcT(&vacas[i], &interferencia, &qAux, node);
      }

      if(qsize != qAux.size()) cambioGlobal = true;

      swap(vacas[i].nodes, qAux);
    }

  }while(cambioGlobal || contAux < 51);
  for(int i=0; i<n; i++){
    vacas[i].print();
  }

  

  return 0;
}