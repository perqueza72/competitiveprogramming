#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-7;



// struct Range{

//     int x, v;
//     double l, r;

//     void update(const double &t){
//         this->l = (double)x - ((double)v*t);
//         this->r = (double)x + ((double)v*t);
//     }
// };


// bool contains(const Range &a, const Range &b){
//     if((a.l <= b.l) && (b.l <= a.r)){
//         return true;
//     }
//     if((a.l <= b.r) && (b.r <= a.r)){
//         return true;
//     }
//     return false;
// }


int n;
double x[(int)1e5+10];
double v[(int)1e5+10];

inline bool fit(const double &t){


    bool puede = true;
    double l = -LLONG_MAX, r = LLONG_MAX, lAux, rAux;
    for(int i=0; i<n; ++i){

        // ranges[i].update(t);
        lAux = x[i] - v[i]*t;
        rAux = x[i] + v[i]*t;
        if(l < lAux) l = lAux;
        if(r > rAux) r = rAux;
        // if(contains(minRange, ranges[i]) || contains(ranges[i], minRange))
        //     continue;
        
        // puede = false;
        // break;
    }

    if(fabs(r-l) <= EPSILON) return true;
    return l < r;
}

inline double bs(){
    double l = 0, r = 1e9+10, mid;
    while(fabs(r-l) >= EPSILON){
        mid = (r+l)/2;

        if(fit(mid)) r = mid;
        else l = mid;
    }

    return mid;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Range r;
    cin >> n;
    for(int i=0; i<n; i++){
        // cin >> r.x >> r.v;
        cin >> x[i] >> v[i];

        // ranges.push_back(r);
    }

    cout.precision(10);
    cout << fixed << bs() << "\n";


    return 0;
}