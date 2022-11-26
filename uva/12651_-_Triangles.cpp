#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, m, r;
    int *pos;
    int v[(int)1e5+10];
    while(cin >> n){
        r = 0;

        cin >> v[0];
        for(int i=1; i<n; i++){
            cin >> a;
            v[i] = v[i-1]+a;
        }
        if(v[n-1]%3){
            cout << "0\n";
            continue;
        }
        m = v[n-1]/3;

        for(int i=0; i<n-2; i++){
            pos = lower_bound(v+1, v+n-1, v[i]+m);
            if(pos != (v+n-1) && *pos == v[i]+m){
                if(binary_search(pos+1, v+n, *pos+m)) r++;
            }
        }
        cout << r << "\n";
    }

    return 0;
}