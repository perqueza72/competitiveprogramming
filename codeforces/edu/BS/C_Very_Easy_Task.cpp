#include <bits/stdc++.h>

using namespace std;

long long n, t1, t2;


bool cover(const long long &tMax){

    long long a = tMax/t1;
    long long b = tMax/t2;

    // cout << a << " " << b << "\n";
    return a + b + 1 >= n;
}

long long bs(){

    long long l =0, r = (long long)1e12;
    long long mid;
    while(l <= r){
        // cout << l << " " << r <<endl;

        mid = (r-l)/2 +l;
        if(cover(mid)) r = mid-1;
        else l = mid +1;
    }

    return l;
}

int main(){

    cin >> n >> t1 >> t2;
    long long t0 = min(t1, t2);
    cout << (t0 + bs());
    
    return 0;
}