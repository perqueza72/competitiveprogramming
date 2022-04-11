#include <bits/stdc++.h>

using namespace std;

int main(){

  // freopen("badmilk.in", "r", stdin);
  // freopen("badmilk.out", "w", stdout);

  int n, m, d, s;
  cin >> n >> m >> d >> s;

  vector<vector<int> > v;
  vector<int> tupla(3);
  for(int i=0; i<d; i++){
    cin >> tupla[0]  >> tupla[1] >> tupla[2];
    v.push_back(tupla);
  }

  int persona;
  vector<int> sick(n+1,0);
  for(int i=0; i<s; i++) cin >> persona >> sick[persona];
  
  // cout << "XD" << endl;
  int tiempoEnfermacion;
  vector<int> milk(m+1,0);
  for(int i=0; i<d; i++){
    tiempoEnfermacion = sick[v[i][0]];
    if(tiempoEnfermacion == 0) continue;
    if(v[i][2] < tiempoEnfermacion){
      milk[v[i][1]]++;
      // cout << v[i][0] << endl;
    }
  }

  vector<int> contaminated;
  for(int i=0; i<milk.size(); i++) if(milk[i] >= s)
    contaminated.push_back(i);

  // cout << "milk";
  // for(auto a: milk){
  //   cout << a << endl;
  // }
  // cout << endl;


  int mType;
  for(int i=0; i<d; i++){
    if(sick[v[i][0]] != 0) continue;
    mType = v[i][1];
    for(int j=0; j<contaminated.size(); j++){
      if(mType == contaminated[j]) sick[v[i][0]] = 101; 
    }
  }
  
  int cont = 0;
  for(int dato : sick){
    cont+= dato != 0;
  }

  cout << cont << endl;
  
  return 0;
}