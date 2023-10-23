#include <bits/stdc++.h>

using namespace std;

int n, k;
int rope[(int)1e4+10];
double EPSILON = 1e-12;

bool fit(const long double &x){

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (((long double)rope[i])/x);
    }

    return sum >= k;
}


double bs(){

    double mid, l=0, r=1e7+10;
    while(abs(r-l) > EPSILON){
        // cout << r << " " << l << "\n";
        
        mid = (r-l)/2 + l;
        if(fit(mid)) l = mid;
        else r = mid;

    }

    return r;
}


int main(){

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> rope[i];
    }
    
    cout.precision(10);
    cout << fixed << bs() << endl;
    return 0;
}