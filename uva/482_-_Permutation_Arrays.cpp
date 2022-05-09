#include <bits/stdc++.h>


using namespace std;

int main(){

  int t, n, aux;
  string v;
  string line;

  vector<int> order;
  vector<string> arr;

  cin >> t;
  while(t--){
    // cout << "here"<< endl;
    getchar();
    getchar();
    order.resize(0);
    getline(cin, line);
    // cout << "line:" << line << endl;
    istringstream iss(line);
    while ( iss >> aux) {    
      order.push_back(aux);
    }

    n = order.size();
    arr.resize(n);

    for(int i=0; i<n; i++){
      cin >> v;
      arr[order[i]-1] = v;
    }

    for(auto v : arr){
      cout << v << "\n";
    }

    if(t) cout << "\n";
  }

  return 0;
}