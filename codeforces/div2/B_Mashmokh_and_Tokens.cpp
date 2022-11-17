#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    long long a, b, w, aux;
    cin >> n >> a >> b;
    for(int i=0; i<n; i++){
        cin >> w;
        cout << (((w*a)%b)/a) << " ";
    }

    return 0;
}