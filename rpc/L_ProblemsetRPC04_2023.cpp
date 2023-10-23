#include <bits/stdc++.h>

using namespace std;

const long double EPSILON = 1e-6;
double n, sqr;

long double total;
bool fit(const long double &x){
    return total <= x*x*x;
}

long double bs(){
    long double l = min(sqr-1, 1.0), r = sqr+1;

    long double mid;
    while((r-l) >= EPSILON) {
        mid = (r- l)/2 + l;

        if(fit(mid)) r = mid;
        else l = mid;
    }

    return l;
}

int main(){

    long double val;
    cin >> n;

    total = 0;
    for(int i=0; i<n; i++){
        cin >> val;
        total += (val*val*val);
    }

    cout.precision(10);
    sqr = pow(total, 1.0/3.0);
    cout << fixed << bs() << endl;
    // cout << fixed << total << endl;
    return 0;
}