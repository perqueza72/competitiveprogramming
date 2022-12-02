#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, m, aT, bT, a, b, gcd;
    cin >> n >> m;

    gcd = __gcd(n, m);
    n/= gcd;
    m/= gcd;

    if(abs(n-m) == 1) cout << "Equal";
    else if(n < m) cout << "Dasha";
    else cout << "Masha";
    cout << endl;

    return 0;
}