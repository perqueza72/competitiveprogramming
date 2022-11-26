#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > pairs;
int n, maxi = 2*1e7+10;
void criba(){
    int last = 2;
    vector<bool> primes(maxi, 1);
    primes[2] = 1;

    for(int i=4; i<maxi; i+=2) primes[i] = false;

    for(long long i=3; i*i<maxi; i+=2){

        if(primes[i]){
            if(i-last == 2) pairs.push_back({last, i});
            last = i;
            for(int long long j=i*i; j<maxi; j+=i){
                primes[j] = false;
            }
        }
    }
    
    int limit = sqrt(maxi);
    if((limit & 1) == 0) limit++;

    for(int i=limit; i<maxi; i+=2){
        if(primes[i]){
            if(i-last == 2) pairs.push_back({last, i});
            last = i;
        }
    }


}

int main(){

    criba();
    while(cin >> n){
        n--;
        printf("(%d, %d)\n", pairs[n].first, pairs[n].second);
    }

    return 0;
}