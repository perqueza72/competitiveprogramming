#include <bits/stdc++.h>

using namespace std;


struct Rect{
  int x1,y1,x2,y2;

  void print(){
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
};

bool intersect(Rect r1, Rect r2, Rect *overlap){
  overlap->x1 = max(r1.x1, r2.x1);
  overlap->y1 = max(r1.y1, r2.y1);
  overlap->x2 = min(r1.x2, r2.x2);
  overlap->y2 = min(r1.y2, r2.y2);

  if(overlap->x2 <= overlap->x1 || overlap->y2 <= overlap->y1) return false;
  return true;
}

int main(){

  int t;
  Rect r1, r2, overlap;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

    if(intersect(r1, r2, &overlap)) overlap.print();
    else printf("No Overlap\n");
    if(i != t-1) printf("\n");

  }


  return 0;
}