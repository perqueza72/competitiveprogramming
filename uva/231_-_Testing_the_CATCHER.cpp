#include <bits/stdc++.h>

using namespace std;

vector<int> v;


vector<int>::iterator bs(vector<int>::iterator l, vector<int>::iterator r, int value){

  vector<int>::iterator mid, begin = l;
  int auxL, auxR, auxMid;
  // int cont = 0;
  while(l < r){
    auxR = r-begin;
    auxL = l-begin;
    auxMid = (auxR+auxL)/2;
    mid = begin+auxMid;
    // if(mid == l || *mid == value) break;
    if(*mid > value){
      l = mid+1;
    }else{
      r = mid;
    }
  }

  return l;
}

inline int Lis(){
  vector<int> lis;
  lis.push_back(v[0]);
  for(int i=1; i<v.size(); i++){
    if(v[i] < lis.back()) lis.push_back(v[i]);
    else{
      auto it = bs(lis.begin(), lis.end(), v[i]);
      *it = v[i];
    }
  }

  return lis.size();

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test, value, cont = 0;
  while(cin >> test, test != -1){
    if(cont) cout << "\n";
    v.resize(0);
    v.push_back(test);
    while(cin >> value, value != -1){
      v.push_back(value);
    }

    cont++;
    cout << "Test #" << cont << ":\n";
    cout << "  maximum possible interceptions: ";
    cout << Lis() << "\n";
  }  

  return 0;
}

