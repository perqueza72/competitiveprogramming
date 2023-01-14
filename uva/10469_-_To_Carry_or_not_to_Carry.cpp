#include <bits/stdc++.h>

using namespace std;

int main(){

    unsigned int a, b, r, count;
    while(cin >> a >> b){
        r = 0;
        count = 0;
        while(a || b){
            r |= (((a&1) != (b&1)) << count);
            count++;
            a>>=1;
            b>>=1;
        }

        cout << r << "\n";
    }
    

    return 0;
}