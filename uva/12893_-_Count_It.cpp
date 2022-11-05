#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cont;
    long long v;
    cin >> n;
    while(n--){
        cont = 0;
        cin >> v;
        for(int i=0; i<64; i++){
            if(v & (1 << i)) cont++;
        }

        cout << cont << "\n";
    }
    return 0;
}