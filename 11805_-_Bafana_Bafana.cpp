#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, k, p, n, cont;
    cin >> t;

    cont = t;
    while(t--){
        cin >> n >> k >> p;

        cout << "Case " << (cont-t) << ": "; 
        cout << ((k-1+p)%n + 1) << "\n";
    }   

    return 0;
}