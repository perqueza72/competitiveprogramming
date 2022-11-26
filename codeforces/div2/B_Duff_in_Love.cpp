#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, limit;
    long long value = 1;
    cin >> n;

    limit = sqrt(n);
    for(long long i=2; i<=limit; i++){
        if(n%i == 0) value*= i;
        while(n%i == 0){
            n/= i;
        }
    }

    value*= n;
    cout << value << endl;

    return 0;
}