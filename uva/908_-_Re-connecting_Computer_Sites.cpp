#include <bits/stdc++.h>

using namespace std;

int n;

struct edge{
  int begin;
  int end;
  int w;

  edge(int begin, int end, int w){
    this->begin = begin;
    this->end = end;
    this->w = w;
  }

  edge(){
    this->begin = 0;
    this->end = 0;
    this->w = 0;
  }

  void operator() (int begin, int end, int w){
    this->begin = begin;
    this->end = end;
    this->w = w;
  }
};

bool operator<(const edge &a, const edge &b){
  if(a.w < b.w) return true;
  return false;
}

vector<int> p;

int dsu(int x){
  if(x == p[x]) return p[x];
  return p[x] = dsu(p[x]);
}

void merge(int a, int b){
  a = dsu(a);
  b = dsu(b);
  if(a != b){
    p[a] = b;
  }
}

vector<edge> v;

void kruskal(){
  int ejes = 0, sum = 0;
  edge e;
  sort(v.begin(), v.end());
  for(int i=0; i<v.size() && ejes < n-1; i++){
    e = v[i];
    if(dsu(e.begin) != dsu(e.end)){
      merge(e.begin, e.end);
      ejes++;
      sum+=e.w;
    }
  }

  cout << sum << "\n";
}

int main(){

  int sum, a, b, w, t, k, id = 0;
  edge e;

  while(cin >> n){
    if(id++) cout << "\n";
    p.resize(n+1);
    v.resize(0);
    for(int i=0; i<=n; i++){
      p[i] = i;
    }
    sum = 0;
    for(int i=1; i<n; i++){
      cin >> a >> b >> w;
      e(a,b,w);
      v.push_back(e);
      sum+= w;
    }
    cout << sum << "\n";
    sum = 0;
    v.resize(0);
    cin >> k;
    for(int i=0; i<k; i++){
      cin >> a >> b >> w;
      e(a,b,w);
      v.push_back(e);
    }
    cin >> t;
    for(int i=0; i<t; i++){
      cin >> a >> b >> w;
      e(a,b,w);
      v.push_back(e);
    }

    kruskal();
  }



  return 0;
}