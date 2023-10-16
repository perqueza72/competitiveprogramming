#include <bits/stdc++.h>

using namespace std;
vector<long long> a;

long long question(const int &l, const int &r){

    cout << "? " << (r-l) << " ";
    for(int i=l; i<r; i++){
        cout << (i+1) << " ";
    }
    cout << endl;
    long long ans;
    cin >> ans;

    return ans;
}

long long sumar(const int &l, const int &r){
    long long s = 0;
    for(int i=l; i<r; i++){
        s+=a[i];
    }

    return s;
}

int find(int l, int r){

    int mid = (l+r)/2;

    if(l >= r) return mid+1;

    if(question(l, mid+1) != sumar(l, mid+1)){
        return find(l, mid);
    }
    return find(mid+1, r);
}


int main(){

    int t,  n;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        for(auto &v : a) cin >> v;


        int ans = find(0, n);
        cout << "! " << ans << endl;
    }
    return 0;
}