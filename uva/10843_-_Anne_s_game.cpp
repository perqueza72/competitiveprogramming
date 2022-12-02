#include <bits/stdc++.h>

using namespace std;

const long long MOD = 2000000011;

int exp(long long b, const int e){
    long long r = 1;
    for(int i=0; i<32; i++){
        if(e&(1<<i)) r= (r*b)%MOD;
        b= (b*b)%MOD;
    }
    
    return r;
}

int main(){

    int n;
    long long x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        cout << "Case #" << (i+1) << ": " << exp(x, x-2) << "\n";
    }
    

    return 0;
}