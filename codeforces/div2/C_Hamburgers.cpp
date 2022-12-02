#include <bits/stdc++.h>

using namespace std;

long long p[3], have[3], burger[3] = {0};
long long r;

bool calc(long long &x){
    long long price = 0;
    for(int i=0; i<3; i++){
        price+= max(0ll, p[i]*(x*(burger[i])-have[i]));
    }
    // cout << "price: " <<price << endl;

    return price <= r;
}

long long bs(long long l, long long r){
    long long mid;

    // int cont = 0;
    while(l <= r){
        mid = (r-l)/2+l;
        // cont++;
        // cout << "it " << cont++ << ": " << l << " " << mid << " " << r << endl;
        if(calc(mid)){
            l = mid+1;
        }else{
            // ans = mid;
            r = mid-1;
        }
    }

    if(calc(r)) return r;
    return l;
}

int main(){
    string s;

    cin >> s;
    cin >> have[0] >> have[1] >> have[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;

    for(auto &c : s){
        if(c == 'B') burger[0]++;
        else if(c == 'S') burger[1]++;
        else if(c == 'C') burger[2]++;
    }

    long long maxi = 1e12+100;
    cout << bs(0, maxi) << endl;
    return 0;
}