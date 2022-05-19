#include <bits/stdc++.h>

using namespace std;

struct Dsu{
  vector<int> p;
  void init(int n){
    p.resize(n+1);
    for(int i=0; i<=n; i++) p[i] = i;
  }

  int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[a] = b;
  }

  int count(void){
    set<int> datos;
    int cont = 0;
    for(int i=1; i<p.size(); i++){
      datos.insert(find(i));
    }
    return datos.size();
  }

};

int main(){

  int t, n, m;
  string s, aux;
  Dsu *dsu = new Dsu();
  vector<bitset<101> > people;
  istringstream input2;
  int a, b, cont;

  cin >> t;
  getchar();
  getchar();
  while(t--){
    cin >> n >> m;
    getchar();

    people.assign(n+1, (bitset<101>()).none());

    while(getline(cin, s), cin.good() && s.size()){
      istringstream input2;
      input2.str(s);
      getline(input2, aux, ' ');
      a = stoi(aux);
      getline(input2, aux, ' ');
      b = stoi(aux);
      // cout << a << " " << b << endl;

      people[a][b] = 1;
    }

    dsu->init(n);
    for(int i=1; i<=n; i++){
      // cout << people[i] << endl;
      for(int j=i+1; j<=n; j++){
        if(people[i] == people[j]){
          dsu->merge(i, j);
        }
      }
    }

    cout << dsu->count() << "\n";
    if(t) cout << "\n";


  }

  return 0;
}