#include <bits/stdc++.h>

using namespace std;

const int MAXI = 1e8+10;
vector<bool> is_prime(MAXI, true);
vector<int> prime;
void criba(){
    is_prime[0] = is_prime[1] = false;
    for(int i=4; i<MAXI; i+=2) is_prime[i] = false;

    int limit = sqrt(MAXI);
    prime.push_back(2);
    for(long long i=3; i<=limit; i+=2){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=i*i; j<=MAXI; j+=i){
                is_prime[j] = false;
            }
        }
    }

    if((limit&1) == 0) limit++;
    for(long long i=limit; i<MAXI; i+=2){
        if(is_prime[i]) prime.push_back(i);
    }

}

int main(){
    int n, m, b, a;
    criba();
    
    while(cin >> n){
        if(n < 8){
            cout << "Impossible.\n";
            continue;
        }

        n-=4;
        cout << "2 ";
        if(n&1){
            cout << "3 ";
            n--;
        }
        else{
            cout << "2 ";
        }

        auto r = lower_bound(prime.begin(), prime.end(), n+1);
        for(int i=0; i<(r-prime.begin()); i++){
            a = prime[i];
            if(n < prime[i]) continue;
            
            b = n-prime[i];
            if(is_prime[a] && is_prime[b]) break;
            
        }

        cout << a << " " << b << "\n";
    }
    

    return 0;
}