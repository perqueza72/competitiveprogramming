#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > v;
vector<int> dondeEsta;
int a, b, num;

vector<int>::iterator getAPos(int a){
  for(auto i = v[dondeEsta[a]].begin(); i<v[dondeEsta[a]].end(); i++){
    if(*i == a){
      return i;
    }
  }
  return v[dondeEsta[a]].begin();
}

void monto(){

  while(num = v[dondeEsta[b]].back(), num != b){
    v[num].push_back(num);
    v[dondeEsta[b]].pop_back();

    dondeEsta[num] = num;
  }
  do{
    num = v[dondeEsta[a]].back();
    if(num != a) v[num].push_back(num);
    v[dondeEsta[a]].pop_back();

    dondeEsta[num] = num;
  }while(num != a);

  v[dondeEsta[b]].push_back(a);
  dondeEsta[a] = dondeEsta[b];
}

void mover(){

  do{
    num = v[dondeEsta[a]].back();
    if(num != a) v[num].push_back(num);
    v[dondeEsta[a]].pop_back();

    dondeEsta[num] = num;
  }while(num != a);

  
  v[dondeEsta[b]].push_back(a);
  dondeEsta[a] = dondeEsta[b];
}

void ponto(){
  vector<int> aux;
  do{
    num = v[dondeEsta[a]].back();
    aux.push_back(num);
    v[dondeEsta[a]].pop_back();

    dondeEsta[num] = dondeEsta[b];
  }while(num != a);

  while(num = v[dondeEsta[b]].back(), num != b){
    v[num].push_back(num);
    dondeEsta[num] = num;
    v[dondeEsta[b]].pop_back();
  }

  while(aux.size()){
    v[dondeEsta[b]].push_back(aux.back());
    aux.pop_back();
  }
}

void pover(){ 
  vector<int> aux;
  do{

    num = v[dondeEsta[a]].back();
    aux.push_back(num);
    v[dondeEsta[a]].pop_back();
    
    dondeEsta[num] = dondeEsta[b];
  }while(num != a);

  while(aux.size()){
    v[dondeEsta[b]].push_back(aux.back());
    aux.pop_back();
  }
}

int main(){

  int n;
  string s, op;
  cin >> n;
  v.resize(n);
  dondeEsta.resize(n);
  for(int i=0; i<n; i++){
    dondeEsta[i] = i;
    v[i].push_back(i);
  }
  while(cin >> s, s != "quit"){
    cin >> a >> op >> b;
    if(dondeEsta[a] == dondeEsta[b]) continue;

    if(s == "move" && op == "onto") monto();
    if(s == "move" && op == "over") mover();
    if(s == "pile" && op == "onto") ponto();
    if(s == "pile" && op == "over") pover();
  }
  for(int i=0; i<v.size(); i++){
    printf("%d:", i);
    for(int j=0; j<v[i].size(); j++){
      // if(j) 
      cout << " ";
      cout << v[i][j];
    }
    cout << "\n";
  }

  return 0;
}