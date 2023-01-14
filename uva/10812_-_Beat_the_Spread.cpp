#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, a, y, x, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        y = (a-b)/2;
        if(y < 0 || (a-b)%2){
            cout << "impossible\n";
            continue;
        }
        x = b+y;

        cout << x << " " << y << "\n";
    }   

    return 0;
}