#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    if(n > 2 || n == 0)
        cout << -1 << endl;
    else if(n == 1)
        cout << "1 2 3\n";
    else if(n == 2)
        cout << "3 4 5\n";

    return 0;
}