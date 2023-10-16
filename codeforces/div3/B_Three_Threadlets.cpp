#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, a[3];
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);

        int x = a[0];
        bool puede = true;
        for(int i=0; i<3; i++) if(a[i] != x) puede = false;
        if(puede){
            cout << "YES\n";
            continue;}

        bool next = false;
        for(int i=0; i<3; i++) if(a[i]%x){
            cout << "NO\n";
            next = true;
            break;
        }
        if(next) continue;

        if(x == a[1]){
            if(a[2]%4 == 0 && a[2]/4 == x) puede = true;
            if(a[2]%3 == 0 && a[2]/3 == x) puede = true;
            if(a[2]%2 == 0 && a[2]/2 == x) puede = true;
        }
        if(puede){
            cout << "YES\n";
            continue;
        }

        if(a[1]%2 == 0 && a[1]/2 == x){
            if(a[1] == a[2]) puede = true;
            if(a[2]%3 == 0 && a[2]/3 == x) puede = true;
        }
        if(puede) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}