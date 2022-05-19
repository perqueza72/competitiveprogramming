#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, mini = (int)1e5, k, sum=0, aux;
  priority_queue<int> pq;

  cin >> n>>k;

  for(int i=0; i<n; i++){
    cin >> aux;
    //cout << "aux " << aux << endl;
    pq.push(-aux);
    mini = min(abs(aux), mini);
  }
  //cout << "mini: " << mini << endl;

  //cout << pq.size() << endl;
  while(k && pq.size()){
    aux = pq.top();
    if(aux <= 0) break;
    pq.pop();
    k--;
    sum+=aux;
  }

  //cout << pq.size() << endl;
  while(pq.size()){
    sum-= pq.top();
    pq.pop();
  }
  //cout << pq.size() << endl << "fin pq.size" << endl;
  //cout << "sum " << sum << endl;
  if(k%2){
    sum-=(2*mini);
  }

  cout << sum << endl;

  return 0;
}