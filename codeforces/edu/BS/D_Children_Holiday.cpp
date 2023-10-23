#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX_SIZ = (int)1e3+10;
long long z[MAX_SIZ], y[MAX_SIZ], t[MAX_SIZ];
long long b[MAX_SIZ];
long long z_i, t_i, x, y_i;

bool inflate(const long long &T, const long long &b, const int &i){

    long long a = max((b-1)/z[i], 0ll);
    return a*y[i] + b*t[i] > T;
}


long long ec(const long long &T, const int &i){

    // long long nom = T    * z[i] + y[i];
    // long long den = t[i] * z[i] + y[i];

    // return nom/den;
    long long mid;
    long long l = 0, r = T;
    while(l <= r){
        // cout << l << " " << r << "\n";
        mid = (r-l)/2 + l;

        if(inflate(T, mid, i)) r = mid-1;
        else l = mid +1;
    }

    return r;

}

bool calc(const long long &T){

    long long sum = 0;

    for(int i=0; i<n; i++){
        b[i] = ec(T, i);
        // cout << b[i] << " ";
        sum += b[i];
    }
    // cout << "\n";
    // cout << "sum of " << T << ": " << sum << "\n";

    return sum >= (long long)m;
}

int bs(long long l, long long r, bool (*func)(const long long &)){

    long long mid;

    while(l <= r){
        // cout << l << " " << r << "\n";
        mid = (r-l)/2 + l;

        if(func(mid)) r = mid-1;
        else l = mid +1;
    }

    return l;
}

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        cin >> t[i] >> z[i] >> y[i];
    }

    long long max_t = bs(0, (long long)1e8+10, &calc);
    long long m_copy = m;

    calc(max_t);
    cout << max_t << "\n";
    for(int i=0; i<n; i++){
        
        // long long ballons = ec(max_t, i);
        
        // cout << min(m_copy, ballons) << " ";
        // m_copy = max(m_copy - ballons, 0ll);

        long long ballons = b[i];
        
        cout << min(m_copy, ballons) << " ";
        m_copy = max(m_copy - ballons, 0ll);
    }

    return 0;
}