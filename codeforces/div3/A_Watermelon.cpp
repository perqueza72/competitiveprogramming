#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    if(n < 3) cout << "NO";
    else if((n-2) & 1) cout << "NO";
    else cout << "YES";
    return 0;
}