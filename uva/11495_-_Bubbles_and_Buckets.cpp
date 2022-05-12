#include <bits/stdc++.h>

using namespace std;


vector<int> v, temp;
long long merge(int start, int mid, int end){
  long long cont = 0;
  int i=start, j=mid+1, k = start;
  while(i<=mid && j<=end){
    if(v[i] <= v[j]){
      temp[k] = v[i++];
    }else{
      cont+= j-k;
      temp[k] = v[j++];
    }

    k++;
  }

  while(i <= mid) temp[k++] = v[i++];
  while(j <= end) temp[k++] = v[j++];

  

  for(int i = start ; i <= end ; ++i){
    v[i] = temp[i];
  }

  return cont;
}

long long mergesort(int start, int end){

  if(start == end) return 0;

  int mid = (start+end)/2, r = 0;
  r+=mergesort(start, mid);
  r+=mergesort(mid+1, end);

  return r+merge(start, mid, end);
}

int main(){

  int n;
  string r;
  while(cin >> n, n){
    v.resize(n);
    temp.resize(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
      // cout << v[i] << endl;
    }

    // cout << mergesort(0, n-1) << endl;
    // for(int i=0; i<n; i++){
    //   cout << v[i] << " ";
    // }
    // cout << endl;
    r = (mergesort(0, n-1)%2) ? "Marcelo" : "Carlos";
    cout << r << "\n";
  }

  return 0;
}