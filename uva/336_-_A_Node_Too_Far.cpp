#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> seen;
vector<vector<int> > grafo;
int cases = 1;
void BFS(queue<int> &q){
  int r;
  int cont = 0;
  queue<int> next;

  k++;
  while(k--){
    while(q.size()){
      r = q.front();
      q.pop();
      if(seen[r]) continue;
      seen[r] = true;
      
      for(int i=0; i<grafo[r].size(); i++){
          next.push(grafo[r][i]);
      }
    }
    next.swap(q);
  }
}

int main(){
  int n, r, kAux;
  int a, b;
  long long readA, readB;
  while(cin >> n, n){
    map<long long, int> change;
    int cont = -1;
    grafo.assign(32, vector<int>(0));
    for(int i=0; i<n; i++){
      cin >> readA >> readB;
      if(!change.count(readA)) change.insert({readA, ++cont});
      a = change[readA];

      if(!change.count(readB)) change.insert({readB, ++cont});
      b = change[readB];

      // cout << a << " " << b << endl;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }

    int tam = change.size();
    while(cin >> readA >> k, readA || k){
      kAux = k;
      r = 0;
      seen.assign(32, false);

      queue<int> q;
      if(change.count(readA)){
        q.push(change[readA]);
        BFS(q);
      }

      for(int i = 0; i<seen.size(); i++) r+=seen[i];      
      printf("Case %d: %ld nodes not reachable from node %lld with TTL = %d.\n", cases++, change.size()-r, readA, kAux);
    }
  }

  return 0;
}