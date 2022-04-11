#include <bits/stdc++.h>

using namespace std;

vector<string> image;
const int x[] = {1,0,-1,0};
const int y[] = {0,1,0,-1};

inline void shape(vector<string> &v){
  int minX = 1e8, maxX = 0;
  bool exist, start = false;
  string s;
  vector<string> res;
  string aux;
  int vacios = 0;
  aux.assign(v[0].length(), '.');
  for(int i=0; i<v.size(); i++){
    s = "";
    exist = false;
    for(int j=0; j<v[i].length(); j++){
      if(v[i][j] == '#'){
        if(start && vacios){
          for(int k=0; k<vacios; k++){
            res.push_back(aux);
          }
          vacios = 0;
        }
        minX = min(minX, j);
        maxX = max(maxX, j);
        exist = true;
      }
      s+= v[i][j];
    }

    if(exist){
      res.push_back(s);
      start = true;
      vacios = 0;
    }else vacios++;
  }

  for(int i=0; i<res.size(); i++){
    res[i].resize(maxX+1);
  } 
  if(minX > 0){
    for(int i=0; i<res.size(); i++){
      for(int j=0; j<res[i].size()-minX; j++){
        res[i][j] = res[i][j+minX];
      }
      res[i].resize(res[i].size()-minX);
    }
  }
  v.swap(res);
}

inline void printV(const vector<string> &v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << "\n";
  }
  cout << endl;
}

bool comp(const vector<string> &mini,const vector<string> &full, const int &miniI = 0, const int &miniJ = 0){
  if(mini.size()+miniI > full.size() || mini[0].size()+miniJ > full[0].size() ) return false;

  for(int i=0; i<mini.size(); i++){
    for(int j=0; j<mini[0].size(); j++){
      if(full[i+miniI][j+miniJ] != mini[i][j] && mini[i+miniI][j+miniJ] == '#'){
        return false;
      }
    }
  }

  return true;
}

vector<string> convert(const vector<string> &tapon, vector<string> v, const int posI = 0, const int posJ = 0){
  for(int i=0; i<tapon.size(); i++){
    for(int j=0; j<tapon[0].length(); j++){
      if(tapon[i][j] == v[i+posI][j+posJ]) v[i+posI][j+posJ] = '.';
    }
  }
  shape(v);

  return v;
}

bool ubicar(const vector<string> &v,const vector<vector<string>> &pieces, const int &x, int &y, const int &k){

  vector<string> aux;
  for(int i=0; i<=(int)(image.size()-v.size()); i++){
    for(int j=0; j<=(int)(image[0].size()-v[0].size()); j++){

      if(comp(v, image, i, j)){
        aux = convert(v, image, i, j);

        for(int l=x+1; l<k; l++){
          if(comp(pieces[l], aux)){
            y = l+1;
            return true;
          }
        }
      }

    }
  }

  return false;
}


int main(){

  freopen("bcs.in", "r", stdin);
  freopen("bcs.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  image.resize(n);
  vector<vector<string> > pieces(k, image);
  for(int i=0; i<n; i++){
    cin >> image[i];
  }
  for(int i=0; i<k; i++){
    for(int j=0; j<n; j++){
      cin >> pieces[i][j];
    }
  }

  shape(image);
  for(int i=0; i<k; i++){
    shape(pieces[i]);
    // printV(pieces[i]);
  }
  // printV(image);

  
  int x, y;
  for(int i=0; i<k; i++){
    // cout << "i: " <<i<< endl;
    if(ubicar(pieces[i], pieces, i, y, k)){
      x = i+1;
      break;
    }
  }

  cout << (int)x << " " << (int)y;

  return 0;
}