#include <bits/stdc++.h>

using namespace std;

struct edge{
  int origin;
  int end;
  int weigth;
};

bool operator<(const edge &a, const edge &b){
  if(a.weigth < b.weigth) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, cont = 0, t, w, sum = 0, aux, k, nodo;
  priority_queue<edge> pq;
  edge e;
  vector<bool> visited;
  vector<vector<edge> > grafo;

  while(cin >> n){
    grafo.assign(n+1, vector<edge>()); 
    visited.assign(n+1, false);
    pq = priority_queue<edge>();
    sum = 0;

    for(int i=1; i<n; i++){
      cin >> e.origin >> e.end >> e.weigth;
      sum+= e.weigth;
      grafo[e.origin].push_back(e);
      aux = e.end;
      e.end = e.origin;
      e.origin = aux;
      grafo[e.end].push_back(e);

    }
    e.origin = e.end;
    e.weigth = 0;
    pq.push(e);
    cout << sum << "\n";

    cin >> k;
    for(int i=0; i<k; i++){
      cin >> e.origin >> e.end >> e.weigth;
      grafo[e.origin].push_back(e);
      aux = e.end;
      e.end = e.origin;
      e.origin = aux;
      grafo[e.end].push_back(e);
    }

    cin >> t;
    for(int i=0; i<t; i++) cin >> aux >> aux >> aux;

    sum = cont = 0;
    while(pq.size() && cont < n){

      nodo = (pq.top()).end;
      w = (pq.top()).weigth;
      pq.pop();
      if(visited[nodo]) continue;
      visited[nodo] = true;
      cont++;
      sum+= w;

      for(int i=0; i<grafo[nodo].size(); i++){
        pq.push(grafo[nodo][i]);
      }
    }

    cout << sum << "\n\n";
  }



  return 0;
}