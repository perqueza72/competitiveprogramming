#include <bits/stdc++.h>

using namespace std;

struct Rect{
  int x1,x2,y1,y2;

  int width(){
    return (x2-x1);
  };
  int height(){
    return (y2-y1);
  };
  int area(){
    return (width()*height());
  }
};

bool intersec(Rect r1, Rect r2, Rect *ans){
  ans->x1 = max(r1.x1, r2.x1);
  ans->y1 = max(r1.y1, r2.y1);
  ans->x2 = min(r1.x2, r2.x2);
  ans->y2 = min(r1.y2, r2.y2);

  if(ans->x2 <= ans->x1 || ans->y2 <= ans->y1) return false;
  return true;
}

bool on_border(Rect r1, Rect r2){
  if((r1.y1 == r2.y1 || r1.y2 == r2.y2) && (r1.x1 == r2.x1 || r1.x2 == r2.x2)) return true;
  return false;
}

int main(){

  // freopen("billboard.in", "r", stdin);
  // freopen("billboard.out", "w", stdout);
  int ans;
  Rect r1,r2,r1r2;
  cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
  cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

  ans = r1.area();
  if(intersec(r1,r2, &r1r2)){
    if(r1r2.width() == r1.width() || r1r2.height() == r1.height()){
      if(on_border(r1,r1r2)) ans -= r1r2.area();
    }
  }

  cout << ans << endl;


  return 0;
}