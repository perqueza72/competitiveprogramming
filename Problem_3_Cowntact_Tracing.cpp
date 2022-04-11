#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main(){

  // freopen("tracing.in", "r", stdin);
  // freopen("tracing.out", "w", stdout);

  int n, m;
  string esperado;

  cin >> n >> m;
  cin >> esperado;
  esperado = "0" + esperado;

  int t, t_max = 0, t_min = 252;
  vector<pair<int,int> > timelaps(251);
  for(int i=0; i<m; i++){
    cin >> t >> timelaps[t].first >> timelaps[t].second;
    t_max = max(t, t_max);
    t_min = min(t, t_min);
  }

  int mink = n, maxk = 0;
  int cows = 0;
  string simulacion;
  bool pudo;
  vector<char> veces;
  for(int i=1; i<=n; i++){
    pudo = false;
    for(int k=0; k<=n; k++){

      simulacion.assign(n+1,'0');
      veces.assign(n+1,k);

      // cout << "k " << k << ":\n";
      simulacion[i] = '1';
      for(t = t_min; t<=t_max; t++){
        if(timelaps[t].first == 0 || timelaps[t].second == 0) continue;
        if(veces[timelaps[t].second] == 0 || veces[timelaps[t].first] == 0) continue;

        if(simulacion[timelaps[t].first] == '1' || simulacion[timelaps[t].second] == '1'){

          if(simulacion[timelaps[t].first] == '1' && simulacion[timelaps[t].second] == '1'){
            veces[timelaps[t].first]--;
            veces[timelaps[t].second]--;
          }
          else if(simulacion[timelaps[t].first] == '1') veces[timelaps[t].first]--;
          else if(simulacion[timelaps[t].second] == '1') veces[timelaps[t].second]--;

          // cout << "datos en tiempo t = " << t << ": " << (int)veces[timelaps[t].first] << " " << (int)veces[timelaps[t].second] << endl;

          simulacion[timelaps[t].first] = '1';
          simulacion[timelaps[t].second] = '1';
        }
      }

      // cout << simulacion << endl;

      if(simulacion == esperado){
        if(pudo){
          maxk = OO;
          break;
        }

        cows++;
        pudo = true;

        mink = min(k, mink);
        maxk = max(maxk, k);
      }
    }
  }

  cout << cows << " " << mink << " ";
  if(maxk == OO) cout << "Infinity"; 
  else cout << maxk;
   cout << endl;

  
  


  return 0;
}