#include <bits/stdc++.h>

using namespace std;


long double cf[11], epsilon = 1e-3;
int t;
long double solve(long double v){
    long double sum = 0;
    v+= 1.0;
    for(int i=0; i<t+1; i++){
        sum+= cf[i]*pow(v, t-i);
        // for(int j=0; j<t-i; j++){
        //     cout << "v: " << v << endl;
        //     v*=v;
        // }
        // sum += cf[i]*v;
    }

    // cout << "sum: " << sum << endl;
    return sum;
}

long double bisection(long double l, long double r){
    long double mid = (r-l)/(long double)2.0 + l;
    int it = 100;
    while(abs(solve(mid)) > epsilon && it--){
        mid = (r-l)/(long double)2.0 + l;
        // cout << "IT " << it << endl;
        // cout << "\t" << l << " solve l: " << solve(l) << endl;
        // cout << "\t" << mid << " solve mid: " << solve(mid) <<endl;
        // cout << "\t" << r << " solve r: " << solve(r) << endl;
        // cout << "m" << mid << endl;
        // cout << "sum con " << mid << ": " << solve(mid) << endl;
        if(solve(mid)*solve(l) > 0){
            l = mid;
        }else{
            r = mid;
        }
    }

    return mid;
}

int main(){

    long double root, l, r, what1, what2;
    while(cin >> t, t){
        for(int i=0; i<t+1; i++)
            cin >> cf[i];

        l = -0.99;
        r = 1e6;

        root = bisection(l, r);
        if(abs(solve(root)) > epsilon){
            cout << "Too many\n";
            continue;
        }
        
        what1 = bisection(l, root-0.1);
        what2 = bisection(root+0.1, r);
        if(abs(solve(what1)) < epsilon || abs(solve(what2)) < epsilon){
            cout << "Too many\n";
            continue;
        }
        cout.precision(2);
        cout << fixed << root << "\n";
        
    }

    return 0;
}