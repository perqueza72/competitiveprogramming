#include <bits/stdc++.h>

using namespace std;

void toUpperWord(string &s){
  for(int i=0; i<s.size(); i++) s[i] = toupper(s[i]);
}

bool f(const pair<string,int> &a, pair<string, int> &b){
  if(a.second == b.second) return a.first <= b.first;
  if(a.second <= b.second) return true;
  return false;
}

void sorting(map<string, int> m, const int &b){
  vector<pair<string, int> >  v;

  int cont = 0;
    for(auto u : m)
      if(u.second <= b) v.push_back(u);


  sort(v.begin(), v.end(), f);
  if(v.empty()) cout << "Too expensive!\n";
  else for(auto u: v) cout << u.first << "\n";
}


int main(){

  int t, n, m, price, b, k, priceRecipe;
  string s, rName, name, a;
  map<string, int> recipe, ingr;
  cin >> t;
  while(t--){
    getchar();
    recipe = ingr = map<string,int>();
    getline(cin, name);
    // cout << name << endl;
    cin >> m >> n >> b;
    // cout << m << " " << n << " " << b << endl;
    for(int i=0; i<m; i++){
      cin >> a >> price;
      ingr.insert({a,price});
      // cout << a << " " << price << endl;
    }
    for(int i=0; i<n; i++){
      priceRecipe = 0;
      getchar();
      getline(cin, rName);
      cin >> k;
      while(k--){
        cin >> a >> price;
        if(ingr.count(a)){
          priceRecipe+= price*ingr[a];
        }else priceRecipe+= 1e7;
        // cout << a << " " << price << endl;
      }
      recipe.insert({rName, priceRecipe});
    }
    toUpperWord(name);
    cout << name << "\n";
    sorting(recipe, b);
    // if(t) 
    cout << "\n";
      // cout << b << " "<< u.second << endl;

  }

  return 0;
}