#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, l, r, cont = 0;
    cin >> t;
    while(cont++<t){
        cin >> l >> r;

        r = (r+1)/2;
        l = l/2;

        cout << "Case " << cont << ": ";
        cout << (r*r-l*l) << "\n";
    }

    return 0;
}