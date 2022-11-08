#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

long long pow(long long a, long long b){
    long long r = 1;
    for(int i=0; i<b; i++){
        r*=a;
        r%=MOD;
    }

    return r;
}

int main(){

    long long n;
    cin >> n;
    
    cout << (pow(3ll,n)-7ll-(n+1ll)*n) << endl;

    return 0;
}