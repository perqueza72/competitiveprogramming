#include <bits/stdc++.h>

using namespace std;

struct Pos{
  int i;
  int j;
  int k;
  int deep = 0;

  Pos(){}

  Pos(int k, int n, int m, int deep = (int)1e8){
    this->i = n;
    this->j = m;
    this->k = k;
    this->deep = deep;
  }

  void operator()(int k, int n, int m){
    this->i = n;
    this->j = m;
    this->k = k;
  }

  void operator=(Pos p){
    this->i = p.i;
    this->j = p.j;
    this->k = p.k;
    this->deep = p.deep;
  }

  void print(){
    printf("capa: %d, %d %d, d: %d\n", k, i, j, deep);
  }
};


vector<vector<vector<int> > > grafo;
vector<pair<int,int> > nodes;
queue<Pos> positions;
queue<pair<int,int> > q, qAux;
int i, j;
int n, m, k;
pair<int,int> value;
Pos goal;

const int MURO = -1;

void neig(const int &i, const int &j){
  nodes.resize(0);
  if(i > 0) nodes.push_back({i-1,j});
  if(i<n-1) nodes.push_back({i+1, j});
  if(j > 0) nodes.push_back({i,j-1});
  if(j<m-1) nodes.push_back({i, j+1});
}

void bfs(const int &capa, int deep = 0){
  while(++deep && q.size()){
    // cout << "out\n\n";
    while(q.size()){
      value = q.front();
      q.pop();
      i = value.first;
      j = value.second;
      if(grafo[capa][i][j] != 0 && grafo[capa][i][j] <= deep) continue;
      // cout << capa << " " << i << " " << j << " " << deep << endl;
      grafo[capa][i][j] = deep;
      if(capa == goal.k && i == goal.i && j == goal.j){
        positions = queue<Pos>();
        return;
      }

      if(capa < k-1 && grafo[capa+1][i][j] != MURO) positions.push(Pos(capa+1, i, j, deep));
      if(capa && grafo[capa-1][i][j] != MURO) positions.push(Pos(capa-1, i, j, deep));
      neig(i, j);
      for(auto node : nodes){
        if(grafo[capa][node.first][node.second]) continue;
        qAux.push(node);
      }
    }
    qAux.swap(q);
  }
}

int main(){
  Pos pos, aux;
  char c;
  int a, r;
  while(cin >> k >> n >> m, k+n+m){
    getchar();
    grafo.assign(k, vector<vector<int> >(n, vector<int>(m, 0)));

    
    for(int i=0; i<k; i++){
      for(int j=0; j<n; j++){
        for(int l=0; l<m; l++){
          c = getchar();
          if(c == 'S') positions.push(Pos(i,j,l,0));
          if(c == 'E') goal(i,j,l);
          a = c == '#' ? -1 : 0;
          grafo[i][j][l] = a;
        }
        getchar();
      }
      getchar();
    }


    while(positions.size()){
      pos = positions.front();
      positions.pop();
      q = queue<pair<int,int> >();
      qAux = queue<pair<int, int> >();

      q.push({pos.i, pos.j});
      bfs(pos.k, pos.deep);

      // for(int i=0; i<positions.size(); i++){
      //   aux = positions.front();
      //   positions.pop();
      //   aux.print();
      //   positions.push(aux);
      // }
    }

    // cout << goal.i << " " << goal.j << " " << goal.k << endl;
    r = grafo[goal.k][goal.i][goal.j];
    if(r != MURO && r != 0)printf("Escaped in %d minute(s).\n", grafo[goal.k][goal.i][goal.j]-1);
    else printf("Trapped!\n");

  }



  return 0;
}