#include <bits/stdc++.h>

using namespace std;


int MAX_VALUE = (int)sqrt(1e6+10);

vector<int> criba(){

    int n = MAX_VALUE, limit = sqrt(n)+1;
    vector<bool> is_prime(MAX_VALUE, true);
    
    is_prime[0] = is_prime[1] = false;
    for(int i=4; i<n; i+=2) is_prime[i] = false;
    for(int i=3; i<limit; i+=2){

        if(is_prime[i]){
            for(int j=i*i; j<limit; j+=i)
                is_prime[j] = false;
        }
    }

    vector<int> prime;
    for(int i=0; i<MAX_VALUE; i++){
        if(is_prime[i]) prime.push_back(i); 
    }
    
    return prime;
}


vector<int> primes;
void f(int n, map<int, int> &v){

    int next = 0, val;
    while(n > 1 && next < primes.size()){
        val = primes[next++];

        if(n%val == 0 && v.count(val) == 0) v.insert({val, 0});
        while(n%val == 0){
            n/=val;
            v[val]++;
        }
    }

    if(n != 1){
        if(v.count(n) == 0) v.insert({n, 1});   
        else v[n]++;
    }

}

int main(){
    primes = criba();

    int t, times, aux, n;
    bool puede;
    cin >> t;
    while(t--){
        map<int, int> leMape;
        puede = true;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> aux;
            f(aux, leMape);
        }
        
        if(leMape.size() == 0){
            cout << "YES\n";
            continue;
        }

        for(auto &a : leMape){
            if(!puede) break;

            if(a.second%n) puede = false;
        }

        if(puede) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}