#include <bits/stdc++.h>

using namespace std;


vector<long long> stall;
long long n;
int c;

bool work(const long long &v){
  long long diff=0;
  int cows = c-1;
  for(int i=1; i<n; i++){
    diff += stall[i] - stall[i-1];
    if(diff >= v){
      diff= 0;
      cows--;
    }
  }
  return cows <= 0;
}

long long bs(long long lower, long long upper){

  if(lower == upper) return lower;
  if(lower+1 == upper){
    if(work(upper)) return upper;
    return lower;
  }
  
  long long mid = (upper+lower)/2;
  if(work(mid)){
    return bs(mid, upper);
  }
  return bs(lower, mid-1);
}

int main(){

  int t;
  cin >> t;
  while(t--){
    cin >> n >> c;
    stall.resize(n);
    for(int i=0; i<n; i++) cin >> stall[i];

    sort(stall.begin(), stall.end());
    long long mini = stall[0];
    long long maxi = stall[stall.size()-1];
    cout << bs(mini,maxi ) << "\n";
  }

  return 0;
}