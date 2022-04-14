#include <bits/stdc++.h>

using namespace std;

int OO = 1e7;

int main(){

  
  pair<char, int> aux = {'|', 0};
  vector<pair<char, int> > datos;
  int len = 0;
  char c;
  while(c = getchar(), c != '\n'){
    if(c == aux.first) aux.second++;
    else{
      datos.push_back(aux);
      aux.first = c;
      aux.second = 1;
    }
    len++;
  }
  datos.push_back(aux);

  len+= 1;
  int n, ini, finish, j, ans, cont;
  bool inicia = false;

  cin >> n;
  getchar();
  for(int i=0; i<n; i++){
    j = 1;

    ans = cont = inicia = 0;
    ini = len;
    finish = -1;
    while(c = getchar(), c != '\n' && c != EOF){
      xd:
      while(j < datos.size() && c != datos[j].first){
        ans+=datos[j++].second-cont;
        cont = 0;
      }

      if(j == datos.size()){
        ans = -1;
        while(c = getchar(), c != EOF && c != '\n');
        break;
      }

      if(c == datos[j].first){
        cont++; //Get one
        if(datos[j].second < cont){
          j++;
          cont = 0;
          goto xd;
        }else {
          ans++;
          if(!inicia){
            ini = ans;
            inicia = true;
          }
        }
      }      
      
    }
    // cout << j << " " << ans << " " << datos[datos.size()-1].second << " " << len << endl;
    if(ans == len) finish = -1;
    else finish = ans;

    if(ini == len || finish == -1) cout << "Not matched\n";
    else cout << "Matched " << (ini-1) << " " << (finish-1) << "\n";
  }

  return 0;
}