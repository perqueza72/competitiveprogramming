#include <bits/stdc++.h>

using namespace std;


bool able(){

    if(x % 3 == 0) return false;
    if(y % 3 == 0) return false;
    if(z % 3 == 0) return false;

    return x+y+z == n;
}

int main(){


    int t, n;
    cin >> t;
    while(t--){
        cin >> n;

        for(z=1; z<n; ){
            for(y=1; y<z;){
                for(x=1; x<y;){
                    able(x, y, z);
                }
            }
        }
    }
}