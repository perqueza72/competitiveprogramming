#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    if((n&1) == 0){
        cout << "-1\n";
        return 0;
    }

    vector<int> v(n), u(n);
    for(int i=0; i<n; i++){
        v[i] = i; 
        cout << v[i] << " ";
    }
    cout << "\n";

    u[0] = n-1;
    cout << (n-1) << " ";
    for(int i=1; i<n; i++){
        u[i] = i-1;
        cout << u[i] << " ";
    }

    cout << "\n";

    for(int i=0; i<n; i++){
        cout << ((u[i]+v[i])%n) << " ";
    }

    
    return 0;
}