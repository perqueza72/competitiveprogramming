#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, r, sum, n;
    bool cont, ant;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        vector<int> v(n);
        for(int i=0; n>i; i++){
            cin >> v[i];
            sum+= v[i];
        }

        if((sum&1) == 0){
            cout << 0 << "\n";
            continue;
        }

        r = 0;
        cont = true;
        while(cont){
            r++;
            for(int i=0; n>i; i++){
                ant = (v[i])&1;
                v[i]/=2;
                if((v[i]&1) != ant){
                    cont = false;
                    break;
                }
            }
        }

        cout << r <<"\n";
    }   

    return 0;
}