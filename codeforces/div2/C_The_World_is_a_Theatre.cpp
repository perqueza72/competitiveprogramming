#include <bits/stdc++.h>

using namespace std;



long long enes[31];
long long kas[31];

long long ex(long long b, long long e){
    if(e <= 0) return 1;

    long long r = 1;
    while(e){
        if(e&1) r*=b;
        b = b*b;
        e>>=1;
    }

    return r;
}

long long combinatoric(long long n, long long k){

    for(int i=1; i<=n; i++) enes[i] = kas[i] = 0;

    int number;
    for(int i=2; i<=n; i++){
        number = i;
        for(int j=2; j<=n && number > 1; j++){
            while(number%j == 0){
                enes[j]++;
                number/=j;
            }
        }
    }

    for(int i=2; i<=k; i++){
        number = i;
        for(int j=2; j<=n && number > 1; j++){
            while(number%j == 0){
                kas[j]++;
                number/=j;
            }
        }
    }

    for(int i=2; i<=(n-k); i++){
        number = i;
        for(int j=2; j<=n && number > 1; j++){
            while(number%j == 0){
                kas[j]++;
                number/=j;
            }
        }
    }

    for(int i=1; i<31; i++){
        enes[i]-=kas[i];
    }

    long long sum = 1;
    for(int i=1; i<=n; i++){
        if(enes[i] == 0) continue;
        sum*=ex(i, enes[i]);
    }

    return sum;
}

int main(){

    long long n, m, t, a, sum=0, comb, aux;
    cin >> n >> m >> t;
    for(long long b=1; b<=m; b++){
        comb = combinatoric(m, b);
        // cout << "comb: "  << comb << endl;
        a = t-b;
        if(a >= 4 && a <= n){
            aux= comb;
            aux*= combinatoric(n, a);
            sum+= aux;
        }
    }

    cout << sum << endl;


    return 0;
}