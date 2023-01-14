#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, t, aux;
    cin >> t;
    while(t--){

        cin >> n;
        vector<pair<int,int > > v(n);
        for(int i=0; n>i; i++){
            cin >> aux;
            v[i] = {aux, i+1};
        }

        sort(v.begin(), v.end());

        cout << n << "\n"; 
        int op = 0;
        int b, a = v[0].first;
        for(int i=1;n>i; i++){
            b = v[i].first;
            if(a == b) continue;

            cout << v[i].second << " " << (a-(b%a)) << "\n";
            a = b+(a-(b%a));
            op++;
        }

        while(op++ < n) cout << 1 << " " << "0\n";
    } 

    return 0;
}