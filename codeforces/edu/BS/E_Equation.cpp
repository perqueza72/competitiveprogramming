#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-7;
double n;


bool fit(const double &x){
    return x*x + sqrt(x) > n;
}

double bs(){
    long long limit = sqrt(n)+1;
    double l = 0.5, r = limit;
    double mid;

    while((r-l) >= EPSILON){
        mid = (r-l)/2 +l;

        if(fit(mid)) r = mid;
        else l = mid;
    }

    return mid;
}


int main(){

    cin >> n;
    cout.precision(10);
    cout << fixed << bs() << endl;

    return 0;
}