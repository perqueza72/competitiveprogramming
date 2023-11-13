#include <bits/stdc++.h>

using namespace std;


unsigned long long n, d, val;

int bits(const unsigned long long &v){
    unsigned long long val = v;
    int cont = 0;
    while(val > 0){
        val>>=1;
        ++cont;
    }

    return cont-1;
}

bool fit(const int &bit){

    __int128 a = (__int128)(1ull<<(bit))*(__int128)d;
    __int128 b = (__int128)(n + d - 1ull);
    return a >= b;
}

int bs(){
    unsigned long long l = 0, r = 60, mid;
    while(l <= r){
        mid = (r-l)/2 + l;

        if(fit(mid)) r = mid-1;
        else l = mid +1;
    }

    return l;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n >> d;

        if(n == 1){
            cout << "0\n";
            continue;
        }
        cout << bs() << "\n";
    }

    return 0;
}