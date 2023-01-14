#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    while(cin >> n){
        long long a = n*n*(n+1ll)*(n+1ll)/4ll;
        cout << a << "\n";
    }   

    return 0;
}