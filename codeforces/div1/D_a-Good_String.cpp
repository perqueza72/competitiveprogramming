#include <bits/stdc++.h>

using namespace std;


vector<char> s;
int r;
//Count the different letters.
int count(const int &l, const int &u, const char &letter){
  r = 0;
  for(int i=l; i<=u; i++) if(s[i] != letter) r++;
  
  return r;
}

int solve(int l, int u, char letter){
  if(l == u) return s[l] != letter;
  

  int mid = (u+l)/2;

  return min(
    solve(l,mid,letter+1) + count(mid+1, u, letter),
    solve(mid+1, u, letter+1) + count(l,mid, letter)
  );
  
}

int main(){

  int n, t;
  cin >> t;
  while(t--){
    cin >> n;
    getchar();

    s.resize(n);
    for(int i=0; i<n; i++){
      s[i] = getchar();
    }
    getchar();

    if(n == 1){
      if(s[0] == 'a') cout << 0 << "\n";
      else cout << 1 << "\n";
    }
    else cout << solve(0, n-1, 'a') << "\n";
    // cout << "ok"<<endl;
  }

  return 0;
}