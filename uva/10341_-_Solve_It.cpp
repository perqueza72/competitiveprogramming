#include <bits/stdc++.h>

using namespace std;


long double p, q, r, s, t, u;
const double epsilon = 1e-7;
long double eq(long double x){
  return p*exp(-x) + q*sin(x)+ r*cos(x) + s*tan(x) + t*x*x + u;
}


int main(){

  cout.precision(4);
   long double x;
   while(cin >> p >> q >> r >> s >> t >> u){
    long double l = 0.0, r = 1.0;
    long double dos = 2.0, m;
    int ite = 100;

    for(int i=0; i<ite; i++){
      m = (l + r)/dos;
      //cout << l << " " << r << ": " << m << "; eq(m) = " << eq(m) << "\n";
      if(eq(m) >= 0.0) l = m;
      else r = m;
    }

    //cout << l << " " << r << " EOF\n";
    if(eq(0) * eq(1) > 0.0) cout << "No solution\n";
    else cout << fixed << l << "\n";
  }


  return 0;
}