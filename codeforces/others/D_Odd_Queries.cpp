#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, t, q, x, l, r, k, sum, aux;
    vector<long long> a;
    cin >> t;
    while(t--){
        cin >> n >> q;
        a.resize(n+1);
        sum = 0;

        a[0] = 0;
        for(int i=0; i<n; i++){
            cin >> aux;
            a[i+1] = a[i]+aux;
        }

        sum = a[n];

        for(int i=0; i<q; i++){
            cin >> l >> r >> k;
            // cout << a[r] << " - " << a[l] << endl;
            // cout << "sum: " << sum << endl;
            x = sum - (a[r]-a[l-1]);
            // cout << x << endl;
            x += k*(r-l+1);
            // cout << x << endl;
            if(x&1) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}