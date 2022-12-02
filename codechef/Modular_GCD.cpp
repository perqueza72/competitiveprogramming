#include <bits/stdc++.h>

using namespace std;


long long n;
const long long MOD = 1e9+7;

__int128 exp(__int128 a, const long long &b, const long long &mod){

    __int128 r = 1;
    a%=mod;
    for(long long i=0; i<64; i++){
        if(b&(1ll<<i)) r=(r*a)%mod; 
        a=(a*a)%mod;
    }
    return r;
}

long long calc(long long a, long long b, __int128 mod){
    if(mod == 0) mod = MOD;
    return (long long)((exp(a, n, mod) + exp(b, n, mod)) % mod);
}

long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){

    int t;
    cin >> t;

    long long a, b, mod, A, B;
    while(t--){
        cin >> a >> b >> n;
        A = abs(a-b);
        B = calc(a, b, abs(a-b));
        
        cout << (gcd(A, B)%MOD) << endl;
    }



    return 0;
}