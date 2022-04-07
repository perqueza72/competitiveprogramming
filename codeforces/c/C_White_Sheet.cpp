#include <bits/stdc++.h>

using namespace std;


struct Rect{
  long long x1,x2,y1,y2;

  long long area(){
    return (y2-y1)*(x2-x1);
  }
};

bool intersect(Rect r1, Rect r2, Rect *res){
  res->x1 = max(r1.x1, r2.x1);
  res->y1 = max(r1.y1, r2.y1);
  res->x2 = min(r1.x2, r2.x2);
  res->y2 = min(r1.y2, r2.y2);

  if(res->x1 >= res->x2 || res->y1 >= res->y2) return false;
  return true;
}

int main(){

  Rect white, b1, b2, wb1, wb2, wb1b2;
  cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  long long area = white.area();
  if(intersect(white, b1, &wb1)){
    area-= wb1.area();
    if(intersect(white, b2, &wb2)){  
      area-= wb2.area();
      if(intersect(wb2, wb1, &wb1b2))
        area+=wb1b2.area();
    }  
  }else if(intersect(white, b2, &wb2)){
    area-=wb2.area();
  }

  if(area > 0) cout << "YES" << endl;
  else cout << "NO" << endl;





  return 0;
}