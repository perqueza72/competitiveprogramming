#include <bits/stdc++.h>

using namespace std;


int main(){
  int h, w, W, H, resp, t, x1,x2,y1,y2;
  
  cin >> t;
  for(int i=0; i<t; i++){
    resp = 1e8+10;
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;

    if(w+x2-x1 > W && h+y2-y1 > H){
      cout << -1 << endl;
      continue;
    }

    // printf("Coordenadas: (%d %d), (%d %d)\n", x1,y1,x2,y2);
    // printf("%d %d %d %d\n", w-x1, x2-(W-w), h-y1, y2-(H-h));
    if(w+x2-x1 <= W){
      resp = min(resp, max(0,w-x1));
      resp = min(resp, max(0,x2-(W-w)));
    }
    if(h+y2-y1 <= H){
      resp = min(resp, max(0, h-y1));
      resp = min(resp, max(0,y2-(H-h)));
    }

    cout << resp << endl;


  }

  return 0;
}