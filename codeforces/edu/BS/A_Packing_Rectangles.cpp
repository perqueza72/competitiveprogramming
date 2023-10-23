#include <bits/stdc++.h>

using namespace std;

long long n, w, h;

bool fit(const long long &x){
    
    long long k = x/w;
    long long m = x/h;
    // cout << k << " " << m << "\n";
    
    if(m == 0 || k == 0) return false;
    if(m >= n || k >= n) return true;    
    return m*k >= n;
}

long long bs(){
    
    long long l = 1, r = (long long)1e18+10;
    long long mid;
    while(l <= r){
        mid = (r-l)/2ll + l;
        
        if(fit(mid)) r = mid-1ll;
        else l = mid+1ll;
    }
    
    return l;
}


int main()
{
    
    cin >> w >> h >> n;
    cout << bs() << endl;

    return 0;
}

