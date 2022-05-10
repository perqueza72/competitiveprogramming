#include <bits/stdc++.h>

using namespace std;


vector<long long> v, temp;

long long compare(long long start, long long mid, long long end){
  long long cont = 0;
  long long auxStart = start;
  
  for(long long i = start, j = mid+1 ; i<= mid || j<=end ; ){
    if(i > mid){
      temp[auxStart] = v[j];
      ++j;
    }else if(j > end){
      temp[auxStart] = v[i];
      ++i;
    }else{
      if(v[i] <= v[j]){
        temp[auxStart] = v[i];
        i++;
      }else{
        cont+=j-auxStart;
        temp[auxStart] = v[j];
        j++;
      }
    }
    ++auxStart;

  } 
    
  for(long long i = start ; i <= end ; ++i){
    v[i] = temp[i];
  }


  

  return cont;
}

long long mergesort(long long start, long long end){
  if(start == end) return 0;

  long long r = 0;
  long long mid = (end+start)/2;
  r+= mergesort(start, mid);
  r+= mergesort(mid+1, end);

  return r+compare(start, mid, end);
}


int main(){

  

  long long t;
  while(cin >> t, t){
    v.resize(t);
    temp.resize(t);
    for(long long i=0; i<t; i++){
      cin >> v[i];
    }

    cout << mergesort(0, t-1) << "\n";
  }
  
  return 0;
}