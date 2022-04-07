#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  int n, iters;
  cin >> n >> iters;
  vector<int> arr(n); 
  vector<vector<int> > combi;
  int a[2], b[2];

  cin >> a[0] >> b[0] >> a[1] >> b[1];
  a[0]--;
  b[0]--;
  a[1]--;
  b[1]--;

  for(int i=0; i<n; i++){
    arr[i] = i+1;
    // cout << arr[i] << " ";
  }

  int temp;
  do{
    combi.push_back(arr);
    for(int k=0; k<2; k++){
      for(int i=a[k], j=b[k]; i<j; i++, j--)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }while(!is_sorted(arr.begin(), arr.end()));

  for(int i=0; i<n; i++){
    cout << combi[iters%combi.size()][i] << "\n";
  }


  return 0;
}