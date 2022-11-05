#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+2;

vector<int> criba(const int &n){

    vector<bool> primes(sqrt(n)+1, true);
    vector<int> response;

    primes[1] = primes[0] = false;
    for(int i=2; i*i<=n; i+=2){
        primes[i] = false;
    }

    response.push_back(2);
    for(long long i=3; i*i<=n; i+=2){
        if(primes[i]){
            response.push_back(i);
            for(long long j=i*i; j*j<=n; j+=i){
                primes[j] = false;
            }
        }
    }

    return response;
}


vector<int> primes = criba(MAX);

int calc(int n){

    long long res = 1, aux;
    for(int i=0; i<primes.size() and n != 1; i++){
        aux = 1;
        while((n/primes[i])*primes[i] == n){
            n/=primes[i];
            aux++;
        }
        res *= aux;
    }

    return res;
}

int main(){

    int dp[MAX];
    memset(dp, -1, sizeof(dp));

    int a,b,c;
    long long v, sum = 0;
    cin >> a >> b >> c;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<=c; k++){
                v = i*j*k;
                if(dp[v] != -1){
                    sum+= (long long)dp[v];
                    continue;
                }

                dp[v] = calc(v);
                sum+=(long long)dp[v];
            }
        }

    }

    cout << sum << endl;

    return 0;
}