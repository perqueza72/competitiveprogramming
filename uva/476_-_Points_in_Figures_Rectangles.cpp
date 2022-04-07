#include <bits/stdc++.h>

using namespace std;

int main(){

  char c;
  vector<pair< pair<double, double>, pair<double,double> > > cuadrados; 
  pair<double, double> x, y, point;
  double px, py;
  while(cin >> c, c != '*'){
    cin >> px >> py;
    x = make_pair(px, py);
    cin >> px >> py;
    y = make_pair(px, py);
    cuadrados.push_back(make_pair(x,y));
  }
  int p = 0;
  bool exist;
  while(cin >> px >> py, px != 9999.9 && py != 9999.9){
    point = make_pair(px, py);
    // cout << "px y py: " <<px << " " << py << endl;
    p++;
    exist = false;
    for(int i=0; i<cuadrados.size(); i++){
      x = cuadrados[i].first;
      y = cuadrados[i].second;
      if(y.first > point.first && point.first > x.first && x.second > point.second && point.second > y.second){
        // cout << "first: " << point.first << " " << point.second << endl;
        // cout << "limx: " << y.first << " " << x.first << endl;
        // cout << "limy: " << x.second << " " << y.second << endl;

        exist = true;
        printf("Point %d is contained in figure %d\n", p, i+1);
      }
    }

    if(!exist){
      printf("Point %d is not contained in any figure\n", p);
    }
  }

  return 0;
}