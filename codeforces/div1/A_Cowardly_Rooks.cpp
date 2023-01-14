#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, m, a, b;
    cin >> t;
    while(t--){
        cin >> n >> m;

        set<int> s;
        int a;
        for(int i=0; i<m; i++){
            cin >> a >> b;
            s.insert(a);
        }

        // if(s1.size() == s2.size() && s1.size() == 1){
        //     cout << "YES\n";
        // }else
        if(s.size() < n){
            cout << "YES\n";
        }else cout << "NO\n";


    }

    return 0;
}