#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, s, total, aux, a, b;
    cin >> t;
    while(t--){
        cin >> n;
        a = b = 0;
        for(int i=0; i<n; i++){
            cin >> aux;
            if(aux&1) a+=aux;
            else b+=aux;
        }
        
        cout << (a < b ? "YES" : "NO") << "\n";
    }

    return 0;
}