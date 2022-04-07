#include <bits/stdc++.h>

using namespace std;


struct Rect{
  int x1, x2, y1, y2;

  int area(){
    return (y2-y1)*(x2-x1);
  }

  void print(){
    printf("(%i,%i),(%i,%i)\n", x1,y1,x2,y2);
  }
};

bool intersec(Rect r1, Rect r2, Rect *newRect){
  newRect->x2 = min(r1.x2, r2.x2);
  newRect->y2 = min(r1.y2, r2.y2);
  newRect->x1 = max(r1.x1, r2.x1);
  newRect->y1 = max(r1.y1, r2.y1);

  if(newRect->x2 < newRect->x1 || newRect->y2 < newRect->y1) return false;
  return true;
}


int main(){

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  Rect bb1, bb2, track, intB1, intB2;
  int resp = 0;

  cin >> bb1.x1 >> bb1.y1 >> bb1.x2 >> bb1.y2;
  cin >> bb2.x1 >> bb2.y1 >> bb2.x2 >> bb2.y2;
  cin >> track.x1 >> track.y1 >> track.x2 >> track.y2;

  if(intersec(bb1, track, &intB1)) resp-= intB1.area();
  if(intersec(bb2, track, &intB2)) resp-= intB2.area();
  resp += bb1.area() + bb2.area();

  // intB1.print();
  // intB2.print();
  cout << resp << endl;


  return 0;
}