#include <bits/stdc++.h>

using namespace std;

int area(pair<int,int> a, pair<int,int> b){
  return abs(a.first - b.first)*abs(a.second - b.second);
}

void printPair(pair<int,int> a){
  cout << "first: " << a.first << " second: " << a.second << "\n";
}

int main(){

  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n, maxi = 0, x, y;
  cin >> n;
  pair<int, int> points[n];
  for(int i=0; i<n; i++){
    cin >> x >> y;
    points[i] = {x,y};
  }

  pair<int,int> a, b,c;
  // sort(points, points+n);
  for(int i=0; i<n; i++){
    a = points[i];
    for(int j=0; j<n; j++){
      if(j == i) continue;
      b = points[j];
      if(a.first == b.first){
        // cout << "a.second: " << a.second << " b.second: " << b.second << endl;
        // cout << "a.second: " << a.second << " b.second: " << b.second << endl;

        for(int k=0; k<n; k++){
          if(k == j || k == i) continue;
          c = points[k];

          if(a.second == c.second){
            // cout << "here" << endl;
            // printPair(a);
            // printPair(b);
            // printPair(c);
            maxi = max(area(c, b), max(area(a,c), maxi));
          }
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    a = points[i];
    for(int j=0; j<n; j++){
      if(j == i) continue;
      b = points[j];
      if(a.second == b.second){
        // cout << "In y = " << a.second << "\n";
        // cout << "a.x: " << a.first << " b.x: " << b.first << endl;


        for(int k=0; k<n; k++){
          if(k == j  || k == i) continue;
          c = points[k];

          if(a.first == c.first){
            maxi = max(area(c, b), max(area(a,c), maxi));
          }
        }
      }
    }
  }

  cout << maxi << endl;

  return 0;
}