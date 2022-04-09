#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<string> spotty(n);
  vector<string> plain(n);
  for(int i=0; i<n; i++) cin >> spotty[i];
  for(int i=0; i<n; i++) cin >> plain[i];

  int cont = 0;

  set<string> se;
  string a = "mom";
  for(char i=0; i<m-2; i++){
    for(char j=i+1; j<m-1; j++){
      for(char k=j+1; k<m; k++){
        se.clear();

        for(int s=0; s<n; s++){
          a[0] = spotty[s][i];
          a[1] = spotty[s][j];
          a[2] = spotty[s][k];
          se.insert(a);
        }

        for(int p=0; p<n; p++){
          a[0] = plain[p][i];
          a[1] = plain[p][j];
          a[2] = plain[p][k];

          if(se.count(a)){
            cont--;
            break;
          }
        }
        
        cont++;

      }
    }
  }



  cout << cont << endl;
  

  return 0;
}