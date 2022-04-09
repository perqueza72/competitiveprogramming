#include <bits/stdc++.h>

using namespace std;

vector<int> x, y;
const int addX[] = {1,1,-1,1};
const int addY[] = {1,-1,-1,1};
int q1, q2, q3, q4;
int N, B, dividerX, dividerY;
int q[4], aux[4];

int main(){

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  cin >> N >> B;
  x.resize(N);
  y.resize(N);
  for(int i=0; i<N; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> results;

  for(int i=0; i<N; i++){
    for(int l=0; l<N; l++){
      for(int j=0; j<4; j++){
        dividerX = x[i]+addX[j];
        dividerY = y[l]+addY[j];

        q[0] = q[1] = q[2] = q[3] = 0;
        for(int k=0; k<N;k++){
          if(dividerX > x[k] && dividerY > y[k]) q[0]++;
          if(dividerX < x[k] && dividerY < y[k]) q[1]++;
          if(dividerX > x[k] && dividerY < y[k]) q[2]++;
          if(dividerX < x[k] && dividerY > y[k]) q[3]++;
        }
        // if(*max_element(q, q+4) < 4){
        //   cout << "i: " << i << " con valor " << *max_element(q, q+4) << " divider: " << dividerX << ", "<< dividerY<< endl;
        // }
        results.push_back(*max_element(q, q+4));
      }
    }
  }

  cout << (*min_element(results.begin(), results.end())) << endl;

  return 0;
}