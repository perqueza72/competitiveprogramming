#include <bits/stdc++.h>

using namespace std;

int main(){


    int t, n;
    cin >> t;
    while(t--){
        cin >> n;

        if(n%3 == 0){
            if(n-5>4){
                cout << "YES\n";
                cout << 1 << " " << 4 << " " << (n-5) << "\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(n-3 > 2){
                cout << "YES\n";
                cout << 1 << " " << 2 << " " << (n-3) << "\n";
            }else cout << "NO\n";
        }
    }
}