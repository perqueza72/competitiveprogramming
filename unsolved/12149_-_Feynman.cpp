#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, r;
    while(cin >> n, n){
        a = r = 0;
        while(n-a){
            r+= (n-a)*(n-a);
            a++;
        }
        cout << r << "\n";
    }

    return 0;
}