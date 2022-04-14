#include <bits/stdc++.h>

using namespace std;

double calc(const int &a,const int &b){
  return (double)a/(double)b;
}

int main(){

  complex<int> originL(0,1), originU(1,0), value, l, u, d(0,0);
  int n, m;
  double v;
  string ans;
  while(cin >> m >> n, m != 1 || n != 1){
    u = originU;
    l = originL;
    ans = "";
    complex<int> comp(m,n);
    v = calc(m, n);

    while(comp != d){
      d = l+u;
      if(v < calc(real(d), imag(d))){
        ans+= "L";
        u = d;
      }else{
        ans+= "R";
        l = d;
      }
    }
    ans.pop_back();
    cout << ans << "\n";
  }

  return 0;
}