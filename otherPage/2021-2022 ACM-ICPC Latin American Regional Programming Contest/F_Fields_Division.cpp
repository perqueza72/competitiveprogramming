#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, m, a, b;
  int value;

  cin >> n >> m;
  vector<vector<int> > grafo(n);
  bool seen[n]{};

  for(int i=0; i<m; i++){
    cin >> a >> b;
    grafo[a-1].push_back(b-1);
    grafo[b-1].push_back(a-1);
  }

  queue<int> q;
  q.push(n-2);
  while(q.size()){
    value = q.front();
    q.pop();

    if(value == n-1 || seen[value]) continue;
    seen[value] = 1;

    for(auto node : grafo[value]){
      q.push(node);
    }
    
  }


  char A, B;
  if(seen[n-1]){
    A = 'A';
    B = 'B';
  }else{
    A = 'B';
    B = 'A';
  }

  for(int i=0; i<n; i++){
    if(seen[i]) cout << A;
    else cout << B;
  }
  cout << endl;

  return 0;
}